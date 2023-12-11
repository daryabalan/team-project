#ifndef FUNCS_H
#define FUNCS_H
#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <numeric> //для accumulate()
using namespace std;

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
