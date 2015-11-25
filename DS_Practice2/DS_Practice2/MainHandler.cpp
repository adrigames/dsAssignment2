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
    if(this->io != NULL)       //Save
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
    std::cout<<'\t'<<(char)186<<4<<(char)186<<\
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

void MainHandler::processInput(int option, bool* exit)
{
    //Once option is captured, process and execute it.
{
    switch(option)
    {
        case 1: this->processnumber();                          //Option 1: insert a new number
                break;
        case 2: this->showList();
                break;
        case 3: break;
        case 4: break;
        default: std::cout<<"Invalid option.\nInsert new option."<<std::endl;
        }
    return;
    }
}
    
void MainHandler::processnumber()
//Process number function
{
    long int input = 0;
    do
    {
        if(std::cin.fail())
        {
            std::cout<<"Invalid input detected.\nPlease, insert number."<<std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            }
        std::cout<<"Enter number: "<<std::endl;
        std::cin>>input;
        }while(std::cin.fail());
        this->io->processNumber(input);
    }

int MainHandler::selectList()
{
    int retrn = 0;
    std::cout<<"Select a list (1: odd numbers; 2: even numbers): "<<std::endl;
    std::cin >> retrn;
    return retrn;
    }

bool MainHandler::selectOrder()
{
    int order = 0;
    std::cout<<"Select an order (1: regular; 2: reverse): "<<std::endl;
    std::cin >> order;
    if(order == 1) return false;
    else if (order == 2) return true;
    else {
        std::cout<<"Invalid option. Please, try again."<<std::endl;
        return this->selectOrder();
        }
    }

void MainHandler::showList()
{
    int list = this->selectList();
    switch(list)
    {
        case 1: 
        try{
            std::cout<<this->odd->list(this->selectOrder())<<std::endl;
        } catch(std::runtime_error r){
            std::cout<<"List is empty!"<<std::endl;
            }
        break;
        
        case 2:
            try{
                std::cout<<this->even->list(this->selectOrder())<<std::endl;
            }catch(std::runtime_error r)
            {
                std::cout<<"List is empty!"<<std::endl;
                }
        break;
        
        default: this->showList();
        break;
        }
    }