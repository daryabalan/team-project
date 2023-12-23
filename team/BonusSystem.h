#ifndef _BONUSYSTEM_H_
#define _BONUSYSTEM_H_

#include <iostream>
#include <vector>
#include "BillDetails.h"
#include "ClientList.h"
#include "YearlyReport.h"
#include <string>
#include <map>

class BonusSystem
{
private:
    std::map<std::string, BillDetails> clients;
    float bonus; // Declare the bonus variable
    std::vector<YearlyReport> yearlyReports;
    std::vector<ClientList> clientLists;

public:
    void depositBonus(const std::string& clientName, float bonusAmount);
    void withdrawBonus(const std::string& clientName, float bonusAmount);
    void findClientByNumberAndAddBonus(const std::string& phoneNumber, int bonusAmount);
    void registerNewCard(std::string lastName, std::string firstName, std::string phoneNumber);
    std::string generateCardNumber();
    void showLoginMenu();
    void debitBonus(std::string cardNumber, int bonus);
    void generateYearlyReport(std::string cardNumber);
    int getBalance(std::string cardNumber);
    void displayYearlyReportsTable();
    void displayBillDetailsTable();
    void getLogin();
    void saveToFile();
};

#endif // _BONUSYSTEM_H_
