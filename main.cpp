#include <iostream>
#include <set>
#include <list>
#include <string>
#include <fstream>
#include "DataReader.h"
#include "ForwardChainer.h"

using namespace std;

int main()
{
    string ask, path;
    bool answer;
    Agenda agenda;
    list<CrossOutImplication> knowledge;
    list<string> entailed;
    ifstream ifs;

    cout << "Sciezka do pliku z wiedza:" << endl;
    cin >> path;

    ifs.open(path, ifstream::in);

    if(ifs.good())
        DataReader::readData(ifs, agenda, knowledge);
    else
    {
        cout << "Blad odczytu pliku." << endl;
        ifs.close();
        return -1;
    }
    ifs.close();

    ForwardChainer chainer(agenda, knowledge);

    cout << "Zapytanie:" << endl;
    cin >> ask;
    chainer.setAsk(ask);
    answer = chainer.solve();
    entailed = chainer.getEntailed();
    auto iter = entailed.begin();
    string chain = (*iter);

    for(++iter; iter!=entailed.end(); ++iter)
    {
        chain+=", ";
        chain+=(*iter);
    }

    if(answer)
        cout << "Tak: ";
    else
        cout << "Nie: ";

    cout << chain << endl;

    return 0;
}
