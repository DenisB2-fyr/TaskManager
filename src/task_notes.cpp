#include "task_notes.h"
#include <iostream>
#include <algorithm>

namespace Task_Management {

Task_Notes::Task_Notes() : m_task(nullptr) {
    // Constructor implicit - inițializează membrul m_task cu nullptr
    // Vectorul m_notes este inițializat automat ca gol
}

Task_Notes::Task_Notes(Task* task) : m_task(task) {
    // Constructor cu parametru - inițializează membrul m_task cu valoarea primită
    // Vectorul m_notes este inițializat automat ca gol
}

Task_Notes::~Task_Notes() {
    // Implementarea destructorului
    // În acest caz simplu, nu avem resurse de eliberat
    // Notă: Nu ștergem m_task deoarece nu deținem ownership-ul acestuia
}

void Task_Notes::AddNote(const Note& note) {
    // Adaugă o notă la colecția de note
    m_notes.push_back(note);
}

void Task_Notes::AddNote(const std::string& text, const std::string& author, 
                        const std::string& creation_date, bool is_important) {
    // Creează o notă nouă și o adaugă la colecție
    // Demonstrează supraîncărcarea funcțiilor (overloading)
    Note note(text, author, creation_date, is_important);
    AddNote(note);
}

const std::vector<Note>& Task_Notes::GetNotes() const {
    // Returnează toate notele
    return m_notes;
}

std::vector<Note> Task_Notes::GetImportantNotes() const {
    // Filtrează și returnează doar notele importante
    std::vector<Note> important_notes;
    
    // Folosim std::copy_if pentru a copia doar notele care îndeplinesc condiția
    std::copy_if(m_notes.begin(), m_notes.end(), 
                std::back_inserter(important_notes),
                [](const Note& note) { return note.is_important; });
    
    return important_notes;
}

std::vector<Note> Task_Notes::SearchNotes(const std::string& keyword) const {
    // Caută note care conțin un anumit cuvânt cheie
    std::vector<Note> matching_notes;
    
    // Folosim std::copy_if pentru a copia doar notele care conțin cuvântul cheie
    std::copy_if(m_notes.begin(), m_notes.end(), 
                std::back_inserter(matching_notes),
                [&keyword](const Note& note) { return note.ContainsKeyword(keyword); });
    
    return matching_notes;
}

void Task_Notes::DisplayNotes() const {
    // Afișează toate notele
    std::cout << "Notes for task: " << (m_task ? m_task->GetTitle() : "Unassigned") << std::endl;
    
    if (m_notes.empty()) {
        std::cout << "  No notes available." << std::endl;
        return;
    }
    
    // Afișează fiecare notă
    for (size_t i = 0; i < m_notes.size(); ++i) {
        std::cout << "  " << (i + 1) << ". " << m_notes[i].ToString() << std::endl;
    }
}

void Task_Notes::SetTask(Task* task) {
    // Setează sarcina asociată
    m_task = task;
}

Task* Task_Notes::GetTask() const {
    // Returnează sarcina asociată
    return m_task;
}

} // namespace Task_Management
