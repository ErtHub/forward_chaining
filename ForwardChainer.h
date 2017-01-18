#pragma once
#include <iostream>
#include "Chainer.h"

/**
 * Forward chainer class.
 */
class ForwardChainer : public Chainer
{
    public:
    /**
     * Constructor that makes own copies of given agenda and rules list.
     * @param agenda_ Agenda to be copied into chainer
     * @param knowledge_ List of rules to be copied into chainer
     */
    ForwardChainer(Agenda agenda_, std::list<CrossOutImplication> knowledge_) : Chainer(agenda_, knowledge_) {};
    /**
     * Virtual destructor.
     */
    virtual ~ForwardChainer() {};
    /**
     * Performs chaining.
     * @return true if goal was inferred, false if goal couldn't be inferred
     * or if it was inferred that goal is not true.
     */
    bool solve();
};
