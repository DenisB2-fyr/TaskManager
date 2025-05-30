#pragma once

#include "inotifier.h"
#include <string>

namespace Task_Management {

/**
 * Clasa Email_Notifier - implementare a interfeței INotifier pentru notificări prin email
 * 
 * Această clasă demonstrează conceptul de implementare a unei interfețe în POO.
 * Implementează toate metodele virtuale pure definite în interfața INotifier.
 */
class Email_Notifier : public INotifier {
public:
    /**
     * Constructor cu parametrul necesar
     * @param sender_email Adresa de email a expeditorului
     */
    Email_Notifier(const std::string& sender_email);
    
    /**
     * Destructor
     */
    virtual ~Email_Notifier();
    
    /**
     * Implementarea funcției virtuale pure pentru trimiterea unei notificări
     * Suprascrie metoda din interfața INotifier
     * 
     * @param recipient Adresa de email a destinatarului
     * @param subject Subiectul email-ului
     * @param message Conținutul email-ului
     * @return true dacă email-ul a fost trimis cu succes, false în caz contrar
     */
    virtual bool SendNotification(const std::string& recipient, const std::string& subject, const std::string& message) const override;
    
    /**
     * Implementarea funcției virtuale pure pentru obținerea tipului de notificare
     * @return Tipul notificării ca string ("Email")
     */
    virtual std::string GetNotificationType() const override;
    
    /**
     * Obține adresa de email a expeditorului
     * @return Adresa de email a expeditorului ca string
     */
    std::string GetSenderEmail() const;
    
    /**
     * Setează adresa de email a expeditorului
     * @param sender_email Noua adresă de email a expeditorului
     */
    void SetSenderEmail(const std::string& sender_email);
    
private:
    std::string m_sender_email;  // Adresa de email a expeditorului
};

} // namespace Task_Management
