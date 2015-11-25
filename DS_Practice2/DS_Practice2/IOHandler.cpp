#include "IOHandler.hpp"

IOHandler::IOHandler(DList* odd, DCList* even)
{
    this->odd = odd;
    this->even = even;
}

IOHandler::~IOHandler()
{
}

void IOHandler::save()
{
    std::ofstream output;
    std::string data = "";
    try{
    data += this->odd->list(false);
    data += "\n";
    data += this->even->list(false);
    data += "\n";
    }catch(std::runtime_error)
    {
        std::cout<<"At least one of the lists is empty.\n"\
                    "The program will try to save existing data."<<std::endl;
        }
    output.open("output.numbers.txt");
    if(output.is_open())
    {
        output<<data;
        std::cout<<"Data saved successfuly"<<std::endl;
        output.close();
        }
    else
    {
        std::cout<<"ERROR: COULD NOT WRITE FILE"<<std::endl;
        }
    }
    
void IOHandler::load()
{
    std::ifstream input;
    input.open("input.numbers.txt");
    if(input.is_open())
    {
        std::string contents = "";
        std::string line;
        std::string section;
        while(!input.eof()){
            getline(input, line);
        while (line.length() > 0)
        {
            section = line.substr(0, line.find(','));
            line.erase(0, line.find(','));
            if(line.find(',') != ~0U)
                line.erase(0, line.find(',')+1);
            if(section.find('.') != ~0U)
                section = section.substr(0, section.find('.'));
            std::istringstream convert(section);
            int aux = 0;
            convert>>aux;
            std::cout<<"Inserting "<<aux<<std::endl;
            if(convert.fail())
                aux = 0;
            else
                {
                    this->processNumber(aux);
                    }
            }
        }
    }
    }

void IOHandler::processNumber(int value)
{
    if (value<0)                        //Check if value is negative
        {
            this->odd->swap();          //Swap odd list's insertion and deletion points
            this->even->swap();         //Swap even list's insertion and deletion points
            }
    else if (value%2 == 0)              //Check if number is even
    {
        this->even->insert(value);      //Insert in even list
        }
    else                                //Number is odd
    {
        this->odd->insert(value);       //Insert in odd list
        }
    }