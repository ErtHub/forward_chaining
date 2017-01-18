#include "CrossOutImplication.h"

using namespace std;

CrossOutImplication::CrossOutImplication(std::set<std::string> premise_, std::string conclusion_)
{
    premise=premise_;
    conclusion=conclusion_;
    crossedOutInPremise.clear();
}

int CrossOutImplication::crossOut(string target)
{
    auto i = premise.find(target);

    if(i==premise.end())
        return -1;
    else
    {
        crossedOutInPremise.insert(target);
        return 0;
    }
}

bool CrossOutImplication::applies()
{
    return premise.size() <= crossedOutInPremise.size();
}

set<string> CrossOutImplication::getPremise()
{
	return premise;
}

string CrossOutImplication::getConclusion()
{
    return conclusion;
}
