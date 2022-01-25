#include <iostream>
#include "student.h"
#include <cstring>

using namespace std;

/* 
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This is the student cpp file
 */

//Creating and setting student variables
Student::Student(char* newFirst, char* newLast, int newId, float newGpa){
  first = new char[15];
  strcpy(first, newFirst);
  last = new char[15];
  strcpy(last, newLast);
  id=newId;
  gpa=newGpa;
}

//Getting the student's name
char* Student::getFirst(){
  return first;
}

//Getting the student's name
char* Student::getLast(){
  return last;
}

int Student::getId(){
  return id;
}

float Student::getGpa(){
  return gpa;
}
