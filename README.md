# Sistem de Management al Sarcinilor

## Descriere Generală

Acest proiect implementează un sistem complet de management al sarcinilor în C++11, demonstrând principiile programării orientate pe obiecte (POO). Sistemul permite crearea, organizarea și gestionarea diferitelor tipuri de sarcini, utilizatori, categorii și notificări.

## Structura Proiectului

Proiectul este organizat în următoarele componente principale:

### Ierarhia de Clase pentru Sarcini
- `Task` (clasă abstractă de bază)
- `Simple_Task` (sarcină simplă)
- `Project_Task` (sarcină de tip proiect cu sub-sarcini)
- `Recurring_Task` (sarcină recurentă)
- `Deadline_Task` (sarcină cu termen limită)

### Ierarhia de Clase pentru Utilizatori
- `User` (utilizator standard)
- `Team_Leader` (lider de echipă)

### Interfețe și Implementări
- `INotifier` (interfață pentru notificări)
- `Email_Notifier` (notificări prin email)
- `SMS_Notifier` (notificări prin SMS)

### Clase de Organizare
- `Category` (categorii pentru sarcini)
- `Task_List` (liste de sarcini)
- `Task_Manager` (manager central - Singleton)
- `Task_Notes` (gestionare note pentru sarcini)

### Structuri și Utilități
- `Date` (structură pentru date calendaristice)
- `Note` (structură pentru note și comentarii)

## Concepte OOP Demonstrate

### 1. Abstractizare
- Clasa abstractă `Task` cu funcții virtuale pure
- Interfața `INotifier` pentru diferite tipuri de notificări

### 2. Moștenire
- Ierarhie de clase `Task` → `Simple_Task`, `Project_Task`, etc.
- Ierarhie de clase `User` → `Team_Leader`

### 3. Încapsulare
- Membri privați în toate clasele
- Metode publice pentru acces controlat (getteri/setteri)
- Metode protejate pentru clasele derivate

### 4. Polimorfism
- Funcții virtuale în clasele de bază
- Suprascrierea funcțiilor în clasele derivate
- Utilizarea obiectelor derivate prin pointeri la clasa de bază

### 5. Alte Concepte Avansate
- Supraîncărcarea operatorilor (`+`, `<<`, operatori de comparație)
- Membri statici (contoare ID, Singleton)
- Utilizarea struct-urilor împreună cu clasele
- Alocarea explicită pe stack și heap
- Design pattern Singleton (`Task_Manager`)

## Funcționalități Principale

1. **Gestionarea Sarcinilor**
   - Crearea diferitelor tipuri de sarcini
   - Organizarea sarcinilor în categorii și liste
   - Monitorizarea progresului și statusului sarcinilor

2. **Gestionarea Utilizatorilor**
   - Crearea utilizatorilor și liderilor de echipă
   - Atribuirea sarcinilor către utilizatori
   - Organizarea utilizatorilor în echipe

3. **Notificări**
   - Trimiterea notificărilor prin email sau SMS
   - Notificări pentru liste de sarcini

4. **Note și Comentarii**
   - Adăugarea notelor la sarcini
   - Căutarea și filtrarea notelor

## Instrucțiuni de Compilare

Proiectul poate fi compilat folosind un compilator C++11 standard:

```bash
# Compilare cu g++
g++ -std=c++11 *.cpp -o task_manager

# Compilare cu clang
clang++ -std=c++11 *.cpp -o task_manager
```

## Instrucțiuni de Utilizare

Exemplul principal de utilizare se găsește în fișierul `main.cpp`, care demonstrează toate funcționalitățile sistemului:

```cpp
// Crearea unui manager de sarcini (Singleton)
Task_Manager& manager = Task_Manager::GetInstance();

// Crearea utilizatorilor
User* john = new User("John Smith", "john@example.com");
User* alice = new User("Alice Johnson", "alice@example.com");

// Crearea sarcinilor
Simple_Task* task1 = new Simple_Task("Cumpără alimente", "Lapte, ouă, pâine", Priority::MEDIUM);
Simple_Task* task2 = new Simple_Task("Sună la dentist", "Programează o consultație", Priority::LOW);

// Atribuirea sarcinilor utilizatorilor
task1->AssignTo(alice);
task2->AssignTo(john);

// Adăugarea sarcinilor în manager
manager.AddTask(task1);
manager.AddTask(task2);

// Marcarea unei sarcini ca finalizată
task1->SetStatus(TaskStatus::COMPLETED);

// Afișarea detaliilor sarcinii
task1->DisplayDetails();
```

## Exemple de Alocare pe Stack și Heap

Proiectul demonstrează explicit alocarea obiectelor atât pe stack cât și pe heap:

### Alocare pe Stack
```cpp
// Crearea unui obiect Date pe stack
Date deadline_date(2025, 6, 15);

// Crearea unui obiect Note pe stack (struct)
Note stack_note("Aceasta este o notă creată pe stack", "Admin", "2025-05-30", true);

// Crearea unui obiect Task_Notes pe stack
Task_Notes stack_notes;
```

### Alocare pe Heap
```cpp
// Crearea utilizatorilor pe heap
User* john = new User("John Smith", "john@example.com");

// Crearea sarcinilor pe heap
Simple_Task* task1 = new Simple_Task("Buy groceries", "Milk, eggs, bread", Priority::MEDIUM);

// Crearea notelor pe heap
Note* heap_note = new Note("Prioritate ridicată", "Manager", "2025-05-30", true);
```

## Utilizarea Operatorilor Supraîncărcați

Proiectul demonstrează utilizarea operatorilor supraîncărcați:

```cpp
// Utilizare operator << pentru afișarea sarcinilor
std::cout << *task1 << std::endl;

// Utilizare operator + pentru combinarea listelor de sarcini
Task_List combined_list = personal_list + work_list;

// Utilizare operatori de comparație pentru Date
bool is_before = today < future_date;
```

## Documentație Suplimentară

Pentru o înțelegere mai profundă a conceptelor OOP utilizate în proiect, consultați:
- `ghid_poo_explicativ.md` - Ghid introductiv pentru conceptele POO
- `ghid_complet_poo.md` - Manual detaliat cu exemple din proiect

## Autor

Acest proiect a fost dezvoltat ca parte a cursului de Programare Orientată pe Obiecte.

## Licență

Acest proiect este disponibil sub licența MIT.
