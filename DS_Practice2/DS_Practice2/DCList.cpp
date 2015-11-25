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
            this->head->getNext()->setPrevious(aux);
            aux->setNext(this->head->getNext());
            this->head->setNext(aux);
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
        aux->setNext(this->last->getNext());
        this->last = this->last->getPrevious();
        delete(aux);
        }
    else
        {
            celltype* aux = this->head;
            value = aux->getValue();
            aux->setPrevious(this->head->getPrevious());
            this->head = this->head->getNext();
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
    while(!this->empty())
    {
        this->extract();
        }
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
    celltype* aux = this->locate(value);
    if (aux == this->head)
    {
        this->makenull();
        return;
        }
    this->last = aux->getPrevious();
    while(aux!= this->head)
    {
        celltype* aux2 = aux;
        aux = aux->getNext();
        delete(aux2);
        }
        delete(aux);
        this->last->setNext(NULL);
    }

celltype* DCList::getHead()
{
    return this->head;
    }

celltype* DCList::getLast()
{
    return this->last;
    }

