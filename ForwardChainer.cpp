#include "ForwardChainer.h"

using namespace std;

bool ForwardChainer::solve()
{
    for(auto it = agenda.begin(); it != agenda.end(); ++it)
    {
        string p = *it;
        if(p==Agenda::negated(ask))
        {
            cout << "Udowodniono nieprawdziwość tezy." << endl;
            return false;
        }
        else if(p==ask)
            return true;

        entailed.push_back(p);

        for(auto i = knowledge.begin(); i!=knowledge.end(); ++i)
        {
            //i->print();
            string q;
            int t;
            if((t=i->crossOut(p))==0 && i->applies())
            {
                q = i->getConclusion();
                if(q==Agenda::negated(ask))
                {
                    cout << "Udowodniono nieprawdziwość tezy." << endl;
                    return false;
                }
                else if(q==ask)
                    return true;

                if(agenda.add(q) < 0)
                    cout << "Uwaga: wykryto sprzeczność: " << q << " & " << Agenda::negated(q) << endl;;
            }
        }
    }
    return false;
}
//TODO: data extraction
