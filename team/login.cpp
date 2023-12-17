#include "Login.h"
#include <iostream>
//#include <locale>
using namespace std;

void Login::ShowMainScreen() { //setlocale(LC_ALL, "rus");
    // Объявляем переменную для хранения выбора пользователя
       int choice;

       // Выводим приветствие и список опций
       cout << "You have successfully logged in!\n";
       cout << "Select one of the following options:\n";
       cout << "1. Registering a new card\n";
       cout << "2. Accrual of bonuses\n";
       cout << "3. Write-off of bonuses\n";
       cout << "4. Generating an annual report\n";
       cout << "5. View your balance\n";
       cout << "6. Viewing the annual reports table\n";
       cout << "7. View the invoice details table\n";
       cout << "8. Exit the program\n";

       // Запрашиваем выбор пользователя
       cout << "Your choice: ";
       cin >> choice;

       // Выполняем действие в зависимости от выбора
       switch (choice)
       {
       case 1:
           // Запрашиваем данные для регистрации новой карты
           string lastName, firstName, phoneNumber;
           cout << "Enter last name: ";
           cin >> lastName;
           cout << "Enter your name: ";
           cin >> firstName;
           cout << "Enter your phone number: ";
           cin >> phoneNumber;

           // Регистрируем новую карту
           //bonusSystem.registerNewCard(lastName, firstName, phoneNumber);

           // Возвращаемся в главное меню
           //ShowMainScreen();
           break;

}
}

