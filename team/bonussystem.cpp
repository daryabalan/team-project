#include "BonusSystem.h"
#include <iostream>
#include <vector>
using namespace std;
void BonusSystem::registerNewCard(string lastName, string firstName, string phoneNumber) {
    // код регистрации карты
}

string BonusSystem::generateCardNumber() {
    // генерация номера карты
    return ""; // актуальный номер карты
}

void BonusSystem::showLoginScreen() {
    // код входа
}

void BonusSystem::accrueBonus(string cardNumber, int bonus) {
    // код
}

void BonusSystem::debitBonus(string cardNumber, int bonus) {
    // код
}

void BonusSystem::generateYearlyReport(string cardNumber) {
    // код
}

int BonusSystem::getBalance(string cardNumber) {
    // код
    return 0; // Replace with actual balance
}

void BonusSystem::displayYearlyReportsTable() {
    // код
}

void BonusSystem::displayBillDetailsTable() {
    // код
}

void BonusSystem::showMainScreen() {
    cout << "Выберите одну из следующих опций:\n";
    cout << "1. Регистрация новой карты\n";
    cout << "2. Начисление бонусов\n";
    cout << "3. Списание бонусов\n";
    cout << "4. Генерация годового отчета\n";
    cout << "5. Просмотр баланса\n";
    cout << "6. Просмотр таблицы годовых отчетов\n";
    cout << "7. Просмотр таблицы деталей счета\n";
    cout << "8. Выход из программы\n";
}

void BonusSystem::getLogin() {
    // код
}
