#include "StudentList.h"

StudentList::StudentList():size(0), root(0) //Constructor
{ cout << "Empty Student List Created"<< endl; }
 
bool StudentList::insert2tree(StudentNode* &root,StudentNode* st) //recursive insertion method
{
	if(st->numiD!=-1) 
	{
		if (root == 0)
       	root = st;
		else if (st->numiD < root->numiD)
			insert2tree(root->left, st);
    	else
       		insert2tree(root->right, st);
		return true;
   	}
	return false;
}

bool StudentList::addStudent2list(StudentNode* st) // Adding student to list
{	
	if(insert2tree(root,st))
	{   size++;
	//cout << "Student is added to the list! Now" << " " << size << " Student(s) in the list!"<< endl;
	 	return true;
	}
	return false;
}

bool StudentList::printwrtID(ostream& os) //printing function wrt ID
{   
	StudentNode* current=0;
	cout << "Printing wrt ID (" << size << " Students)" <<endl;
	cout << "---------------" << endl;
	if(size==0 && root==0) //If empty
	{
		cout << "Empty List, Cannot Print!" << endl;
		return false;
	}
	else 
	{  
		traverseANDprint(root,os);
	}

}

bool StudentList::traverseANDprint(StudentNode* root,ostream& os)  //recursive printing
{
	if(root->left !=0) traverseANDprint(root->left,os);
	os << *root << endl;
	if(root->right!=0) traverseANDprint(root->right,os);
	return true;
}

bool StudentList::search(int temp) 
{
	  return traverseANDsearch(root,temp);
	  
}

bool StudentList::traverseANDsearch(StudentNode* root, int temp) // recursive searching
{   
	if(root==0 || root->numiD < 0 || root->numiD >9999999999) // limits our ID criteria, not less then 0, not more then 9999999999
	{ 
		cout << "Student Not Found!" << endl;
		return false;
	}
	else if(temp==root->numiD) 
	{
		cout << "Student is Found! Printing..." << endl << *root << endl;
		return true;
	}
	else if(temp < root->numiD) traverseANDsearch(root->left,temp);
	else if(temp > root->numiD) traverseANDsearch(root->right,temp);
	else return false;
}


bool StudentList::removefromlist(int given) //deleting a node
{	
	if(size==0)
	{
		cout<< "Cannot delete anything from an empty list"<< endl;
		return false;
	}
	else
	{
		if(search(given)== true)
		{
			Delete(root,given);
		    cout << "Student is Deleted" << endl;
		    size--;
			return true;
		}
		else
		{
			cout << "So cannot delete!" << endl;
			return false;
		}
	}
}


bool StudentList::Delete(StudentNode* &root,int given) //Real recursive deletion part
{   //Recursive delete sequence, see Dale's Book
	if(given < root->numiD) Delete(root->left,given);
	else if(given > root->numiD) Delete(root->right,given);
	else DeleteNode(root);
	return true;
}

void StudentList::DeleteNode(StudentNode* &root) //delete a specific node
{   
	StudentNode data=StudentNode("RANDOM");
	StudentNode* tempPtr=0;

	tempPtr=root;
	if(root->left == 0 )
	{
		root=root->right;
		delete tempPtr;
	}
	else if(root->right== 0)
	{
		root=root->left;
		delete tempPtr;
	}
	else
	{
		GetPredecessor(root->left,data);
		
		root->iD=data.iD;
		root->name=data.name;
		root->surname=data.surname;
		root->dept=data.dept;
		root->numiD=data.numiD;
		Delete(root->left,data.numiD);
    }
}
void StudentList::GetPredecessor(StudentNode* root,StudentNode& data) //Implented for deletion process, see Dale's Book
{
	while(root->right!=0) root=root->right;
		
	data.iD=root->iD;
	data.name=root->name;
	data.surname=root->surname;
	data.dept=root->dept;
	data.numiD=root->numiD;
		
}








