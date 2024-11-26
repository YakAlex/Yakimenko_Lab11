#include <iostream>
#include <regex>
#include <string>
#include <Windows.h>
using namespace std;

struct Route {
private:
    string departurePoint;
    string destinationPoint;
    string flightNumberValue;


    string flightNumber() const {
        if (flightNumberValue.substr(0, 2) == "SA") return "Singapore Airlines";
        if (flightNumberValue.substr(0, 2) == "QA") return "Qatar Airways";
        if (flightNumberValue.substr(0, 2) == "AA") return "American Airlines";
        return "Невідома авіакомпанія";
    }

    bool isValid(const string& flyNum) const {
        return regex_match(flyNum, regex("^[A-Z]{2}\\d{2}$"));
    }

public:
    Route() = default;

    Route(const string& departure, const string& destination, const string& flyNum)
        : departurePoint(departure), destinationPoint(destination) {
        if (isValid(flyNum)) {
            flightNumberValue = flyNum;
        } else {
            cerr << "Не правильно введений номер рейсу!\n";
            exit(0);
        }
    }

    void ShowRoutes() const {
        cout << "Доступні авіакомпанії:\n";
        cout << "Singapore Airlines (SA) || Qatar Airways (QA) || American Airlines (AA)\n";
    }

    void init() {
        cout << "Введіть місце відправки: \n";
        cin >> departurePoint;
        cout << "Введіть місце призначення: \n";
        cin >> destinationPoint;
        cout << "Введіть номер рейсу (приклад 'AA52'): \n";
        cin >> flightNumberValue;

        if (!isValid(flightNumberValue)) {
            cerr << "Не правильно введений номер рейсу! Спробуйте ще раз.\n";
            init();
        }
    }

    void DisplayRoutes() const {
        cout << "\nІнформація про рейс:\n"
             << "Відправний пункт: " << departurePoint << "\n"
             << "Пункт призначення: " << destinationPoint << "\n"
             << "Номер рейсу: " << flightNumberValue << "\n"
             << "Авіакомпанія: " << flightNumber() << "\n";
    }
};

int main() {
    SetConsoleOutputCP(CP_UTF8);

    Route route;
    route.ShowRoutes();
    route.init();
    route.DisplayRoutes();

    return 0;
}
