#include "Login.h"

#include <iostream>

int main() {
  Login login;

  string adminId = "111";
  string adminPassword = "1111";

  // Ввод данных от пользователя
  cout << "Enter your id: ";
  string enteredId;
  cin >> enteredId;

  cout << "Enter your password: ";
  string enteredPassword;
  cin >> enteredPassword;

  // Проверка введенных данных
  if (enteredId == adminId && enteredPassword == adminPassword) {

    login.ShowMainScreen();
  } else {
    // В противном случае выводим сообщение об ошибке
    cout << "Error! Check your id and password if it write correcly\n";
  }

  return 0;
}
