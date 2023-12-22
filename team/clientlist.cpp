#include "Client.h"
#include "ClientList.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include <ctime>


 /*void ClientList::addClient(Client newClient){
     std::unordered_map<std::string,float> cardMap;
     std::unordered_map<std::string,float>::iterator mapIter;
     cardMap[newClient.cardNumber] = newClient.balance;
     while (mapIter != cardMap.end()){
         std::cout << mapIter->first << " " << mapIter->second<<endl;
         ++mapIter;
     }
 }*/

 void ClientList::addClient(Client newClient){
     std::ofstream file("D:\\Github rep\\Project\\team-project\\clientList.txt", std::ios::app);
 }


