#ifndef _BONUSYSTEM_H_
#define _BONUSYSTEM_H_

#include <iostream>

#include <vector>

#include "ClientList.h"

#include "YearlyReport.h"

#include <string>

#include <map>

class BonusSystem {

  int bonus; // бонусы
  std::vector < YearlyReport > yearlyReports;
  std::vector < ClientList > clientLists;

  public:
  void findClientByNumberAndAddBonus(const std::string & phoneNumber, int bonusAmount);//метод для начисления бонусов по номеру телефона
  void registerNewCard(std::string lastName, std::string firstName, std::string phoneNumber);//регистрация новой карты
  void showLoginMenu();
  void displayYearlyReportsTable();
  void displayBillDetailsTable();
  void getLogin();
  void saveToFile();
  void findClientByNumberAndDeductBonus(const std::string & phoneNumber, int bonusAmount);
};

#endif // _BONUSYSTEM_H_
