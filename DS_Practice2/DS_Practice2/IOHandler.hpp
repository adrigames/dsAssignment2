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
    DList* odd;
    DCList* even;
public:
    IOHandler(DList*, DCList*);
    ~IOHandler();
    void save();
    void load();
    void processNumber(int);
};

#endif // IOHANDLER_HPP
