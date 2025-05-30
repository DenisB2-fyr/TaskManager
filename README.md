Task Management System

Prezentare generală

După câteva luni de dezvoltare, am finalizat acest sistem de management al sarcinilor care demonstrează implementarea principiilor POO în C++11. Proiectul a pornit din nevoia de a crea o soluție flexibilă pentru organizarea și urmărirea sarcinilor în echipe de dezvoltare software, dar poate fi adaptat și pentru alte domenii.

Am pus accent pe design-ul arhitectural și pe implementarea elegantă a conceptelor OOP, mai degrabă decât pe interfața utilizator (care ar putea fi dezvoltată ulterior). Codul este structurat pentru extensibilitate și mentenabilitate pe termen lung.

Structură și organizare

Proiectul folosește o structură standard cu directoarele include/ pentru headere și src/ pentru implementări:

Plain Text


task_management_system/
├── include/           # Fișiere header (.h)
├── src/               # Fișiere sursă (.cpp)
└── README.md          # Acest fișier


Componentele principale

Am organizat codul în câteva module logice:

Ierarhia de sarcini

Am implementat o ierarhie flexibilă de sarcini, pornind de la o clasă abstractă de bază:

•
Task - clasa abstractă cu interfața comună

•
Simple_Task - pentru sarcini de bază, fără complexitate

•
Project_Task - pentru sarcini complexe care conțin sub-sarcini

•
Recurring_Task - pentru sarcini care se repetă periodic

•
Deadline_Task - pentru sarcini cu termen limită

Utilizatori și roluri

•
User - utilizator standard

•
Team_Leader - extinde User cu capacități de management al echipei

Notificări

Am folosit o interfață pentru a permite multiple implementări de notificări:

•
INotifier - interfața pentru sistemul de notificări

•
Email_Notifier și SMS_Notifier - implementări concrete

Organizare și utilități

•
Category - pentru clasificarea sarcinilor

•
Task_List - colecții de sarcini

•
Task_Manager - singleton pentru gestionarea centralizată

•
Date - structură pentru manipularea datelor calendaristice

•
Note - structură pentru note și comentarii atașate sarcinilor

Concepte POO implementate

Abstractizare

Am folosit abstractizarea pentru a separa interfața de implementare. De exemplu, Task definește comportamentul general al unei sarcini fără a specifica detalii de implementare:

Plain Text


class Task {
public:
    virtual void DisplayDetails() const = 0;
    virtual std::string GetTaskType() const = 0;
    // ...
};


Moștenire

Ierarhia de sarcini demonstrează moștenirea, permițând specializarea comportamentului:

Plain Text


class Simple_Task : public Task {
    // Implementare specifică
};

class Project_Task : public Task {
    // Implementare specifică cu funcționalități adiționale
};


Încapsulare

Am folosit încapsularea pentru a proteja datele interne și a oferi o interfață controlată:

Plain Text


class User {
private:
    std::string m_name;
    std::string m_email;
    
public:
    std::string GetName() const;
    void SetName(const std::string& name);
    // ...
};


Polimorfism

Polimorfismul permite tratarea uniformă a diferitelor tipuri de sarcini:

Plain Text


// În cod:
Task* task = new Project_Task("Redesign", "Website redesign", Priority::HIGH);
task->DisplayDetails();  // Apelează implementarea din Project_Task


Particularități de implementare

Alocarea memoriei

Am demonstrat explicit alocarea pe stack și heap:

Plain Text


// Alocare pe stack
Date deadline(2025, 6, 15);
Note note("Reminder", "John", "2025-05-30");

// Alocare pe heap
Task* task = new Simple_Task("Meeting", "Team sync", Priority::MEDIUM);
User* user = new User("Alice", "alice@example.com");


Supraîncărcarea operatorilor

Am implementat supraîncărcarea operatorilor pentru operații intuitive:

Plain Text


// Combinarea listelor de sarcini
Task_List combined = work_list + personal_list;

// Afișarea sarcinilor
std::cout << *task;

// Compararea datelor
if (today < deadline) {
    // ...
}


Design patterns

Am folosit Singleton pentru Task_Manager pentru a asigura o singură instanță centralizată:

Plain Text


Task_Manager& manager = Task_Manager::GetInstance();


Compilare și utilizare

Compilare

Proiectul poate fi compilat cu orice compilator modern care suportă C++11:

Bash


# Cu g++
g++ -std=c++11 -I./include src/*.cpp -o task_manager

# Cu clang
clang++ -std=c++11 -I./include src/*.cpp -o task_manager


Exemplu de utilizare

Plain Text


#include <iostream>
#include "task.h"
#include "simple_task.h"
#include "user.h"
#include "task_manager.h"

int main() {
    // Obține instanța manager-ului
    Task_Manager& manager = Task_Manager::GetInstance();
    
    // Creează utilizatori
    User* john = new User("John", "john@example.com");
    manager.AddUser(john);
    
    // Creează sarcini
    Simple_Task* task = new Simple_Task("Raport", "Finalizare raport Q2", Priority::HIGH);
    task->AssignTo(john);
    manager.AddTask(task);
    
    // Afișează detalii
    task->DisplayDetails();
    
    // Eliberează memoria
    delete john;
    delete task;
    
    return 0;
}


Extensii posibile

Proiectul poate fi extins în mai multe direcții:

•
Interfață grafică (Qt/wxWidgets)

•
Persistența datelor (SQLite/fișiere)

•
Sincronizare în rețea

•
Integrare cu servicii externe (Jira, Trello)

Concluzie

Acest proiect demonstrează implementarea principiilor POO într-un sistem practic de management al sarcinilor. Arhitectura modulară și extensibilă permite adaptarea și extinderea ușoară pentru diferite scenarii de utilizare.

