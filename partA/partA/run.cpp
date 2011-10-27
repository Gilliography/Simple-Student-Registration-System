/**********************************************************************************************/
// Seckin Savasci
//2008400078
//Cmpe 160 Project 2
//Written in VC++ 2010 Xpress Ed. BETA
/***********************************************************************************************/

#include "StudentList.h" // not anymore include statements, see StudentList.h->StudentNode.h

int createStudentList(string filename, StudentList& list1) //See project description for further info
{
	ifstream txtread;  
	txtread.open(filename);
	if(!txtread) //controlling whether it's working or not
	{
		cout << "Cannot open/read file" << endl;
		return -1;
	}
	cout << "File is open" << endl;
	while(!txtread.eof()) //Read Until EOF
	{	
		StudentNode* std=new StudentNode(txtread);
		list1.addStudent2list(std); //see addstudent2list description for further info
	}
	system("PAUSE");
	return 0;
}

void editStudentList(StudentList& list1) //See project description, also looking the main() will help you
{
	string command;

	cout << "*******Student Registration System*******" << endl;

	for(;;)
	{
		cout << "Enter a command: " << endl; //Command prompt
    	cin >> command;

		

		if(command == PrintWrtId)
		{
	  		list1.printwrtID();
			cout << "done printing w.r.t id" << endl;
		}
		else if(command == DeleteStudent)
		{	
			int given=0;
			again:
			try //if anything wrong occurs, we have to "handle" it
			{
				cout<<"Enter ID:";
				cin>>given;
				//cout<< "read" << endl;
			}
			catch(...) //catching local exceptions
			{
				cout<<"except"<<endl;
				goto again;
			}
			list1.removefromlist(given);
		}
		else if (command == Quit)
		{
			cout << "Exiting from Registration System" << endl;
			break;
		}
		else if (command== AddStudent)
		{	
			StudentNode* ptr=new StudentNode;
			list1.addStudent2list(ptr);
		}
			else if(command== Search)
		{	

			int temp;
			cout<< "Please, enter ID:";
			cin>> temp;

			clock_t now=clock();
			list1.search(temp);
			cout << "Search ended in "<<clock()-now<< " miliseconds" << endl;


		}
		else cout << "no such command as: " << command << endl;
	}
}




int main()
{
	
	StudentList cmpe160; // Creating emty list
	
	createStudentList("StudentList.txt",cmpe160); // reading from file and adding to cmpe160 list
	
	editStudentList(cmpe160); // opens Editing mode 
	
	system("PAUSE");
	return 0;
	
}