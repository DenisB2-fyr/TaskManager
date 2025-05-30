#pragma once

#include "task.h"
#include "note.h"
#include <vector>

namespace Task_Management {

/**
 * Clasa Task_Notes - gestionează notele atașate unei sarcini
 * 
 * Această clasă demonstrează utilizarea struct-urilor împreună cu clasele
 * și implementează funcționalitatea de adăugare și gestionare a notelor pentru sarcini.
 */
class Task_Notes {
public:
    /**
     * Constructor implicit
     */
    Task_Notes();
    
    /**
     * Constructor cu sarcina asociată
     * @param task Pointer către sarcina asociată
     */
    Task_Notes(Task* task);
    
    /**
     * Destructor
     */
    ~Task_Notes();
    
    /**
     * Adaugă o notă la sarcină
     * @param note Nota de adăugat
     */
    void AddNote(const Note& note);
    
    /**
     * Adaugă o notă la sarcină (versiune cu parametri individuali)
     * @param text Textul notei
     * @param author Autorul notei
     * @param creation_date Data creării notei
     * @param is_important Indicator dacă nota este importantă
     */
    void AddNote(const std::string& text, const std::string& author, 
                const std::string& creation_date, bool is_important = false);
    
    /**
     * Obține toate notele
     * @return Vector cu toate notele
     */
    const std::vector<Note>& GetNotes() const;
    
    /**
     * Obține notele importante
     * @return Vector cu notele marcate ca importante
     */
    std::vector<Note> GetImportantNotes() const;
    
    /**
     * Caută note care conțin un anumit cuvânt cheie
     * @param keyword Cuvântul cheie de căutat
     * @return Vector cu notele care conțin cuvântul cheie
     */
    std::vector<Note> SearchNotes(const std::string& keyword) const;
    
    /**
     * Afișează toate notele
     */
    void DisplayNotes() const;
    
    /**
     * Setează sarcina asociată
     * @param task Pointer către sarcina asociată
     */
    void SetTask(Task* task);
    
    /**
     * Obține sarcina asociată
     * @return Pointer către sarcina asociată
     */
    Task* GetTask() const;
    
private:
    Task* m_task;               // Sarcina asociată cu aceste note
    std::vector<Note> m_notes;  // Colecția de note
};

} // namespace Task_Management
