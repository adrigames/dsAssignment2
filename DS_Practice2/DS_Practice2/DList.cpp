#include "DList.hpp"

DList::DList()
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
            this->last = aux;
            }
        }
    
    if (this->head == NULL)
        this->head = aux;
    if (this->last == NULL)
        this->last = aux;
    }

int DList::extract()
{
    int value = 0;
    if (this->empty())
        throw std::runtime_error("This list is empty!");
    if(swapped)
    {
        celltype* aux = this->last;
        value = aux->getValue();
        this->last = this->last->getPrevious();
        delete(aux);
        }
    else
        {
            celltype* aux = this->head;
            value = aux->getValue();
            this->head = this->head->getNext();
            delete(aux);
            }
    return value;
    }

void DList::swap()
{
    this->swapped = !this->swapped;
    }

void DList::makenull()
{
    while(!this->empty())
    {
        this->extract();
        }
    }

bool DList::empty()
{
    return this->head == NULL && this->last == NULL;
    }

bool DList::isSwapped()
{
    return this->swapped;
    }
    
int DList::makeList(int *array)
{
    if (this->empty()) throw std::runtime_error("List is empty!\n");
    int length = 0;
    celltype* aux = this->head;
    while(aux != NULL)
    {
        array[length] = aux->getValue();
        length++;
        aux = aux->getNext();
        }
    return length;
    }

std::string DList::list(bool inverted)
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

celltype* DList::locate(int value)
{
    if(this->empty()) return NULL;
    celltype* aux = this->head;
    while (aux!= NULL)
    {
        if (aux->getValue() == value)
        {
            break;
            }
        else{
            aux = aux->getNext();
            }
        }
    return aux;
    }

void DList::cut(int value)
{
    celltype* aux = this->locate(value);
    this->last = aux->getPrevious();
    while(aux!= NULL)
    {
        celltype* aux2 = aux;
        aux = aux->getNext();
        delete(aux2);
        }
        delete(aux);
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