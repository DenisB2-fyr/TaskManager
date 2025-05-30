#pragma once

#include <string>

namespace Task_Management {

/**
 * Enumerație pentru nivelurile de prioritate ale sarcinilor
 * Aceasta este o enumerație de tip class (enum class), care oferă siguranță de tip
 * și evită conflictele de nume cu alte enumerații
 */
enum class Priority {
    LOW,     // Prioritate scăzută
    MEDIUM,  // Prioritate medie
    HIGH,    // Prioritate ridicată
    URGENT   // Prioritate urgentă
};

/**
 * Enumerație pentru statusul unei sarcini
 * Folosind enum class în loc de enum simplu pentru siguranță și claritate
 */
enum class TaskStatus {
    NOT_STARTED,  // Sarcina nu a fost începută
    IN_PROGRESS,  // Sarcina este în curs de desfășurare
    COMPLETED,    // Sarcina a fost finalizată
    DEFERRED,     // Sarcina a fost amânată
    CANCELLED     // Sarcina a fost anulată
};

// Declarații anticipate (forward declarations)
// Acestea permit referirea la clase înainte de a fi definite complet
class Date;
class User;
class Category;

/**
 * Clasa abstractă de bază pentru toate sarcinile din sistem
 * 
 * Aceasta este o clasă abstractă deoarece conține funcții virtuale pure (=0)
 * și nu poate fi instanțiată direct. Servește ca interfață și implementare parțială
 * pentru toate tipurile de sarcini din sistem.
 */
class Task {
public:
    /**
     * Constructor cu parametri necesari
     * @param title Titlul sarcinii
     * @param description Descrierea sarcinii
     * @param priority Prioritatea sarcinii
     */
    Task(const std::string& title, const std::string& description, Priority priority);
    
    /**
     * Constructor de copiere
     * Permite crearea unei copii a unui obiect Task existent
     * @param other Obiectul Task de copiat
     */
    Task(const Task& other);
    
    /**
     * Destructor virtual
     * Virtual pentru a permite curățarea corectă a resurselor în clasele derivate
     * Când un obiect este șters prin pointer la clasa de bază, se apelează destructorul corect
     */
    virtual ~Task();
    
    /**
     * Obține titlul sarcinii
     * @return Titlul sarcinii ca string
     */
    std::string GetTitle() const;
    
    /**
     * Setează titlul sarcinii
     * @param title Noul titlu al sarcinii
     */
    void SetTitle(const std::string& title);
    
    /**
     * Obține descrierea sarcinii
     * @return Descrierea sarcinii ca string
     */
    std::string GetDescription() const;
    
    /**
     * Setează descrierea sarcinii
     * @param description Noua descriere a sarcinii
     */
    void SetDescription(const std::string& description);
    
    /**
     * Obține ID-ul unic al sarcinii
     * @return ID-ul sarcinii ca string
     */
    std::string GetId() const;
    
    /**
     * Obține prioritatea sarcinii
     * @return Prioritatea sarcinii (enum Priority)
     */
    Priority GetPriority() const;
    
    /**
     * Setează prioritatea sarcinii
     * @param priority Noua prioritate a sarcinii
     */
    void SetPriority(Priority priority);
    
    /**
     * Obține statusul sarcinii
     * @return Statusul sarcinii (enum TaskStatus)
     */
    TaskStatus GetStatus() const;
    
    /**
     * Setează statusul sarcinii
     * @param status Noul status al sarcinii
     */
    void SetStatus(TaskStatus status);
    
    /**
     * Atribuie un utilizator sarcinii
     * @param user Pointer către utilizatorul care va fi responsabil de sarcină
     */
    void AssignTo(User* user);
    
    /**
     * Obține utilizatorul atribuit sarcinii
     * @return Pointer către utilizatorul atribuit sau nullptr dacă nu există
     */
    User* GetAssignedUser() const;
    
    /**
     * Adaugă o categorie la sarcină
     * @param category Pointer către categoria de adăugat
     */
    void AddCategory(Category* category);
    
    /**
     * Obține toate categoriile atribuite sarcinii
     * @return Vector cu pointeri către categorii
     */
    const std::vector<Category*>& GetCategories() const;
    
    /**
     * Funcție virtuală pură pentru afișarea detaliilor sarcinii
     * Trebuie implementată de toate clasele derivate
     * Funcțiile virtuale pure (=0) definesc o interfață care trebuie implementată
     */
    virtual void DisplayDetails() const = 0;
    
    /**
     * Funcție virtuală pură pentru obținerea tipului de sarcină
     * @return Tipul sarcinii ca string
     */
    virtual std::string GetTaskType() const = 0;
    
    /**
     * Funcție virtuală pură pentru verificarea dacă sarcina este finalizată
     * @return true dacă sarcina este finalizată, false în caz contrar
     */
    virtual bool IsCompleted() const = 0;
    
    /**
     * Funcție virtuală pură pentru calcularea procentului de finalizare
     * @return Procentul de finalizare (0-100)
     */
    virtual double GetCompletionPercentage() const = 0;
    
    /**
     * Supraîncărcarea operatorului << pentru afișare ușoară
     * Permite utilizarea obiectelor Task direct cu std::cout
     * Exemplu: std::cout << task;
     */
    friend std::ostream& operator<<(std::ostream& os, const Task& task);
    
protected:
    /**
     * Metodă protejată pentru clasele derivate pentru a adăuga detalii specifice la stream
     * Protejată pentru a fi accesibilă doar în clasele derivate, nu public
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const;
    
private:
    std::string m_title;        // Titlul sarcinii
    std::string m_description;  // Descrierea sarcinii
    std::string m_id;           // ID-ul unic al sarcinii
    Priority m_priority;        // Prioritatea sarcinii
    TaskStatus m_status;        // Statusul sarcinii
    User* m_assigned_user;      // Utilizatorul atribuit sarcinii
    std::vector<Category*> m_categories;  // Categoriile atribuite sarcinii
    
    /**
     * Contor static pentru generarea ID-urilor unice
     * Static înseamnă că este partajat între toate instanțele clasei
     */
    static int s_id_counter;
    
    /**
     * Generează un ID unic pentru sarcină
     * Metodă privată, utilizată doar intern
     * @return ID-ul generat ca string
     */
    std::string _GenerateId();
};

} // namespace Task_Management
