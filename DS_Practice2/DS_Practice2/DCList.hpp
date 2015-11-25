#ifndef DCLIST_HPP
#define DCLIST_HPP

#include "celltype.hpp"
#include <string>
#include <sstream>
#include <exception>

class DCList
{
private:
    celltype* head, *last;
    bool swapped;
    
    int makeList(int*);
public:
    DCList();
    ~DCList();
    void insert(int);
    int extract(void);
    void swap(void);
    void makenull(void);
    bool empty(void);
    bool isSwapped(void);
    std::string list(bool);
    void cut(int);
    celltype* getHead(void);
    celltype* getLast(void);
    celltype* locate(int);
};

#endif // DCLIST_HPP
