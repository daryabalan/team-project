#include "ClientList.h"

#include "BonusSystem.h"

#include <fstream>

#include <iostream>

#include <sstream>  // Added for std::istringstream

#include <string>   // Added for std::stoi

void ClientList::viewAllClientsData() {
  std::ifstream inFile("C:\\TeamProgect\\clients.txt");
  if (inFile.is_open()) {
    std::string line;
    while (std::getline(inFile, line)) {
      std::cout << line << std::endl;
    }
    inFile.close();
  } else {
    std::cout << "Unable to open clients.txt" << std::endl;
  }
}

void ClientList::viewOperationsByPhoneNumber(const std::string & phoneNumber) {//детализация карты
  std::ifstream inFile("C:\\TeamProgect\\clients_with_bonus.txt");
  if (inFile.is_open()) {
    bool found = false;
    std::string line;
    while (std::getline(inFile, line)) {
      if (line.find("Phone Number: " + phoneNumber) != std::string::npos) {
        found = true;
        std::cout << line << std::endl; // Выводим информацию о клиенте
        // Читаем и выводим операции, связанные с этим номером телефона
        while (std::getline(inFile, line) && line != "--------------------------") {
          std::cout << line << std::endl;
        }
        // Продолжаем поиск и вывод операций для других клиентов
      }
    }
    inFile.close();
    if (!found) {
      std::cout << "Client with phone number " << phoneNumber << " not found" << std::endl;
    }
  } else {
    std::cout << "Unable to open clients_with_bonus.txt" << std::endl;
  }
}
