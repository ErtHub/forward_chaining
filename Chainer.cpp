#include "Chainer.h"

using namespace std;

Chainer::Chainer(set<string> agenda_, list<CrossOutImplication> knowledge_)
{
    putData(agenda_, knowledge_);
}

void Chainer::setAsk(string ask_)
{
    ask=ask_;
}

void Chainer::putData(set<string> agenda_, list<CrossOutImplication> knowledge_)
{
    agenda=agenda_;
    knowledge=knowledge_;
    entailed.clear();
}

list<string> Chainer::getEntailed()
{
    return entailed;
}

void Chainer::clear()
{
    ask.clear();
    agenda.clear();
    knowledge.clear();
    entailed.clear();
}
