#pragma once

#include <string>
#include <vector>

namespace Task_Management {

/**
 * Forward declarations
 * Acestea permit referirea la clase înainte de a fi definite complet
 * Reduce dependențele între fișiere header și timpul de compilare
 */
class Task;

/**
 * Clasa Category - pentru organizarea sarcinilor în categorii
 * 
 * Această clasă demonstrează concepte de încapsulare și agregare în POO.
 * Agregarea este demonstrată prin faptul că o categorie conține referințe la obiecte Task,
 * dar nu este responsabilă de ciclul lor de viață.
 */
class Category {
public:
    /**
     * Constructor cu parametri necesari
     * @param name Numele categoriei
     * @param description Descrierea categoriei
     */
    Category(const std::string& name, const std::string& description);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Category de copiat
     */
    Category(const Category& other);
    
    /**
     * Destructor
     */
    ~Category();
    
    /**
     * Obține numele categoriei
     * @return Numele categoriei ca string
     */
    std::string GetName() const;
    
    /**
     * Setează numele categoriei
     * @param name Noul nume al categoriei
     */
    void SetName(const std::string& name);
    
    /**
     * Obține descrierea categoriei
     * @return Descrierea categoriei ca string
     */
    std::string GetDescription() const;
    
    /**
     * Setează descrierea categoriei
     * @param description Noua descriere a categoriei
     */
    void SetDescription(const std::string& description);
    
    /**
     * Obține ID-ul unic al categoriei
     * @return ID-ul categoriei ca string
     */
    std::string GetId() const;
    
    /**
     * Adaugă o sarcină la această categorie
     * Demonstrează conceptul de agregare - categoria referențiază sarcini,
     * dar nu este responsabilă de ciclul lor de viață
     * @param task Pointer către sarcina de adăugat
     */
    void AddTask(Task* task);
    
    /**
     * Elimină o sarcină din această categorie
     * @param task_id ID-ul sarcinii de eliminat
     * @return true dacă sarcina a fost găsită și eliminată, false în caz contrar
     */
    bool RemoveTask(const std::string& task_id);
    
    /**
     * Obține toate sarcinile din această categorie
     * @return Vector cu pointeri către toate sarcinile
     */
    const std::vector<Task*>& GetTasks() const;
    
    /**
     * Obține numărul de sarcini din această categorie
     * @return Numărul de sarcini
     */
    size_t GetTaskCount() const;
    
    /**
     * Afișează detaliile categoriei
     */
    void DisplayDetails() const;
    
    /**
     * Supraîncărcarea operatorului << pentru afișare ușoară
     * Demonstrează conceptul de supraîncărcare a operatorilor în C++
     * Permite utilizarea obiectelor Category direct cu std::cout
     */
    friend std::ostream& operator<<(std::ostream& os, const Category& category);
    
private:
    std::string m_name;         // Numele categoriei
    std::string m_description;  // Descrierea categoriei
    std::string m_id;           // ID-ul unic al categoriei
    std::vector<Task*> m_tasks; // Sarcinile din această categorie
    
    /**
     * Contor static pentru generarea ID-urilor unice
     * Static înseamnă că este partajat între toate instanțele clasei
     */
    static int s_id_counter;
    
    /**
     * Generează un ID unic pentru categorie
     * @return ID-ul generat ca string
     */
    std::string _GenerateId();
};

} // namespace Task_Management
