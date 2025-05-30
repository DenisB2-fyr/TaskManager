#pragma once

#include <string>

namespace Task_Management {

/**
 * Interfața INotifier - definește contractul pentru diferite metode de notificare
 * 
 * Această clasă demonstrează conceptul de interfață în POO.
 * În C++, interfețele sunt implementate ca clase abstracte pure
 * (clase care conțin doar funcții virtuale pure).
 * 
 * O interfață definește un contract pe care clasele care o implementează
 * trebuie să-l respecte, fără a specifica cum trebuie implementat.
 */
class INotifier {
public:
    /**
     * Destructor virtual pentru curățarea corectă a resurselor în clasele derivate
     */
    virtual ~INotifier() {}
    
    /**
     * Funcție virtuală pură pentru trimiterea unei notificări
     * Trebuie implementată de toate clasele care implementează această interfață
     * 
     * @param recipient Destinatarul notificării
     * @param subject Subiectul notificării
     * @param message Conținutul notificării
     * @return true dacă notificarea a fost trimisă cu succes, false în caz contrar
     */
    virtual bool SendNotification(const std::string& recipient, const std::string& subject, const std::string& message) const = 0;
    
    /**
     * Funcție virtuală pură pentru obținerea tipului de notificare
     * @return Tipul notificării ca string
     */
    virtual std::string GetNotificationType() const = 0;
};

} // namespace Task_Management
