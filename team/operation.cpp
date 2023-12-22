//operation.cpp
#include "operation.h"
#include "Client.h"
#include <iostream>
#include <fstream>

// Реализация конструктора Operation::Operation
Operation::Operation(std::string card, std::string operationType, int quantBonus) {
    this->cardNumber = card;
    this->operationType = operationType;
    this->quantBonus = quantBonus;
    this->CurrentBalance = CurrentBalance;
    // Инициализация остальных членов класса, если необходимо
}

// Реализация метода Operation::transaction_operation
void Operation::transaction_operation() {
    std::cout << "Enter the quantity of bonuses to accrue: \n";
    std::cin >> quantBonus;
    std::cout << "Transaction has been processed.\n";
    // Например, обновление текущего баланса и другие операции
}

// Реализация метода Operation::writeToFile
void Operation::writeToFile(const std::string& cardNumber, const std::string& operationType, int quantBonus, float balance, const Client& client, float amount) {
    std::ofstream file("D:\\Github rep\\Project\\team-project\\operation.txt", std::ios::app);

    if (file.is_open()) {
        file << "Card Number: " << cardNumber << "\n";
        file << "Phone Number: " << client.phoneNumber << "\n";
        file << "Operation Type: " << operationType << "\n";
        file << "Bonus Quantity: " << quantBonus << "\n";
        balance += quantBonus;
        file << "Current Balance: " << balance<< "\n";
        file << "--------------------------\n";
        file.close();
        std::cout << "Operation details have been saved to file\n";
    } else {
        std::cout << "Unable to open file for writing\n";
    }
}
