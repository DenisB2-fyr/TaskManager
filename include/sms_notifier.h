#pragma once

#include "inotifier.h"
#include <string>

namespace Task_Management {

/**
 * Clasa SMS_Notifier - implementare a interfeței INotifier pentru notificări prin SMS
 * 
 * Această clasă demonstrează conceptul de implementare a unei interfețe în POO.
 * Implementează toate metodele virtuale pure definite în interfața INotifier.
 * Reprezintă o a doua implementare a aceleiași interfețe, demonstrând polimorfismul.
 */
class SMS_Notifier : public INotifier {
public:
    /**
     * Constructor cu parametrul necesar
     * @param sender_phone Numărul de telefon al expeditorului
     */
    SMS_Notifier(const std::string& sender_phone);
    
    /**
     * Destructor
     */
    virtual ~SMS_Notifier();
    
    /**
     * Implementarea funcției virtuale pure pentru trimiterea unei notificări
     * Suprascrie metoda din interfața INotifier
     * 
     * @param recipient Numărul de telefon al destinatarului
     * @param subject Subiectul SMS-ului (va fi inclus în mesaj)
     * @param message Conținutul SMS-ului
     * @return true dacă SMS-ul a fost trimis cu succes, false în caz contrar
     */
    virtual bool SendNotification(const std::string& recipient, const std::string& subject, const std::string& message) const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de notificare
     * @return Tipul notificării ca string ("SMS")
     */
    virtual std::string GetNotificationType() const override;
    
    /**
     * Obține numărul de telefon al expeditorului
     * @return Numărul de telefon al expeditorului ca string
     */
    std::string GetSenderPhone() const;
    
    /**
     * Setează numărul de telefon al expeditorului
     * @param sender_phone Noul număr de telefon al expeditorului
     */
    void SetSenderPhone(const std::string& sender_phone);
    
private:
    std::string m_sender_phone;  // Numărul de telefon al expeditorului
};

} // namespace Task_Management
