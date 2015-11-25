#include "IOHandler.hpp"

IOHandler::IOHandler()
{
}

IOHandler::~IOHandler()
{
}

void IOHandler::save(DList* odd, DCList* even)
{
    std::ofstream output;
    std::string data = "";
    data += odd->list();
    data += "\n";
    data += even->list();
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
    
void IOHandler::load(DList* odd, DCList* even)
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
                    this->processNumber(aux, odd, even);
                    }
            }
        }
    }

void IOHandler::processNumber(int value, DList* odd, DCList* even)
{
    if (value<0)                        //Check if value is negative
        {
            odd->swap();                //Swap odd list's insertion and deletion points
            even->swap();               //Swap even list's insertion and deletion points
            }
    else if (value%2 == 0)              //Check if number is even
    {
        even->insert(value);            //Insert in even list
        }
    else                                //Number is odd
    {
        odd->insert(value);             //Insert in odd list
        }
    }