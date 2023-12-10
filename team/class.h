#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;
//////////////////// глобальные методы //////////////////////
void getaLine(string& inStr); // получение строки текста
char getaChar(); // получение символа
//////////////////// класс Client (клиенты) //////////////////
//Он хранит Фамилию, Имя, номер телефона, номер карты, баланс карты клиента.
class Client
{
private:
    string first_name; // имя клиента
    string last_name; // фамилия клиента
    string phone_number; //номер телефона
    string card_number; //номер карты
    int balance; //баланс бонусов

public:
    // Конструктор, инициализирующий фамилию, имя, номер телефона, номер карты и начальный баланс
    Client(string last, string first, string phone, string card, int balance)
        : last_name(last), first_name(first), phone_number(phone), card_number(card), balance(balance) {}

    // Деструктор класса
    ~Client() {}

    // Методы доступа к фамилии и установки фамилии клиента
    string getLastName();
    void setLastName(string last);

    // Методы доступа к имени и установки имени клиента
    string getFirstName();
    void setFirstName(string first);

    // Методы доступа к номеру телефона и установки номера телефона клиента
    string getPhoneNumber();
    void setPhoneNumber(string phone);

    // Методы доступа к номеру карты и установки номера карты клиента
    string getCardNumber();
    void setCardNumber(string card);

    // Методы доступа к балансу и установки баланса бонусов клиента
    int getBalance();
    void setBalance(int balance);
};
///////////////////класс ClientList(таблица клиентов)////////////////////////
//Хранит список всех клиентов.
class ClientList
{
private:
vector<Client> clients; // Вектор для хранения клиентов
public:

    // Деструктор
    ~ClientList();

    // Метод для добавления нового клиента в список
    void addClient(Client newClient);

    // Метод для удаления клиента из списка по номеру карты
    void deleteClientByCardNumber(string cardNumber);
};

///////////////////класс Login(вход в систему)////////////////////////
//обеспечивает доступ к системе пре правильно введённых данных
class Login
{
private:
string admin_id;//логин
string password;//пароль
public:
void Show_MainScreen(); // показать главное меню
};

#endif // FUNCS_H

