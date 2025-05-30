#include "project_task.h"
#include <iostream>
#include <algorithm>

namespace Task_Management {

Project_Task::Project_Task(const std::string& title, const std::string& description, Priority priority)
    : Task(title, description, priority) {
    // Apelăm constructorul clasei de bază (Task) cu parametrii primiți
    // Nu avem inițializări suplimentare pentru m_subtasks deoarece vectorul este gol la început
}

Project_Task::Project_Task(const Project_Task& other)
    : Task(other) {
    // Apelăm constructorul de copiere al clasei de bază
    
    // Notă importantă: Aceasta este o copiere superficială (shallow copy) a pointerilor
    // În implementarea reală, ar trebui să facem o copiere profundă (deep copy)
    // clonând fiecare sub-sarcină pentru a evita probleme de ownership
    m_subtasks = other.m_subtasks;
}

Project_Task::~Project_Task() {
    // Implementarea destructorului
    // În implementarea reală, dacă deținem sub-sarcinile, ar trebui să le ștergem aici
    // Dar pentru simplitate, presupunem ownership partajat
}

void Project_Task::DisplayDetails() const {
    // Afișează detaliile proiectului
    std::cout << "=== Project Task Details ===" << std::endl;
    _WriteDetailsToStream(std::cout);  // Apelăm metoda protejată pentru afișarea detaliilor de bază
    std::cout << "============================" << std::endl;
    
    // Afișează sub-sarcinile
    if (!m_subtasks.empty()) {
        std::cout << "Subtasks:" << std::endl;
        for (size_t i = 0; i < m_subtasks.size(); ++i) {
            // Afișăm informații despre fiecare sub-sarcină
            std::cout << "  " << (i + 1) << ". " << m_subtasks[i]->GetTitle() 
                      << " [" << m_subtasks[i]->GetTaskType() << "]" 
                      << " - " << (m_subtasks[i]->IsCompleted() ? "Completed" : "Not Completed")
                      << std::endl;
        }
    }
}

std::string Project_Task::GetTaskType() const {
    // Returnează tipul sarcinii ca string
    return "Project Task";
}

bool Project_Task::IsCompleted() const {
    // Verifică dacă proiectul este finalizat
    
    // Dacă nu există sub-sarcini, verificăm statusul proiectului în sine
    if (m_subtasks.empty()) {
        return GetStatus() == TaskStatus::COMPLETED;
    }
    
    // Un proiect este finalizat doar dacă toate sub-sarcinile sunt finalizate
    // std::all_of este o funcție din STL care verifică dacă toate elementele
    // din interval satisfac o condiție (predicat)
    return std::all_of(m_subtasks.begin(), m_subtasks.end(), 
                      [](const Task* task) { return task->IsCompleted(); });
}

double Project_Task::GetCompletionPercentage() const {
    // Calculează procentul de finalizare al proiectului
    
    // Dacă nu există sub-sarcini, verificăm statusul proiectului în sine
    if (m_subtasks.empty()) {
        return (GetStatus() == TaskStatus::COMPLETED) ? 100.0 : 0.0;
    }
    
    // Calculăm procentul mediu de finalizare al tuturor sub-sarcinilor
    double total_percentage = 0.0;
    for (const auto& subtask : m_subtasks) {
        total_percentage += subtask->GetCompletionPercentage();
    }
    
    // Returnăm media
    return total_percentage / m_subtasks.size();
}

void Project_Task::AddSubtask(Task* subtask) {
    // Adaugă o sub-sarcină la proiect dacă pointerul nu este null
    if (subtask) {
        m_subtasks.push_back(subtask);
    }
}

bool Project_Task::RemoveSubtask(const std::string& subtask_id) {
    // Caută sub-sarcina cu ID-ul specificat
    // std::find_if este o funcție din STL care găsește primul element
    // din interval care satisface o condiție (predicat)
    auto it = std::find_if(m_subtasks.begin(), m_subtasks.end(),
                          [&subtask_id](const Task* task) { return task->GetId() == subtask_id; });
    
    // Dacă am găsit sub-sarcina, o eliminăm și returnăm true
    if (it != m_subtasks.end()) {
        m_subtasks.erase(it);
        return true;
    }
    
    // Dacă nu am găsit sub-sarcina, returnăm false
    return false;
}

const std::vector<Task*>& Project_Task::GetSubtasks() const {
    // Returnează toate sub-sarcinile
    return m_subtasks;
}

size_t Project_Task::GetSubtaskCount() const {
    // Returnează numărul de sub-sarcini
    return m_subtasks.size();
}

Project_Task Project_Task::operator+(const Project_Task& other) const {
    // Supraîncărcarea operatorului + pentru combinarea a două proiecte
    // Creăm un nou proiect care combină ambele
    Project_Task combined(*this);
    
    // Adăugăm toate sub-sarcinile din celălalt proiect
    for (const auto& subtask : other.m_subtasks) {
        combined.AddSubtask(subtask);
    }
    
    return combined;  // Returnăm noul proiect combinat
}

void Project_Task::_WriteDetailsToStream(std::ostream& os) const {
    // Mai întâi apelăm metoda din clasa de bază pentru a afișa detaliile comune
    Task::_WriteDetailsToStream(os);
    
    // Apoi adăugăm detaliile specifice acestei clase
    os << "Type: Project Task\n";
    os << "Subtasks: " << m_subtasks.size() << "\n";
    os << "Completion: " << GetCompletionPercentage() << "%\n";
}

} // namespace Task_Management
