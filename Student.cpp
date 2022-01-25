#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

/* 
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This file is the implementation of the student class
 */

//Constructor
Student::Student(char* newFirst, char* newLast, int newId, float newGpa){
  first = new char[15];
  strcpy(first, newFirst);
  last = new char[15];
  strcpy(last, newLast);
  id=newId;
  gpa=newGpa;
}

//Getting the student's first name
char* Student::getFirst(){
  return first;
}

//Getting the student's last name
char* Student::getLast(){
  return last;
}

//Getting the student's ID
int Student::getId(){
  return id;
}

//Getting the student's GPA
float Student::getGpa(){
  return gpa;
}
