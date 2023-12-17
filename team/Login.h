#ifndef _LOGIN_H_
#define _LOGIN_H_
#include <iostream>
#include <vector>
#include <list>
#include "BonusSystem.h"
#include <string>
#include <numeric> //для accumulate()
using namespace std;

///////////////////класс Login(вход в систему)////////////////////////
//обеспечивает доступ к системе при правильно введённых данных
class Login
{
private:
string admin_id;//логин
string password;//пароль
BonusSystem* sysref;
public:
void showLoginMenu();//метод проверки ввода пароля
void ShowMainScreen();//метод обращения к меню бонусной системы
void SetSysRef(BonusSystem* ref);
};
#endif // FUNCS_H
