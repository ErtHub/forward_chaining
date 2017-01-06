#pragma once
#include <iostream>
#include <string>
#include <list>
#include "CrossOutImplication.h"

namespace DataReader
{
    int readData(std::istream& is, std::set<std::string>& agenda, std::list<CrossOutImplication>& knowledge);
}
