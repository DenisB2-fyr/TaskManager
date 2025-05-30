#include "simple_task.h"
#include <iostream>

namespace Task_Management {

Simple_Task::Simple_Task(const std::string& title, const std::string& description, Priority priority)
    : Task(title, description, priority) {
    // Apelăm constructorul clasei de bază (Task) cu parametrii primiți
    // Aceasta este o formă de reutilizare a codului prin moștenire
}

Simple_Task::Simple_Task(const Simple_Task& other)
    : Task(other) {
    // Apelăm constructorul de copiere al clasei de bază
    // Nu avem membri suplimentari în această clasă, deci nu mai este nevoie de cod suplimentar
}

Simple_Task::~Simple_Task() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

void Simple_Task::DisplayDetails() const {
    // Afișează detaliile sarcinii simple
    std::cout << "=== Simple Task Details ===" << std::endl;
    _WriteDetailsToStream(std::cout);  // Apelăm metoda protejată pentru afișarea detaliilor
    std::cout << "==========================" << std::endl;
}

std::string Simple_Task::GetTaskType() const {
    // Returnează tipul sarcinii ca string
    return "Simple Task";
}

bool Simple_Task::IsCompleted() const {
    // Verifică dacă sarcina este finalizată
    // O sarcină simplă este finalizată dacă statusul său este COMPLETED
    return GetStatus() == TaskStatus::COMPLETED;
}

double Simple_Task::GetCompletionPercentage() const {
    // Calculează procentul de finalizare
    // Pentru sarcini simple, este fie 0% fie 100%
    return IsCompleted() ? 100.0 : 0.0;
}

void Simple_Task::MarkAsCompleted() {
    // Marchează sarcina ca finalizată
    SetStatus(TaskStatus::COMPLETED);
}

void Simple_Task::_WriteDetailsToStream(std::ostream& os) const {
    // Mai întâi apelăm metoda din clasa de bază pentru a afișa detaliile comune
    Task::_WriteDetailsToStream(os);
    
    // Apoi adăugăm detaliile specifice acestei clase
    os << "Type: Simple Task\n";
    os << "Completion: " << (IsCompleted() ? "Completed" : "Not Completed") << "\n";
}

} // namespace Task_Management
