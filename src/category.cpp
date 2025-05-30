#include "category.h"
#include "task.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace Task_Management {

// Inițializarea membrului static
int Category::s_id_counter = 0;

Category::Category(const std::string& name, const std::string& description)
    : m_name(name), m_description(description) {
    // Generăm un ID unic pentru categorie
    m_id = _GenerateId();
}

Category::Category(const Category& other)
    : m_name(other.m_name),
      m_description(other.m_description),
      m_id(other.m_id),
      m_tasks(other.m_tasks) {
    // Constructor de copiere - copiază toate datele din obiectul other
    // Notă: Aceasta este o copiere superficială (shallow copy) a pointerilor la sarcini
}

Category::~Category() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

std::string Category::GetName() const {
    // Returnează numele categoriei
    return m_name;
}

void Category::SetName(const std::string& name) {
    // Setează numele categoriei
    m_name = name;
}

std::string Category::GetDescription() const {
    // Returnează descrierea categoriei
    return m_description;
}

void Category::SetDescription(const std::string& description) {
    // Setează descrierea categoriei
    m_description = description;
}

std::string Category::GetId() const {
    // Returnează ID-ul unic al categoriei
    return m_id;
}

void Category::AddTask(Task* task) {
    // Adaugă o sarcină la categorie dacă pointerul nu este null
    if (task) {
        m_tasks.push_back(task);
        task->AddCategory(this);  // Adăugăm și categoria la sarcină (relație bidirecțională)
    }
}

bool Category::RemoveTask(const std::string& task_id) {
    // Caută sarcina cu ID-ul specificat
    auto it = std::find_if(m_tasks.begin(), m_tasks.end(),
                          [&task_id](const Task* task) { return task->GetId() == task_id; });
    
    // Dacă am găsit sarcina, o eliminăm și returnăm true
    if (it != m_tasks.end()) {
        m_tasks.erase(it);
        return true;
    }
    
    // Dacă nu am găsit sarcina, returnăm false
    return false;
}

const std::vector<Task*>& Category::GetTasks() const {
    // Returnează toate sarcinile din categorie
    return m_tasks;
}

size_t Category::GetTaskCount() const {
    // Returnează numărul de sarcini din categorie
    return m_tasks.size();
}

void Category::DisplayDetails() const {
    // Afișează detaliile categoriei folosind operatorul << suprascris
    std::cout << *this;
}

// Implementarea operatorului << suprascris
// Aceasta este o funcție friend declarată în clasa Category
std::ostream& operator<<(std::ostream& os, const Category& category) {
    // Afișează detaliile categoriei
    os << "=== Category Details ===" << std::endl;
    os << "ID: " << category.m_id << std::endl;
    os << "Name: " << category.m_name << std::endl;
    os << "Description: " << category.m_description << std::endl;
    os << "Tasks: " << category.m_tasks.size() << std::endl;
    
    // Afișează sarcinile din această categorie
    if (!category.m_tasks.empty()) {
        os << "Tasks in this category:" << std::endl;
        for (size_t i = 0; i < category.m_tasks.size(); ++i) {
            os << "  " << (i + 1) << ". " << category.m_tasks[i]->GetTitle() << std::endl;
        }
    }
    
    os << "=======================" << std::endl;
    return os;  // Returnăm stream-ul pentru a permite înlănțuirea
}

// Metodă privată pentru generarea ID-urilor unice
std::string Category::_GenerateId() {
    // Folosim un stringstream pentru a construi ID-ul
    std::stringstream ss;
    ss << "CAT-" << ++s_id_counter;  // Incrementăm contorul static și îl includem în ID
    return ss.str();  // Returnăm ID-ul ca string
}

} // namespace Task_Management
