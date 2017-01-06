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
    //cout << target << endl;
    auto i = premise.find(target);

    if(i==premise.end())
        return -1;
    else
    {
        crossedOutInPremise.insert(target);
        /*for(auto j:crossedOutInPremise)
            cout << j;
        cout << endl;*/
        return 0;
    }
}

bool CrossOutImplication::applies()
{
    //cout << premise.size() << " " << crossedOutInPremise.size() << endl;
    return premise.size() <= crossedOutInPremise.size();
}

string CrossOutImplication::getConclusion()
{
    return conclusion;
}
