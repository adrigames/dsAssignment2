#include "DCList.hpp"

DCList::DCList()
{
    this->head = NULL;
    this->last = NULL;
    this->swapped = false;
}

DCList::~DCList()
{
}

void DCList::insert(int value)
{
    celltype* aux = new celltype(value, NULL, NULL);
    if(!this->empty())
    {
        if(swapped)
        {
            if(swapped)
        {
            if(this->head->getNext() != NULL){
                this->head->getNext()->setPrevious(aux);
                aux->setNext(this->head->getNext());
            }
            this->head->setNext(aux);
            }
            }
        else
        {
            this->last->setNext(aux);
            aux->setPrevious(this->last);
            aux->setNext(this->head);
            this->last = aux;
            }
        }
    
    if (this->head == NULL){
        this->head = aux;
        this->head->setPrevious(aux);
        }
    if (this->last == NULL){
        this->last = aux;
        this->last->setNext(aux);
    }
}
int DCList::extract()
{
    int value = 0;
    if (this->empty())
        throw std::runtime_error("This list is empty!");
    if(swapped)
    {
        celltype* aux = this->last;
        value = aux->getValue();
        this->last = this->last->getPrevious();
        this->last->setNext(this->head);
        delete(aux);
        }
    else
        {
            celltype* aux = this->head;
            value = aux->getValue();
            this->head = this->head->getNext();
            this->head->setPrevious(this->last);
            delete(aux);
            }
    return value;
    }

void DCList::swap()
{
    this->swapped = !this->swapped;
    }

void DCList::makenull()
{
    celltype* aux = this->head;
    this->last->setNext(NULL);
    while(aux != this->last)
    {
        celltype* aux2 = aux;
        aux = aux->getNext();
        delete(aux2);
        }
        delete(aux);
        this->head = NULL;
        this->last = NULL;
    }

bool DCList::empty()
{
    return this->head == NULL && this->last == NULL;
    }

bool DCList::isSwapped()
{
    return this->swapped;
    }
    
int DCList::makeList(int *array)
{
    if (this->empty()) throw std::runtime_error("List is empty!\n");
    int length = 0;
    celltype* aux = this->head;
    array[length] = this->head->getValue();
    length++;
    aux = aux->getNext();
    while(aux != this->head)
    {
        array[length] = aux->getValue();
        length++;
        aux = aux->getNext();
        }
    return length;
    }

std::string DCList::list(bool inverted)
{
    int* values = new int[8192];
    int length = this->makeList(values);
    int i = 0;
    std::string result = "";
    std::stringstream stream;
    if(!inverted){
    for (i=0; i<length; i++)
    {
        stream<<values[i];
        if(i==length-1)
        {
            stream<<'.';
            }
        else
            {
                stream<<',';
                }
        }
    }
    else{
        for(i=length-1; i>=0; i--)
        {
            stream<<values[i];
        if(i==0)
        {
            stream<<'.';
            }
        else
            {
                stream<<',';
                }
            }
    }
        result += stream.str();
        delete(values);
        return result;
    }

celltype* DCList::locate(int value)
{
    if(this->empty()) return NULL;
    celltype* aux = this->head;
    if (aux->getValue() == value) 
        return aux;
    else
        aux = aux->getNext();
    while (aux!= this->head)
    {
        if (aux->getValue() == value)
        {
            return aux;
            }
        else{
            aux = aux->getNext();
            }
        }
    return NULL;
    }

void DCList::cut(int value)
{
    celltype* aux = this->locate(value);        //Look for value
    this->last->setNext(NULL);                  //Make sure loop finishes
    this->last = aux->getPrevious();            //Establish new last
    if (aux == this->head)                      //If everything has to be deleted
    {
        this->makenull();                       //Call makenull
        return;
        }
    while(aux!= NULL)                           //Else, while there are cells left
    {
        celltype* aux2 = aux;                   //Get reference
        aux = aux->getNext();                   //Move on
        delete(aux2);                           //Delete last cell
        }
        delete(aux);                            //At the end, delete last cell
        this->last->setNext(this->head);        //Make last point to head
    }

celltype* DCList::getHead()
{
    return this->head;
    }

celltype* DCList::getLast()
{
    return this->last;
    }

