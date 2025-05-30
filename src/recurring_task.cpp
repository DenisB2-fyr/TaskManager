#include "recurring_task.h"
#include <iostream>
#include <sstream>
#include <iomanip>

namespace Task_Management {

Recurring_Task::Recurring_Task(const std::string& title, const std::string& description, 
                             Priority priority, RecurrencePattern pattern, int interval)
    : Task(title, description, priority), 
      m_pattern(pattern), 
      m_interval(interval),
      m_occurrences_completed(0) {
    // Apelăm constructorul clasei de bază și inițializăm membrii specifici acestei clase
    // Apoi calculăm data primei apariții
    _CalculateNextOccurrence();
}

Recurring_Task::Recurring_Task(const Recurring_Task& other)
    : Task(other),
      m_pattern(other.m_pattern),
      m_interval(other.m_interval),
      m_occurrences_completed(other.m_occurrences_completed),
      m_next_occurrence(other.m_next_occurrence) {
    // Constructor de copiere - copiază toate datele din obiectul other
}

Recurring_Task::~Recurring_Task() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

void Recurring_Task::DisplayDetails() const {
    // Afișează detaliile sarcinii recurente
    std::cout << "=== Recurring Task Details ===" << std::endl;
    _WriteDetailsToStream(std::cout);
    std::cout << "=============================" << std::endl;
}

std::string Recurring_Task::GetTaskType() const {
    // Returnează tipul sarcinii ca string
    return "Recurring Task";
}

bool Recurring_Task::IsCompleted() const {
    // Sarcinile recurente nu sunt niciodată complet finalizate, ele doar se repetă
    // Aceasta este o diferență conceptuală importantă față de alte tipuri de sarcini
    return false;
}

double Recurring_Task::GetCompletionPercentage() const {
    // Pentru sarcinile recurente, conceptul de procent de finalizare nu se aplică în mod tradițional
    // Am putea returna procentul până la următoarea apariție, dar pentru simplitate returnăm 0
    return 0.0;
}

Recurring_Task::RecurrencePattern Recurring_Task::GetRecurrencePattern() const {
    // Returnează modelul de recurență
    return m_pattern;
}

void Recurring_Task::SetRecurrencePattern(RecurrencePattern pattern) {
    // Setează modelul de recurență și recalculează următoarea apariție
    m_pattern = pattern;
    _CalculateNextOccurrence();
}

int Recurring_Task::GetInterval() const {
    // Returnează intervalul de recurență
    return m_interval;
}

void Recurring_Task::SetInterval(int interval) {
    // Setează intervalul de recurență dacă este valid și recalculează următoarea apariție
    if (interval > 0) {
        m_interval = interval;
        _CalculateNextOccurrence();
    }
}

std::string Recurring_Task::GetNextOccurrence() const {
    // Convertește timpul următoarei apariții într-un string formatat
    auto time_t = std::chrono::system_clock::to_time_t(m_next_occurrence);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Recurring_Task::CompleteCurrentOccurrence() {
    // Marchează apariția curentă ca finalizată și calculează următoarea apariție
    m_occurrences_completed++;
    _CalculateNextOccurrence();
}

void Recurring_Task::_WriteDetailsToStream(std::ostream& os) const {
    // Mai întâi apelăm metoda din clasa de bază pentru a afișa detaliile comune
    Task::_WriteDetailsToStream(os);
    
    // Apoi adăugăm detaliile specifice acestei clase
    os << "Type: Recurring Task\n";
    os << "Pattern: " << _PatternToString() << "\n";
    os << "Interval: " << m_interval << "\n";
    os << "Occurrences Completed: " << m_occurrences_completed << "\n";
    os << "Next Occurrence: " << GetNextOccurrence() << "\n";
}

void Recurring_Task::_CalculateNextOccurrence() {
    // Obținem timpul curent
    auto now = std::chrono::system_clock::now();
    
    // Calculăm următoarea apariție pe baza modelului și intervalului
    // Aceasta este o implementare simplificată
    switch (m_pattern) {
        case RecurrencePattern::DAILY:
            // Adăugăm interval * 24 ore
            m_next_occurrence = now + std::chrono::hours(24 * m_interval);
            break;
        case RecurrencePattern::WEEKLY:
            // Adăugăm interval * 7 zile
            m_next_occurrence = now + std::chrono::hours(24 * 7 * m_interval);
            break;
        case RecurrencePattern::MONTHLY:
            // Simplificat: adăugăm interval * 30 zile per lună
            m_next_occurrence = now + std::chrono::hours(24 * 30 * m_interval);
            break;
        case RecurrencePattern::YEARLY:
            // Simplificat: adăugăm interval * 365 zile per an
            m_next_occurrence = now + std::chrono::hours(24 * 365 * m_interval);
            break;
    }
}

std::string Recurring_Task::_PatternToString() const {
    // Convertește enumerația RecurrencePattern în string pentru afișare
    switch (m_pattern) {
        case RecurrencePattern::DAILY: return "Daily";
        case RecurrencePattern::WEEKLY: return "Weekly";
        case RecurrencePattern::MONTHLY: return "Monthly";
        case RecurrencePattern::YEARLY: return "Yearly";
        default: return "Unknown";
    }
}

} // namespace Task_Management
