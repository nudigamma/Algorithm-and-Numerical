#ifndef NODE_HPP
#define NODE_HPP


class Node {

public:
    Node();
    Node(double);
    Node(double,Node *);
    

    double GetItem();

    Node * GetNext();

    void SetItem(double);

    void SetNext(Node *); 

private:

    double _item;

    Node * _next;
                        
   

};




#endif