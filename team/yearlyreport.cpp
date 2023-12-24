#include "YearlyReport.h"

#include "BonusSystem.h"

#include <fstream>

#include <iostream>

#include <sstream>

#include <string>

void YearlyReport::summarizeClientBonuses(const std::string & phoneNumber) {
  int totalBonusAccrued = 0;
  int totalBonusWithoutBonus = 0;

  // Суммируем баллы из файла clients_adding_bonus.txt
  std::ifstream inFileAdding("C:\\TeamProgect\\clients_adding_bonus.txt");
  if (inFileAdding.is_open()) {
    std::string line;
    while (std::getline(inFileAdding, line)) {
      if (line.find("Phone Number: " + phoneNumber) != std::string::npos) {
        if (std::getline(inFileAdding, line) && line.find("Adding bonuses: ") != std::string::npos) {
          int bonus;
          std::istringstream(line.substr(16)) >> bonus;

          totalBonusAccrued += bonus;
        }
      }
    }
    inFileAdding.close();

    std::cout << "Total bonuses accrued for client " << phoneNumber << ": " << totalBonusAccrued << std::endl;
  } else {
    std::cout << "Unable to open clients_adding_bonus.txt" << std::endl;
  }

  // Суммируем баллы из файла clients_without_bonus.txt
  std::ifstream inFileWithoutBonus("C:\\TeamProgect\\clients_without_bonus.txt");
  if (inFileWithoutBonus.is_open()) {
    std::string line;
    while (std::getline(inFileWithoutBonus, line)) {
      if (line.find("Phone Number: " + phoneNumber) != std::string::npos) {
        if (std::getline(inFileWithoutBonus, line) && line.find("Deducted bonus: ") != std::string::npos) {
          int bonus;
          std::istringstream(line.substr(15)) >> bonus;
          totalBonusWithoutBonus += bonus;
        }
      }
    }
    inFileWithoutBonus.close();

    std::cout << "Total bonuses written off from the client " << phoneNumber << ": " << totalBonusWithoutBonus << std::endl;
  } else {
    std::cout << "Unable to open clients_without_bonus.txt" << std::endl;
  }
}
