#include "StudentNode.h"
string randomString(int,bool,bool,bool);
StudentNode::StudentNode(istream& is): left(0),right(0),visited(0)  // Default constructor, which reads data from an istream(default cin)
{	
	//int i=0;
	if(is==cin) // Default reading
	{  	getline(is,iD);

		cout << "Enter ID:";
	   	getline(is,iD);
		
		while(iD.empty()) 
		{	
			cout<<"Student w/o an ID is not accepted" << endl;
			cout << "Enter ID:";
			getline(is,iD);
		}
		cout << "Enter Name:";
		getline(is,name);
		while(name.empty()) 
		{	
			cout<<"Student w/o a Name is not accepted" << endl;
			cout << "Enter Name:";
			getline(is,name);
		}
		cout << "Enter Surname:";
		getline(is,surname);
		while(surname.empty()) 
		{	
			cout<<"Student w/o a Surname is not accepted" << endl;
			cout << "Enter Surname:";
			getline(is,surname);
		}
		cout << "Enter Department:";
		getline(is,dept);
		while(dept.empty()) 
		{	
			cout<<"Student w/o a department is not accepted" << endl;
			cout << "Enter Dept:";
			getline(is,dept);
		}
		Format();
			char idmanip[10];
			for(unsigned i=0;i<iD.length();i++)
				idmanip[i]=iD.at(i);
			numiD=atol(idmanip);
	}
	else 
	{	string line;
		getline(is,line);
		
		string stringlist[4];
		int count = 0;

		for (unsigned i = 0; i < line.length(); i++)
		{
        	if (line[i] == ',')
        	{
                stringlist[count] = line.substr(0, i);
                line.erase(0, i+1);
                i = 0;
                count++;
        	}
        	else if (i == line.length()-1)      // Last word
        	{
                stringlist[count] = line.substr(0, i+1);
        	}
		}
		if(!stringlist[0].empty() && !stringlist[1].empty() && !stringlist[2].empty() && !stringlist[3].empty())
		{
			iD=stringlist[0];
			name=stringlist[1];
			surname=stringlist[2];
			dept=stringlist[3];
			Format();
			char idmanip[10];
			for(unsigned i=0;i<iD.length();i++)
				idmanip[i]=iD.at(i);
			numiD=atol(idmanip);
		}
		else
		{
			numiD=-1; // also using as a validation check
			cout << "Corrupt line, skipping this line!" << endl;

		}
	}
}
StudentNode::StudentNode(string method): left(0), right(0), visited(0) //RANDOM Node creation
{	if(method!="RANDOM") return;
	iD=randomString(10,false,true,false);
	name=randomString(3,true,false,false);
	surname=randomString(3,true,false,false);
	dept="CMPE";

	Format();
			char idmanip[10];
			for(unsigned i=0;i<iD.length();i++)
				idmanip[i]=iD.at(i);
			numiD=atol(idmanip);
			again: numiD=((rand()%10000000) * (rand()%1000000))%10000000000;
			if(numiD<999999999) goto again;
}

StudentNode& StudentNode::Format()  //Erases leading and following whitespaces, makes all characters uppercase
{	
	string Sntemp;
	string IDtemp;
	string Ntemp;
	string Dtemp;
	int i,j,k;
	
	

	try{
	
		//ID
		for(i=0;isspace(iD.at(i)); i++);
		for(j=iD.length()-1;isspace(iD.at(j)) || j<0;j--);
		for(k=i; k<=j ;k++) IDtemp+=iD.at(k);
		iD=IDtemp;
	
		//SURNAME
	
		for(i=0;isspace(surname[i]); i++);
		for(j=surname.length()-1;isspace(surname[j]);j--);
		for(k=i; k<=j ;k++) Sntemp+=surname[k];
		surname=Sntemp;
	
		transform(surname.begin(), surname.end(),surname.begin(),::toupper); // see algorithm header for detailed info

		//NAME

		for(i=0;isspace(name[i]); i++);
		for(j=name.length()-1;isspace(name[j]);j--);
		for(k=i; k<=j ;k++) Ntemp+=name[k];
		name=Ntemp;

		transform(name.begin(), name.end(),name.begin(),::toupper);

		//DEPT

		for(i=0;isspace(dept[i]); i++);
		for(j=dept.length()-1;isspace(dept[j]);j--);
		for(k=i; k<=j ;k++) Dtemp+=dept[k];
		dept=Dtemp;

		transform(dept.begin(),dept.end(),dept.begin(),::toupper);
	}
	catch (std::out_of_range& ex)
	{ 
		cout << "At least one of your value is empty.Empty Values are not accepted!" <<endl;
		
		getline(cin,iD);

		cout << "Enter ID:";
	   	getline(cin,iD);
		
		while(iD.empty()) 
		{	
			cout<<"Student w/o an ID is not accepted" << endl;
			cout << "Enter ID:";
			getline(cin,iD);
		}
		cout << "Enter Name:";
		getline(cin,name);
		while(name.empty()) 
		{	
			cout<<"Student w/o a Name is not accepted" << endl;
			cout << "Enter Name:";
			getline(cin,name);
		}
		cout << "Enter Surname:";
		getline(cin,surname);
		while(surname.empty()) 
		{	
			cout<<"Student w/o a Surname is not accepted" << endl;
			cout << "Enter Surname:";
			getline(cin,surname);
		}
		cout << "Enter Department:";
		getline(cin,dept);
		while(dept.empty()) 
		{	
			cout<<"Student w/o a department is not accepted" << endl;
			cout << "Enter Dept:";
			getline(cin,dept);
		}
		Format();
	}
 	return (*this);
	
}


	
ostream& operator<<(ostream& os, StudentNode st) // printing one node
{
	
	os << setw(10) << right << st.numiD <<" "<< st.surname <<" "<< st.name <<" "<< st.dept;
	
	return os;
}





