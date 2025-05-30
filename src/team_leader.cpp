#include "team_leader.h"
#include <iostream>

namespace Task_Management {

Team_Leader::Team_Leader(const std::string& name, const std::string& email, const std::string& department)
    : User(name, email), m_department(department) {
    // Apelăm constructorul clasei de bază (User) cu parametrii necesari
    // și inițializăm membrul specific acestei clase (m_department)
    // Aceasta demonstrează moștenirea și reutilizarea codului
}

Team_Leader::Team_Leader(const Team_Leader& other)
    : User(other), m_department(other.m_department), m_team_members(other.m_team_members) {
    // Apelăm constructorul de copiere al clasei de bază
    // și copiem membrii specifici acestei clase
}

Team_Leader::~Team_Leader() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
}

std::string Team_Leader::GetDepartment() const {
    // Returnează departamentul liderului de echipă
    return m_department;
}

void Team_Leader::SetDepartment(const std::string& department) {
    // Setează departamentul liderului de echipă
    m_department = department;
}

void Team_Leader::AddTeamMember(User* member) {
    // Adaugă un membru la echipă dacă pointerul nu este null
    if (member) {
        m_team_members.push_back(member);
    }
}

bool Team_Leader::RemoveTeamMember(const std::string& member_id) {
    // Caută membrul cu ID-ul specificat
    auto it = std::find_if(m_team_members.begin(), m_team_members.end(),
                          [&member_id](const User* member) { return member->GetId() == member_id; });
    
    // Dacă am găsit membrul, îl eliminăm și returnăm true
    if (it != m_team_members.end()) {
        m_team_members.erase(it);
        return true;
    }
    
    // Dacă nu am găsit membrul, returnăm false
    return false;
}

const std::vector<User*>& Team_Leader::GetTeamMembers() const {
    // Returnează toți membrii echipei
    return m_team_members;
}

size_t Team_Leader::GetTeamSize() const {
    // Returnează numărul de membri din echipă
    return m_team_members.size();
}

void Team_Leader::DisplayDetails() const {
    // Suprascrierea metodei din clasa de bază pentru a afișa detalii specifice
    // Aceasta este o demonstrație de polimorfism
    std::cout << "=== Team Leader Details ===" << std::endl;
    _WriteDetailsToStream(std::cout);
    
    // Afișează membrii echipei
    if (!m_team_members.empty()) {
        std::cout << "Team members:" << std::endl;
        for (size_t i = 0; i < m_team_members.size(); ++i) {
            std::cout << "  " << (i + 1) << ". " << m_team_members[i]->GetName() 
                      << " [" << m_team_members[i]->GetId() << "]" << std::endl;
        }
    }
    
    std::cout << "==========================" << std::endl;
}

std::string Team_Leader::GetUserType() const {
    // Suprascrierea metodei din clasa de bază pentru a returna tipul specific
    // Aceasta este o altă demonstrație de polimorfism
    return "Team Leader";
}

void Team_Leader::_WriteDetailsToStream(std::ostream& os) const {
    // Mai întâi apelăm metoda din clasa de bază pentru a afișa detaliile comune
    User::_WriteDetailsToStream(os);
    
    // Apoi adăugăm detaliile specifice acestei clase
    os << "Department: " << m_department << std::endl;
    os << "Team Size: " << m_team_members.size() << std::endl;
}

} // namespace Task_Management
