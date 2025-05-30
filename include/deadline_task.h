#pragma once

#include "task.h"
#include "date.h"
#include <string>

namespace Task_Management {

/**
 * Clasa Deadline_Task - reprezintă o sarcină cu termen limită
 * 
 * Această clasă moștenește din clasa abstractă Task și implementează toate funcțiile virtuale pure.
 * Demonstrează conceptul de moștenire și polimorfism în POO, precum și utilizarea structurilor
 * (Date) împreună cu clasele.
 */
class Deadline_Task : public Task {
public:
    /**
     * Constructor cu parametri necesari
     * @param title Titlul sarcinii
     * @param description Descrierea sarcinii
     * @param priority Prioritatea sarcinii
     * @param deadline Data limită pentru finalizarea sarcinii
     */
    Deadline_Task(const std::string& title, const std::string& description, 
                 Priority priority, const Date& deadline);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Deadline_Task de copiat
     */
    Deadline_Task(const Deadline_Task& other);
    
    /**
     * Destructor
     */
    virtual ~Deadline_Task();
    
    /**
     * Implementarea funcției virtuale pure pentru afișarea detaliilor sarcinii
     * Suprascrie metoda din clasa de bază
     */
    virtual void DisplayDetails() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de sarcină
     * @return Tipul sarcinii ca string ("Deadline Task")
     */
    virtual std::string GetTaskType() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru verificarea dacă sarcina este finalizată
     * @return true dacă statusul sarcinii este COMPLETED, false în caz contrar
     */
    virtual bool IsCompleted() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru calcularea procentului de finalizare
     * Pentru sarcini cu termen limită, aceasta este fie 0% fie 100%
     * @return 100.0 dacă sarcina este finalizată, 0.0 în caz contrar
     */
    virtual double GetCompletionPercentage() const override;
    
    /**
     * Obține data limită
     * @return Data limită ca obiect Date
     */
    Date GetDeadline() const;
    
    /**
     * Setează data limită
     * @param deadline Noua dată limită
     */
    void SetDeadline(const Date& deadline);
    
    /**
     * Verifică dacă termenul limită a trecut
     * @return true dacă data curentă este după data limită, false în caz contrar
     */
    bool IsOverdue() const;
    
    /**
     * Calculează numărul de zile rămase până la termenul limită
     * @return Numărul de zile rămase (negativ dacă termenul a trecut)
     */
    int DaysRemaining() const;
    
protected:
    /**
     * Metodă protejată pentru a adăuga detalii specifice la stream
     * Suprascrie metoda din clasa de bază
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const override;
    
private:
    Date m_deadline;  // Data limită pentru finalizarea sarcinii
};

} // namespace Task_Management
