#include "Login.h"
#include <iostream>
using namespace std;

void Login::showLoginMenu() {
    // Объявляем переменные для хранения логина и пароля
        string admin_id;
        string password;

        // Выводим приветствие и инструкцию
        cout << "Добро пожаловать в программу бонусной системы!\n";
        cout << "Для входа в систему введите логин и пароль.\n";

    cout << "Введите логин: ";
    cin >> admin_id;
    cout << "Введите пароль: ";
    cin >> password;
    // Проверяем логин и пароль
        if (validateUserCredentials())
        {
            // Если логин и пароль верны, выводим главное меню
            log.Show_MainScreen();
        }
        else
        {
            // Если логин или пароль неверны, выводим сообщение об ошибке и повторяем ввод
            cout << "Неверный логин или пароль. Попробуйте еще раз.\n";
            showLoginMenu();
        }
}

void Login::ShowMainScreen() {
    // Объявляем переменную для хранения выбора пользователя
       int choice;

       // Выводим приветствие и список опций
       cout << "Вы успешно вошли в систему!\n";
       cout << "Выберите одну из следующих опций:\n";
       cout << "1. Регистрация новой карты\n";
       cout << "2. Начисление бонусов\n";
       cout << "3. Списание бонусов\n";
       cout << "4. Генерация годового отчета\n";
       cout << "5. Просмотр баланса\n";
       cout << "6. Просмотр таблицы годовых отчетов\n";
       cout << "7. Просмотр таблицы деталей счета\n";
       cout << "8. Выход из программы\n";

       // Запрашиваем выбор пользователя
       cout << "Ваш выбор: ";
       cin >> choice;

       // Выполняем действие в зависимости от выбора
       switch (choice)
       {
       case 1:
           // Запрашиваем данные для регистрации новой карты
           string lastName, firstName, phoneNumber;
           cout << "Введите фамилию: ";
           cin >> lastName;
           cout << "Введите имя: ";
           cin >> firstName;
           cout << "Введите номер телефона: ";
           cin >> phoneNumber;

           // Регистрируем новую карту
           bonusSystem.registerNewCard(lastName, firstName, phoneNumber);

           // Возвращаемся в главное меню
           Show_MainScreen();
           break;
       case 2:
           // Запрашиваем данные для начисления бонусов
           string cardNumber;
           int bonus;
           cout << "Введите номер карты: ";
           cin >> cardNumber;
           cout << "Введите количество бонусов: ";
           cin >> bonus;

           // Начисляем бонусы
           bonusSystem.accrueBonus(cardNumber, bonus);

           // Возвращаемся в главное меню
           Show_MainScreen();
           break;
       case 3:
           // Запрашиваем данные для списания бонусов
           cout << "Введите номер карты: ";
           cin >> cardNumber;
           cout << "Введите количество бонусов: ";
           cin >> bonus;

           // Списываем бонусы
           bonusSystem.debitBonus(cardNumber, bonus);

           // Возвращаемся в главное меню
           Show_MainScreen();
           break;
       case 4:
           // Запрашиваем данные для генерации годового отчета
           cout << "Введите номер карты: ";
           cin >> cardNumber;

           // Генерируем годовой отчет
           bonusSystem.generateYearlyReport(cardNumber);

           // Возвращаемся в главное меню
           Show_MainScreen();
           break;
       case 5:
           // Запрашиваем данные для просмотра баланса
           cout << "Введите номер карты: ";
           cin >> cardNumber;
           // Получаем баланс по номеру карты
                   int balance = bonusSystem.getBalance(cardNumber);

                   // Выводим баланс
                   cout << "Баланс по карте " << cardNumber << " составляет " << balance << " бонусов.\n";

                   // Возвращаемся в главное меню
                   Show_MainScreen();
                   break;
               case 6:
                   // Отображаем таблицу годовых отчетов
                   bonusSystem.displayYearlyReportsTable();

                   // Возвращаемся в главное меню
                   Show_MainScreen();
                   break;
               case 7:
                   // Отображаем таблицу деталей счета
                   bonusSystem.displayBillDetailsTable();

                   // Возвращаемся в главное меню
                   Show_MainScreen();
                   break;
               case 8:
                   // Выходим из программы
                   cout << "Спасибо за использование программы бонусной системы. До свидания!\n";
                   exit(0);
                   break;
               default:
                   // Выводим сообщение об ошибке и повторяем ввод
                   cout << "Неверный выбор. Попробуйте еще раз.\n";
                   Show_MainScreen();
                   break;
               }
           }

bool validateUserCredentials() {//функция проверки введённых данных

    if (password == "123"&&admin_id=="Dasha") {
        return true;
    } else {
        return false;
    }
}
