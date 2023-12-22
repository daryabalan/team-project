#ifndef _OPERATION_H_
#define _OPERATION_H_
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
#include "Client.h"
#include <numeric> //для accumulate()
using namespace std;
///////////////////класс Operation(операции)////////////////////////
//содержит данные обо всех операциях
class Operation
{
private:
    string cardNumber; // Номер карты
    string operationType; // Тип операции
    int quantBonus; // Количество бонусов
    int CurrentBalance; //Текущий баланс
    tm date; // Дата операции

public:
    float balance;

    // Конструктор, принимающий номер карты, тип операции и количество бонусов
    Operation(string card, string operationType, int quantBonus);

    // Метод для получения даты операции
    tm getDate();

    // Метод для установки даты операции
    void setDate(tm date);

    // Метод для вывода деталей операции
    void operation_details();

    // Метод для проведения транзакции
    void transaction_operation();

    // Метод для установки номера карты
    void setCardNumber(string card);

    // Метод для получения типа операции
    string getOperationType();

    // Метод для установки типа операции
    void setOperationType(string type);

    // Метод для получения количества бонусов
    int getQuantBonus();

    // Метод для установки количества бонусов
    void setQuantBonus(int bonus);

    std::string getCardNumber() const {
           return cardNumber;
       }

       float getBalance() const {
           return balance;
       }
     void writeToFile(const std::string& cardNumber, const std::string& operationType, int quantBonus, float currentBalance, const Client& client, float amount);
};

#endif // FUNCS_H
