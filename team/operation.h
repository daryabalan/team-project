#ifndef _OPERATION_H_
#define _OPERATION_H_
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <ctime>
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
    tm date; // Дата операции

public:
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

    // Метод для получения номера карты
    string getCardNumber();

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
};

#endif // FUNCS_H
