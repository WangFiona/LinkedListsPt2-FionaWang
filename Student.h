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
  Student(char* newName);
  char* name;
  char* getName();
};
#endif
