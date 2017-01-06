#include "DataReader.h"

using namespace std;

int DataReader::readData(istream& is, set<string>& agenda, list<CrossOutImplication>& knowledge)
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
                conditions.insert(sbstr.substr(sbstart, sbend-sbstart));
                sbstart = sbend + conj.length();
                sbend = sbstr.find(conj, sbstart);
            }
            conditions.insert(sbstr.substr(sbstart, sbend));
            start = end + ifThen.length();
            end = string::npos;
        }

        sbstr = str.substr(start, end);
        start = 0U;
        end = sbstr.find(conj);
        while(end!=string::npos)
        {
            statements.insert(sbstr.substr(start, end-start));
            start = end + conj.length();
            end = sbstr.find(conj, start);
        }
        statements.insert(sbstr.substr(start, end));

        if(conditions.empty())
        {
            for(auto i:statements)
                agenda.insert(i);
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
