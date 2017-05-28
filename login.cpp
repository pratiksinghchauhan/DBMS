//************************ HEADER FILES USED ******************
#include <fstream.h>     // for file handling
#include <string.h>      // for strcmp()
#include <stdio.h>       // for gets() and printf
#include <conio.h>       // for clrscr() , getch()
#include <time.h>        // for time function
#include <sys\stat.h>    // for knowing the size of file
#include <iomanip.h>     // For setw()
#define CL_Size  50      // Size of class (to be changed manually)
//*********************************** Declaration of global variables
int i=0,login=0,flag=0,role=0,admin=0;
char c,fnd='n',opt[5],temp[14];   // opt is option ( for character filter )
char tname[14]={NULL};   // temporary name
char ad_tname[14]={NULL};
char tpswd[14]={NULL};   //temporary password
//******************************************************delay()
void delay(int i)  // for delaying the execution of succeeding code
{
	int a,b,c;
	for(a=0;a<=i;a++)
	{
		for(b=0;b<=i;b++)
		  for(c=0;c<=i;c++);
	}
}
//******************************************** programmer made getPass()
void getPass(char p[14])
{
	int i=0;
	while(1)
	{
		c=getch();
		if(c==13)
		  break;
		p[i++]=c;
		if(c!= '\b')
		 cout<<"*";      // for secrecy
		p[i]='\0';
	}
}
	/*int star=0;                        //exp started
	while(1)
	{
		c=getch();
		pswd[i++]=c;
		if(c==13)
			break;
		if(c!='\b')
		{
			cout<<"*";
			star++;
		}

		else
		{
			while(star!=0)
			{
				pswd[i--]='0';
				cout<<'\b';
				star--;
			}
		}
	}
	pswd[i]='\0';   //exp ended
	*/

//**************************************************FileSize()
int FileSize()
{
	 struct stat statbuf;
	 stat("password.dat", &statbuf);
	 return statbuf.st_size;
}
//********************************************class password
class password
{
		char uname[14];   // username
		char pswd[14];    // password
		char hint[20];    // password hint
		int value;
	public:
		int ret_value(){return value;}
		char* ret_uname(){return uname;}
		char* ret_pswd(){return pswd;}
		char* ret_hint(){return hint;}
		void storeData();
};
//****************************************void password::storeData()
void password::storeData()
{
	signup:
	clrscr();
	cout<<"\t  CREATE ACCOUNT \n";
	cout<<"\n Enter details ";
	ifstream fin("password.dat",ios::in|ios::binary);
	if(FileSize()==0 || !fin)
		value=1;
	else
		value=0;
	cout<<"\n\n Enter username (maximum 14 characters):- ";
	gets(uname);
	password p;
	fin.seekg(0); // checking if username already exists
	while(fin.read((char*)&p,sizeof(p)))
	{
		if(strcmpi(p.uname,uname)==0)
		{
			cout<<" User name already exists. Try again\a";
			delay(1300);
			fin.close();
			goto signup;
		 }
	}
	cout<<" Enter password (maximum 14 characters):- ";
	getPass(pswd);
	char tpass[14];
	cout<<"\n Re enter password to confirm :- ";
	getPass(tpass);
	if(strlen(uname)==0 || strlen(pswd)==0)
	{
		cout<<"\n\n Either username or password is not entered.\a\n"
				"\n Please press any key to try again or escape "
				"\n to go to main menu";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	else if(strlen(pswd)>14 || strlen(tpass)>14)
	{
		cout<<"\n Password too long\a"
				"\n Please press any key to try again";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	else if(strcmp(pswd,tpass)!=0)
	{
		cout<<"\n\n Passwords do not match \a"
				"\n Please press any key to try again";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	cout<<"\n Enter a password hint (maximum 20 characters):- ";
	gets(hint);
	flag=0;
	if(strlen(uname)>0 && strlen(uname)<15 && strlen(pswd)>0 &&strlen(pswd)<15&& strcmp(pswd,tpass)==0 && strlen(hint)>0 && strlen(hint)<21)
	{
		flag=1;
		cout<<"\n Thanks for registering\n";
	}
} // "void password::storedata()" closes
//*************************************************************
 password p;// Global class
//***********************************************create_Account()
void create_Account()
{
	 ofstream fout("password.dat",ios::app|ios::binary);
	 if(!fout)
	 {
		cout<<" File Error\a";
		return;
	 }
	 p.storeData();
	 if(strlen(p.ret_uname())!=0 && flag==1)
	 {
		fout.write((char*)&p,sizeof(p));
		fout.close();
		cout<<"\n Account created successfully ";
	 }
	 else
		cout<<"\n\n Oops !! Sorry something went wrong. Please try to create account again. "
				"\n Make sure you enter Name, Password and Hint within specified limit";
	 getch();
	 return;
}
//************************************************delete_Account()
void delete_Account()
{
	 clrscr();
	 cout<<"\n\t Delete Account \n";
	 cout<<"\n Are you sure you want to delete this account (Y/N)?      ";
	 c=getche();
	 if(c=='y'||c=='Y')
	 {
		ifstream fin("password.dat",ios::in|ios::binary);
		ofstream foc("pass_temp.dat",ios::out|ios::binary);
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(strcmpi(p.ret_uname(),tname)!=0)
				foc.write((char*)&p,sizeof(p));
		}
		remove("password.dat");
		rename("pass_temp.dat","password.dat");
	  }
	 else
		return;
	 cout<<"\n\n Account successfully deleted"
			 "\n Press any key  ";
	 getch();
	 delay(1480);
	 return;
}
//*****************************************************LogIn()
void LogIn()
{
	clrscr();
	cout<<"\n Are you a guest ?"
			"\n Guest is someone who does not has an account"
			"\n Enter Y for Yes or N for No    ";
	c=getche();
	delay(1000);
	if(c=='y' || c=='Y')
	{
		login=1;
		role=0;
		strcpy(tname,"Guest");
		cout<<"\n\n Hello Guest.";
		getch();
		return;
	}
	login:
	ifstream fin("password.dat",ios::in|ios::binary);
	if(!fin)
	{
		cout<<"  File Error \a";
		fin.close();
		delay(1400);
		return;
	}
	clrscr();
	fin.close();
	tname[0]=NULL;   // For emptying the previous data
	tpswd[0]=NULL;
	cout<<"\tLOGIN";
	login=role=admin=0;
   fin.open("password.dat",ios::in|ios::binary);
	cout<<"\n\n Enter username :- ";
	gets(tname);
	cout<<" Enter password :- ";
	getPass(tpswd);
	fin.seekg(0);
	while(fin.read((char*)&p,sizeof(p)))
	{
		if(strcmpi(p.ret_uname(),tname)==0 && strcmp(p.ret_pswd(),tpswd)==0)
			{
				cout<<"\n CORRECT!! WELCOME...";
				login=1;
				role=1;
				fnd='y';
				fin.close();
				getch();
				return;
			}
	}
	fin.close();
	fin.open("password.dat",ios::binary);
	while(fin.read((char*)&p,sizeof(p)))
	{
		if(strcmpi(p.ret_uname(),tname)==0 && p.ret_value()!=1)
		{
				strcpy(temp,p.ret_hint());    // Finding password hint
		}
	}
	if(fnd=='n')
	{
		cout<<"\n INCORRECT..Please try again....\a\n\n";
		cout<<"\n Password Hint :-  ";
		puts(temp);
		fin.close();
		cout<<"\n\n Press any other key to try again\n"
				" or press escape to go to password menu";
		if(getch()==27)
			return;
		else
			goto login;
	}
}
//********************************************************LogOut()
void LogOut()
{
	if(login!=1)
	{
		cout<<"\n Already logged out. Press any key.\a";
		return;
	}
	logout:
	clrscr();
	cout<<"\t LOGOUT\n";
	cout<<"\n Logged in as "<<tname<<endl<<endl;
	cout<<"\n Press 1 to logout or 2 to go back";
	c=getch();
	if(c=='1' )
	{
		login=0;      // logged out
		role=0;
		admin=0;
		cout<<"\n\n Logged out successfully";
		delay(1400);
		fnd='n';
		return;
	}
	else if(c=='2')
		return;
	else
	{
		cout<<"\n INVALID INPUT\a";
		delay(1300);
		goto  logout;
	}
}// else if for logout closes
//****************************************************void administrator()
void administrator()
{
	ifstream fin("password.dat",ios::in|ios::binary); //creating object & opening
	clrscr();
	cout<<"\t ADMINISTRATOR's MENU\n";
	if(FileSize()==0 || !fin)
	{
		cout<<"\n You are the first user of this software and you will be it's administrator."
				"\n You need to create an account first.\n"
				"\n Press any key to create an account";
		getch();
		create_Account();
		fin.close();
		return;
	}
	admin_login:    // Special login system for admin
	fin.close(); 	 //In case admin has already created account
	fin.open("password.dat",ios::in|ios::binary);
	clrscr();
	cout<<"\t ADMINISTRATOR's MENU\n";
	cout<<"\n Enter administrator's password :- ";
	tpswd[0]=NULL;
	getPass(tpswd);
	char admin_nm[14]={NULL};
	fin.seekg(0);
	fnd='n';
	c='0';
	while(fin.read((char*)&p,sizeof(p)))
	{
		if(strcmp(p.ret_pswd(),tpswd)==0 && p.ret_value()==1)
		{
			strcpy(admin_nm,p.ret_uname());
			strcpy(tname,admin_nm);
			cout<<"\n\n Welcome administrator "<<admin_nm<<endl;
			login=1;
			role=100;
			fnd='y';
			fin.close();
			getch();
			break;
		}
		else if(fnd=='n')
		{
			cout<<"\n\n INCORRECT PASSWORD\n\n Press any key to try again or escape to go back\a";
			fin.close();
			getch();
			goto admin_login;
		}
	}
	admin_fn:
	if(fnd=='n')
		return;
	clrscr();
	cout<<"\n\t\t\t\t\t\tAdmin : "<<admin_nm<<endl;
	cout<<"\n\t ADMINISTRATOR MENU\n"
			"\n Manage Accounts\n"
			"\n Press : \n"
			"\n 1 for Creating an Account"
			"\n 2 for Deleting an Account"
			"\n 3 for Viewing  an Account"
			"\n 4 for Statistics"
			"\n 5 for LogOut    " ;
	c=getche();
	delay(1000);
	if(c=='1')
	{
		create_Account();
		goto admin_fn;
	}
	else if(c=='2')
	 {
		admin_da:
		clrscr();
		cout<<"\t ACCOUNT DELETION\n";
		cout<<"\n Names of accounts created are listed below :";
		fin.open("password.dat",ios::in|ios::binary);
		cout<<"\n +===================================================+"
				"\n | Serial Number  ||   Username of account holder    |"
				"\n +===================================================+";
		i=1;
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(p.ret_value()!=1)
			{
				cout<<"\n |"<<setw(6)<<(i++)<<setw(12)<<"||"<<setw(31)<<p.ret_uname()<<"  |";
			}
		}
		cout<<"\n +===================================================+";
		fin.close();
		cout<<"\n Type name of account to be DELETED :- ";
		gets(ad_tname);
		if(strlen(ad_tname)==0)
		{
			cout<<"\n Nothing entered !!\a";
			delay(1200);
			goto admin_fn;
		}
		fin.open("password.dat",ios::in|ios::binary);
		flag=0;
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(strcmpi(ad_tname,p.ret_uname())==0)
			{
				strcpy(tname,ad_tname);
				flag=1;
				delete_Account();
				fin.close();
            strcpy(tname,"Administrator");
				goto admin_fn;
			}
		}
		if(strcmpi(ad_tname,p.ret_uname())!=0 && flag==0)
			{
				cout<<"\n No such name found. Press any key. \a";
				fin.close();
				getch();
				goto admin_da;
			}
	 }
	else if(c=='3')
	{
		clrscr();
		cout<<"\t ACCOUNT DETAILS\n";
		clrscr();
		cout<<"\n Names of accounts created are listed below :";
		fin.open("password.dat",ios::in|ios::binary);
		cout<<"\n +===================================================+"
				"\n | Serial Number  ||   Username of account holder    |"
				"\n +===================================================+";
		i=1;
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(p.ret_value()!=1)
			{
				cout<<"\n |"<<setw(6)<<(i++)<<setw(12)<<"||"<<setw(31)<<p.ret_uname()<<"  |";
			}
		}
		cout<<"\n +===================================================+";
		fin.close();
		cout<<"\n Type name of account to  VIEW DETAILS :- ";
		gets(ad_tname);
		if(strlen(ad_tname)==0)
		{
			goto admin_fn;
		}
		fin.open("password.dat",ios::in|ios::binary);
		flag=0;
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(strcmpi(ad_tname,p.ret_uname())==0)
			{
				flag=1;
				break;
			}
		}
		if(flag==1)
			{
				cout<<"\n Name :- "<<p.ret_uname();
				cout<<"\n Password :- "<<p.ret_pswd();
				cout<<"\n Password Hint :- ";
				puts(p.ret_hint());
				fin.close();
				cout<<"\n\n\n Press any key";
				getch();
				goto admin_fn;
			}
		getch();
		goto admin_fn;
	}
	else if(c=='4')
	{
		clrscr();
		struct stat statbuf;
		stat("password.dat", &statbuf);
		cout<<"\n\t STATISTICS\n";
		cout<<"\n Total accounts created (including yours):- "<<(FileSize()/CL_Size);
		cout<<"\n Size of password file is "<<(double(FileSize())/(1024))<<" KiloBytes";
		printf("\n Time file last opened: %s", ctime(&statbuf.st_ctime));
		cout<<"\n\n Press any key :-)";
		getch();
		goto admin_fn;
	}
	else if(c=='5')
	{
		LogOut();
	}
	else
		goto admin_fn;
}
//******************************************************************pass()
void pass()
{
	 passmain:
	 clrscr();
	 cout<<"\n\t\tAuthentication System  (Version 20-Dec-2013)\n";
	 //-----------------TIME and DATE--------------------------------
	 time_t rawtime;
	 struct tm * timeinfo;
	 time (&rawtime);
	 timeinfo = localtime (&rawtime);
	 printf ("\n Current time and date: %s", asctime(timeinfo));
	 if(login==1)
		cout<<"\n Select an option ... \t\t\t\tLogged in as "<<tname;
	 else
		cout<<"\n Select an option ... ";
	 if(login!=1 || login==1)
	 {
		cout<<"\n\n Enter : \n\n"
				" 1 for LogIn or LogOut	\n"
				" 2 for Administrator's Menu \n";
	 }
	 cout<<"\n\n  OPTION :- ";
	 gets(opt);
	 if(strlen(opt)>1)
	 {
		cout<<"\n  INVALID INPUT. Please try again\a";
		delay(1200);
		goto passmain;
	 }
	 else
	 {
		for(i=0;i<1;i++) // i is global. It may have garbage value. So loop is needed
			c=opt[i];
	 }
	if(c=='1' && login!=1)
	 {
		 LogIn();
		 goto passmain;
	 }
	 else if(c=='1' && login==1)
	{
		LogOut();
		goto passmain;
	}
	else if(c=='2' && login!=1)
	{
		 administrator();
		 goto passmain;
	}
	else if(c=='2' && login==1)
	{
		cout<<"\n  You must log out first\a";
		delay(1300);
		goto passmain;
	}
	else
		goto passmain;
}
void main()
{
	pass();
}
