#include <iostream>
#include <cmath>

using namespace std;

void task_if28();    
void task_if33();    
void task_geom20();  

int main() {
    int menu = 0;
    do {
        cout << "\n==================================" << endl;
        cout << "        ЛАБОРАТОРНА РОБОТА №3         " << endl;
        cout << "==================================" << endl;
        cout << "1. Завдання 1.1 (If28: Високосний рік)" << endl;
        cout << "2. Завдання 1.2 (If33: Функція p(x))" << endl;
        cout << "3. Завдання 2 (Геометрія: Варіант 20)" << endl;
        cout << "4. Вихід з програми" << endl;
        cout << "==================================" << endl;
        cout << "Введіть номер завдання (1-4): ";
        
        cin >> menu;

        // Якщо ввели не число або сталася помилка потоку
        if (cin.fail()) {
            cout << "Помилка: введіть числове значення від 1 до 4!" << endl;
            cin.clear(); // Скидаємо стан потоку
            cin.ignore(32767, '\n'); // Очищуємо буфер клавіатури
            continue;
        }

        switch (menu) {
            case 1:
                task_if28();
                break;
            case 2:
                task_if33();
                break;
            case 3:
                task_geom20();
                break;
            case 4:
                cout << "Вихід з програми. До побачення!" << endl;
                break;
            default:
                cout << "Невірний номер завдання! Будь ласка, виберіть від 1 до 4." << endl;
        }

        if (menu != 4) {
            cout << "\nНатисніть Enter для продовження...";
            cin.ignore(32767, '\n');
            cin.get();
        }

    } while (menu != 4);

    return 0;
}

void task_if28() {
    cout << "\n--- Завдання 1 (If28): Визначення кількості днів у році ---" << endl;
    int year = 0;
    cout << "Введіть номер року (додатне ціле число): ";
    cin >> year;

    if (cin.fail() || year <= 0) {
        cout << "Помилка: введено некоректний рік!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }

    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        cout << year << " рік є високосним. Кількість днів: 366." << endl;
    } else {
        cout << year << " рік є звичайним. Кількість днів: 365." << endl;
    }
}

void task_if33() {
    cout << "\n--- Завдання 1 (If33): Обчислення значення функції p(x) ---" << endl;
    double x = 0;
    cout << "Введіть дійсне значення x: ";
    cin >> x;

    if (cin.fail()) {
        cout << "Помилка: введено не числові дані!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }

    int p = 0; // згідно з умовою значення функції приймає цілий тип
    if (x <= 1) {
        p = static_cast<int>(pow(x, 3));
    } else if (x > 1 && x < 4) {
        p = static_cast<int>(2 * x + 1);
    } else {
        p = 9;
    }

    cout << "Результат обчислення функції p(" << x << ") = " << p << endl;
}

void task_geom20() {
    cout << "\n--- Завдання 2: Перевірка потрапляння точки в область (Варіант 20) ---" << endl;
    
    double a = 0, r = 0, x = 0, y = 0;
    
    cout << "Введіть сторону квадрата a: ";
    cin >> a;
    cout << "Введіть радіус кола r: ";
    cin >> r;

    if (cin.fail() || a <= 0 || r <= 0 || r > a / 2.0) {
        cout << "Помилка некоректних даних! (a та r мають бути > 0, r <= a/2)" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }

    cout << "Введіть координати точки (x, y через пробіл): ";
    cin >> x >> y;

    if (cin.fail()) {
        cout << "Помилка: введено не числові координати!" << endl;
        cin.clear();
        cin.ignore(32767, '\n');
        return;
    }

    double dist_sq = x * x + y * y;
    double r_sq = r * r;
    double half_a = a / 2.0;

    // Область 1: 2-га чверть (x <= 0, y >= 0) — усередині квадрата, але строго поза колом
    bool region1 = (x <= 0 && x >= -half_a) && (y >= 0 && y <= half_a) && (dist_sq > r_sq);

    // Область 2: 1-ша чверть (x > 0, y > 0) — усередині кола та під діагоналлю y <= x
    bool region2 = (x > 0 && y > 0) && (dist_sq <= r_sq) && (y <= x);

    if (region1 || region2) {
        cout << "Точка (" << x << ", " << y << ") Потрапляє в зафарбовану область (Варіант 20)." << endl;
    } else {
        cout << "Точка (" << x << ", " << y << ") Не потрапляє в зафарбовану область." << endl;
    }
}
