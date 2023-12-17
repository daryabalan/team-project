#ifndef _BONUSYSTEM_H_
#define _BONUSYSTEM_H_
#include <iostream>
#include <vector>
#include <list>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include "BillDetails.h"
#include "ClientList.h"
#include "YearlyReport.h"
#include <ctime>
#include <string>
#include <numeric> //для accumulate()
using namespace std;
///////////////////класс BonusSystem(бонусная система)////////////////////////
class BonusSystem
{
private:
    vector<YearlyReport>yearlyReports; // Вектор годовых отчетов
    vector<BillDetails>Clients; // Вектор деталей счета
    vector<ClientList>ClientLists; //Вектор списка клиентов
public:

    // Метод для регистрации новой карты
    void registerNewCard(string lastName, string firstName, string phoneNumber);

    // Метод для генерации номера карты
    string generateCardNumber();

    // Метод для отображения экрана входа в систему
    void showLoginMenu();//метод проверки ввода пароля

    // Метод для начисления бонусов
    void accrueBonus(string cardNumber, int bonus);

    // Метод для списания бонусов
    void debitBonus(string cardNumber, int bonus);

    // Метод для генерации годового отчета
    void generateYearlyReport(string cardNumber);

    // Метод для получения баланса по номеру карты
    int getBalance(string cardNumber);

    // Метод для отображения таблицы годовых отчетов
    void displayYearlyReportsTable();

    // Метод для отображения таблицы деталей счета
    void displayBillDetailsTable();

    // Метод для получения входных данных
    void getLogin();
};

#endif // FUNCS_H
