//************************ HEADER FILES USED ******************
#include <fstream.h>     // for file handling
#include <string.h>      // for strcmp() and strcmpi()
#include <stdio.h>       // for gets() , puts() and printf
#include <conio.h>       // for clrscr() , getch()
#include <time.h>        // for time function
#include <sys\stat.h>    // for knowing file info
#include <iomanip.h>     // For setw()
#include <password.h>    // It contains password module. It's made by us.
#include <db.h>          // It contains all dbms things. It's made by us.
#include <ctype.h>   
void instruction()
{

		clrscr();
		cout<<"\n\t\t\t KRYPTON DATABASE MANAGEMENT SYSTEM\n"<<endl;
		cout<<"\n\t Step 1 :: Goto password menu and login.\n"
				"\n\t If you don't have an account then ask admin to create it for you"
				"\n\t Registered users have full access to database features "
				"\n\t Guests cannot update or delete a table.\n"
				"\n\t Step 2 :: Goto Start and do whatever you want to do.\n"
				"\n\t Step 3 :: Enjoy.\n"
				"\n\t Step 4 :: When exiting, logout by going to password menu. ";
		getch();
}

void about()
{
		clrscr();
		cout<<"\n\tKRYPTON DATABASE MANAGEMENT SYSTEM ";
		cout<<"\n\tVersion 19.01.2014\n";
		cout<<"\tDeveloped by:- "
				"\n\t\t\t\t 1. Abhishek"
				"\n\t\t\t\t 2. Bikki"
				"\n\t\t\t\t 3. Kewal"
				"\n\t\t\t\t 4. Pratik\n\n";
		cout<<"\tThis program is COPYRIGHT© PROTECTED . Any part of this "
				"program\n\tshould NOT be duplicated, distributed or sold in any "
				"manner, \n\twithout the written permission of the authors.\n\n";
		getch();

}

void main()
{        
	int ctrf=0,zi=0;
	char zc[5]={'<',' ',' ',' ',' '}; //initializing_to_blanks
	char zk; //to_store_typed_char
	mains:
	do
	{
	clrscr();
	cout<<"\n\t\t____________________________________________\n"
			"\n\t\t    KRYPTON DATABASE MANAGEMENT SYSTEM"
			"\n\t\t____________________________________________";
			
	if(login==1)
		cout<<"\n\n\t MAIN MENU \t\t\t\t     Logged in as "<<tname<<endl<<endl;
	else
		cout<<"\n\n\t MAIN MENU \n\n";
	cout<<"    1.  START          "<<zc[0]<<zc[0]<<zc[0]<<endl
		 <<"    2.  INSTRUCTIONS   "<<zc[1]<<zc[1]<<zc[1]<<endl
		 <<"    3.  ABOUT	         "<<zc[2]<<zc[2]<<zc[2]<<endl
		 <<"    4.  PASSWORD MENU  "<<zc[3]<<zc[3]<<zc[3]<<endl
		 <<"    5.  QUIT           "<<zc[4]<<zc[4]<<zc[4]<<endl;
	zk=getch();
	if(zk==13) //if_enter_is_pressed
		break;
	if(zk=='w')
		{
		 zi=zi-1;
		 if(zi==(-1))
		zi=4;
		 for(int zl=0;zl<5;zl++) //initializing_to_blanks
		zc[zl]=' ';
		 zc[zi]='<';
		}
	 else if(zk=='s')
	 {
	 zi=zi+1;
	  if(zi==5)
		 zi=0;
	 for(int zl=0;zl<5;zl++)  //initializing_to_blanks
		zc[zl]=' ';
	 zc[zi]='<';
	 }
	else
	{
	clrscr();
	cout<<"Please USE W OR S TO NAVIGATE AND ENTER TO SELECT THE HIGHLIGHTED OPTION";
	getch();
	goto mains;
	}
}
	while(ctrf==0);
	// for choice(zi+1) ==1
	if(zi+1==1)
		{
			clrscr();
			if(login==1)
				hdb();
			else
			{
				cout<<"\n\n  You need to log in first.\n  Please go back and login from password menu\n  Press any key to go back\a";
				getch() ;
			}
			goto mains;
		}
	// for choice(zi+2) ==2
	if(zi+1==2)
		{
			clrscr();
			instruction();
			goto mains;
		}
	if(zi+1==3)
		{
		about();
		goto mains;
		}

	if((zi+1)==4)
		{
			clrscr();
			cout<<"\n\t ACCOUNT RELATED SETTINGS\n\n";
			pass();
			goto mains;
		 }

	 if((zi+1)==5);
		{
		clrscr();
		cout<<"\n\t  Thank you :-) . Bye. Come back again";
		return;
		}
}
