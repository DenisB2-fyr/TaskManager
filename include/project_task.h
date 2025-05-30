#pragma once

#include "task.h"
#include <string>
#include <vector>

namespace Task_Management {

/**
 * Clasa Project_Task - reprezintă o sarcină complexă cu mai multe sub-sarcini
 * 
 * Această clasă moștenește din clasa abstractă Task și implementează toate funcțiile virtuale pure.
 * Demonstrează conceptul de moștenire, polimorfism și compoziție în POO.
 * Compoziția este demonstrată prin faptul că un Project_Task conține alte obiecte Task.
 */
class Project_Task : public Task {
public:
    /**
     * Constructor cu parametri necesari
     * @param title Titlul proiectului
     * @param description Descrierea proiectului
     * @param priority Prioritatea proiectului
     */
    Project_Task(const std::string& title, const std::string& description, Priority priority);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Project_Task de copiat
     */
    Project_Task(const Project_Task& other);
    
    /**
     * Destructor
     */
    virtual ~Project_Task();
    
    /**
     * Implementarea funcției virtuale pure pentru afișarea detaliilor proiectului
     * Suprascrie metoda din clasa de bază
     */
    virtual void DisplayDetails() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de sarcină
     * @return Tipul sarcinii ca string ("Project Task")
     */
    virtual std::string GetTaskType() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru verificarea dacă proiectul este finalizat
     * Un proiect este finalizat doar dacă toate sub-sarcinile sale sunt finalizate
     * @return true dacă toate sub-sarcinile sunt finalizate, false în caz contrar
     */
    virtual bool IsCompleted() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru calcularea procentului de finalizare
     * Pentru proiecte, aceasta se bazează pe finalizarea sub-sarcinilor
     * @return Procentul mediu de finalizare al tuturor sub-sarcinilor
     */
    virtual double GetCompletionPercentage() const override;
    
    /**
     * Adaugă o sub-sarcină la acest proiect
     * Demonstrează conceptul de compoziție - un obiect conține alte obiecte
     * @param subtask Pointer către sub-sarcina de adăugat
     */
    void AddSubtask(Task* subtask);
    
    /**
     * Elimină o sub-sarcină din acest proiect
     * @param subtask_id ID-ul sub-sarcinii de eliminat
     * @return true dacă sub-sarcina a fost găsită și eliminată, false în caz contrar
     */
    bool RemoveSubtask(const std::string& subtask_id);
    
    /**
     * Obține toate sub-sarcinile
     * @return Vector cu pointeri către toate sub-sarcinile
     */
    const std::vector<Task*>& GetSubtasks() const;
    
    /**
     * Obține numărul de sub-sarcini
     * @return Numărul de sub-sarcini
     */
    size_t GetSubtaskCount() const;
    
    /**
     * Supraîncărcarea operatorului + pentru combinarea a două proiecte
     * Demonstrează conceptul de supraîncărcare a operatorilor în C++
     * @param other Proiectul de combinat cu acesta
     * @return Un nou proiect care combină ambele proiecte
     */
    Project_Task operator+(const Project_Task& other) const;
    
protected:
    /**
     * Metodă protejată pentru a adăuga detalii specifice la stream
     * Suprascrie metoda din clasa de bază
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const override;
    
private:
    std::vector<Task*> m_subtasks;  // Lista de sub-sarcini ale proiectului
};

} // namespace Task_Management
