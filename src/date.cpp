#include "date.h"
#include <sstream>
#include <iomanip>
#include <ctime>
#include <chrono>

namespace Task_Management {

Date::Date() : year(0), month(0), day(0) {
    // Constructor implicit - inițializează toate câmpurile cu 0
    // Aceasta reprezintă o dată invalidă care poate fi detectată cu IsValid()
}

Date::Date(int year, int month, int day) : year(year), month(month), day(day) {
    // Constructor cu parametri - inițializează câmpurile cu valorile specificate
    // Nu validăm datele aici, dar putem verifica ulterior cu IsValid()
}

Date::Date(const Date& other) : year(other.year), month(other.month), day(other.day) {
    // Constructor de copiere - copiază toate câmpurile din obiectul other
}

std::string Date::ToString() const {
    // Convertește data într-un string formatat (YYYY-MM-DD)
    // Folosim stringstream și manipulatori pentru formatare
    std::stringstream ss;
    ss << std::setfill('0') << std::setw(4) << year << "-"
       << std::setfill('0') << std::setw(2) << month << "-"
       << std::setfill('0') << std::setw(2) << day;
    return ss.str();
}

bool Date::IsValid() const {
    // Validare de bază
    // Anul trebuie să fie pozitiv, luna între 1 și 12, ziua cel puțin 1
    if (year < 0 || month < 1 || month > 12 || day < 1) {
        return false;
    }
    
    // Verificăm numărul de zile în lună
    int days_in_month;
    switch (month) {
        case 2: // Februarie
            // Verificăm dacă este an bisect
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                days_in_month = 29;  // An bisect
            } else {
                days_in_month = 28;  // An obișnuit
            }
            break;
        case 4: case 6: case 9: case 11: // Aprilie, Iunie, Septembrie, Noiembrie
            days_in_month = 30;
            break;
        default: // Ianuarie, Martie, Mai, Iulie, August, Octombrie, Decembrie
            days_in_month = 31;
            break;
    }
    
    // Verificăm dacă ziua este validă pentru luna respectivă
    return day <= days_in_month;
}

Date Date::GetCurrentDate() {
    // Obținem data curentă din sistemul de operare
    // Aceasta este o metodă statică - poate fi apelată fără o instanță a clasei
    auto now = std::chrono::system_clock::now();
    std::time_t now_time = std::chrono::system_clock::to_time_t(now);
    std::tm* now_tm = std::localtime(&now_time);
    
    // Creăm și returnăm un obiect Date cu data curentă
    return Date(now_tm->tm_year + 1900, now_tm->tm_mon + 1, now_tm->tm_mday);
}

int Date::DaysBetween(const Date& date1, const Date& date2) {
    // Aceasta este o implementare simplificată
    // Într-o aplicație reală, am folosi un algoritm mai precis
    
    // Convertim la structura tm
    std::tm tm1 = {};
    tm1.tm_year = date1.year - 1900;  // tm_year este numărul de ani de la 1900
    tm1.tm_mon = date1.month - 1;     // tm_mon este între 0-11
    tm1.tm_mday = date1.day;
    
    std::tm tm2 = {};
    tm2.tm_year = date2.year - 1900;
    tm2.tm_mon = date2.month - 1;
    tm2.tm_mday = date2.day;
    
    // Convertim la time_t (secunde de la epoca Unix)
    std::time_t time1 = std::mktime(&tm1);
    std::time_t time2 = std::mktime(&tm2);
    
    // Calculăm diferența în secunde și convertim la zile
    double diff_seconds = std::difftime(time2, time1);
    int diff_days = static_cast<int>(diff_seconds / (60 * 60 * 24));
    
    return diff_days;
}

Date Date::AddDays(int days) const {
    // Convertim la structura tm
    std::tm tm_date = {};
    tm_date.tm_year = year - 1900;
    tm_date.tm_mon = month - 1;
    tm_date.tm_mday = day + days;  // Adăugăm zilele
    
    // Normalizăm data (mktime ajustează automat valorile overflow)
    std::time_t time_date = std::mktime(&tm_date);
    std::tm* new_tm = std::localtime(&time_date);
    
    // Creăm și returnăm un nou obiect Date
    return Date(new_tm->tm_year + 1900, new_tm->tm_mon + 1, new_tm->tm_mday);
}

// Implementarea operatorilor de comparație
// Acești operatori permit compararea directă a obiectelor Date

bool Date::operator==(const Date& other) const {
    // Două date sunt egale dacă toate componentele sunt egale
    return year == other.year && month == other.month && day == other.day;
}

bool Date::operator!=(const Date& other) const {
    // Negarea operatorului ==
    return !(*this == other);
}

bool Date::operator<(const Date& other) const {
    // Comparăm mai întâi anii
    if (year != other.year) {
        return year < other.year;
    }
    // Dacă anii sunt egali, comparăm lunile
    if (month != other.month) {
        return month < other.month;
    }
    // Dacă și lunile sunt egale, comparăm zilele
    return day < other.day;
}

bool Date::operator<=(const Date& other) const {
    // Mai mic sau egal înseamnă fie mai mic, fie egal
    return *this < other || *this == other;
}

bool Date::operator>(const Date& other) const {
    // Negarea operatorului <=
    return !(*this <= other);
}

bool Date::operator>=(const Date& other) const {
    // Negarea operatorului <
    return !(*this < other);
}

} // namespace Task_Management
