#ifndef DLIST_HPP
#define DLIST_HPP

#include "celltype.hpp"
#include <string>
#include <sstream>
#include <exception>

class DList
{
private:
    celltype* head, *last;
    bool swapped;
    
    int makeList(int*);
public:
    DList();
    ~DList();
    void insert(int);
    int extract(void);
    void swap(void);
    void makenull(void);
    bool empty(void);
    bool isSwapped(void);
    std::string list(void);
    void cut(int);
    celltype* getHead(void);
    celltype* getLast(void);
    celltype* locate(int);
};

#endif // DLIST_HPP
