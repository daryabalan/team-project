#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
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
    string date; // Дата операции

public:
    // Конструктор, принимающий номер карты, тип операции и количество бонусов
    Operation(string card, string operationType, int quantBonus);

    // Метод для получения даты операции
    string getDate();

    // Метод для установки даты операции
    void setDate(string date);

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
