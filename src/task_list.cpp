#include "task_list.h"
#include "task.h"
#include "inotifier.h"
#include <iostream>
#include <sstream>
#include <algorithm>

namespace Task_Management {

// Inițializarea membrului static
int Task_List::s_id_counter = 0;

Task_List::Task_List(const std::string& name)
    : m_name(name), m_notifier(nullptr) {
    // Generăm un ID unic pentru lista de sarcini
    m_id = _GenerateId();
}

Task_List::Task_List(const Task_List& other)
    : m_name(other.m_name),
      m_id(other.m_id),
      m_tasks(other.m_tasks),
      m_notifier(other.m_notifier) {
    // Constructor de copiere - copiază toate datele din obiectul other
    // Notă: Aceasta este o copiere superficială (shallow copy) a pointerilor
}

Task_List::~Task_List() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

std::string Task_List::GetName() const {
    // Returnează numele listei de sarcini
    return m_name;
}

void Task_List::SetName(const std::string& name) {
    // Setează numele listei de sarcini
    m_name = name;
}

std::string Task_List::GetId() const {
    // Returnează ID-ul unic al listei de sarcini
    return m_id;
}

void Task_List::AddTask(Task* task) {
    // Adaugă o sarcină la listă dacă pointerul nu este null
    if (task) {
        m_tasks.push_back(task);
    }
}

bool Task_List::RemoveTask(const std::string& task_id) {
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

const std::vector<Task*>& Task_List::GetTasks() const {
    // Returnează toate sarcinile din listă
    return m_tasks;
}

size_t Task_List::GetTaskCount() const {
    // Returnează numărul de sarcini din listă
    return m_tasks.size();
}

size_t Task_List::GetCompletedTaskCount() const {
    // Numără sarcinile finalizate folosind std::count_if din STL
    // Aceasta este o funcție care numără elementele care satisfac o condiție
    return std::count_if(m_tasks.begin(), m_tasks.end(),
                        [](const Task* task) { return task->IsCompleted(); });
}

double Task_List::GetCompletionPercentage() const {
    // Dacă lista este goală, returnăm 0%
    if (m_tasks.empty()) {
        return 0.0;
    }
    
    // Calculăm procentul mediu de finalizare al tuturor sarcinilor
    double total_percentage = 0.0;
    for (const auto& task : m_tasks) {
        total_percentage += task->GetCompletionPercentage();
    }
    
    // Returnăm media
    return total_percentage / m_tasks.size();
}

void Task_List::DisplayDetails() const {
    // Afișează detaliile listei de sarcini folosind operatorul << suprascris
    std::cout << *this;
}

void Task_List::SetNotifier(INotifier* notifier) {
    // Setează notificatorul pentru această listă
    // Demonstrează injecția de dependențe - un concept avansat în POO
    m_notifier = notifier;
}

bool Task_List::SendNotification(const std::string& recipient, const std::string& subject) const {
    // Verificăm dacă avem un notificator setat
    if (!m_notifier) {
        return false;
    }
    
    // Construim mesajul notificării
    std::stringstream message;
    message << "Task List: " << m_name << "\n";
    message << "Total Tasks: " << m_tasks.size() << "\n";
    message << "Completed Tasks: " << GetCompletedTaskCount() << "\n";
    message << "Completion Percentage: " << GetCompletionPercentage() << "%\n";
    
    // Trimitem notificarea folosind notificatorul
    // Aceasta demonstrează polimorfismul - apelăm o metodă virtuală prin interfață
    return m_notifier->SendNotification(recipient, subject, message.str());
}

Task_List Task_List::operator+(const Task_List& other) const {
    // Supraîncărcarea operatorului + pentru combinarea a două liste de sarcini
    // Creăm o nouă listă care combină ambele
    Task_List combined(*this);
    
    // Adăugăm toate sarcinile din cealaltă listă
    for (const auto& task : other.m_tasks) {
        combined.AddTask(task);
    }
    
    return combined;  // Returnăm noua listă combinată
}

// Implementarea operatorului << suprascris
std::ostream& operator<<(std::ostream& os, const Task_List& task_list) {
    os << "=== Task List Details ===" << std::endl;
    os << "ID: " << task_list.m_id << std::endl;
    os << "Name: " << task_list.m_name << std::endl;
    os << "Tasks: " << task_list.m_tasks.size() << std::endl;
    os << "Completed Tasks: " << task_list.GetCompletedTaskCount() << std::endl;
    os << "Completion Percentage: " << task_list.GetCompletionPercentage() << "%" << std::endl;
    
    // Afișează sarcinile din această listă
    if (!task_list.m_tasks.empty()) {
        os << "Tasks in this list:" << std::endl;
        for (size_t i = 0; i < task_list.m_tasks.size(); ++i) {
            os << "  " << (i + 1) << ". " << task_list.m_tasks[i]->GetTitle() 
               << " [" << task_list.m_tasks[i]->GetTaskType() << "]"
               << " - " << (task_list.m_tasks[i]->IsCompleted() ? "Completed" : "Not Completed")
               << std::endl;
        }
    }
    
    os << "=======================" << std::endl;
    return os;  // Returnăm stream-ul pentru a permite înlănțuirea
}

// Metodă privată pentru generarea ID-urilor unice
std::string Task_List::_GenerateId() {
    // Folosim un stringstream pentru a construi ID-ul
    std::stringstream ss;
    ss << "LIST-" << ++s_id_counter;  // Incrementăm contorul static și îl includem în ID
    return ss.str();  // Returnăm ID-ul ca string
}

} // namespace Task_Management
