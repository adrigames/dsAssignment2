#include "MainHandler.hpp"

MainHandler::MainHandler()
{
    this->odd = new DList();
    this->even = new DCList();
    this->io = new IOHandler(this->odd, this->even);
    this->io->load();
}

MainHandler::~MainHandler()         //In case of this object being destroyed
{
    if(this->io != std::NULL)       //Save
    {
        this->io->save();
        }
}

void MainHandler::drawMenu(bool* exit)
{
    system("cls"); //Clean screen 
    int option = -1;
    std::cout<<'\t'<<(char)201<<(char)205<<(char)187<<\
    "Please, select an option:"<<std::endl;
    std::cout<<'\t'<<(char)186<<1<<(char)186<<\
    "PROCESS NUMBER"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<2<<(char)186<<\
    "SHOW LIST"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<3<<(char)186<<\
    "CUT LIST"<<"\t\t"<<std::endl;
    std::cout<<'\t'<<(char)186<<5<<(char)186<<\
    "EXIT"<<"\t\t\t"<<std::endl;
    std::cout<<'\t'<<(char)200<<(char)205<<(char)188<<std::endl<<std::endl;
    std::cout<<"\t\tOption (you can enter batchs. If an option requires an argument, the following number will be taken as such): ";
    if(std::cin>>option){
        std::cout<<std::endl;
        this->processInput(option, exit);
        }
    else
    {
        std::cout<<"INPUT ERROR: INVALID INPUT"<<std::endl; //Throw error
        //Clean buffer
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    system("pause");
    }