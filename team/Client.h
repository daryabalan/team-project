#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;

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
