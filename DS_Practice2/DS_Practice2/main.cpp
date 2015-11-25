#include "MainHandler.hpp"

int main(int argc, char **argv)
{
	MainHandler* mainLoop = new MainHandler();
    bool exit = false;
    while(!exit)
        mainLoop->drawMenu(&exit);
	return 0;
}
