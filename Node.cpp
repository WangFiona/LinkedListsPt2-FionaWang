#include "node.h"
#include "student.h"
#include <cstring>

/* 
 * Author: Jeffrey Teh
 * Date: January 20, 2022
 * This file is the implementation of the node class
 */

//Constructor
Node::Node(Student* newStudent){
  //Setting the node's student to the inputted student
  NodeStudent = newStudent;
  //Setting the next node to null
  next = NULL;
}

//Destructor
Node::~Node(){
  cout << "You are deleting ... " << endl;
  //Deleting the node's student
  delete NodeStudent;
  //Setting the next node to null
  next = NULL;
}

//Setting the next node
void Node::setNext(Node* newNext){
  next = newNext;
}

//Returning the next node
Node* Node::getNext(){
  return next;
}

//Returning the node's student
Student* Node::getStudent(){
  return NodeStudent;
}
