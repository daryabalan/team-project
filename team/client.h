#ifndef CLIENT_H
#define CLIENT_H

#include <string>

class Client {
public:
    std::string fullName;
    std::string phoneNumber;
    std::string cardNumber;

    void generateCardNumber();
    void saveToFile();
    void setFullName(const std::string& name);
    void setPhoneNumber(const std::string& number);
};
#endif









