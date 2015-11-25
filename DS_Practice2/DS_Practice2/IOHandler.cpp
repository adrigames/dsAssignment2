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
    data += this->odd->list(false);
    data += "\n";
    data += this->even->list(false);
    data += "\n";
    
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
        std::string contents = "", line = "";
        while(getline(input, line)){
                contents += line;
                line += "\n";
            }
        std::istringstream convert(contents);
        while (!convert.eof())
        {
            int aux = 0;
            if(!(convert>>aux))
                aux = 0;
            else
                {
                    this->processNumber(aux);
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