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
    void putData(std::string ask_, std::set<std::string> agenda_, std::list<CrossOutImplication> knowledge_, std::list<std::string> entailed_);
    void clear();
    virtual bool solve() = 0;
};
