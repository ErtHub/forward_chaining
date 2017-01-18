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

        /* cross out p from rules which have p in their premises set */
        for(auto i = knowledge.begin(); i!=knowledge.end(); ++i)
        {
            string q;
            int t;

            /* if whole premises set was crossed out, rule's conclusion has been inferred */
            if((t=i->crossOut(p))==0 && i->applies())
            {
                /* save rule's premises so that they could be printed later */
                set<string> premise = i->getPremise();
                entailed.insert(entailed.end(), premise.begin(), premise.end());
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
