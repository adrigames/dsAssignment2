#include "celltype.hpp"

celltype::celltype(int value, celltype* next, celltype* previous)
{
    this->value = value;
    this->next = next;
    this->previous = previous;
}

celltype::~celltype()
{
}

int celltype::getValue()
{
    return this->value;
}

celltype* celltype::getNext()
{
    return this->next;
    }
    
celltype* celltype::getPrevious()
{
    return this->previous;
    }

void celltype::setNext(celltype* newNext)
{
    this->next = newNext;
    }

void celltype::setPrevious(celltype* newPrevious)
{
    this->previous = newPrevious;
    }

void celltype::setValue(int newValue)
{
    this->value = value;
    }