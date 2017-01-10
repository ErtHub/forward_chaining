#include "DataReader.h"
#include <algorithm>

using namespace std;

string eliminateNegation(string&& s)
{
    char neg = '~';
    int counter = count(s.begin(), s.end(), neg);
    if(counter%2==0)
        return s.substr(s.rfind(neg) + 1, s.size());
    else
        return s.substr(s.rfind(neg), s.size());
}

int DataReader::readData(istream& is, Agenda& agenda, list<CrossOutImplication>& knowledge)
{
    string str, sbstr;
    string ifThen = "=>";
    string conj = "&";
    set<string> conditions, statements;

    while(is.good() && getline(is, str))
    {
        if(str.empty())
            break;
        auto start = 0U;
        auto end = str.find(ifThen);
        if(end!=string::npos)
        {
            sbstr = str.substr(start, end-start);
            auto sbstart = 0U;
            auto sbend = sbstr.find(conj);
            while(sbend!=string::npos)
            {
                conditions.insert(eliminateNegation(sbstr.substr(sbstart, sbend-sbstart)));
                sbstart = sbend + conj.length();
                sbend = sbstr.find(conj, sbstart);
            }
            conditions.insert(eliminateNegation(sbstr.substr(sbstart, sbend)));
            start = end + ifThen.length();
            end = string::npos;
        }

        sbstr = str.substr(start, end);
        start = 0U;
        end = sbstr.find(conj);
        while(end!=string::npos)
        {
            statements.insert(eliminateNegation(sbstr.substr(start, end-start)));
            start = end + conj.length();
            end = sbstr.find(conj, start);
        }
        statements.insert(eliminateNegation(sbstr.substr(start, end)));

        if(conditions.empty())
        {
            for(auto i:statements)
            {
                if(agenda.add(i) < 0)
                    cout << "Uwaga: wykryto sprzeczność: " << i << " & " << Agenda::negated(i) << endl;
            }
        }
        else
        {
            for(auto i:statements)
                knowledge.push_back(CrossOutImplication(conditions, i));
        }

        conditions.clear();
        statements.clear();
    }
    return 0;
}
