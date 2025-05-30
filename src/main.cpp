#include <iostream>
#include "task_management_system/task.h"
#include "task_management_system/simple_task.h"
#include "task_management_system/project_task.h"
#include "task_management_system/recurring_task.h"
#include "task_management_system/deadline_task.h"
#include "task_management_system/user.h"
#include "task_management_system/team_leader.h"
#include "task_management_system/category.h"
#include "task_management_system/task_list.h"
#include "task_management_system/task_manager.h"
#include "task_management_system/inotifier.h"
#include "task_management_system/email_notifier.h"
#include "task_management_system/sms_notifier.h"
#include "task_management_system/date.h"
#include "task_management_system/note.h"
#include "task_management_system/task_notes.h"

using namespace Task_Management;

/**
 * Main function demonstrating the Task Management System
 * Including explicit examples of stack and heap allocation
 * and operator overloading usage
 */
int main() {
    std::cout << "Task Management System Demo" << std::endl;
    std::cout << "==========================" << std::endl << std::endl;
    
    // EXEMPLU EXPLICIT: Alocare pe STACK
    std::cout << "DEMONSTRAȚIE ALOCARE PE STACK:" << std::endl;
    std::cout << "-----------------------------" << std::endl;
    
    // Crearea unui obiect Date pe stack
    Date deadline_date(2025, 6, 15);
    std::cout << "Obiect Date creat pe stack: " << deadline_date.ToString() << std::endl;
    
    // Crearea unui obiect Note pe stack (struct)
    Note stack_note("Aceasta este o notă creată pe stack", "Admin", "2025-05-30", true);
    std::cout << "Obiect Note (struct) creat pe stack: " << stack_note.ToString() << std::endl;
    
    // Crearea unui obiect Task_Notes pe stack
    Task_Notes stack_notes;
    stack_notes.AddNote(stack_note);
    stack_notes.AddNote("O altă notă pe stack", "System", "2025-05-30");
    std::cout << "Obiect Task_Notes creat pe stack cu " << stack_notes.GetNotes().size() << " note" << std::endl;
    
    std::cout << std::endl;
    
    // EXEMPLU EXPLICIT: Alocare pe HEAP
    std::cout << "DEMONSTRAȚIE ALOCARE PE HEAP:" << std::endl;
    std::cout << "----------------------------" << std::endl;
    
    // Create task manager instance (Singleton)
    Task_Manager& manager = Task_Manager::GetInstance();
    
    // Crearea utilizatorilor pe heap
    User* john = new User("John Smith", "john@example.com");
    User* alice = new User("Alice Johnson", "alice@example.com");
    Team_Leader* mike = new Team_Leader("Mike Brown", "mike@example.com", "Development");
    
    std::cout << "Utilizatori creați pe heap: " << john->GetName() << ", " 
              << alice->GetName() << ", " << mike->GetName() << std::endl;
    
    // Add users to manager
    manager.AddUser(john);
    manager.AddUser(alice);
    manager.AddUser(mike);
    
    // Add team members to leader
    mike->AddTeamMember(john);
    mike->AddTeamMember(alice);
    
    // Create categories on heap
    Category* work = new Category("Work", "Work-related tasks");
    Category* personal = new Category("Personal", "Personal tasks");
    Category* urgent = new Category("Urgent", "Tasks that need immediate attention");
    
    std::cout << "Categorii create pe heap: " << work->GetName() << ", " 
              << personal->GetName() << ", " << urgent->GetName() << std::endl;
    
    // Create simple tasks on heap
    Simple_Task* task1 = new Simple_Task("Buy groceries", "Milk, eggs, bread", Priority::MEDIUM);
    Simple_Task* task2 = new Simple_Task("Call dentist", "Schedule appointment", Priority::LOW);
    
    // Create project task with subtasks on heap
    Project_Task* project = new Project_Task("Website Redesign", "Redesign company website", Priority::HIGH);
    Simple_Task* subtask1 = new Simple_Task("Design mockups", "Create UI mockups", Priority::MEDIUM);
    Simple_Task* subtask2 = new Simple_Task("Implement frontend", "HTML/CSS implementation", Priority::MEDIUM);
    Simple_Task* subtask3 = new Simple_Task("Backend integration", "Connect to API", Priority::HIGH);
    
    std::cout << "Sarcini create pe heap: " << task1->GetTitle() << ", " 
              << task2->GetTitle() << ", " << project->GetTitle() << std::endl;
    
    project->AddSubtask(subtask1);
    project->AddSubtask(subtask2);
    project->AddSubtask(subtask3);
    
    // Create recurring task on heap
    Recurring_Task* recurring = new Recurring_Task("Team meeting", "Weekly team sync", 
                                                 Priority::MEDIUM, 
                                                 Recurring_Task::RecurrencePattern::WEEKLY, 1);
    
    // Create deadline task on heap using the stack-allocated Date
    Deadline_Task* deadline_task = new Deadline_Task("Submit report", "End of quarter report", 
                                                   Priority::URGENT, deadline_date);
    
    // Assign tasks to users
    task1->AssignTo(alice);
    task2->AssignTo(john);
    project->AssignTo(mike);
    recurring->AssignTo(mike);
    deadline_task->AssignTo(john);
    
    // Add categories to tasks
    task1->AddCategory(personal);
    task2->AddCategory(personal);
    project->AddCategory(work);
    recurring->AddCategory(work);
    deadline_task->AddCategory(work);
    deadline_task->AddCategory(urgent);
    
    // Add tasks to manager
    manager.AddTask(task1);
    manager.AddTask(task2);
    manager.AddTask(project);
    manager.AddTask(recurring);
    manager.AddTask(deadline_task);
    
    // Create task lists
    Task_List personal_list("Personal Tasks");
    personal_list.AddTask(task1);
    personal_list.AddTask(task2);
    
    Task_List work_list("Work Tasks");
    work_list.AddTask(project);
    work_list.AddTask(recurring);
    work_list.AddTask(deadline_task);
    
    // Create notifiers on heap
    Email_Notifier* email_notifier = new Email_Notifier("notifications@taskmanager.com");
    SMS_Notifier* sms_notifier = new SMS_Notifier("+1234567890");
    
    std::cout << "Notificatori creați pe heap: Email și SMS" << std::endl;
    
    // Set notifiers for task lists
    personal_list.SetNotifier(email_notifier);
    work_list.SetNotifier(sms_notifier);
    
    // Create notes for tasks (demonstrating struct usage)
    Note* heap_note1 = new Note("Prioritate ridicată", "Manager", "2025-05-30", true);
    Note* heap_note2 = new Note("Verifică detaliile înainte de finalizare", "QA", "2025-05-30");
    
    std::cout << "Note (struct) create pe heap: " << heap_note1->ToString() << std::endl;
    
    // Create task notes manager on heap
    Task_Notes* task1_notes = new Task_Notes(task1);
    task1_notes->AddNote(*heap_note1);
    task1_notes->AddNote(*heap_note2);
    
    std::cout << "Task_Notes creat pe heap cu " << task1_notes->GetNotes().size() << " note" << std::endl;
    
    std::cout << std::endl;
    
    // DEMONSTRAȚIE UTILIZARE OPERATORI SUPRAÎNCĂRCAȚI
    std::cout << "DEMONSTRAȚIE UTILIZARE OPERATORI SUPRAÎNCĂRCAȚI:" << std::endl;
    std::cout << "---------------------------------------------" << std::endl;
    
    // Utilizare operator << pentru afișarea sarcinilor
    std::cout << "Utilizare operator << pentru Task:" << std::endl;
    std::cout << *task1 << std::endl;
    
    // Utilizare operator + pentru combinarea listelor de sarcini
    std::cout << "Utilizare operator + pentru Task_List:" << std::endl;
    Task_List combined_list = personal_list + work_list;
    std::cout << "Lista combinată conține " << combined_list.GetTaskCount() << " sarcini" << std::endl;
    
    // Utilizare operator + pentru Project_Task
    std::cout << "Utilizare operator + pentru Project_Task:" << std::endl;
    Project_Task* another_project = new Project_Task("Mobile App", "Develop mobile app", Priority::HIGH);
    Project_Task combined_project = *project + *another_project;
    std::cout << "Proiect combinat: " << combined_project.GetTitle() << " cu " 
              << combined_project.GetSubtaskCount() << " sub-sarcini" << std::endl;
    
    // Utilizare operatori de comparație pentru Date
    std::cout << "Utilizare operatori de comparație pentru Date:" << std::endl;
    Date today = Date::GetCurrentDate();
    Date future_date(2026, 1, 1);
    
    std::cout << "Astăzi: " << today.ToString() << std::endl;
    std::cout << "Data viitoare: " << future_date.ToString() << std::endl;
    std::cout << "today < future_date: " << (today < future_date ? "true" : "false") << std::endl;
    std::cout << "today == future_date: " << (today == future_date ? "true" : "false") << std::endl;
    
    // Mark some tasks as completed
    task1->SetStatus(TaskStatus::COMPLETED);
    subtask1->SetStatus(TaskStatus::COMPLETED);
    
    // Display task details
    std::cout << std::endl;
    std::cout << "Task Details:" << std::endl;
    std::cout << "--------------" << std::endl;
    task1->DisplayDetails();
    std::cout << std::endl;
    
    project->DisplayDetails();
    std::cout << std::endl;
    
    // Display task notes
    std::cout << "Task Notes:" << std::endl;
    std::cout << "--------------" << std::endl;
    task1_notes->DisplayNotes();
    std::cout << std::endl;
    
    // Display task lists
    std::cout << "Task Lists:" << std::endl;
    std::cout << "--------------" << std::endl;
    personal_list.DisplayDetails();
    std::cout << std::endl;
    
    work_list.DisplayDetails();
    std::cout << std::endl;
    
    // Display combined list
    std::cout << "Combined Task List:" << std::endl;
    std::cout << "--------------" << std::endl;
    combined_list.DisplayDetails();
    std::cout << std::endl;
    
    // Clean up (in a real application, we would use smart pointers)
    delete john;
    delete alice;
    delete mike;
    delete work;
    delete personal;
    delete urgent;
    delete task1;
    delete task2;
    delete project;
    delete subtask1;
    delete subtask2;
    delete subtask3;
    delete recurring;
    delete deadline_task;
    delete email_notifier;
    delete sms_notifier;
    delete heap_note1;
    delete heap_note2;
    delete task1_notes;
    delete another_project;
    
    std::cout << "Toate resursele alocate pe heap au fost eliberate." << std::endl;
    
    return 0;
}
