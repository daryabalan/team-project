#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;

///////////////////класс Login(вход в систему)////////////////////////
//обеспечивает доступ к системе пре правильно введённых данных
class Login
{
private:
string admin_id;//логин
string password;//пароль
public:
bool validateUserCredentials();//проверка пароля
void showLoginMenu();//метод проверки ввода пароля
void ShowMainScreen();//метод обращения к меню бонусной системы
};
#endif // FUNCS_H
