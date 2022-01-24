#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 11,2022
 * This cpp file tests to make sure that the linked list works
 * by printing out the names of three students
 */

/*int main(){
  //Initializing the students
  char* name = new char[20];
  strcpy(name, "Helen");
  Student* student1 = new Student(name);
  strcpy(name, "Angie");
  Student* student2 = new Student(name);
  strcpy(name, "Ruby");
  Student* student3 = new Student(name);

  //Initializing the node, setting, and printing the first student
  Node* head = NULL;
  head = new Node(student1);
  //head->setStudent(student1);
  cout << "Student Names:" << endl;
  cout << head->getStudent() << endl;

  //Setting and printing the second student
  Node* current = head;
  current->setNext(new Node(student2));
  //current->getNext()->setStudent(student2);
  cout << head->getNext()->getStudent() << endl;

  //Setting and printing the third student
  current = current->getNext();
  current->setNext(new Node(student3));
  //current->getNext()->setStudent(student3);
  cout << head->getNext()->getNext()->getStudent()->getName() << endl;
  
  return 0;
}
*/
