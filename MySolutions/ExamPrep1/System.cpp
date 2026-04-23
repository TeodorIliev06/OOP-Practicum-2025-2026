#include "System.h"

System& System::getInstance()
{
    static System instance;
    return instance;
}