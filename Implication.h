#pragma once
#include <string>
#include <set>

/* Struct representing an implication */
typedef struct Implic
{
    /* Multiple unique premises */
    std::set<std::string> premise;
    /* Single conlusion */
    std::string conclusion;
} Implication;
