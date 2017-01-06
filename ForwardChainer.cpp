#include "ForwardChainer.h"

using namespace std;

bool ForwardChainer::solve()
{
    while(!agenda.empty())
    {
        string p = *(agenda.begin());
        agenda.erase(agenda.begin());
        entailed.push_back(p);

        for(auto i = knowledge.begin(); i!=knowledge.end(); ++i)
        {
            //i->print();
            string q;
            int t;
            if((t=i->crossOut(p))==0 && i->applies())
            {
                q = i->getConclusion();
                if(q==ask)
                    return true;
                agenda.insert(q);
            }
            //cout << t << endl;
            //if(i->applies()) cout << "mati" << endl;
        }
    }
    return false;
}
//TODO: data extraction
