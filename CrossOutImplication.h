#include "Implication.h"

class CrossOutImplication : private Implication
{
    private:
    std::set<std::string> crossedOutInPremise;

    public:
    int crossOut(std::string target);
    bool applies();
    std::string getConclusion();
};
