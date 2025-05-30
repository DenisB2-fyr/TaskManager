#pragma once

namespace Task_Management {

/**
 * Structura Note - reprezintă o notă sau un comentariu atașat unei sarcini
 * 
 * Această structură demonstrează utilizarea struct-urilor alături de clase în POO.
 * În C++, structurile sunt similare cu clasele, dar membrii sunt publici în mod implicit.
 * Structurile sunt folosite de obicei pentru date simple, fără comportament complex.
 */
struct Note {
    std::string text;           // Textul notei
    std::string author;         // Autorul notei
    std::string creation_date;  // Data creării notei
    bool is_important;          // Indicator dacă nota este importantă
    
    /**
     * Constructor implicit
     * Inițializează membrii cu valori implicite
     */
    Note() : text(""), author(""), creation_date(""), is_important(false) {}
    
    /**
     * Constructor cu parametri
     * @param text Textul notei
     * @param author Autorul notei
     * @param creation_date Data creării notei
     * @param is_important Indicator dacă nota este importantă
     */
    Note(const std::string& text, const std::string& author, 
         const std::string& creation_date, bool is_important = false)
        : text(text), author(author), creation_date(creation_date), is_important(is_important) {}
    
    /**
     * Convertește nota în string formatat
     * @return Reprezentarea string a notei
     */
    std::string ToString() const {
        std::string importance = is_important ? "[IMPORTANT] " : "";
        return importance + "Note by " + author + " (" + creation_date + "): " + text;
    }
    
    /**
     * Verifică dacă nota conține un anumit cuvânt cheie
     * @param keyword Cuvântul cheie de căutat
     * @return true dacă nota conține cuvântul cheie, false în caz contrar
     */
    bool ContainsKeyword(const std::string& keyword) const {
        return text.find(keyword) != std::string::npos;
    }
};

} // namespace Task_Management
