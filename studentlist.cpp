#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 24, 2022
 */

void add(Node * &head, Node * prev, Node * cur, Student * newS);
void print(Node * head);
void delet(Node * &head, Node* prev, Node* curr, int id);
void average(Node * head, Node * curr, float averag, int count);

int main(){
  Node* head = NULL;
  bool running = true;
  char command[10];
  char ADD[] = "ADD";
  char PRINT[] = "PRINT";
  char DELETE[] = "DELETE";
  char QUIT[] = "QUIT";
  char AVERAGE[]="AVERAGE";
  
  //Ask the user for a command
  cout << "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;

  while (running == true) {
    cin.get(command,10);
    cin.get();

    //Allow both upper and lower case
    for(int i=0; i < strlen(command); i++) {
      command[i] = toupper(command[i]);
    }

    //Determine which command the user input
    if (strcmp(command, ADD)==false) {
      char* first = new char[15];
      char* last = new char[15];
      int id=0;
      float gpa=0;
      
      cout << "Please enter a first name:" << endl;
      cin.get(first, 15);
      cin.get();
      
      cout << "Enter a last name:" << endl;
      cin.get(last, 15);
      cin.get();

      cout << "Enter the student ID:" << endl;
      cin >> id;
      cin.get();
      //Make sure that the ID is not currently in use
      Node* current=head;
      bool unique=false;
      bool passed=true;
      while(unique==false){
	passed=true;
	current=head;
	while(current!=NULL){
	  if(current->getStudent()->getId() == id){
	    cout << "This ID has already been used please pick a different one:"<< endl;
	    cin >> id;
	    cin.get();
	    passed=false;
	  }
	  current=current->getNext();
	}
	unique= passed==false ? false : true;
      }
	
      cout << "Enter the student's GPA:" << endl;
      cin >> gpa;
      cin.get();
      
      Student* newS = new Student(first, last, id, gpa);
      add(head, head, head, newS);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, PRINT)==false) {
      if(head==NULL){
	cout << "The database is empty" << endl;
      } else{
	print(head);
      }
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, DELETE)==false) {
      cout<< "Enter the ID of the student you would like to delete:" << endl;
      int deleteId=0;
      cin >> deleteId;
      cin.get();
      delet(head,head,head,deleteId);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, AVERAGE)==false){
      average(head,head,0,0);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, QUIT)==false) {
      running = false;
    } else {
      cout << "Please enter a valid command:" << endl;
    }
  }
  
  return 0;
}

void add(Node * &head, Node * prev, Node * curr, Student * newS) {
  if(head==NULL){
    head = new Node(newS);
  }
  else if(curr==NULL){
    prev->setNext(new Node(newS));
  }
  else if(newS->getId() <= head->getStudent()->getId()){
    Node* temp = head;
    head = new Node(newS);
    head->setNext(temp);
  }
  else if(curr->getStudent()->getId() > newS->getId()){
    prev->setNext(new Node(newS));
    prev->getNext()->setNext(curr);
  }
  else{
    add(head, curr, curr->getNext(), newS);
  }
}

void print(Node * head) {
  if(head!=NULL){
    cout << head->getStudent()->getFirst() << " " <<
      head->getStudent()->getLast() << ", ";
    cout << head->getStudent()->getId() << ", ";
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << head->getStudent()->getGpa() << endl;
    print(head->getNext());
  } //else{
    //cout << "The database is empty" << endl;
  //}
}

void delet(Node * &head, Node * prev, Node * curr, int id) {
  if(head==NULL){
    cout << "There are no students in the database" << endl;
  }
  else if(id == curr->getStudent()->getId()){
    if(head->getNext()==NULL){
      delete curr;
      head=NULL;
    }
    else if(head==curr){
      curr = head->getNext();
      delete head;
      head=curr;
    }
    else if(curr!=NULL){
      Node* temp = curr->getNext();
      delete curr;
      prev->setNext(temp);
    }
  }
  else{
    delet(head, curr, curr->getNext(), id);
  }
}

void average(Node * head, Node * curr, float averag, int count) {
  if(head==NULL){
    cout << "There are no GPAs to calculate" << endl;
  } else if(head->getNext()==NULL){
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average GPA: " << curr->getStudent()->getGpa() << endl;
  } else if(curr==NULL){
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average GPA: " << averag/count << endl;
  } else {
    count++;
    average(head, curr->getNext(), averag+curr->getStudent()->getGpa(), count);
  }
}
