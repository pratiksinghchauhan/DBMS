# define CL_Size 50 // Size of class to be changed manually
//*********************************** Declaration of global variables
int ip=0,login=0,flagp=0,valuep=0,admin=0;
char c,fnd='n',opt[5],temp[14];   // opt is option ( for character filter )
char tname[14]={NULL};   // temporary name
char ad_tname[14]={NULL};
char tpswd[14]={NULL};   //temporary password
//******************************************************delay()
/*
void delay(int ip)  // for delaying the execution of succeeding code
{
	int a,b,c;
	for(a=0;a<=ip;a++)
	{
		for(b=0;b<=ip;b++)
		  for(c=0;c<=ip;c++);
	}
}
*/
//******************************************** programmer made getPass()
void getPass(char p[14])
{
	int ip=0;
	while(1)
	{
		c=getch();


		if(c==13)
		  break;
		p[ip++]=c;
		if(c!= '\b')
		 cout<<"*";      // for secrecy
		p[ip]='\0';
	}
}
//****************************************************** encrypt()
void encrypt(char p[14])
{
	 int ip=0;
	 for(ip=0;ip<strlen(p);ip++)
	 {
		c='p';
		p[ip]=p[ip]+1+(int)c;    // very easy :-)
	 }
}
//****************************************************** decrypt()
void decrypt(char p[14])
{
	 int ip=0;
	 c='p';
	 for(ip=0;ip<strlen(p);ip++)
	 {
	  p[ip]=p[ip]-1-(int)c;
	 }
}
//**************************************************FileSize()
int FileSize()
{
	 struct stat statbuf;
	 stat("d:\\password.dat", &statbuf);
	 return statbuf.st_size;
}
//********************************************class password
class password
{
		char uname[14];   // username
		char pswd[14];    // password
		char hint[20];    // password hint
		int role;
	public:
		int ret_role(){return role;}
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
	cout<<"\n  Enter details ";
	ifstream fin("d:\\password.dat",ios::in|ios::binary);
	cout<<"\n\n  Enter username (maximum 13 characters):- ";
	gets(uname);
	password p;
   ip=0;
	fin.seekg(0); // checking if username already exists
	while(fin.read((char*)&p,sizeof(p)))
	{
		decrypt(p.uname);
		if(strcmpi(p.uname,uname)==0)
		{
			cout<<"\n  User name already exists. Try again\a";
			//delay(1300);
			fin.close();
			goto signup;
		 }
		 ip++;
	}
	cout<<"\n  Use combination of alphabets, digits, symbols for stronger password\n\n";
	cout<<"  Enter password (maximum 13 characters):- ";
	getPass(pswd);
	char tpass[14];
	cout<<"\n  Re enter password to confirm :- ";
	getPass(tpass);
	if(strlen(uname)==0 || strlen(pswd)==0)
	{
		cout<<"\n\n  Either username or password is not entered.\a\n"
				"\n  Please press any key to try again or escape "
				"\n  to go to main menu";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	else if(strlen(pswd)>14 || strlen(tpass)>14)
	{
		cout<<"\n  Password too long\a"
				"\n  Please press any key to try again";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	else if(strcmp(pswd,tpass)!=0)
	{
		cout<<"\n\n  Passwords do not match \a"
				"\n  Please press any key to try again";
		c=getch();
		if(c==27)
			return;
		else
			goto signup;
	}
	cout<<"\n\n  Hint will help you to remember your password in case you forget it.\n";
	cout<<"\n  Enter a password hint (maximum 20 characters):- ";
	gets(hint);
	if(ip>0)
	{
		cout<<"\n  Enter 0 for standard account or 1 for administrator account:- ";
		cin>>role;
	}
	else
   	role=1;
	flagp=0;
	if(strlen(uname)>0 && strlen(uname)<15 && strlen(pswd)>0 &&strlen(pswd)<15&& strcmp(pswd,tpass)==0 && strlen(hint)>0 && strlen(hint)<21 )
	{
		if(role==1 || role==0)
		{
			flagp=1;
			encrypt(pswd);
			encrypt(uname);
			encrypt(hint);
			cout<<"\n  Thanks for registering\n";
		}
	}
} // "void password::storedata()" closes
//*************************************************************
 password p;// Global class
//***********************************************create_Account()
void create_Account()
{
	 ofstream fout("d:\\password.dat",ios::app|ios::binary);
	 if(!fout)
	 {
		cout<<"  File Error. \a";
		return;
	 }
	 p.storeData();
	 if(strlen(p.ret_uname())!=0 && flagp==1)
	 {
		fout.write((char*)&p,sizeof(p));
		fout.close();
		cout<<"\n  Account created successfully ";
	 }
	 else
		cout<<"\n\n  Oops !! Sorry something went wrong. Please try to create account again. "
				"\n  Make sure you enter Name, Password and Hint within specified limit or"
				"\n  typing your details with less length may help\a";
	 getch();
	 return;
}
//************************************************delete_Account()
void delete_Account()
{
	 clrscr();
	 cout<<"\n\t  Delete Account \n";
	 cout<<"\n  Are you sure you want to delete this account (Y/N)?      ";
	 c=getche();
	 if(c=='y'||c=='Y')
	 {
		ifstream fin("d:\\password.dat",ios::in|ios::binary);
		ofstream foc("d:\\pass_temp.dat",ios::out|ios::binary);
		while(fin.read((char*)&p,sizeof(p)))
		{
			decrypt(p.ret_uname());
			if(strcmpi(p.ret_uname(),tname)!=0)
			{
				encrypt(p.ret_uname());
				foc.write((char*)&p,sizeof(p));
			}
		}
		remove("d:\\password.dat");
		rename("d:\\pass_temp.dat","d:\\password.dat");
	  }
	 else
		return;
	 cout<<"\n\n  Account successfully deleted"
			 "\n  Press any key  ";
	 getch();
	 //delay(1480);
	 return;
}
//*****************************************************LogIn()
void LogIn()
{
	clrscr();
	cout<<"\n\n   Press U for user or G for Guest\n\n"
			"\n   +--------------+      +--------------+"
			"\n   |     User     |      |     Guest    |"
			"\n   +--------------+      +--------------+\n\n   ";
	c=getche();
	//delay(1000);
	if(c=='g' || c=='G')
	{
		login=1;
		valuep=0;
		strcpy(tname,"Guest");
		cout<<"\n\n\n   Hello Guest. Press any key";
		getch();
		return;
	}
	else if(c==27)
   	return;
	login:
	ifstream fin("d:\\password.dat",ios::in|ios::binary);
	if(!fin)
	{
		clrscr();
		cout<<"\n\t\t  File Error \a"
				"\n\n\n\n    May be the file does not exist or we are not able to access it"
				"\n\n\n\n    Please ask the administrator to make an account for you and then try"
				"\n\n\n\n\t\t  Press any key";
		fin.close();
		getch();
		return;
	}
	clrscr();
	fin.close();
	tname[0]=NULL;   // For emptying the previous data
	tpswd[0]=NULL;
	cout<<"\t LOGIN";
	login=valuep=admin=0;
   fin.open("d:\\password.dat",ios::in|ios::binary);
	cout<<"\n\n  Enter username :- ";
	gets(tname);
	cout<<"  Enter password :- ";
	getPass(tpswd);
	fin.seekg(0);
	while(fin.read((char*)&p,sizeof(p)))
	{
		decrypt(p.ret_uname());
		decrypt(p.ret_pswd());
		if(strcmpi(p.ret_uname(),tname)==0 && strcmp(p.ret_pswd(),tpswd)==0)
			{
				cout<<"\n  CORRECT!! WELCOME...";
				login=1;
				valuep=1;
				fnd='y';
				fin.close();
				getch();
				return;
			}
	}
	fin.close();
	fin.open("d:\\password.dat",ios::binary);
	while(fin.read((char*)&p,sizeof(p)))
	{
   	decrypt(p.ret_uname());
		if(strcmpi(p.ret_uname(),tname)==0)
		{
				decrypt(p.ret_hint());
				strcpy(temp,p.ret_hint());    // Finding password hint
		}
	}
	if(fnd=='n')
	{
		cout<<"\n  INCORRECT..Please try again....\a\n\n";
		cout<<"\n  Password Hint :-  ";
		puts(temp);
		fin.close();
		cout<<"\n\n  Press any other key to try again"
				"\n  or press escape to go to password menu";
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
		cout<<"\n  Already logged out. Press any key.\a";
		return;
	}
	logout:
	clrscr();
	cout<<"\t\t  LOGOUT\n\n";
	cout<<"  Come back soon :-)\n\n";
	cout<<"\n  Press 1 to logout or 2 to go back";
	c=getch();
	if(c=='1' )
	{
		login=0;      // logged out
		valuep=0;
		admin=0;
		cout<<"\n\n  Logged out successfully";
		//delay(1400);
		fnd='n';
		return;
	}
	else if(c=='2')
		return;
	else
	{
		cout<<"\n  INVALID INPUT\a";
		//delay(1300);
		goto  logout;
	}
}// else if for logout closes
//****************************************************void administrator()
void administrator()
{
	ifstream fin("d:\\password.dat",ios::in|ios::binary); //creating object & opening
	clrscr();
	cout<<"\n\t\t  ADMINISTRATOR's MENU\n";
	if(FileSize()==0 || !fin)
	{
		cout<<"\n  You are the first user of this software and you will be it's \n  first administrator."
				"\n  You need to create an account first.\n"
				"\n  Press any key to create an account";
		getch();
		create_Account();
		fin.close();
		return;
	}
	admin_login:    // Special login system for admin
	fin.close(); 	 //In case admin has already created account
	fin.open("d:\\password.dat",ios::in|ios::binary);
	clrscr();
	cout<<"\t  ADMINISTRATOR's MENU\n";
	cout<<"\n  Enter administrator's name :- ";
	gets(tname);
	cout<<"\n  Enter administrator's password :- ";
	getPass(tpswd);
	//encrypt(tpswd);
	char admin_nm[14]={NULL};
	fin.seekg(0);
	fnd='n';
	c='0';
	while(fin.read((char*)&p,sizeof(p)))
	{
		decrypt(p.ret_uname());
		decrypt(p.ret_pswd());
		if(strcmp(p.ret_pswd(),tpswd)==0 && strcmpi(tname,p.ret_uname())==0 && p.ret_role()==1)
		{
			strcpy(admin_nm,p.ret_uname());
			strcpy(tname,admin_nm);
			//decrypt(admin_nm);
			cout<<"\n\n  Welcome administrator "<<admin_nm<<endl;
			login=1;
			valuep=1;
         admin=1;
			fnd='y';
			fin.close();
			getch();
			break;
		}
	}
	 if(fnd=='n')
		{
			cout<<"\n\n  Either username or password is wrong !!!\n\n  Password hint for administrator account will not be shown for security \n  reasons.\n\n  Press any key to try again or escape to go back \a";
			fin.close();
			c=getch();
			if(c==27)
				return;
			else
				goto admin_login;
		}
	admin_fn:
   fin.close();
	if(fnd=='n')
		return;
	clrscr();
	cout<<"\n\t\t\t\t\t\t\tAdmin : "<<admin_nm<<endl;
	cout<<"\n\t\t  ADMINISTRATOR MENU\n"
			"\n   Manage Accounts\n"
			"\n   Just Press and wait : \n"
			"\n   1 for Creating an Account"
			"\n   2 for Deleting an Account"
			"\n   3 for Viewing  an Account"
			"\n   4 for Editing  an Account"
			"\n   5 for Statistics"
			"\n   6 for LogOut"
			"\n   7 to go back     " ;
	c=getche();
	//delay(1000);
	if(c=='1')
	{
		create_Account();
      fin.close();
		goto admin_fn;
	}
	else if(c=='2')
	 {
		admin_da:
		clrscr();
		cout<<"\n\t\t  ACCOUNT DELETION\n";
		cout<<"\n  Names of accounts created are listed below :";
		fin.open("d:\\password.dat",ios::in|ios::binary);
		cout<<"\n  +==========================================================+"
				"\n  | Serial Number  ||      Username      ||   Account type   |"
				"\n  +==========================================================+";
		ip=1;
		while(fin.read((char*)&p,sizeof(p)))
		{
				decrypt(p.ret_uname());
				if(p.ret_role()==1)
					cout<<"\n  |"<<setw(10)<<(ip++)<<setw(8)<<"||"<<setw(15)<<p.ret_uname()<<"     ||"<<setw(2)<<"  Administrator "<<"  |";
				else
					cout<<"\n  |"<<setw(10)<<(ip++)<<setw(8)<<"||"<<setw(15)<<p.ret_uname()<<"     ||"<<setw(2)<<"    Standard    "<<"  |";
		}
		cout<<"\n  +==========================================================+";
		fin.close();
		cout<<"\n  Type name of account to be DELETED :- ";
		gets(ad_tname);
		//encrypt(ad_tname);
		if(strlen(ad_tname)==0)
		{
			cout<<"\n\n  Nothing entered";
			//delay(1250);
			goto admin_fn;
		}
		fin.open("d:\\password.dat",ios::in|ios::binary);
		flagp=0;
		ip=0;
		while(fin.read((char*)&p,sizeof(p)))
		{
			 if(p.ret_role()==1)
				ip++;
		}
		fin.close();
		fin.open("d:\\password.dat",ios::in|ios::binary);
		fin.seekg(0);
		while(fin.read((char*)&p,sizeof(p)))
		{
			decrypt(p.ret_uname());
			if(strcmpi(ad_tname,admin_nm)==0 )
			{
				cout<<"\n  Current account cannot be deleted. To delete this account "
						"\n  first logout and  use other administrator's account to delete it"
						"\n  Press any key";
				getch();
            goto admin_fn;
			}
			if(strcmpi(ad_tname,p.ret_uname())==0 )
			{
				if(ip==1 && p.ret_role()==1 && strcmpi(ad_tname,p.ret_uname())==0)
				{
					flagp=0;
					cout<<"\n Program has only one administrator and this account cannot be deleted\a";
					//delay(1300);
				}
				else
				{
					strcpy(tname,ad_tname);
					delete_Account();
					flagp==1;
				}
				fin.close();
				strcpy(tname,"Administrator");
				goto admin_fn;
			}
		}
		if(strcmpi(ad_tname,p.ret_uname())!=0 && flagp==0)
			{
				cout<<"\n  No such name found. Press any key \a";
				fin.close();
				getch();
				goto admin_da;
			}
	 }
	else if(c=='3')
	{
		clrscr();
		cout<<"\t  ACCOUNT DETAILS\n";
		clrscr();
		cout<<"\n  Names of accounts created are listed below :";
		fin.open("d:\\password.dat",ios::in|ios::binary);
		cout<<"\n  +==========================================================+"
				"\n  | Serial Number  ||      Username      ||   Account type   |"
				"\n  +==========================================================+";
		ip=1;
		while(fin.read((char*)&p,sizeof(p)))
		{
				decrypt(p.ret_uname());
				if(p.ret_role()==1)
					cout<<"\n  |"<<setw(10)<<(ip++)<<setw(8)<<"||"<<setw(15)<<p.ret_uname()<<"     ||"<<setw(2)<<"  Administrator "<<"  |";
				else
					cout<<"\n  |"<<setw(10)<<(ip++)<<setw(8)<<"||"<<setw(15)<<p.ret_uname()<<"     ||"<<setw(2)<<"    Standard    "<<"  |";
		}
		cout<<"\n  +==========================================================+";
		fin.close();
		cout<<"\n  Type name of account to  VIEW DETAILS :- ";
		gets(ad_tname);
		//encrypt(ad_tname);
		if(strlen(ad_tname)==0)
		{
			cout<<"\n\n  Nothing entered";
			//delay(1250);
			goto admin_fn;
		}
		fin.open("d:\\password.dat",ios::in|ios::binary);
		flagp=0;
		while(fin.read((char*)&p,sizeof(p)))
		{
			decrypt(p.ret_uname());
			if(strcmpi(ad_tname,p.ret_uname())==0)
			{
				flagp=1;
				break;
			}
		}
		if(flagp==1)
			{
				decrypt(p.ret_pswd());
				decrypt(p.ret_hint());
				cout<<"\n  Name :- "<<p.ret_uname();
				cout<<"\n  Password :- "<<p.ret_pswd();
				cout<<"\n  Password Hint :- ";
				puts(p.ret_hint());
				if(p.ret_role()==1)
					cout<<"\n  Administrator account";
				else
					cout<<"\n  Standard account";
				fin.close();
				cout<<"\n\n\n  Press any key";
				getch();
				goto admin_fn;
			}
		else if(flagp==0)
		{
			fin.close();
         cout<<"\n\n  Name not found. Press any key";
		}
		getch();
		goto admin_fn;
	}
	else if(c=='4')
	{
   	clrscr();
		cout<<"\n\n\t\t EDIT ACCOUNT DETAILS"
				"\n\n   Dear admin for editing any account simply delete that account first"
				"\n   and create it again with required details. Press any key    ";
		getch();
		goto admin_fn;
	}
	else if(c=='5')
	{
		clrscr();
		struct stat statbuf;
		stat("d:\\password.dat", &statbuf);
		cout<<"\n\t\t  STATISTICS\n";
		cout<<"\n   Total accounts created (including yours):- "<<(FileSize()/CL_Size);
		cout<<"\n\n   Size of password file is "<<(double(FileSize())/(1024))<<" KiloBytes";
		ip=0;
		fin.close();
		fin.open("d:\\password.dat",ios::in|ios::binary);
		while(fin.read((char*)&p,sizeof(p)))
		{
			if(p.ret_role()==1)
				ip++;
		}
		fin.close();
		cout<<"\n\n   Total administrator accounts created :- "<<ip;
		cout<<"\n\n   Total Standard accounts created :- "<<(((FileSize()/CL_Size))-ip);
		printf("\n\n   Time file last opened: %s", ctime(&statbuf.st_ctime));
		cout<<"\n\n   Press any key :-)  ";
		getch();
		goto admin_fn;
	}
	else if(c=='6')
	{
		LogOut();
	}
	else if(c=='7')
   	return;
	else
		goto admin_fn;
}
//******************************************************************pass()
void pass()
{
	 passmain:
	 clrscr();
	 cout<<"\n\t\t PASSWORD MENU  (Version 19/Jan/2014)\n";
	 //-----------------TIME and DATE--------------------------------
	 time_t rawtime;
	 struct tm * timeinfo;
	 time (&rawtime);
	 timeinfo = localtime (&rawtime);
	 printf ("\n  Current time and date: %s", asctime(timeinfo));
	 //---------------------------------------------------------------
	 if(login==1)
		cout<<"\n  Select an option ... \t\t\t\tLogged in as "<<tname;
	 else
		cout<<"\n  Select an option ... ";
	 if(login!=1 || login==1)
	 {
		cout<<"\n\n  Enter : \n\n"
				"  1 for LogIn or LogOut	\n"
				"  2 for Administrator's Menu \n"
				"  3 to go back";
	 }
	 cout<<"\n\n   OPTION :- ";
	 gets(opt);
	 if(strlen(opt)>1)
	 {
		cout<<"\n   INVALID INPUT. Please try again\a";
		//delay(1200);
		goto passmain;
	 }
	 else
	 {
		for(ip=0;ip<1;ip++) // ip is global. It may have garbage value. So loop is needed
			c=opt[ip];
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
		cout<<"\n\n   You must log out first\a";
		//delay(1300);
		goto passmain;
	}
	else if(c=='3')
		return;
	else
		goto passmain;
}
