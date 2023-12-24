#include "BillDetails.h"
#include "BonusSystem.h"
#include <fstream>
#include <iostream>
#include <sstream>  // Added for std::istringstream
#include <string>   // Added for std::stoi

void BonusSystem::findClientByNumberAndAddBonus(const std::string& phoneNumber, int bonusAmount) {
    std::ifstream inFile("C:\\TeamProgect\\clients.txt");
    if (inFile.is_open()) {
        std::string line;
        std::string clientData;
        bool clientFound = false;
        while (std::getline(inFile, line)) {
            clientData += line + "\n";
            if (line.find("Phone Number: " + phoneNumber) != std::string::npos) {
                clientFound = true;
                break;
            }
        }
        inFile.close();

        if (clientFound) {
            // Найден клиент, начисляем бонусы
            std::string fullName, phoneNum, cardNumber;
            int balance = 0;

            std::istringstream iss(clientData);
            std::ostringstream updatedClientData;

            std::string currentLine;
            while (std::getline(iss, currentLine)) {
                if (currentLine.find("Full Name: ") != std::string::npos) {
                    fullName = currentLine.substr(11);
                } else if (currentLine.find("Phone Number: ") != std::string::npos) {
                    phoneNum = currentLine.substr(14);
                } else if (currentLine.find("Card Number: ") != std::string::npos) {
                    cardNumber = currentLine.substr(13);
                } else if (currentLine.find("Bonus balance: ") != std::string::npos) {
                    std::stringstream ss(currentLine.substr(15));
                    ss >> balance;
                }
            }

            // Начисляем бонусы
            balance += bonusAmount;

            // Перезаписываем данные в файл clients.txt
            std::ofstream outFile("C:\\TeamProgect\\clients.txt");
            if (outFile.is_open()) {
                std::istringstream iss2(clientData);
                while (std::getline(iss2, currentLine)) {
                    if (currentLine.find("Phone Number: " + phoneNumber) != std::string::npos) {
                        updatedClientData << "Full Name: " << fullName << "\n";
                        updatedClientData << "Phone Number: " << phoneNum << "\n";
                        updatedClientData << "Card Number: " << cardNumber << "\n"; // Номер карты добавлен
                        updatedClientData << "Bonus balance: " << balance << "\n";
                    } else {
                        updatedClientData << currentLine << "\n";
                    }
                }
                outFile << updatedClientData.str();
                outFile.close();
                std::cout << "Client data has been updated in clients.txt\n";

                // Добавляем данные в файл clients_with_bonus.txt
                std::ofstream bonusFile("C:\\TeamProgect\\ClientsWithBonus.txt", std::ios::app);
                if (bonusFile.is_open()) {
                    bonusFile << "Full Name: " << fullName << "\n";
                    bonusFile << "Phone Number: " << phoneNum << "\n";
                    bonusFile << "Card Number: " << cardNumber << "\n"; // Номер карты добавлен
                    bonusFile << "Bonus balance: " << balance << "\n";
                    bonusFile << "--------------------------\n";
                    bonusFile.close();
                    std::cout << "Client data with bonus has been saved to clients_with_bonus.txt\n";
                } else {
                    std::cout << "Unable to open clients_with_bonus.txt for writing\n";
                }
            } else {
                std::cout << "Unable to open clients.txt for writing\n";
            }
        } else {
            std::cout << "Клиент с номером " << phoneNumber << " не найден" << std::endl;
        }
    } else {
        std::cout << "Unable to open clients.txt" << std::endl;
    }
}

