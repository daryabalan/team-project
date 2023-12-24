#ifndef _YEARLYREPORT_H_
#define _YEARLYREPORT_H_
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
    int totalCreditPoints; // Общее количество начисленных бонусных баллов
    int totalDebitPoints; // Общее количество израсходованных бонусных баллов
    int yearEndBalance; // Баланс на конец года

public:
    // Конструктор, принимающий номер карты, кредит, дебет и баланс
    YearlyReport() {
            // Инициализация по умолчанию
        }

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

    void summarizeClientBonuses(const std::string& phoneNumber);
};
#endif // FUNCS_H
