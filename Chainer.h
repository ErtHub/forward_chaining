#pragma once
#include <set>
#include <list>
#include <string>
#include "CrossOutImplication.h"
#include "Agenda.h"

/**
 * Abstract chainer class holds data needed
 * for the process of chaining (inference).
 */
class Chainer
{
    protected:
    /** Goal chainer is supposed to infer */
    std::string ask;
    /** Agenda class */
    Agenda agenda;
    /* List of rules */
    std::list<CrossOutImplication> knowledge;
    /* List of symbols which led to achieve goal */
    std::list<std::string> entailed;

    public:
    /**
     * Constructor that makes own copies of given agenda and rules list.
     * @param agenda_ Agenda to be copied into chainer
     * @param knowledge_ List of rules to be copied into chainer
     */
    Chainer(Agenda agenda_, std::list<CrossOutImplication> knowledge_);
    /**
     * Virtual destructor.
     */
    virtual ~Chainer() {};
    /**
     * Sets chainers ask.
     * @param ask_ Ask to be set
     */
    void setAsk (std::string ask_);
    /**
     * Copies given agenda and knowledge to chainers members.
     * @param agenda_ Agenda to be copied
     * @param knowledge_ List of rules to be copied
     */
    void putData(Agenda agenda_, std::list<CrossOutImplication> knowledge_);
    /**
     * Returns list of symbols which led to achieve goal.
     * @return list of symbols
     */
    std::list<std::string> getEntailed();
    /**
     * Deletes all the data from agenda, knowledge, entailed and ask.
     */
    void clear();
    /**
     * Performs chaining.
     */
    virtual bool solve() = 0;
};
