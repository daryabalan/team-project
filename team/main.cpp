#include "BonusSystem.h"
#include "Login.h"

int main() {
    //Функция setlocale() задаёт локализацию программы.
    setlocale(LC_ALL, "rus");
    Login log;
    BonusSystem bonusSystem;

    // вход
    log.showLoginMenu();

    // Если пароль верный-вывести меню
    if (log.validateUserCredentials()) {
        cout << "Вы успешно вошли в систему!\n";
        bonusSystem.showMainScreen();
    } else {
        cout << "Неверный пароль. Вход в систему запрещен.\n";
    }

    return 0;
}
