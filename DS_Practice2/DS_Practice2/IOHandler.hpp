#ifndef IOHANDLER_HPP
#define IOHANDLER_HPP

#include "DList.hpp"
#include "DCList.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

class IOHandler
{
public:
    IOHandler();
    ~IOHandler();
    void save(DList*, DCList*);
    void load(DList*, DCList*);
};

#endif // IOHANDLER_HPP
