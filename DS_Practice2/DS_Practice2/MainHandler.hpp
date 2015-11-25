#ifndef MAINHANDLER_HPP
#define MAINHANDLER_HPP

#include "DList.hpp"
#include "DCList.hpp"
#include "IOHandler.hpp"
#include <iostream>
#include <windows.h>

class MainHandler
{
private:
    DList* odd;
    DCList* even;
    IOHandler* io;
    
    void processInput(int, *bool);
    int selectList(void);
    void showList(void);
    void cutList(int);
    bool confirmExit(void);
    void Exit(bool*);
public:
    MainHandler();
    ~MainHandler();
    void drawMenu(bool*);

};

#endif // MAINHANDLER_HPP
