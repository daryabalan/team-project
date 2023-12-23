#ifndef _BILLDETAILS_H_
#define _BILLDETAILS_H_
#include <iostream>
#include <vector>
#include <list>
#include "operation.h"
#include "Client.h"
#include <string>
#include <numeric> //для accumulate()
#include <map>
using namespace std;

///////////////////класс BillDetails(детализация счёта)////////////////////////
//содержит данные об операциях конкретного пользователя
class BillDetails
{
private:
std::map<std::string, BillDetails> clients;
    vector<Operation> operations; // Вектор операций
    //vector<Client> clients; //Вектор клиентов
public:

    float balance;
    // Конструктор, принимающий номер карты, кредит, дебет и баланс
   // BillDetails(string card, int credit, int debit, int balance);

    // Метод для получения даты операции
    tm getDate();

    // Метод для получения типа операции
    string getOperationType();

    // Метод для получения количества бонусов
    int getQuantBonus();
};
#endif // FUNCS_H
