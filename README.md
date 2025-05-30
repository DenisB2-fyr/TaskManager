# Task Management System

## Structură

```
task_management_system/
├── include/           # Fișiere header (.h)
├── src/               # Fișiere sursă (.cpp)
└── README.md
```

## Componente

### Clase
- **Task** (abstractă)
  - **Simple_Task**
  - **Project_Task**
  - **Recurring_Task**
  - **Deadline_Task**
- **User**
  - **Team_Leader**
- **INotifier** (interfață)
  - **Email_Notifier**
  - **SMS_Notifier**
- **Category**
- **Task_List**
- **Task_Manager** (Singleton)

### Structuri
- **Date**
- **Note**

## Concepte POO implementate

### Abstractizare
```cpp
class Task {
public:
    virtual void DisplayDetails() const = 0;
    virtual std::string GetTaskType() const = 0;
};
```

### Moștenire
```cpp
class Simple_Task : public Task {
    // Implementare specifică
};
```

### Încapsulare
```cpp
class User {
private:
    std::string m_name;
    std::string m_email;
public:
    std::string GetName() const;
    void SetName(const std::string& name);
};
```

### Polimorfism
```cpp
Task* task = new Project_Task("Redesign", "Website redesign", Priority::HIGH);
task->DisplayDetails();  // Apelează implementarea din Project_Task
```

## Implementări specifice

### Alocarea memoriei
```cpp
// Stack
Date deadline(2025, 6, 15);
Note note("Reminder", "John", "2025-05-30");

// Heap
Task* task = new Simple_Task("Meeting", "Team sync", Priority::MEDIUM);
User* user = new User("Alice", "alice@example.com");
```

### Supraîncărcarea operatorilor
```cpp
Task_List combined = work_list + personal_list;
std::cout << *task;
if (today < deadline) { /* ... */ }
```

### Design patterns
```cpp
Task_Manager& manager = Task_Manager::GetInstance();  // Singleton
```

## Compilare

```bash
# g++
g++ -std=c++11 -I./include src/*.cpp -o task_manager

# clang
clang++ -std=c++11 -I./include src/*.cpp -o task_manager
```

## Exemplu de utilizare

```cpp
#include <iostream>
#include "task.h"
#include "simple_task.h"
#include "user.h"
#include "task_manager.h"

int main() {
    Task_Manager& manager = Task_Manager::GetInstance();
    
    User* john = new User("John", "john@example.com");
    manager.AddUser(john);
    
    Simple_Task* task = new Simple_Task("Raport", "Finalizare raport Q2", Priority::HIGH);
    task->AssignTo(john);
    manager.AddTask(task);
    
    task->DisplayDetails();
    
    delete john;
    delete task;
    
    return 0;
}
```
