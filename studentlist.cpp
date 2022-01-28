#include <iostream>
#include "node.h"
#include "student.h"
#include <cstring>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 24, 2022
 * This is the main class for the linked lists project.
 * The user can add, print, delete, and get the average gpa of students in the database.
 */

//Initializing the functions
void add(Node * &head, Node * prev, Node * cur, Student * newS);
void print(Node * head);
void delet(Node * &head, Node* prev, Node* curr, int id);
void average(Node * head, Node * curr, float averag, int count);

int main(){
  //Initializing variables
  Node* head = NULL;
  bool running = true;
  bool found=false;
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

      //Ask the user for the first name of the new student
      cout << "Please enter a first name:" << endl;
      cin.get(first, 15);
      cin.get();

      //Ask the user for the last name
      cout << "Enter a last name:" << endl;
      cin.get(last, 15);
      cin.get();

      //Ask the user for the student's ID
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

      //Ask the user for the student's GPA
      cout << "Enter the student's GPA:" << endl;
      cin >> gpa;
      cin.get();

      //Make a new student and proceed into the add function
      Student* newS = new Student(first, last, id, gpa);
      add(head, head, head, newS);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, PRINT)==false) {
      if(head==NULL){ //Check if there are students in the database
	cout << "The database is empty" << endl;
      } else{
	print(head); //Print out all students and their information
      }
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, DELETE)==false) {
      if(head==NULL){ //Check if there are students in the database                       
        cout << "The database is empty" << endl;
      } else{
	//Ask the user for the ID they would like to delete
	cout<< "Enter the ID of the student you would like to delete:" << endl;
	int deleteId=0;
	cin >> deleteId;
	cin.get();
	found=false;
	Node* cur= head;
	while(cur!=NULL){
	  if(cur->getStudent()->getId()==deleteId){ found=true;}
	  cur=cur->getNext();
	}
	if(found==false){
	  cout << "That ID does not exist" << endl;
	} else {
	  delet(head,head,head,deleteId);
	}
      }
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, AVERAGE)==false){
      //Calculate the average of all GPAs
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

//Function for adding students in order
void add(Node * &head, Node * prev, Node * curr, Student * newS) {
  if(head==NULL){ //If the list is empty
    head = new Node(newS);
  }
  else if(curr==NULL){ //If the new student has the largest ID
    prev->setNext(new Node(newS));
  }
  //If the new student has the smallest ID
  else if(newS->getId() <= head->getStudent()->getId()){
    Node* temp = head;
    head = new Node(newS);
    head->setNext(temp);
  }
  //Searching for where to insert the new student
  else if(curr->getStudent()->getId() > newS->getId()){
    prev->setNext(new Node(newS));
    prev->getNext()->setNext(curr);
  }
  else{ //Use recursion to search the list
    add(head, curr, curr->getNext(), newS);
  }
}

//Function for printing the students and their information
void print(Node * head) {
  if(head!=NULL){ //Check if the database is empty
    //Print out the student names, IDs, and GPAs
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

//Function for deleting students
void delet(Node * &head, Node * prev, Node * curr, int id) {
  if(head==NULL){ //If the database is empty
    cout << "There are no students in the database" << endl;
  }
  else if(id == curr->getStudent()->getId()){ //Once the matching ID is found
    if(head->getNext()==NULL){ //If there is only one student
      delete curr;
      head=NULL;
    }
    else if(head==curr){ //Deleting the first student
      curr = head->getNext();
      delete head;
      head=curr;
    }
    else if(curr!=NULL){ //Deleting students that are not the first
      Node* temp = curr->getNext();
      delete curr;
      prev->setNext(temp);
    }
  }
  else{ //Use recursion to search the list
    delet(head, curr, curr->getNext(), id);
  }
}

//Function for finding the average GPA
void average(Node * head, Node * curr, float averag, int count) {
  if(head==NULL){ //If the database is empty
    cout << "The database is empty" << endl;
  } else if(head->getNext()==NULL){ //If there is only one student
    //Rounding the GPA
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average GPA: " << curr->getStudent()->getGpa() << endl;
  } else if(curr==NULL){ //If there is more than one student
    //Rounding the GPA
    cout.setf(ios::fixed, ios::floatfield);
    cout.setf(ios::showpoint);
    cout.precision(2);
    cout << "Average GPA: " << averag/count << endl;
  } else { //Use recursion to add up all of the GPAs
    count++;
    average(head, curr->getNext(), averag+curr->getStudent()->getGpa(), count);
  }
}
