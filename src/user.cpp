#include "user.h"
#include "task.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace Task_Management {

// Inițializarea membrului static
int User::s_id_counter = 0;

User::User(const std::string& name, const std::string& email)
    : m_name(name), m_email(email) {
    // Generăm un ID unic pentru utilizator
    m_id = _GenerateId();
}

User::User(const User& other)
    : m_name(other.m_name),
      m_email(other.m_email),
      m_id(other.m_id),
      m_assigned_tasks(other.m_assigned_tasks) {
    // Constructor de copiere - copiază toate datele din obiectul other
    // Notă: Aceasta este o copiere superficială (shallow copy) a pointerilor la sarcini
}

User::~User() {
    // Implementarea destructorului virtual
    // În acest caz simplu, nu avem resurse de eliberat
}

std::string User::GetName() const {
    // Returnează numele utilizatorului
    return m_name;
}

void User::SetName(const std::string& name) {
    // Setează numele utilizatorului
    m_name = name;
}

std::string User::GetEmail() const {
    // Returnează adresa de email a utilizatorului
    return m_email;
}

void User::SetEmail(const std::string& email) {
    // Setează adresa de email a utilizatorului
    m_email = email;
}

std::string User::GetId() const {
    // Returnează ID-ul unic al utilizatorului
    return m_id;
}

void User::AddAssignedTask(Task* task) {
    // Adaugă o sarcină la lista de sarcini atribuite dacă pointerul nu este null
    if (task) {
        m_assigned_tasks.push_back(task);
    }
}

bool User::RemoveAssignedTask(const std::string& task_id) {
    // Caută sarcina cu ID-ul specificat
    auto it = std::find_if(m_assigned_tasks.begin(), m_assigned_tasks.end(),
                          [&task_id](const Task* task) { return task->GetId() == task_id; });
    
    // Dacă am găsit sarcina, o eliminăm și returnăm true
    if (it != m_assigned_tasks.end()) {
        m_assigned_tasks.erase(it);
        return true;
    }
    
    // Dacă nu am găsit sarcina, returnăm false
    return false;
}

const std::vector<Task*>& User::GetAssignedTasks() const {
    // Returnează toate sarcinile atribuite utilizatorului
    return m_assigned_tasks;
}

size_t User::GetAssignedTaskCount() const {
    // Returnează numărul de sarcini atribuite utilizatorului
    return m_assigned_tasks.size();
}

void User::DisplayDetails() const {
    // Afișează detaliile utilizatorului folosind operatorul << suprascris
    std::cout << *this;
}

std::string User::GetUserType() const {
    // Returnează tipul utilizatorului ca string
    // Această metodă poate fi suprascrisă în clasele derivate pentru a returna tipuri specifice
    return "Standard User";
}

void User::_WriteDetailsToStream(std::ostream& os) const {
    // Scrie detaliile utilizatorului în stream-ul de ieșire
    os << "ID: " << m_id << std::endl;
    os << "Name: " << m_name << std::endl;
    os << "Email: " << m_email << std::endl;
    os << "Type: " << GetUserType() << std::endl;
    os << "Assigned Tasks: " << m_assigned_tasks.size() << std::endl;
}

// Implementarea operatorului << suprascris
std::ostream& operator<<(std::ostream& os, const User& user) {
    os << "=== User Details ===" << std::endl;
    user._WriteDetailsToStream(os);
    
    // Afișează sarcinile atribuite acestui utilizator
    if (!user.m_assigned_tasks.empty()) {
        os << "Tasks assigned to this user:" << std::endl;
        for (size_t i = 0; i < user.m_assigned_tasks.size(); ++i) {
            os << "  " << (i + 1) << ". " << user.m_assigned_tasks[i]->GetTitle() << std::endl;
        }
    }
    
    os << "===================" << std::endl;
    return os;  // Returnăm stream-ul pentru a permite înlănțuirea
}

// Metodă privată pentru generarea ID-urilor unice
std::string User::_GenerateId() {
    // Folosim un stringstream pentru a construi ID-ul
    std::stringstream ss;
    ss << "USER-" << ++s_id_counter;  // Incrementăm contorul static și îl includem în ID
    return ss.str();  // Returnăm ID-ul ca string
}

} // namespace Task_Management
