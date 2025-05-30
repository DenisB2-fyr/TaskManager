#pragma once

#include "task.h"
#include <string>

namespace Task_Management {

/**
 * Clasa Simple_Task - reprezintă o sarcină simplă cu un singur status de finalizare
 * 
 * Această clasă moștenește din clasa abstractă Task și implementează toate funcțiile virtuale pure.
 * Demonstrează conceptul de moștenire și polimorfism în POO.
 */
class Simple_Task : public Task {
public:
    /**
     * Constructor cu parametri necesari
     * @param title Titlul sarcinii
     * @param description Descrierea sarcinii
     * @param priority Prioritatea sarcinii
     */
    Simple_Task(const std::string& title, const std::string& description, Priority priority);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Simple_Task de copiat
     */
    Simple_Task(const Simple_Task& other);
    
    /**
     * Destructor
     * Virtual pentru a permite curățarea corectă a resurselor în potențiale clase derivate
     */
    virtual ~Simple_Task();
    
    /**
     * Implementarea funcției virtuale pure pentru afișarea detaliilor sarcinii
     * Suprascrie (override) metoda din clasa de bază
     * Keyword-ul override ajută compilatorul să verifice că suprascrierea este corectă
     */
    virtual void DisplayDetails() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de sarcină
     * @return Tipul sarcinii ca string ("Simple Task")
     */
    virtual std::string GetTaskType() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru verificarea dacă sarcina este finalizată
     * @return true dacă statusul sarcinii este COMPLETED, false în caz contrar
     */
    virtual bool IsCompleted() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru calcularea procentului de finalizare
     * Pentru sarcini simple, aceasta este fie 0% fie 100%
     * @return 100.0 dacă sarcina este finalizată, 0.0 în caz contrar
     */
    virtual double GetCompletionPercentage() const override;
    
    /**
     * Marchează sarcina ca finalizată
     * Setează statusul sarcinii la COMPLETED
     */
    void MarkAsCompleted();
    
protected:
    /**
     * Metodă protejată pentru a adăuga detalii specifice la stream
     * Suprascrie metoda din clasa de bază
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const override;
};

} // namespace Task_Management
