#ifndef CELLTYPE_HPP
#define CELLTYPE_HPP

class celltype
{
private:
    celltype* next, *previous;
    int value;
public:
    celltype(int, celltype*, celltype*);
    ~celltype();
    int getValue();
    celltype* getNext();
    celltype* getPrevious();
    void setNext(celltype*);
    void setPrevious(celltype*);
    void setValue(int);

};

#endif // CELLTYPE_HPP
