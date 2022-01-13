#include <iostream>
#include "Student.h"
#include <cstring>

using namespace std;

/* 
 * Author: Fiona Wang
 * Date: January 11, 2022
 * This is the student cpp file
 */

//Creating and setting student variables
Student::Student(char* newName){
  name = new char[20];
  strcpy(name, newName);
}

//Getting the student's name
char* Student::getName(){
  return name;
}
