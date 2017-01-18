#pragma once
#include <list>

using namespace std;

/**
 * Agenda class holds symbols known to be true
 * and symbols infered during chaining.
 * Inheritance from list provides fixed order
 * and constant time insertion.
 */
class Agenda : public list<string>
{
    public:
    Agenda() {};
    ~Agenda() {};

    /**
     * Returns negattion of given predicate.
     * @return negated pred
     */
    static string negated(string pred)
    {
        char neg = '~';
        if(pred.front() == neg)
            return pred.substr(1, pred.size());
        else
            return neg + pred;
    }

    /**
     * Attaches pred to the list only if pred and ~pred
     * are NOT in list already.
     *
     * @return 0 if pred was inserted, 1 if pred already in list,
     *   -1 if ~pred already in list
     */
    int add(string& pred)
    {
        string not_pred = negated(pred);
        for(auto i = this->begin(); i!= this->end(); ++i)
        {
            if(*i == pred)
                return 1;
            else if(*i == not_pred)
                return -1;
        }
        this->push_back(pred);
        return 0;
    }
};
