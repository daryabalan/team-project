#include "BonusSystem.h"
#include <cstdlib>
#include <ctime>
#include <sstream>

std::string BonusSystem::generateCardNumber() {
    srand(static_cast<unsigned int>(time(0)));  // Инициализация генератора случайных чисел
    stringstream ss;

    // Генерация 10-значного случайного числа
    for (int i = 0; i < 10; ++i) {
        ss << rand() % 10;
    }

    return ss.str();
}
