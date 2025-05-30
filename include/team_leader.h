#pragma once

#include "user.h"
#include <string>
#include <vector>

namespace Task_Management {

/**
 * Clasa Team_Leader - reprezintă un lider de echipă care extinde clasa User
 * 
 * Această clasă demonstrează conceptul de moștenire în POO.
 * Team_Leader moștenește toate proprietățile și metodele clasei User (clasa de bază)
 * și adaugă funcționalități specifice pentru gestionarea unei echipe.
 */
class Team_Leader : public User {
public:
    /**
     * Constructor cu parametri necesari
     * @param name Numele liderului de echipă
     * @param email Adresa de email a liderului de echipă
     * @param department Departamentul liderului de echipă
     */
    Team_Leader(const std::string& name, const std::string& email, const std::string& department);
    
    /**
     * Constructor de copiere
     * @param other Obiectul Team_Leader de copiat
     */
    Team_Leader(const Team_Leader& other);
    
    /**
     * Destructor
     */
    virtual ~Team_Leader();
    
    /**
     * Obține departamentul liderului de echipă
     * @return Departamentul ca string
     */
    std::string GetDepartment() const;
    
    /**
     * Setează departamentul liderului de echipă
     * @param department Noul departament
     */
    void SetDepartment(const std::string& department);
    
    /**
     * Adaugă un membru la echipa acestui lider
     * @param member Pointer către utilizatorul de adăugat ca membru
     */
    void AddTeamMember(User* member);
    
    /**
     * Elimină un membru din echipa acestui lider
     * @param member_id ID-ul membrului de eliminat
     * @return true dacă membrul a fost găsit și eliminat, false în caz contrar
     */
    bool RemoveTeamMember(const std::string& member_id);
    
    /**
     * Obține toți membrii echipei
     * @return Vector cu pointeri către toți membrii echipei
     */
    const std::vector<User*>& GetTeamMembers() const;
    
    /**
     * Obține dimensiunea echipei
     * @return Numărul de membri din echipă
     */
    size_t GetTeamSize() const;
    
    /**
     * Suprascrie metoda pentru afișarea detaliilor liderului de echipă
     * Demonstrează conceptul de polimorfism prin suprascriere (override)
     */
    virtual void DisplayDetails() const override;
    
    /**
     * Suprascrie metoda pentru obținerea tipului de utilizator
     * @return Tipul utilizatorului ca string ("Team Leader")
     */
    virtual std::string GetUserType() const override;
    
protected:
    /**
     * Metodă protejată pentru a adăuga detalii specifice la stream
     * Suprascrie metoda din clasa de bază
     * @param os Stream-ul de ieșire
     */
    virtual void _WriteDetailsToStream(std::ostream& os) const override;
    
private:
    std::string m_department;         // Departamentul liderului de echipă
    std::vector<User*> m_team_members; // Membrii echipei
};

} // namespace Task_Management
