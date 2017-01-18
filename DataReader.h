#pragma once
#include <iostream>
#include <string>
#include <list>
#include "CrossOutImplication.h"
#include "Agenda.h"

namespace DataReader
{
    /**
     * Reads data from input stream and puts it into given agenda and knowledge list.
     * Data is expected to be in format which is recognized by the reader, that is:
     * Each fact (a letter) shuld be placed in new line or grouped into conjunction
     * like this:
     * a
     * b&~c&g
     * ~e
     * Negated symbol is prepended with symbol '~' (look above).
     * Rules are given as implications with single conlusion symbol and one or more
     * premise symbols. Like this:
     * b=>e
     * ~z&q=>p
     * Reader warns if given data contains contradiction. Behaviour of reader
     * for data that has wrong format is undefined.
     * @param is Input stream to read from
     * @param agenda Agenda class to be filled with symbols read from stream
     * @param knowledge List of rules to be filled with rules read from stream
     */
    void readData(std::istream& is, Agenda& agenda, std::list<CrossOutImplication>& knowledge);
}
