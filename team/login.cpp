#include "Login.h"
#include "Client.h"
#include "ClientList.h"
#include "operation.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void Login::ShowMainScreen() {
    int choice;
    std::cout << "You have successfully logged in!\n";
    std::cout << "Select one of the following options:\n";
    std::cout << "1. Registering a new card\n";
    std::cout << "2. Accrual of bonuses\n";
    std::cout << "3. Write-off of bonuses\n";
    std::cout << "4. Generating an annual report\n";
    std::cout << "5. View your balance\n";
    std::cout << "6. Viewing the annual reports table\n";
    std::cout << "7. View the invoice details table\n";
    std::cout << "8. Exit the program\n";
    std::cout << "Your choice: ";
    std::cin >> choice;

    std::vector<Client> clients;  // Вектор для хранения клиентов

    Client newClient;
    ClientList newClientList;
    do {
    switch (choice) {
    case 1: {
        std::string firstName, phoneNumber;

        std::cout << "Enter your full name: ";
        std::cin.ignore(); // Используем ignore, чтобы очистить буфер ввода перед вводом имени
        std::getline(std::cin, firstName); // Считываем полное имя с пробелами
        std::cout << "Enter your phone number: ";
        std::cin >> phoneNumber;

        newClient.setFullName(firstName); // Устанавливаем имя клиента
        newClient.setPhoneNumber(phoneNumber); // Устанавливаем номер телефона клиента
        newClient.generateCardNumber(); // Генерируем номер карты
        //newClient.setBalance(balance);
        newClient.balance=0.0f;

        newClient.saveToFile(); // Сохраняем данные клиента в файл
        std::cout << "Generated card number: " << newClient.cardNumber << std::endl;
        break;
    };
    case 2: {
               // Аккумуляция бонусов
               std::string cardNumber;
               int bonusQuantity;

               std::cout << "Enter your card number: ";
               std::cin >> cardNumber;
               std::cout << "Enter the quantity of bonuses to accrue: ";
               std::cin >> bonusQuantity;
               //std::cout <<newClient.balance;

               Operation operation(cardNumber, "Accrual", bonusQuantity);
               //operation.transaction_operation();  // Проведение транзакции

               // Исправленный вызов writeToFile
              operation.writeToFile(cardNumber, "Accrual", bonusQuantity, operation.getBalance(), newClient, 0.0f);  // Запись деталей операции в файл

               std::cout << "Bonuses have been accrued to your account.\n";
               break;
           };

    case 3: {
        newClientList.addClient(newClient);

    };
    }
    } while(choice!=8);
}
