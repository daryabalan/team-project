#include "BonusSystem.h"

#include <fstream>

#include <iostream>

#include <sstream>

#include <string>

void BonusSystem::findClientByNumberAndAddBonus(const std::string & phoneNumber, int bonusAmount) {
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
      std::istringstream iss(clientData);
      std::string fullName, phoneNum;
      int balance = 0;

      std::string line;
      while (std::getline(iss, line)) {
        if (line.find("Full Name: ") != std::string::npos) {
          fullName = line.substr(11);
        } else if (line.find("Phone Number: ") != std::string::npos) {
          phoneNum = line.substr(14);
        } else if (line.find("Bonus balance: ") != std::string::npos) {
          std::stringstream ss(line.substr(15));
          ss >> balance;
        }
      }

      // Получаем текущий баланс из файла и добавляем бонусы
      std::ifstream inFile2("C:\\TeamProgect\\clients.txt");
      if (inFile2.is_open()) {
        std::string fileLine;
        while (std::getline(inFile2, fileLine)) {
          if (fileLine.find("Phone Number: " + phoneNumber) != std::string::npos) {
            if (std::getline(inFile2, fileLine) && fileLine.find("Bonus balance: ") != std::string::npos) {
              int currentBalance;
              std::istringstream(fileLine.substr(15)) >> currentBalance;
              balance = currentBalance + bonusAmount;

            }
            break;
          }
        }
        inFile2.close();
      }

      // Перезаписываем данные в файл clients.txt
      std::ofstream outFile("C:\\TeamProgect\\clients.txt");
      if (outFile.is_open()) {
        std::istringstream iss2(clientData);
        std::string currentLine;
        while (std::getline(iss2, currentLine)) {
          if (currentLine.find("Phone Number: " + phoneNumber) != std::string::npos) {
            outFile << "Phone Number: " << phoneNum << "\n";
            outFile << "Bonus balance: " << balance << "\n";
            outFile << "--------------------------\n";
          } else {
            outFile << currentLine << "\n";
          }
        }
        outFile.close();
        std::cout << "Client data has been updated in clients.txt\n";
      } else {
        std::cout << "Unable to open clients.txt for writing\n";
      }

      // Добавляем данные в файл clients_with_bonus.txt
      std::ofstream bonusFile("C:\\TeamProgect\\clients_with_bonus.txt", std::ios::app);
      std::ofstream withoutBonusFile("C:\\TeamProgect\\clients_adding_bonus.txt", std::ios::app);
      if (bonusFile.is_open() && withoutBonusFile.is_open()) {
        bonusFile << "Full Name: " << fullName << "\n";
        bonusFile << "Phone Number: " << phoneNum << "\n";
        bonusFile << "Adding bonus: " << bonusAmount << "\n";
        bonusFile << "--------------------------\n";
        bonusFile.close();
        std::cout << "Client data with deducted bonus has been saved to clients_with_bonus.txt\n";

        withoutBonusFile << "Full Name: " << fullName << "\n";
        withoutBonusFile << "Phone Number: " << phoneNum << "\n";
        withoutBonusFile << "Adding bonuses: " << bonusAmount << "\n";
        withoutBonusFile << "--------------------------\n";
        withoutBonusFile.close();
        std::cout << "Client data with bonus has been saved to clients_with_bonus.txt\n";
      } else {
        std::cout << "Unable to open clients_with_bonus.txt for writing\n";
      }
    } else {
      std::cout << "Client with number " << phoneNumber << " not found" << std::endl;
    }
  } else {
    std::cout << "Unable to open clients.txt" << std::endl;
  }
}

void BonusSystem::findClientByNumberAndDeductBonus(const std::string & phoneNumber, int bonusAmount) {
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
      // Найден клиент, списываем бонусы
      std::istringstream iss(clientData);
      std::string fullName, phoneNum;
      int balance = 0;

      std::string line;
      while (std::getline(iss, line)) {
        if (line.find("Full Name: ") != std::string::npos) {
          fullName = line.substr(11);
        } else if (line.find("Phone Number: ") != std::string::npos) {
          phoneNum = line.substr(14);
        } else if (line.find("Bonus balance: ") != std::string::npos) {
          std::stringstream ss(line.substr(15));
          ss >> balance;
        }
      }

      // Получаем текущий баланс из файла и вычитаем бонусы
      std::ifstream inFile2("C:\\TeamProgect\\clients.txt");
      if (inFile2.is_open()) {
        std::string fileLine;
        while (std::getline(inFile2, fileLine)) {
          if (fileLine.find("Phone Number: " + phoneNumber) != std::string::npos) {
            if (std::getline(inFile2, fileLine) && fileLine.find("Bonus balance: ") != std::string::npos) {
              int currentBalance;
              std::istringstream(fileLine.substr(15)) >> currentBalance;
              if (currentBalance >= bonusAmount) {
                balance = currentBalance - bonusAmount;
                std::cout << "Bonuses successfully written off\n";
              } else {
                // Если баланс недостаточный для списания
                std::cout << "Not enough bonuses to write off\n";
              }
            }
            break;
          }
        }
        inFile2.close();
      }

      // Перезаписываем данные в файл clients.txt
      std::ofstream outFile("C:\\TeamProgect\\clients.txt");
      if (outFile.is_open()) {
        std::istringstream iss2(clientData);
        std::string currentLine;
        while (std::getline(iss2, currentLine)) {
          if (currentLine.find("Phone Number: " + phoneNumber) != std::string::npos) {
            outFile << "Phone Number: " << phoneNum << "\n";
            outFile << "Accrued bonuses " << balance << "\n";
            outFile << "--------------------------\n";
          } else {
            outFile << currentLine << "\n";
          }
        }
        outFile.close();
        std::cout << "Client data has been updated in clients.txt\n";
      } else {
        std::cout << "Unable to open clients.txt for writing\n";
      }

      // Добавляем данные в файл clients_with_bonus.txt
      std::ofstream bonusFile("C:\\TeamProgect\\clients_with_bonus.txt", std::ios::app);
      std::ofstream withoutBonusFile("C:\\TeamProgect\\clients_without_bonus.txt", std::ios::app);
      if (bonusFile.is_open() && withoutBonusFile.is_open()) {
        bonusFile << "Full Name: " << fullName << "\n";
        bonusFile << "Phone Number: " << phoneNum << "\n";
        bonusFile << "Deducted bonus: " << bonusAmount << "\n";
        bonusFile << "--------------------------\n";
        bonusFile.close();
        std::cout << "Client data with deducted bonus has been saved to clients_with_bonus.txt\n";

        withoutBonusFile << "Full Name: " << fullName << "\n";
        withoutBonusFile << "Phone Number: " << phoneNum << "\n";
        withoutBonusFile << "Deducted bonus: " << bonusAmount << "\n";
        withoutBonusFile << "--------------------------\n";
        withoutBonusFile.close();
        std::cout << "Client data with deducted bonus has been saved to clients_without_bonus.txt\n";
      } else {
        std::cout << "Unable to open one or both of the files for writing\n";
      }
    } else {
      std::cout << "Клиент с номером " << phoneNumber << " не найден" << std::endl;
    }
  } else {
    std::cout << "Unable to open clients.txt" << std::endl;
  }
}
