#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;

///////////////////класс BillDetails(детализация счёта)////////////////////////
//содержит данные об операциях конкретного пользователя
class BillDetails
{
private:
    vector<Operation> operations; // Вектор операций
    vector<Client> clients; //Вектор клиентов
public:
    // Конструктор, принимающий номер карты, кредит, дебет и баланс
    BillDetails(string card, int credit, int debit, int balance);

    // Метод для получения даты операции
    date getDate();

    // Метод для получения типа операции
    string getOperationType();

    // Метод для получения количества бонусов
    int getQuantBonus();
};
#endif // FUNCS_H
