#include "Client.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>

// Реализация метода установки полного имени
void Client::setFullName(const std::string& name) {
    fullName = name;
}

// Реализация метода установки номера телефона
void Client::setPhoneNumber(const std::string& number) {
    phoneNumber = number;
}

void Client::generateCardNumber() {
    // Генерация уникального номера карты на основе текущего времени
    std::stringstream ss;
    ss << time(0);
    cardNumber = ss.str();
}


void Client::saveToFile() {
    std::ofstream file("C:\\TeamProgect\\clients.txt", std::ios::app); // Указываем полный путь к файлу
    if (file.is_open()) {
        // Запись данных в файл
        file << "Full Name: " << fullName << "\n";
        file << "Phone Number: " << phoneNumber << "\n";
        file << "Bonus balance: " <<balance<< "\n";
        file << "Card Number: " << cardNumber << "\n";
        file << "--------------------------\n";
        file.close();  // Закрытие файла после записи
        std::cout << "Client data has been saved to file\n";
    } else {
        std::cout << "Unable to open file for writing\n";
    }
}
