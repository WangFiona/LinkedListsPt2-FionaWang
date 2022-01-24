#include <iostream>
#include "Node.h"
#include "Student.h"

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 24, 2022
 */

void add(Node * &head, Node * prev, Node * cur, Student * newS);
void print(Node * &head);
void delet(Node * &head);
void average(Node * &head);

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
      for (int i=0; i<list.size(); i++) {
        while (id == list[i].id) {
          cout << "Please enter a unique ID number:" << endl;
          cin >> id;
          cin.get();
        }
      }
	
      cout << "Enter the student's GPA:" << endl;
      cin >> gpa;
      cin.get();
      
      Student* newS = new Student(first, last, id, gpa);
      add(head, head, head, newS);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, PRINT)==false) {
      print(head);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, DELETE)==false) {
      delet(head);
      cout<< "Enter a command (ADD, PRINT, DELETE, AVERAGE, or QUIT):" << endl;
    } else if (strcmp(command, AVERAGE)==false){
      average(head);
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
  else if(curr==NULLL){
    prev->setNext(
  }
}

void print(Node * &head) {
  
}

void delet(Node * &head) {
  
}

void average(Node * &head) {
  
}