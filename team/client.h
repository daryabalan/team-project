#ifndef CLIENT_H
#define CLIENT_H

#include <string>
#include <iostream>

class Client {
public:
    std::string fullName;
    std::string phoneNumber;
    std::string cardNumber;
    float balance;

    void generateCardNumber();
    void saveToFile();
    void setFullName(const std::string& name);
    void setPhoneNumber(const std::string& number);
    //void setBalance(float& balance);
};
#endif
