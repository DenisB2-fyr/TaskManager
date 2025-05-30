#include "email_notifier.h"
#include <iostream>

namespace Task_Management {

Email_Notifier::Email_Notifier(const std::string& sender_email)
    : m_sender_email(sender_email) {
    // Inițializăm adresa de email a expeditorului
}

Email_Notifier::~Email_Notifier() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

bool Email_Notifier::SendNotification(const std::string& recipient, const std::string& subject, const std::string& message) const {
    // Într-o implementare reală, această metodă ar conecta la un serviciu de email
    // Pentru această demonstrație, doar afișăm detaliile email-ului
    
    std::cout << "Sending email notification:" << std::endl;
    std::cout << "  From: " << m_sender_email << std::endl;
    std::cout << "  To: " << recipient << std::endl;
    std::cout << "  Subject: " << subject << std::endl;
    std::cout << "  Message: " << message << std::endl;
    
    // Simulăm trimiterea cu succes
    return true;
}

std::string Email_Notifier::GetNotificationType() const {
    // Returnează tipul notificării
    return "Email";
}

std::string Email_Notifier::GetSenderEmail() const {
    // Returnează adresa de email a expeditorului
    return m_sender_email;
}

void Email_Notifier::SetSenderEmail(const std::string& sender_email) {
    // Setează adresa de email a expeditorului
    m_sender_email = sender_email;
}

} // namespace Task_Management
