#ifndef _CLIENTLIST_H_
#define _CLIENTLIST_H_
#include <iostream>
#include <vector>
#include "Client.h"
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
void viewAllClientsData();
void viewOperationsByPhoneNumber(const std::string& phoneNumber);
    // Метод для добавления нового клиента в список
    void addClient(Client newClient);
};
#endif // FUNCS_H
