#ifndef STUDENTLIST_H
#define STUDENTLIST_H
#include "StudentNode.h"

class StudentList 
{
	unsigned size; // size of the list
	StudentNode* root; //pointing the root node
	

public:
	 StudentList(); // constructor
	 bool addStudent2list(StudentNode*);  //Adding Student to list
	 bool insert2tree(StudentNode*&,StudentNode*); // insertion of a node to a tree
	 bool printwrtID(ostream& = cout); 
	 bool removefromlist(int);
	 bool traverseANDprint(StudentNode*);
	 bool Delete(StudentNode*&,int);
	 void DeleteNode(StudentNode*&);
	 void GetPredecessor(StudentNode*,StudentNode&);
	 bool search(int);
	 bool traverseANDsearch(StudentNode*,int);
	 

};
#endif