//Header Guard
#ifndef NODE_H
#define NODE_H
#include <iostream>
#include "student.h"

using namespace std;

/*
 * Author: Jeffrey Teh
 * Date: January 20, 2022
 * This file is the interface for the node class
 */

class Node{
  //Student to be set by constructor
  Student* NodeStudent;    
  //Next Node
  Node* next;
  
 public:
  //Constructor
  Node(Student* newStudent);  
  //Destructor
  ~Node();
  //Setting the next node
  void setNext(Node* newNext);
  //Getting the next node
  Node* getNext();
  //Getting the student from the node
  Student* getStudent();
};

#endif
