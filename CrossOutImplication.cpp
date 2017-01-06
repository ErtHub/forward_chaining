#include "CrossOutImplication.h"

using namespace std;

int CrossOutImplication::crossOut(string target)
{
    auto i = premise.find(target);

    if(i==premise.end())
        return -1;
    else
    {
        crossedOutInPremise.insert((*i));
        return 0;
    }
}

bool CrossOutImplication::applies()
{
    return premise.size() <= crossedOutInPremise.size();
}

string CrossOutImplication::getConclusion()
{
    return conclusion;
}
