#pragma once
#include "Implication.h"
#include <iostream>
#include <map>

class CrossOutImplication : private Implication
{
    private:
    std::set<std::string> crossedOutInPremise;

    public:
    CrossOutImplication() = delete;
    CrossOutImplication(std::set<std::string> premise_, std::string conclusion_);
    int crossOut(std::string target);
    bool applies();
    std::string getConclusion();
    /*void print()
    {
        for(auto i:premise)
            std::cout << i;
        std::cout << " : ";
        std::cout << conclusion << std::endl;
    }*/
};
