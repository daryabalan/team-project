#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;

///////////////////класс YearlyReport(Годовой отчёт)////////////////////////
//содержит годовой отчёт по операциям карт

class YearlyReport
{
private:
    vector<Operation> operations; // Вектор операций
    int totalCreditPoints; // Общее количество начисленных бонусных баллов
    int totalDebitPoints; // Общее количество израсходованных бонусных баллов
    int yearEndBalance; // Баланс на конец года

public:
    // Конструктор, принимающий номер карты, кредит, дебет и баланс
    YearlyReport(string card, int credit, int debit, int balance);

    // Метод для получения номера карты
    string getCardNumber();

    // Метод для установки номера карты
    void setCardNumber(string card);

    // Метод для получения общего количества начисленных бонусных баллов
    int getTotalCreditPoints();

    // Метод для установки общего количества начисленных бонусных баллов
    void setTotalCreditPoints(int credit);

    // Метод для получения общего количества израсходованных бонусных баллов
    int getTotalDebitPoints();

    // Метод для установки общего количества израсходованных бонусных баллов
    void setTotalDebitPoints(int debit);

    // Метод для получения баланса на конец года
    int getYearEndBalance();

    // Метод для установки баланса на конец года
    void setYearEndBalance(int balance);
};
#endif // FUNCS_H
