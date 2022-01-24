#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This is the student header file and just contains the student's name
 */

class Student{
 public:
  //Initializing student variables and functions
  Student(char* newFirst, char* newLast, int newId, float newGpa);
  char* first;
  char* last;
  int id;
  float gpa;
  
  char* getFirst();
  char* getLast();
  char* getId();
  char* getGpa();
};
#endif
