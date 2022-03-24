#include<iostream>
#include<fstream>
#include<iomanip>
#include<cstdlib>
#include<string>
#include<windows.h>
#include<unistd.h>
using namespace std;
//***************************************************************
//    	function declaration
//****************************************************************
void intro();
void entry_menu();
void write_Employee();
void display_all();
void display_sp(int);
void modify_Employee(int);
void delete_Employee(int);
void addTrainingRecords();
void entryMenu();
void write_training(int); //apply
void print_all(); //display all
void print_sp(int); //search by id
void modify_req(int); //wrong inputs
void delete_req(int); // Cancelation
//void training_event(int);

///////////////////////////////////////////////////////////////////////////////
//****************************************************************
//                   CLASS USED IN PROJECT
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
class Admin
{
  private :
  string username;
  string password;
public:
    void login_page();
};
class Employee
{
private:
    int id;
    char name[1000];
    int age;
    char birthday[11];
    char gender[15];
    int phone;
    char nationality[100];
    char position[100];
    char date1[20];
    char ar[20];
    void display();

public:
    void getdata();
	  void showdata() const;
	  int retid() const;
};
class member
{
  private:
      int id;
  public:
	   void display_sp(int n);
     friend class training;
};
class employee
{
private:
    int id;
public:
    void loginemployee();
};
class training
{
private:
  int id;
    char type[5000];
    char descr[5000];
    char appdate[20];
    void display();

public:
    void getrecords();
	  void showrecords() const;
	  int retid() const;
	  int num;

friend class Admin;
};

class TRAIN{
   string date;
   string traingname;
   string trainigcontact;
   string trainingVenue;
public:
    TRAIN ()
    {

    }
    void setstuff(string d, string n ,string c, string v)
     {
       date = d;
       traingname = n;
       trainigcontact = c;
       trainingVenue = v;

     }

     void display ()
     {
       cout << date <<endl;
       cout << traingname <<endl;
       cout << trainigcontact<< endl;
       cout << trainingVenue << endl;
     }
void addTrainingRecords();
};

class TRAINEmployee{

    TRAIN trainingStuff;
public:
  TRAINEmployee()
  {

  }
    void settraining (TRAIN obj)
    {
      trainingStuff = obj;
    }
    void puttraining()
    {
      trainingStuff.display ();
    }

};

///////////////////////////////////////////////////////////////////////////////
void training::getrecords()
{
  cout<<"\n\tEMPLOYEE ID                :   ";
  cin>>id;
  cout<<"\n\tTRAINING TYPE              :   ";
  cin.ignore();
  cin.getline(type,5000);
  cout<<"\n\tTRAINING DESCRIPTION       :   ";
//  cin.ignore();
  cin.getline(descr,5000);

  cout<<"\n\tAPPLICATION DATE           :   ";
//  cin.ignore();
  cin.getline(appdate,20);
}
void training::showrecords() const
{
  cout<< setw(2)<<"\n\tEMPLOYEE ID              : "<<id;
  cout<< setw(2)<<"\n\tTRAINING TYPE            : "<<type;
  cout<< setw(2)<<"\n\tTRAINING DESCRIPTION     : "<<descr;
  cout<< setw(2)<<"\n\tAPPLICATION DATE         : "<<appdate;

}
int  training::retid()const
{
	return id;
}
void entryMenu()
{
  system("color 90");
	char ch;
	int num;

	system("cls");
  cout <<endl;
  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
  cout << setw(2) << "     \t\tMAIN MENU         "    <<endl<< endl;
  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
  cout << setw(2) << "\t\t1. TRAINING APPLICATION       "  <<endl<<endl;
  cout << setw(2) << "\t\t2. EDIT TRAINING APPLICATION  "  <<endl<<endl;
	cout << setw(2) << "\t\t3. TRAINING CANCELATION       "  <<endl<<endl;
  cout << setw(2) << "\t\t4. VIEW MY PROFILE            "  <<endl<<endl;
  cout << setw(2) << "\t\t5. VIEW MY TRAINING           "  <<endl<<endl;
  cout << setw(2) << "\t\t6. EXIT TO MAIN MENU          "  <<endl<<endl;
  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
	cout << setw(2) << "\tPLEASE INSERT YOUR OPTION (1-5)     "  <<endl <<endl;
  cout << setw(2) << "\tCHOICE :: ";
	cin>>ch;
	system("cls");

	switch(ch)
	{
    case '1'://	cout << setw(2) <<"\nPlease Enter ID number : "; cin>>num;
  				    write_training(num);
  				    break;
    case '2':	cout << setw(2) <<"\n\tPLEASE RE-ENTER EMPLOYEE ID : "; cin>>num;
              if(MessageBox(NULL, "ARE YOU SURE TO MODIFY YOUR DETAILS ", "MODIFICATION",  MB_YESNOCANCEL) == IDYES)
              {   modify_req(num); }
                else
                  { system("CLS");
                    entryMenu();   }

               break;
   case '3':	cout << setw(2) <<"\n\tPLEASE RE-ENTER EMPLOYEE ID : "; cin>>num;
              if(MessageBox(NULL, "ARE YOU SURE TO DELETION YOUR DETAILS ", "DELETION",  MB_YESNOCANCEL) == IDYES)
               {  delete_req(num);  }
                 else
                   { system("CLS");
                     entryMenu();   }
                  break;

	  case '4': cout << setw(2) <<"\n\tPLEASE,VERIFY YOUR EMPLOYEE ID : "; cin>>num;
              display_sp(num);
          	  return;
    case '5': cout << setw(2) <<"\n\tPLEASE,VERIFY YOUR EMPLOYEE ID : "; cin>>num;
                        print_sp(num);
                    	  return;

    case '6':	cout << setw(2) << "\n\tExiting Program";
                      Sleep(1000);
                      return;
  default:	cout<< setw(2) <<"\a"; entryMenu();
  }
}
///////////////////////////////////////////////////////////////////////////////
void write_training(int n)
{
  {
  	 training st;
  	 ofstream outFile;
  	 outFile.open("training.dat",ios::binary|ios::app);
  	 st.getrecords();
  	 outFile.write(reinterpret_cast<char *> (&st), sizeof(training));
  	 outFile.close();
     cout<< setw(2) <<"\n\tNew record Has Been Created ";

  	cin.ignore();
  	cin.get();
  	entryMenu();
  }
}
///////////////////////////////////////////////////////////////////////////////
void modify_req(int n)
{
	bool found=false;
	training st;
	fstream File;
	File.open("training.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(training));
		if(st.retid()==n)
		{
			st.showrecords();
      cout << setw(2) << endl;
			cout << setw(2) <<"\n\tPlease Enter The New Details of the particular member"<<endl;
			st.getrecords();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(training));
        cout << setw(2) << endl;
		    cout<< setw(2) <<"\n\t Record has been Updated"<< endl;
		    found=true;
		}
	}
	File.close();
	if(found==false)
  cout << setw(2) << endl;
//	cout << setw(2) <<" Record Not Found ";
	cin.ignore();
	cin.get();
	entryMenu();
}
///////////////////////////////////////////////////////////////////////////////
void delete_req(int n)
{
	training st;
	ifstream inFile;
	inFile.open("training.dat",ios::binary);
	if(!inFile)
	{
		cout<< setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(training)))
	{
		if(st.retid()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(training));
		}
	}
	outFile.close();
	inFile.close();
	remove("training.dat");
	rename("Temp.dat","training.dat");
  cout << setw(2) << endl;
	cout<< setw(2) <<"\n\t\tRecord Deleted .."<<endl;
	cin.ignore();
	cin.get();
	entryMenu();
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
void print_all()
{
	training st;
	ifstream inFile;
	inFile.open("training.dat",ios::binary);
	if(!inFile)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
  cout<< setw(2) <<"====================================================="<<endl;
	cout<< setw(2) <<"\tDISPLAY ALL RECORD !!!" << endl;
  cout<< setw(2) <<"====================================================="<<endl;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(training)))
	{
		st.showrecords();
    cout << endl;
		cout<< setw(2) <<"=====================================================";
	}
	inFile.close();
	cin.ignore();
	cin.get();
	entry_menu();
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
void print_sp(int n)
{
	training st;
	ifstream inFile;
	inFile.open("training.dat",ios::binary);
	if(!inFile)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(training)))
	{
		if(st.retid()==n)
		{
	  		 st.showrecords();
         cout << endl;
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<< setw(2) <<"\n\t\tRecord does not exist";
	cin.ignore();
	cin.get();
	entryMenu();
}
void employee:: loginemployee()
{
  system("color 3f");
  cout << "\n\n\n";
  cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
  cout << setw(2) <<"\t\tTRAINING MANAGEMENT SYSTEM ADMINSTRATOR LOGIN PAGE "<<endl;
  cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
  cout << "\n\n\n";
  cout<<"\a\n\n\n\n\n\n\n\n\n\t\t\tENTER EMPLOYEE ID: ";
  cin>>id;

  if ((id <1000)||(id>2000))
  {
    {
      cout <<"\t\t\nInvalid Employee ID, Please try again !"<<endl;
      sleep(1);
      system("CLS");
      return loginemployee();
    }
  }
  else
  {
   return entryMenu();
  }
}
///////////////////////////////////////////////////////////////////////////////
void Employee::getdata()
{
  cout<<"\n\tEMPLOYEE ID                            :   ";
  cin>>id;

  if ((id <1000)||(id>2000))
  {
    cout << "\t\nInvalid Employee ID, Please try again !"<<endl;
    sleep(1);
    system("CLS");
    return getdata();
  }
  cout<<"\n\tEMPLOYEE NAME                          :   ";
  cin.ignore();
  cin.getline(name,100);

  cout<<"\n\tEMPLOYEE AGE                           :   ";
  cin>>age;

  cout<<"\n\tEMPLOYEE BIRTHDAY  (DD/MM/YYYY)        :   ";
  cin.ignore();
  cin.getline(birthday,11);

  cout<<"\n\tEMPLOYEE GENDER (FEMALE OR MALE)       :   ";
//  cin.ignore();
  cin.getline(gender,15);

  cout<<"\n\tEMPLOYEE CONTACT NO.                   :   ";
  cin>>phone;

  cout<<"\n\tEMPLOYEE NATIONALITY                   :   ";
  cin.ignore();
  cin.getline(nationality,100);

  cout<<"\n\tEMPLOYEE POSITION                      :   ";
//  cin.ignore();
  cin.getline(position,100);

  cout<<"\n\tEMPLOYEE REGISTRATION DATE(DD/MM/YYYY) :   ";
//  cin.ignore();
  cin.getline(date1,20);

  cout<<"\n\tTRAINING STATUS (APPROVED/REJECTED)    :   ";
//  cin.ignore();
  cin.getline(ar,20);

	}
///////////////////////////////////////////////////////////////////////////////
void Employee::showdata() const
{
	cout<< setw(2)<<"\n\tEMPLOYEE ID                   : "<<id;
  cout<< setw(2)<<"\n\tEMPLOYEE NAME                 : "<<name;
	cout<< setw(2)<<"\n\tEMPLOYEE AGE                  : "<<age;
  cout<< setw(2)<<"\n\tEMPLOYEE BIRTHDAY             : "<<birthday;
  cout<< setw(2)<<"\n\tEMPLOYEE GENDER               : "<<gender;
  cout<< setw(2)<<"\n\tEMPLOYEE CONTACT NO.          : "<<phone;
  cout<< setw(2)<<"\n\tEMPLOYEE NATIONALITY          : "<<nationality;
  cout<< setw(2)<<"\n\tEMPLOYEE POSITION             : "<<position;
	cout<< setw(2)<<"\n\tEMPLOYEE REGISTRATION DATE    : "<<date1;
  cout<<setw(2) <<"\n\tTRAINING STATUS               : "<<ar;
}
///////////////////////////////////////////////////////////////////////////////
int  Employee::retid()const
{
	return id;
}
///////////////////////////////////////////////////////////////////////////////
void intro()
{
  system("color 17");
  MessageBox(NULL, "Welcome Training Management System", " SHECODES ", MB_OK);
  cout << setw(2) <<"\n\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";
	cout<< setw(2) <<"\n\n\t\t  TRAINING MANAGEMENT SYSTEM" <<endl;
  cout<< setw(2)<<"\n\t||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n";

	cout<< setw(2)<<"\n\n\t     DEVELOPED BY : SHECODES";
	cout<< setw(2)<<"\n\n\t     UNIVERSITY   : MULTIMEDIA UNIVERISTY CYBERJAYA";
	cout<< setw(2)<<"\n\n\t     SUBJECT      : SOFTWARE ENGINEERING ";

//	cin.get();
}
///////////////////////////////////////////////////////////////////////////////
void entry_menu()
{
  system("color 1f");
	char ch;
	int num;

	system("cls");
  cout <<endl;

  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
  cout << setw(2) << "     \t\tTRAINING MANAGEMENT SYSTEM         "    <<endl<< endl;
  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
	cout << setw(2) << "\t\t1.ADD EMPLOYEE RECORD             "  <<endl<<endl;

	cout << setw(2) << "\t\t2.VIEW EMPLOYEE RECORDS           "  <<endl<<endl;

	cout << setw(2) << "\t\t3.SEARCH EMPLOYEE RECORD          "  <<endl<<endl;

	cout << setw(2) << "\t\t4.EDIT EMPLOYEE RECORD            "  <<endl<<endl;

	cout << setw(2) << "\t\t5.ADD TRAINING RECORD          "  <<endl<<endl;

  cout << setw(2) << "\t\t6.TRAINING STATUS                 "  <<endl<<endl;

	cout << setw(2) << "\t\t7.EXIT TO MAIN MENU               "  <<endl<<endl;
  cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
	cout << setw(2) << "\tPLEASE INSERT YOUR OPTION (1-7)     "  <<endl<<endl;
  cout << setw(2) << "\tCHOICE :: ";
	cin>>ch;

	system("cls");
	switch(ch)
	{
	case '1':	write_Employee();
	          break;
	case '2':	display_all();
	          break;
	case '3':	cout << setw(2) <<"\n\tPLEASE ENTER EMPLOYEE ID : "; cin>>num;
				    display_sp(num);
				    break;
	case '4':	cout << setw(2) <<"\n\tPLEASE ENTER EMPLOYEE ID : "; cin>>num;
            if(MessageBox(NULL, "ARE YOU SURE TO MODIFY THE FOLLOWING RECORD", " MODIFICATION ", MB_YESNOCANCEL)==IDYES)
            {  modify_Employee(num);}
            { system("CLS");
              entry_menu();}
				    break;
	case '5': addTrainingRecords();
                 entry_menu(); //}
				    break;
   case '6':print_all();
          	break;

	case '7':	cout << setw(2) << "\t\nExiting Program";
            Sleep(1000);
            return;
	default:	cout<< setw(2) <<"\a"; entry_menu();
	}
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	Function to write in text file
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
void addTrainingRecords()
{    TRAIN A,B,C;
    TRAINEmployee D,E,F;
    cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
    cout << "\t\tADD TRAINING RECORDS " << endl;
    cout << setw(2) << "<><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>"<<endl<<endl;
    A.setstuff ("\t\t12/12/2019", "\t\tPERI", "\t\t123321123", "\t\tKLCC");
    B.setstuff("\t\t15/12/2019", "\t\tJOEY",  "\t\t1234565555", "\t\tMMU");
    C.setstuff("\t\t22/12/2019", "\t\tDHARSH","\t\t1234566565", "\t\tAPU");
    D.settraining(A);
    E.settraining(B);
    F.settraining(C);
    D.puttraining ();
    cout << endl;
    E.puttraining();
    cout << endl;
      F.puttraining();
      cout<<endl;
    system("pause");
}
void write_Employee()
{
	 Employee st;
	 ofstream outFile;
	 outFile.open("Employee.dat",ios::binary|ios::app);
	 st.getdata();
	 outFile.write(reinterpret_cast<char *> (&st), sizeof(Employee));
	 outFile.close();
   cout << endl<<endl;
   cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
   cout<< setw(2) <<"\n\tNEW RECORD HAS BEEN SUCCESSFULLY CREATED "<<endl;
   cout<< setw(2) <<"\n <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
	cin.ignore();
	cin.get();
	entry_menu();
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	Function to read all records from file
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
void display_all()
{
	Employee st;
	ifstream inFile;
	inFile.open("Employee.dat",ios::binary);
	if(!inFile)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
  cout<< setw(2) <<"==============================================================================================="<<endl;
	cout<< setw(2) <<"\t\tDISPLAY ALL RECORD !!!" << endl;
  cout<< setw(2) <<"==============================================================================================="<<endl;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Employee)))
	{
		st.showdata();
    cout << endl;
    cout<< setw(2) <<"==============================================================================================="<<endl;
	}
	inFile.close();
	cin.ignore();
	cin.get();
	entry_menu();
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	function to read specific record from file
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
void display_sp(int n)
{
	Employee st;
	ifstream inFile;
	inFile.open("Employee.dat",ios::binary);
	if(!inFile)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	bool flag=false;
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Employee)))
	{
		if(st.retid()==n)
		{
      system ("CLS");
      cout<< setw(2) <<"==============================================================================================="<<endl;
    	cout<< setw(2) <<"\t\tDISPLAY ALL RECORD !!!" << endl;
      cout<< setw(2) <<"==============================================================================================="<<endl;
	  	st.showdata();
      cout <<"\n";
      system("PAUSE");
			 flag=true;
		}
	}
	inFile.close();
	if(flag==false)
  {
  MessageBox(NULL, "WARNING, RECORD DOES NOT EXISIT", " ERROR ", MB_OK);
	cout<< setw(2) <<"\n\tRECORD DOES NOT EXIST";

	cin.ignore();
	cin.get();
	entry_menu();
  }
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	function to modify record of file
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
void modify_Employee(int n)
{
	bool found=false;
	Employee st;
	fstream File;
	File.open("Employee.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout << setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&st), sizeof(Employee));
		if(st.retid()==n)
		{
			st.showdata();
      cout << setw(2) << endl<<endl;
      cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
			cout << setw(2) <<"\tPLEASE INSERT NEW DATA FOR TO MODIFY THE RESULTS ABOVE"<<endl;
      cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl <<endl;
			st.getdata();
		    int pos=(-1)*static_cast<int>(sizeof(st));
		    File.seekp(pos,ios::cur);
		    File.write(reinterpret_cast<char *> (&st), sizeof(Employee));
        cout << setw(2) << endl;
		    cout<< setw(2) <<"\n\t RECORD HAS BEEN SUCCESSFULLY UPDATED"<< endl;
		    found=true;
		}
	}
	File.close();
	if(found==false){
  cout << setw(2) << endl;
	cout << setw(2) <<"\n\t\t RECORD IS NOT FOUND "<< endl;}
	cin.ignore();
	cin.get();
	entry_menu();

}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	function to delete record of file
//****************************************************************
///////////////////////////////////////////////////////////////////////////////
void delete_Employee(int n)
{
	Employee st;
	ifstream inFile;
	inFile.open("Employee.dat",ios::binary);
	if(!inFile)
	{
		cout<< setw(2) <<"\n\tFile could not be open !! Press any Key...";
		cin.ignore();
		cin.get();
		return;
	}
	ofstream outFile;
	outFile.open("Temp.dat",ios::out);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&st), sizeof(Employee)))
	{
		if(st.retid()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&st), sizeof(Employee));
		}
	}
	outFile.close();
	inFile.close();
	remove("Employee.dat");
	rename("Temp.dat","Employee.dat");
  cout << setw(2) << endl;
  cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
	cout<< setw(2) <<"\tRECORD HAS BEEN SUCCESSFULLY DELETED .."<< endl;
  cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl <<endl;
	cin.ignore();
	cin.get();
	entry_menu();
}
///////////////////////////////////////////////////////////////////////////////

int main()
{
    system("color 4A");
    Admin a;
    employee b;
    system("TITLE TSE2101 - TRAINING MANAGEMENT SYSTEM");
  	char ch;
  	int num;
	cout.setf(ios::fixed|ios::showpoint);
  cout<<setprecision(1);
	intro();
  sleep(2.0);
    mm:
    do
	{
	  system("color 1f");
		system("cls");
    cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  "<<endl;
		cout<<" \t\t\tMAIN MENU"<<endl;
    cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  "<<endl;
		cout<<"\n\n\t1. TRAINING MANAGEMENT SYSTEM ADMINISTRATION ";
    cout<<"\n\n\t2. MEMBER LOGIN";
		cout<<"\n\n\t3. EXIT"<<endl;
    cout << endl;
    cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>  "<<endl;
		cout<<"\n\n\tPLEASE SELECT YOUR OPTION (1-3) "<<endl;

		cout<<"\tCHOICE :: ";
    cin >> ch;
		switch(ch)
		{
      case '1': a.login_page();
        				break;
      case '2': system("CLS");
                b.loginemployee();
			case '3' :
      break;
			default :cout<<"\a";
		}
  }while(ch!='3');
    return 0;
}
///////////////////////////////////////////////////////////////////////////////
//***************************************************************
//    	INTRODUCTION FUNCTION
//***************************************************************
///////////////////////////////////////////////////////////////////////////////
void Admin:: login_page()
{
    system("color 3f");
    string username;
    string password;
    int loading = 0;

    system("cls");
    system("color 1f");
    do
    {
        cout << "\n\n\n";
        cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
        cout << setw(2) <<"\t\tTRAINING MANAGEMENT SYSTEM ADMINSTRATOR LOGIN PAGE "<<endl;
        cout<< setw(2) <<" <><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><> "<<endl;
        cout<<"\a\n\n\n\n\n\n\n\n\n\t\t\tENTER USERNAME: ";
        cin>>username;
        if (username == "admin" || username == "ADMIN")
        {
                cout<<"\a\t\t\tENTER PASSWORD: ";
                cin>>password;

                if (password == "1234")
                {
                    for(int i = 0; i < 1; i++)
                        {
                            system("cls");
                            cout<<endl;
                            cout << "\a\n\n\n\n\n\n\n\n\n\t\t\tAccess Granted...\n";
                            Sleep(200);system("cls");Sleep(200);
                        }
                }
                        else
                        {
                            for(int i = 0; i < 3; i++)
                                {
                                    system("cls");
                                    cout<<endl;
                                    cout << "\a\n\n\n\n\n\n\n\n\n\t\t\tAccess Aborted...\n";
                                    Sleep(200);system("cls");Sleep(200);
                                }
                        }
                }
        else
        {
            cout<<"\t\t\t Invalid Username. Try again! " <<endl;
            sleep(1.0);
            system("cls");
        }
      } while (password != "1234");
      while (loading <= 50)
{
  cout << setw(2) << "\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t::... Please Wait While The System Initialize ...::\n";
  cout<<"\t\t\t\t\t\t" << loading << "%";
  //Sleep(20);
  system ("cls");
  loading ++;
  }
  return entry_menu();
}
///////////////////////////////////////////////////////////////////////
