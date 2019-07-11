#include <cstddef>
#include "Node.hpp"



//  default contructor
Node::Node(): _item{0}, _next{nullptr}{

}

Node::Node(double value ): _item{value}, _next{nullptr}{

}


Node::Node(double value , Node * next_node): _item {value}, _next {next_node} {};

double Node::GetItem(){
    return _item;

}

void Node::SetItem(double value ){
    _item = value;
}

Node * Node::GetNext(){
    return _next;
}

void Node::SetNext(Node* new_node){
    _next= new_node;
}