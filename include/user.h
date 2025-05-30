#pragma once

#include <string>
#include <vector>

namespace Task_Management {

/**
 * Forward declarations
 * Acestea permit referirea la clase înainte de a fi definite complet
 */
class Task;

/**
 * Clasa User - pentru reprezentarea utilizatorilor sistemului
 * 
 * Această clasă demonstrează concepte de încapsulare și agregare în POO.
 * Va servi și ca clasă de bază pentru ierarhia de utilizatori, demonstrând moștenirea.
 */
class User {
public:
    /**
     * Constructor cu parametri necesari
     * @param name Numele utilizatorului
     * @param email Adresa de email a utilizatorului
     */
    User(const std::string& name, const std::string& email);
    
    /**
     * Constructor de copiere
     * @param other Obiectul User de copiat
     */
    User(const User& other);
    
    /**
     * Destructor virtual
     * Virtual pentru a permite curățarea corectă a resurselor în clasele derivate
     */
    virtual ~User();
    
    /**
     * Obține numele utilizatorului
     * @return Numele utilizatorului ca string
     */
    std::string GetName() const;
    
    /**
     * Setează numele utilizatorului
     * @param name Noul nume al utilizatorului
     */
    void SetName(const std::string& name);
    
    /**
     * Obține adresa de email a utilizatorului
     * @return Adresa de email ca string
     */
    std::string GetEmail() const;
    
    /**
     * Setează adresa de email a utilizatorului
     * @param email Noua adresă de email
     */
    void SetEmail(const std::string& email);
    
    /**
     * Obține ID-ul unic al utilizatorului
     * @return ID-ul utilizatorului ca string
     */
    std::string GetId() const;
    
    /**
     * Adaugă o sarcină atribuită acestui utilizator
     * Demonstrează conceptul de agregare - utilizatorul referențiază sarcini,
     * dar nu este responsabil de ciclul lor de viață
     * @param task Pointer către sarcina de adăugat
     */
    void AddAssignedTask(Task* task);
    
    /**
     * Elimină o sarcină din atribuirile acestui utilizator
     * @param task_id ID-ul sarcinii de eliminat
     * @return true dacă sarcina a fost găsită și eliminată, false în caz contrar
     */
    bool RemoveAssignedTask(const std::string& task_id);
    
    /**
     * Obține toate sarcinile atribuite acestui utilizator
     * @return Vector cu pointeri către toate sarcinile atribuite
     */
    const std::vector<Task*>& GetAssignedTasks() const;
    
    /**
     * Obține numărul de sarcini atribuite acestui utilizator
     * @return Numărul de sarcini atribuite
     */
    size_t GetAssignedTaskCount() const;
    
    /**
     * Afișează detaliile utilizatorului
     * Virtual pentru a permite suprascrierea în clasele derivate
     */
    virtual void DisplayDetails() const;
    
    /**
     * Obține tipul utilizatorului
     * Virtual pentru a permite suprascrierea în clasele derivate
     * @return Tipul utilizatorului ca string
     */
    virtual std::string GetUserType() const;
    
    /**
     * Supraîncărcarea operatorului << pentru afișare ușoară
     * Permite utilizarea obiectelor User direct cu std::cout
     */
    friend std::ostream& operator<<(std::ostream& os, const User& user);
    
protected:
    /**
     * Metodă protejată pentru clasele derivate pentru a adăuga detalii specifice la stream
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const;
    
private:
    std::string m_name;   // Numele utilizatorului
    std::string m_email;  // Adresa de email a utilizatorului
    std::string m_id;     // ID-ul unic al utilizatorului
    std::vector<Task*> m_assigned_tasks;  // Sarcinile atribuite acestui utilizator
    
    /**
     * Contor static pentru generarea ID-urilor unice
     * Static înseamnă că este partajat între toate instanțele clasei
     */
    static int s_id_counter;
    
    /**
     * Generează un ID unic pentru utilizator
     * @return ID-ul generat ca string
     */
    std::string _GenerateId();
};

} // namespace Task_Management
