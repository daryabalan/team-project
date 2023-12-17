//main.cpp()
#include "Login.h"
#include <iostream>
#include "BonusSystem.h"
//#include <locale>

int main() { //setlocale(LC_ALL, "rus");
    Login login;
    BonusSystem sys;
    // Предположим, что у нас есть заданный id и пароль администратора
    string adminId = "111";
    string adminPassword = "1111";

    // Ввод данных от пользователя
    cout << "Enter your id: ";
    string enteredId;
    cin >> enteredId;

    cout << "Enter your password: ";
    string enteredPassword;
    cin >> enteredPassword;

    // Проверка введенных данных
    if (enteredId == adminId && enteredPassword == adminPassword) {
        // Если данные правильные, показываем главное меню
        login.SetSysRef(sys);
        login.ShowMainScreen();
    } else {
        // В противном случае выводим сообщение об ошибке
        cout << "Error! Check your id and password if it write correcly\n";
    }

    return 0;
}
