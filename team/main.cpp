#include "Login.h"
#include "BonusSystem.h"
#include <iostream>
#include <locale> // for setlocale
using namespace std;

int main() {
    //Функция setlocale() задаёт локализацию программы.
    setlocale(LC_ALL, "rus");
    Login login;

    BonusSystem bonusSystem;

    // вход
    login.showLoginMenu();

    // Если пароль верный-вывести меню
    if (login.validateUserCredentials()) {
        cout << "Вы успешно вошли в систему!\n";
        bonusSystem.showMainScreen();
    } else {
        cout << "Неверный пароль. Вход в систему запрещен.\n";
    }

    return 0;
}
