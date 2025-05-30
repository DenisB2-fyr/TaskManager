#pragma once

#include "task.h"
#include <string>
#include <vector>
#include "date.h"

namespace Task_Management {

/**
 * Clasa Recurring_Task - reprezintă o sarcină care se repetă la intervale regulate
 * 
 * Această clasă moștenește din clasa abstractă Task și implementează toate funcțiile virtuale pure.
 * Demonstrează conceptul de moștenire și polimorfism în POO, precum și utilizarea tipurilor de date complexe.
 */
class Recurring_Task : public Task {
public:
    /**
     * Enumerație pentru modelul de recurență
     * Demonstrează utilizarea enum class pentru tipuri enumerate sigure
     */
    enum class RecurrencePattern {
        DAILY,    // Zilnic
        WEEKLY,   // Săptămânal
        MONTHLY,  // Lunar
        YEARLY    // Anual
    };
    
    /**
     * Constructor cu parametri necesari
     * @param title Titlul sarcinii
     * @param description Descrierea sarcinii
     * @param priority Prioritatea sarcinii
     * @param pattern Modelul de recurență
     * @param interval Intervalul de recurență (ex: la fiecare 2 săptămâni)
     */
    Recurring_Task(const std::string& title, const std::string& description, 
                  Priority priority, RecurrencePattern pattern, int interval);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Recurring_Task de copiat
     */
    Recurring_Task(const Recurring_Task& other);
    
    /**
     * Destructor
     */
    virtual ~Recurring_Task();
    
    /**
     * Implementarea funcției virtuale pure pentru afișarea detaliilor sarcinii
     * Suprascrie metoda din clasa de bază
     */
    virtual void DisplayDetails() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de sarcină
     * @return Tipul sarcinii ca string ("Recurring Task")
     */
    virtual std::string GetTaskType() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru verificarea dacă sarcina este finalizată
     * Sarcinile recurente nu sunt niciodată complet finalizate, ele doar se repetă
     * @return false (sarcinile recurente nu sunt niciodată complet finalizate)
     */
    virtual bool IsCompleted() const override;
    
    /**
     * Implementarea funcției virtuale pure pentru calcularea procentului de finalizare
     * Pentru sarcinile recurente, acest concept nu se aplică în mod tradițional
     * @return 0.0 (conceptul de procent de finalizare nu se aplică)
     */
    virtual double GetCompletionPercentage() const override;
    
    /**
     * Obține modelul de recurență
     * @return Modelul de recurență (enum RecurrencePattern)
     */
    RecurrencePattern GetRecurrencePattern() const;
    
    /**
     * Setează modelul de recurență
     * @param pattern Noul model de recurență
     */
    void SetRecurrencePattern(RecurrencePattern pattern);
    
    /**
     * Obține intervalul de recurență
     * @return Intervalul de recurență (număr întreg)
     */
    int GetInterval() const;
    
    /**
     * Setează intervalul de recurență
     * @param interval Noul interval de recurență
     */
    void SetInterval(int interval);
    
    /**
     * Obține data următoarei apariții
     * @return Data următoarei apariții ca string
     */
    std::string GetNextOccurrence() const;
    
    /**
     * Finalizează apariția curentă și programează următoarea
     */
    void CompleteCurrentOccurrence();
    
protected:
    /**
     * Metodă protejată pentru a adăuga detalii specifice la stream
     * Suprascrie metoda din clasa de bază
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const override;
    
private:
    RecurrencePattern m_pattern;  // Modelul de recurență
    int m_interval;               // Intervalul de recurență
    int m_occurrences_completed;  // Numărul de apariții finalizate
    std::chrono::system_clock::time_point m_next_occurrence;  // Data și ora următoarei apariții
    
    /**
     * Calculează următoarea apariție pe baza modelului și intervalului
     * Metodă privată, utilizată doar intern
     */
    void _CalculateNextOccurrence();
    
    /**
     * Convertește modelul de recurență în string
     * Metodă privată, utilizată doar intern
     * @return Reprezentarea string a modelului de recurență
     */
    std::string _PatternToString() const;
};

} // namespace Task_Management
