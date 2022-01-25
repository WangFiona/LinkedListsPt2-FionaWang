#include <iostream>
#include "node.h"
#include "student.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 24, 2022
 */

void add(Node * &head, Node * prev, Node * cur, Student * newS, int id);
void print(Node * head);
void delet(Node * &head);
void average(Node * head, Node * curr, float averag, int count);

int main(){
  Node* head = NULL;
  bool running = true;
  int idPos=0;
  int idPosPrev=0;
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
      /*//Make sure that the ID is not currently in use     
      for (int i=0; i<list.size(); i++) {
        while (id == list[i].id) {
          cout << "Please enter a unique ID number:" << endl;
          cin >> id;
          cin.get();
        }
	}*/
	
      cout << "Enter the student's GPA:" << endl;
      cin >> gpa;
      cin.get();
      
      Student* newS = new Student(first, last, id, gpa);

      Node* current = head;
      bool found=false;
      idPos=0;
      idPosPrev=0;
      if(current!=NULL){
	idPos=gpa;
      	if(current->getNext()==NULL){
	  idPos=current->getStudent()->getId() < gpa ?
	    current->getStudent()->getId() : gpa;
	  found=true;
	} else{
	  idPos=0;
	  while(current!=NULL){
	    if(current->getStudent()->getId() < gpa &&
	       current->getStudent()->getId() >=idPosPrev){
	      idPosPrev=idPos;
	      idPos=current->getStudent()->getId();
	      found=true;
	    }
	    current=current->getNext();
	  }
	}
      } if(found==false){
	idPos=0;
      }
      add(head, head, head, newS, idPos);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, PRINT)==false) {
      print(head);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, DELETE)==false) {
      delet(head);
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

void add(Node * &head, Node * prev, Node * curr, Student * newS, int id) {
  if(head==NULL){
    head = new Node(newS);
  }
  else if(curr==NULL){
    prev->setNext(new Node(newS));
  }
  else if(id < head->getStudent()->getId()){
    Node* temp = head;
    head = new Node(newS);
    head->setNext(temp);
  }
  else if(curr->getStudent()->getId() > id){
    prev->setNext(new Node(newS));
    prev->getNext()->setNext(curr);
  } else{
    add(head, curr, curr->getNext(), newS, id);
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
  }
}

void delet(Node * &head) {
  
}

void average(Node * head, Node * curr, float averag, int count) {
  if(head==NULL){
    cout << "There are no GPAs to calculate!" << endl;
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
