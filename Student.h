#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>

using namespace std;

/*
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This file is the interface for the student class
 * It includes the name, ID, and GPA of the student
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
  int getId();
  float getGpa();
};
#endif
