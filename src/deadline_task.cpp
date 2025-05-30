#include "deadline_task.h"
#include <iostream>

namespace Task_Management {

Deadline_Task::Deadline_Task(const std::string& title, const std::string& description, 
                           Priority priority, const Date& deadline)
    : Task(title, description, priority), m_deadline(deadline) {
    // Apelăm constructorul clasei de bază și inițializăm membrul specific acestei clase (m_deadline)
    // Aceasta demonstrează moștenirea și reutilizarea codului
}

Deadline_Task::Deadline_Task(const Deadline_Task& other)
    : Task(other), m_deadline(other.m_deadline) {
    // Apelăm constructorul de copiere al clasei de bază
    // și copiem membrul specific acestei clase (m_deadline)
}

Deadline_Task::~Deadline_Task() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

void Deadline_Task::DisplayDetails() const {
    // Afișează detaliile sarcinii cu termen limită
    std::cout << "=== Deadline Task Details ===" << std::endl;
    _WriteDetailsToStream(std::cout);
    std::cout << "============================" << std::endl;
}

std::string Deadline_Task::GetTaskType() const {
    // Returnează tipul sarcinii ca string
    return "Deadline Task";
}

bool Deadline_Task::IsCompleted() const {
    // Verifică dacă sarcina este finalizată
    // O sarcină cu termen limită este finalizată dacă statusul său este COMPLETED
    return GetStatus() == TaskStatus::COMPLETED;
}

double Deadline_Task::GetCompletionPercentage() const {
    // Calculează procentul de finalizare
    // Pentru sarcini cu termen limită, este fie 0% fie 100%
    return IsCompleted() ? 100.0 : 0.0;
}

Date Deadline_Task::GetDeadline() const {
    // Returnează data limită
    return m_deadline;
}

void Deadline_Task::SetDeadline(const Date& deadline) {
    // Setează data limită
    m_deadline = deadline;
}

bool Deadline_Task::IsOverdue() const {
    // Verifică dacă termenul limită a trecut
    // Comparăm data curentă cu data limită
    Date current_date = Date::GetCurrentDate();
    return current_date > m_deadline;
}

int Deadline_Task::DaysRemaining() const {
    // Calculează numărul de zile rămase până la termenul limită
    // Folosim metoda statică DaysBetween din structura Date
    Date current_date = Date::GetCurrentDate();
    return Date::DaysBetween(current_date, m_deadline);
}

void Deadline_Task::_WriteDetailsToStream(std::ostream& os) const {
    // Mai întâi apelăm metoda din clasa de bază pentru a afișa detaliile comune
    Task::_WriteDetailsToStream(os);
    
    // Apoi adăugăm detaliile specifice acestei clase
    os << "Type: Deadline Task\n";
    os << "Deadline: " << m_deadline.ToString() << "\n";
    
    // Verificăm dacă termenul limită a trecut
    if (IsOverdue()) {
        os << "Status: OVERDUE by " << -DaysRemaining() << " days\n";
    } else {
        os << "Days Remaining: " << DaysRemaining() << "\n";
    }
    
    os << "Completion: " << (IsCompleted() ? "Completed" : "Not Completed") << "\n";
}

} // namespace Task_Management
