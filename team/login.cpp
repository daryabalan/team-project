#include "Login.h"

#include "Client.h"

#include "ClientList.h"

#include "YearlyReport.h"

#include "BonusSystem.h"

#include <iostream>

#include <string>

#include <fstream>

#include <vector>

void Login::ShowMainScreen() {
  int choice;
  system("cls"); // Очищаем экран консоли
  BonusSystem bonusSystem;
  do {
    std::cout << "You have successfully logged in!\n";
    std::cout << "Select one of the following options:\n";
    std::cout << "1. Registering a new client\n";//регистрация нового клиента
    std::cout << "2. Accrual of bonuses\n";//начислить бонусы
    std::cout << "3. Write-off of bonuses\n";//списать бонусы
    std::cout << "4. Generating an annual report\n";//формирование общего(годвого) отчёта
    std::cout << "5. View your balance\n";//просмотр баланса
    std::cout << "6. View the invoice details table\n";//детализация карты
    std::cout << "7. Exit the program\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    std::vector < Client > clients; // Вектор для хранения клиентов

    switch (choice) {
    case 1: {
      system("cls"); // Очищаем экран консоли
      Client newClient;
      std::string firstName, phoneNumber;

      std::cout << "Enter your full name: ";
      std::cin.ignore(); // Используем ignore, чтобы очистить буфер ввода перед вводом имени
      std::getline(std::cin, firstName); // Считываем полное имя с пробелами
      std::cout << "Enter your phone number: ";
      std::cin >> phoneNumber;

      newClient.setFullName(firstName); // Устанавливаем имя клиента
      newClient.setPhoneNumber(phoneNumber); // Устанавливаем номер телефона клиента
      newClient.balance = 0;

      newClient.saveToFile(); // Сохраняем данные клиента в файл
      clients.push_back(newClient);
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }
    case 2: {
      system("cls"); // Очищаем экран консоли
      std::string phoneNumber;
      int bonusAmount;

      std::cout << "phoneNumber: ";
      std::cin >> phoneNumber;

      std::cout << "bonusAmount: ";
      std::cin >> bonusAmount;

      bonusSystem.findClientByNumberAndAddBonus(phoneNumber, bonusAmount);
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }

    case 3: {
      system("cls"); // Очищаем экран консоли
      std::string phoneNumber;
      int penaltyAmount;

      std::cout << "Enter phone number: ";
      std::cin >> phoneNumber;

      std::cout << "Enter penalty amount: ";
      std::cin >> penaltyAmount;

      bonusSystem.findClientByNumberAndDeductBonus(phoneNumber, penaltyAmount);
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }

    case 4: {
      system("cls"); // Очищаем экран консоли
      YearlyReport yearlyReport;
      std::string phoneNumber;

      std::cout << "Enter the phone number: ";
      std::cin >> phoneNumber;

      yearlyReport.summarizeClientBonuses(phoneNumber);
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }

    case 5: {
      system("cls"); // Очищаем экран консоли
      ClientList clientList; // Создание объекта класса ClientList
      clientList.viewAllClientsData(); // Вызов метода через объект
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }
    case 6: {
      system("cls"); // Очищаем экран консоли
      ClientList clientList;
      std::string phoneNumber;
      std::cout << "Enter the phone number: ";
      std::cin >> phoneNumber;
      clientList.viewOperationsByPhoneNumber(phoneNumber);
      system("pause"); // Результат останется на экране до нажатия клавиши
      system("cls"); // Очистка консоли после завершения пункта меню
      break;
    }
    case 7: {
      std::cout << "Exiting the program\n";
      return; // завершаем функцию, выходя из цикла и возвращаясь в вызывающую функцию
    }
    default: {
      std::cout << "Invalid choice, please try again\n";
      break;
    }
    }
  } while (true);
}


