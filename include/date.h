#pragma once

#include <string>

namespace Task_Management {

/**
 * Structura Date - utilitar pentru manipularea datelor calendaristice în sistem
 * 
 * Această structură demonstrează utilizarea structurilor (struct) alături de clase în POO.
 * În C++, structurile sunt similare cu clasele, dar membrii sunt publici în mod implicit.
 * Structurile sunt folosite de obicei pentru date simple, fără comportament complex.
 */
struct Date {
    int year;   // Anul
    int month;  // Luna (1-12)
    int day;    // Ziua (1-31)
    
    /**
     * Constructor implicit
     * Inițializează toate câmpurile cu 0
     */
    Date();
    
    /**
     * Constructor cu parametri
     * @param year Anul
     * @param month Luna
     * @param day Ziua
     */
    Date(int year, int month, int day);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Date de copiat
     */
    Date(const Date& other);
    
    /**
     * Convertește data în string formatat
     * @return Data formatată ca string (ex: "2025-05-15")
     */
    std::string ToString() const;
    
    /**
     * Verifică dacă data este validă
     * @return true dacă data este validă, false în caz contrar
     */
    bool IsValid() const;
    
    /**
     * Metodă statică pentru obținerea datei curente
     * Demonstrează conceptul de metode statice în C++
     * @return Obiect Date reprezentând data curentă
     */
    static Date GetCurrentDate();
    
    /**
     * Metodă statică pentru calcularea zilelor între două date
     * @param date1 Prima dată
     * @param date2 A doua dată
     * @return Numărul de zile între cele două date
     */
    static int DaysBetween(const Date& date1, const Date& date2);
    
    /**
     * Adaugă un număr de zile la dată
     * @param days Numărul de zile de adăugat
     * @return Noua dată rezultată
     */
    Date AddDays(int days) const;
    
    /**
     * Supraîncărcarea operatorului == pentru compararea a două date
     * Demonstrează conceptul de supraîncărcare a operatorilor în C++
     * @param other Data de comparat cu aceasta
     * @return true dacă datele sunt egale, false în caz contrar
     */
    bool operator==(const Date& other) const;
    
    /**
     * Supraîncărcarea operatorului != pentru compararea a două date
     * @param other Data de comparat cu aceasta
     * @return true dacă datele sunt diferite, false în caz contrar
     */
    bool operator!=(const Date& other) const;
    
    /**
     * Supraîncărcarea operatorului < pentru compararea a două date
     * @param other Data de comparat cu aceasta
     * @return true dacă această dată este mai mică decât other, false în caz contrar
     */
    bool operator<(const Date& other) const;
    
    /**
     * Supraîncărcarea operatorului <= pentru compararea a două date
     * @param other Data de comparat cu aceasta
     * @return true dacă această dată este mai mică sau egală cu other, false în caz contrar
     */
    bool operator<=(const Date& other) const;
    
    /**
     * Supraîncărcarea operatorului > pentru compararea a două date
     * @param other Data de comparat cu aceasta
     * @return true dacă această dată este mai mare decât other, false în caz contrar
     */
    bool operator>(const Date& other) const;
    
    /**
     * Supraîncărcarea operatorului >= pentru compararea a două date
     * @param other Data de comparat cu aceasta
     * @return true dacă această dată este mai mare sau egală cu other, false în caz contrar
     */
    bool operator>=(const Date& other) const;
};

} // namespace Task_Management
