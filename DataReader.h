#pragma once
#include <iostream>
#include <string>
#include <list>
#include "CrossOutImplication.h"
#include "Agenda.h"

namespace DataReader
{
    int readData(std::istream& is, Agenda& agenda, std::list<CrossOutImplication>& knowledge);
}
