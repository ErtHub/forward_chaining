#pragma once
#include <iostream>
#include "Chainer.h"

class ForwardChainer : public Chainer
{
    public:
    ForwardChainer(std::set<std::string> agenda_, std::list<CrossOutImplication> knowledge_) : Chainer(agenda_, knowledge_) {};
    virtual ~ForwardChainer() {};
    bool solve();
};
