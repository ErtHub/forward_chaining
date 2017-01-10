#pragma once
#include <list>

using namespace std;

class Agenda : public list<string>
{
    public:
    Agenda() {};
    ~Agenda() {};

    static string negated(string pred)
    {
        char neg = '~';
        if(pred.front() == neg)
            return pred.substr(1, pred.size());
        else
            return neg + pred;
    }

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
