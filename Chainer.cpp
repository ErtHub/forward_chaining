#include "Chainer.h"

using namespace std;

void Chainer::putData(string ask_, set<string> agenda_, list<CrossOutImplication> knowledge_, list<string> entailed_)
{
    clear();
    ask=ask_;
    agenda=agenda_;
    knowledge=knowledge_;
    entailed=entailed_;
}

void Chainer::clear()
{
    ask.clear();
    agenda.clear();
    knowledge.clear();
    entailed.clear();
}
