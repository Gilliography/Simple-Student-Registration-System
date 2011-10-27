#ifndef STUDENTNODE_H
#define STUDENTNODE_H


#define PrintWrtId "p"
#define AddStudent "i"
#define DeleteStudent "d"
#define Quit "q"
#define Search "s"

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <time.h>
#include <string>
#include <algorithm>
#include <fstream>
#include <cctype>
#include <stack>

using namespace std;
class StudentList;
class StudentNode {
	
	string iD; // for read stream and manipulate
	long int numiD;  //after i/o formatted there is a conversion from iD to numiD for the sake of ordering
	string surname;
	string name;
	string dept;
	StudentNode* left; //left child
	StudentNode* right; //right child
	StudentNode* parent;
	bool visited;
	
public:
	StudentNode& Format();
	StudentNode(istream& = cin); //constructor
	StudentNode(string);
	friend ostream& operator<<(ostream& , StudentNode); //for printing
	friend class StudentList; //for StudentList to access node datas

};

ostream& operator<<(ostream& , StudentNode);

  





	
	
	

	
	

	


#endif 