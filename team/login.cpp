#include "Login.h"
#include "Client.h"
#include "BonusSystem.h"
#include "BillDetails.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

void Login::ShowMainScreen() {
    int choice;
    BonusSystem bonusSystem;
    do {
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

        switch (choice) {
            case 1: {
            Client newClient;
                   std::string firstName, phoneNumber;

                   std::cout << "Enter your full name: ";
                   std::cin.ignore(); // Используем ignore, чтобы очистить буфер ввода перед вводом имени
                   std::getline(std::cin, firstName); // Считываем полное имя с пробелами
                   std::cout << "Enter your phone number: ";
                   std::cin >> phoneNumber;


                   newClient.setFullName(firstName); // Устанавливаем имя клиента
                   newClient.setPhoneNumber(phoneNumber); // Устанавливаем номер телефона клиента
                   newClient.generateCardNumber(); // Генерируем номер карты
                   newClient.balance=0.0f;


                   newClient.saveToFile(); // Сохраняем данные клиента в файл
                   std::cout << "Generated card number: " << newClient.getCardNumber() << std::endl;
                   clients.push_back(newClient);
                   break;
               }
        case 2: {
            std::string phoneNumber;
            int bonusAmount;

            std::cout << "phoneNumber: ";
            std::cin >> phoneNumber;

            std::cout << "bonusAmount: ";
            std::cin >> bonusAmount;

            bonusSystem.findClientByNumberAndAddBonus(phoneNumber, bonusAmount);
            break;
        }

        case 3: {

        }

            case 8: {
                std::cout << "Exiting the program\n";
                return;  // завершаем функцию, выходя из цикла и возвращаясь в вызывающую функцию
            }
            default: {
                std::cout << "Invalid choice, please try again\n";
                break;
            }
        }
    } while (true);
}


