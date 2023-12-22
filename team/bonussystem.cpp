#include "BonusSystem.h"

string BonusSystem::generateCardNumber(){
stringstream ss;
ss << time(0);
return ss.str();
}

void BonusSystem::readBalance() {

}

