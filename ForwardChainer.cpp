#include "ForwardChainer.h"

using namespace std;

bool ForwardChainer::solve()
{
    while(!agenda.empty())
    {
        string p = *(agenda.begin());
        agenda.erase(agenda.begin());
        entailed.push_back(p);

        for(auto i:knowledge)
        {
            string q;
            if(i.crossOut(p)==0 && i.applies())
            {
                q = i.getConclusion();
                agenda.insert(q);
                if(q==ask)
                    return true;
                agenda.insert(q);
            }
        }
    }
    return false;
}
//TODO: constructors, destructors, data extraction
