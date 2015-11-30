#include "DList.hpp"

DList::DList()
//Initialize list
{
    this->head = NULL;
    this->last = NULL;
    this->swapped = false;
}

DList::~DList()
{
}

void DList::insert(int value)
{
    celltype* aux = new celltype(value, NULL, NULL);    //New cell
    if(!this->empty())                                  //If list is not empty
    {
        if(swapped)                                     //If insertion and deletion are swapped
        {
            if(this->head->getNext() != NULL){          //Insert after head
                this->head->getNext()->setPrevious(aux);
                aux->setNext(this->head->getNext());
            }
            this->head->setNext(aux);                   //Set as next of head
            }
        else                                            //If not swapped
        {
            this->last->setNext(aux);                   //Insert after last.
            aux->setPrevious(this->last);
            this->last = aux;
            }
        }
    
    //If list is empty, set head and last to new cell
    if (this->head == NULL)
        this->head = aux;
    if (this->last == NULL)
        this->last = aux;
    }

int DList::extract()
{
    int value = 0;
    if (this->empty())
        throw std::runtime_error("This list is empty!");    //If list is empty, throw error
    if(swapped)                                             //If list is swapped
    {
        celltype* aux = this->last;                         //Extract the last
        value = aux->getValue();
        this->last = this->last->getPrevious();
        delete(aux);
        }
    else                                                    //If not
        {
            celltype* aux = this->head;                     //Extract the head
            value = aux->getValue();
            this->head = this->head->getNext();
            delete(aux);
            }
    return value;
    }

void DList::swap()
{
    this->swapped = !this->swapped;                         //Swap insertion and deletion points
    }

void DList::makenull()
{
    while(!this->empty())                                   //While there are elements
    {
        this->extract();                                    //Keep on extracting them
        }
    }

bool DList::empty()
{
    return this->head == NULL && this->last == NULL;        //Check if both head and last are null
    }

bool DList::isSwapped()
{
    return this->swapped;                                   //Return true if list is swapped
    }
    
int DList::makeList(int *array)
{
    if (this->empty()) 
        throw std::runtime_error("List is empty!\n");    //If list is empty, throw error
    int length = 0;                                      //Register length
    celltype* aux = this->head;                          //Set starting point to the head
    while(aux != NULL)                                   //Keep going until the end
    {
        array[length] = aux->getValue();                 //Add value to array
        length++;                                        //Update length
        aux = aux->getNext();                            //Move to next
        }
    return length;                                       //Return length of the array
    }

std::string DList::list(bool inverted)
{
    int* values = new int[8192];
    int length = this->makeList(values);
    int i = 0;
    std::string result = "";
    std::stringstream stream;
    if(!inverted){                              //Decide order
    for (i=0; i<length; i++)
    {
        stream<<values[i];                      //Insert value
        if(i==length-1)                         //Check for last
        {
            stream<<'.';                        //Insert period
            }
        else
            {
                stream<<',';                    //Insert comma
                }
        }
    }
    else{
        for(i=length-1; i>=0; i--)
        {
            stream<<values[i];                  //Insert value
        if(i==0)                                //Check for last
        {
            stream<<'.';                        //Insert period
            }
        else
            {
                stream<<',';                    //Insert comma
                }
            }
    }
        result += stream.str();                 //Make string
        delete(values);                         //Delete array
        return result;                          //Return string
    }

celltype* DList::locate(int value)
{
    if(this->empty()) 
        return NULL;                             //If list is empty, value can't be found          
    celltype* aux = this->head;
    while (aux!= NULL)                          //Iterate list
    {
        if (aux->getValue() == value)           //If value is found
        {
            break;                              //Exit loop
            }
        else{                                   //If not
            aux = aux->getNext();               //Move on
            }
        }
    return aux;                                 //Return value of aux (NULL if not found)
    }

void DList::cut(int value)
{
    celltype* aux = this->locate(value);                //Search value
    if(aux == NULL){                                    //If value is not found
        throw std::runtime_error("Value not found!\n"); //throw error
        }
    this->last = aux->getPrevious();                    //Set new last
    if (aux == this->head)                              //If position is head
    {
        this->makenull();                               //makenull
        return;
        }
    while(aux!= NULL)                                   //Else, iterate
    {
        celltype* aux2 = aux;                           //Delete current position
        aux = aux->getNext();
        delete(aux2);
        }
        delete(aux);                                    //Delete last position
        this->last->setNext(NULL);
    }

celltype* DList::getHead()
{
    return this->head;
    }

celltype* DList::getLast()
{
    return this->last;
    }