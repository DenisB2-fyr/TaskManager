#pragma once

#include <string>
#include <vector>

namespace Task_Management {

/**
 * Forward declarations
 * Acestea permit referirea la clase înainte de a fi definite complet
 */
class Task;
class INotifier;

/**
 * Clasa Task_List - pentru gestionarea colecțiilor de sarcini
 * 
 * Această clasă demonstrează concepte de agregare și compoziție în POO,
 * precum și utilizarea interfețelor și supraîncărcarea operatorilor.
 */
class Task_List {
public:
    /**
     * Constructor cu numele listei
     * @param name Numele listei de sarcini
     */
    Task_List(const std::string& name);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Task_List de copiat
     */
    Task_List(const Task_List& other);
    
    /**
     * Destructor
     */
    ~Task_List();
    
    /**
     * Obține numele listei de sarcini
     * @return Numele listei ca string
     */
    std::string GetName() const;
    
    /**
     * Setează numele listei de sarcini
     * @param name Noul nume al listei
     */
    void SetName(const std::string& name);
    
    /**
     * Obține ID-ul unic al listei de sarcini
     * @return ID-ul listei ca string
     */
    std::string GetId() const;
    
    /**
     * Adaugă o sarcină la listă
     * @param task Pointer către sarcina de adăugat
     */
    void AddTask(Task* task);
    
    /**
     * Elimină o sarcină din listă
     * @param task_id ID-ul sarcinii de eliminat
     * @return true dacă sarcina a fost găsită și eliminată, false în caz contrar
     */
    bool RemoveTask(const std::string& task_id);
    
    /**
     * Obține toate sarcinile din listă
     * @return Vector cu pointeri către toate sarcinile
     */
    const std::vector<Task*>& GetTasks() const;
    
    /**
     * Obține numărul de sarcini din listă
     * @return Numărul de sarcini
     */
    size_t GetTaskCount() const;
    
    /**
     * Obține numărul de sarcini finalizate
     * @return Numărul de sarcini finalizate
     */
    size_t GetCompletedTaskCount() const;
    
    /**
     * Calculează procentul de finalizare al listei
     * @return Procentul de finalizare (0-100)
     */
    double GetCompletionPercentage() const;
    
    /**
     * Afișează detaliile listei de sarcini
     */
    void DisplayDetails() const;
    
    /**
     * Setează notificatorul pentru această listă de sarcini
     * Demonstrează utilizarea interfețelor și injecția de dependențe
     * @param notifier Pointer către un obiect care implementează interfața INotifier
     */
    void SetNotifier(INotifier* notifier);
    
    /**
     * Trimite o notificare despre lista de sarcini
     * @param recipient Destinatarul notificării
     * @param subject Subiectul notificării
     * @return true dacă notificarea a fost trimisă cu succes, false în caz contrar
     */
    bool SendNotification(const std::string& recipient, const std::string& subject) const;
    
    /**
     * Supraîncărcarea operatorului + pentru combinarea a două liste de sarcini
     * Demonstrează conceptul de supraîncărcare a operatorilor în C++
     * @param other Lista de sarcini de combinat cu aceasta
     * @return O nouă listă de sarcini care combină ambele liste
     */
    Task_List operator+(const Task_List& other) const;
    
    /**
     * Supraîncărcarea operatorului << pentru afișare ușoară
     * Permite utilizarea obiectelor Task_List direct cu std::cout
     */
    friend std::ostream& operator<<(std::ostream& os, const Task_List& task_list);
    
private:
    std::string m_name;           // Numele listei de sarcini
    std::string m_id;             // ID-ul unic al listei
    std::vector<Task*> m_tasks;   // Sarcinile din listă
    INotifier* m_notifier;        // Notificatorul pentru această listă
    
    /**
     * Contor static pentru generarea ID-urilor unice
     * Static înseamnă că este partajat între toate instanțele clasei
     */
    static int s_id_counter;
    
    /**
     * Generează un ID unic pentru lista de sarcini
     * @return ID-ul generat ca string
     */
    std::string _GenerateId();
};

} // namespace Task_Management
