#include <iostream>
#include <cmath>

using namespace std;

int main() {
    //  Завдання If28: Визначення кількості днів у році 
    cout << " Завдання If28 " << endl;
    int year;
    cout << "Введіть номер року: ";
    cin >> year;
    
    // Перевірка на високосний рік за умовами завдання
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " рік є високосним, у ньому 366 днів." << endl;
    } else {
        cout << year << " рік є звичайним, у ньому 365 днів." << endl;
    }
    
    cout << endl;

    //  Завдання If33: Обчислення значення функції p(x) 
    cout << " Завдання If33 " << endl;
    double x;
    cout << "Введіть дійсне значення x: ";
    cin >> x;
    
    int p; // функція приймає значення цілого типу
    
    if (x <= 1) {
        p = round(pow(x, 3));
    } 
    else if (x > 1 && x < 4) {
        p = round(2 * x + 1);
    } 
    else {
        p = 9;
    }
    
    cout << "Для x = " << x << " значення функції p(x) = " << p << endl;

    return 0;
}