#pragma once
#include "Implication.h"
#include <iostream>
#include <map>

/**
 * Class represents implication with symbols
 * that was crossed out form its premise set.
 */
class CrossOutImplication : private Implication
{
    private:
    /* Set of symbols crossed out from implication premise set */
    std::set<std::string> crossedOutInPremise;

    public:
    /**
     * Deleted deafult constructor.
     */
    CrossOutImplication() = delete;
    /**
     * Constructor that makes own copies of given premise set and conclusion.
     * @param premise_ Premise set to be copied into chainer
     * @param conclusion_ Conclusion to be copied into chainer
     */
    CrossOutImplication(std::set<std::string> premise_, std::string conclusion_);
    /**
     * Marks given target as crossed out if target belongs to implication premise set.
     * @param target Symbol to be crossed out from implication
     * @return 0 if taget has been crossed out, -1 otherwise
     */
    int crossOut(std::string target);
    /**
     * Checks if all of implation's premises was crossed out.
     * @return true if all symbols in premise was crossed out, false otherwise
     */
    bool applies();
    /**
     * Returns implication premise set.
     * @return premise set
     */
	std::set<std::string> getPremise();
    /**
     * Returns implication conclusion.
     * @return conclusion
     */
    std::string getConclusion();
};
