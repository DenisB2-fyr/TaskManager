#include "task.h"
#include <sstream>

namespace Task_Management {

// Inițializarea membrului static
// Aceasta se face în fișierul .cpp, nu în .h
int Task::s_id_counter = 0;

Task::Task(const std::string& title, const std::string& description, Priority priority)
    : m_title(title), 
      m_description(description), 
      m_priority(priority),
      m_status(TaskStatus::NOT_STARTED),  // Inițial, sarcina nu este începută
      m_assigned_user(nullptr) {  // Inițial, nu este atribuit niciun utilizator
    m_id = _GenerateId();  // Generăm un ID unic pentru sarcină
}

Task::Task(const Task& other)
    : m_title(other.m_title),
      m_description(other.m_description),
      m_id(other.m_id),
      m_priority(other.m_priority),
      m_status(other.m_status),
      m_assigned_user(other.m_assigned_user),
      m_categories(other.m_categories) {
    // Constructor de copiere - copiază toate datele din obiectul other
}

Task::~Task() {
    // Implementarea destructorului virtual
    // În acest caz simplu, nu avem resurse de eliberat
    // Dar este important să fie virtual pentru clasele derivate
}

std::string Task::GetTitle() const {
    return m_title;  // Returnează titlul sarcinii
}

void Task::SetTitle(const std::string& title) {
    m_title = title;  // Setează titlul sarcinii
}

std::string Task::GetDescription() const {
    return m_description;  // Returnează descrierea sarcinii
}

void Task::SetDescription(const std::string& description) {
    m_description = description;  // Setează descrierea sarcinii
}

std::string Task::GetId() const {
    return m_id;  // Returnează ID-ul unic al sarcinii
}

Priority Task::GetPriority() const {
    return m_priority;  // Returnează prioritatea sarcinii
}

void Task::SetPriority(Priority priority) {
    m_priority = priority;  // Setează prioritatea sarcinii
}

TaskStatus Task::GetStatus() const {
    return m_status;  // Returnează statusul sarcinii
}

void Task::SetStatus(TaskStatus status) {
    m_status = status;  // Setează statusul sarcinii
}

void Task::AssignTo(User* user) {
    m_assigned_user = user;  // Atribuie sarcina unui utilizator
}

User* Task::GetAssignedUser() const {
    return m_assigned_user;  // Returnează utilizatorul atribuit
}

void Task::AddCategory(Category* category) {
    m_categories.push_back(category);  // Adaugă o categorie la sarcină
}

const std::vector<Category*>& Task::GetCategories() const {
    return m_categories;  // Returnează toate categoriile atribuite
}

void Task::_WriteDetailsToStream(std::ostream& os) const {
    // Scrie detaliile de bază ale sarcinii în stream-ul de ieșire
    os << "ID: " << m_id << "\n";
    os << "Title: " << m_title << "\n";
    os << "Description: " << m_description << "\n";
    
    // Convertește enumerația Priority în text pentru afișare
    os << "Priority: ";
    switch (m_priority) {
        case Priority::LOW: os << "Low"; break;
        case Priority::MEDIUM: os << "Medium"; break;
        case Priority::HIGH: os << "High"; break;
        case Priority::URGENT: os << "Urgent"; break;
    }
    os << "\n";
    
    // Convertește enumerația TaskStatus în text pentru afișare
    os << "Status: ";
    switch (m_status) {
        case TaskStatus::NOT_STARTED: os << "Not Started"; break;
        case TaskStatus::IN_PROGRESS: os << "In Progress"; break;
        case TaskStatus::COMPLETED: os << "Completed"; break;
        case TaskStatus::DEFERRED: os << "Deferred"; break;
        case TaskStatus::CANCELLED: os << "Cancelled"; break;
    }
    os << "\n";
    
    // Afișează informații despre utilizatorul atribuit
    if (m_assigned_user) {
        os << "Assigned to: [User information]" << "\n";
    } else {
        os << "Assigned to: Unassigned" << "\n";
    }
    
    // Afișează informații despre categorii
    os << "Categories: ";
    if (m_categories.empty()) {
        os << "None";
    } else {
        os << m_categories.size() << " categories";
    }
    os << "\n";
}

// Implementarea operatorului << suprascris
// Aceasta este o funcție friend declarată în clasa Task
std::ostream& operator<<(std::ostream& os, const Task& task) {
    task._WriteDetailsToStream(os);  // Delegăm afișarea către metoda protejată
    return os;  // Returnăm stream-ul pentru a permite înlănțuirea (ex: cout << task1 << task2)
}

// Metodă privată pentru generarea ID-urilor unice
std::string Task::_GenerateId() {
    std::stringstream ss;
    ss << "TASK-" << ++s_id_counter;  // Incrementăm contorul static și îl includem în ID
    return ss.str();  // Returnăm ID-ul ca string
}

} // namespace Task_Management
