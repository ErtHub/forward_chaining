#pragma once
#include <set>
#include <list>
#include <string>
#include "CrossOutImplication.h"

class Chainer
{
    protected:
    std::string ask;

    std::set<std::string> agenda;

    //std::list<std::string> facts;
    std::list<CrossOutImplication> knowledge;
    //std::list<int> count;
    std::list<std::string> entailed;

    public:
    Chainer(std::set<std::string> agenda_, std::list<CrossOutImplication> knowledge_);
    virtual ~Chainer() {};
    void setAsk (std::string ask_);
    void putData(std::set<std::string> agenda_, std::list<CrossOutImplication> knowledge_);
    std::list<std::string> getEntailed();
    void clear();
    virtual bool solve() = 0;
};
