#include "sms_notifier.h"
#include <iostream>

namespace Task_Management {

SMS_Notifier::SMS_Notifier(const std::string& sender_phone)
    : m_sender_phone(sender_phone) {
    // Inițializăm numărul de telefon al expeditorului
}

SMS_Notifier::~SMS_Notifier() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

bool SMS_Notifier::SendNotification(const std::string& recipient, const std::string& subject, const std::string& message) const {
    // Într-o implementare reală, această metodă ar conecta la un serviciu de SMS
    // Pentru această demonstrație, doar afișăm detaliile SMS-ului
    
    std::cout << "Sending SMS notification:" << std::endl;
    std::cout << "  From: " << m_sender_phone << std::endl;
    std::cout << "  To: " << recipient << std::endl;
    // Pentru SMS-uri, includem subiectul în mesaj, deoarece SMS-urile nu au câmp de subiect separat
    std::cout << "  Message: " << subject << ": " << message << std::endl;
    
    // Simulăm trimiterea cu succes
    return true;
}

std::string SMS_Notifier::GetNotificationType() const {
    // Returnează tipul notificării
    return "SMS";
}

std::string SMS_Notifier::GetSenderPhone() const {
    // Returnează numărul de telefon al expeditorului
    return m_sender_phone;
}

void SMS_Notifier::SetSenderPhone(const std::string& sender_phone) {
    // Setează numărul de telefon al expeditorului
    m_sender_phone = sender_phone;
}

} // namespace Task_Management
