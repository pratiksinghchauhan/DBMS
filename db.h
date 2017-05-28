#include<ctype.h>
class datastru
{
  public:

// DATA MEMBERS
	char tbnm[20];
	char clnm[20][20];
	char datatype[20][20];
	int size[20];
	int nocl;

//	MEMBER FUNCTIONS
	void create();
	void showTable();
	void confirm();
	void alter();
	void desctable();
	void droptable();
	void showTableHead();


};

void datastru :: create()
	{
			int i;
			char choice;
		xx:
			clrscr();
			cout<<"  Enter the name of the table:-";
			gets(tbnm);
			if(strlen(tbnm)==0)
			{
				cout<<"  No data entered.....\n\n";
				goto xx;
			}
			cout<<endl;

			he:
			cout<<"  Enter the number of the coulmn(s):-";
			 cin>>nocl;
			cout<<"\n  Enter the name of coulmn(s)(size should not exceed 20)\n";
			for(i=0;i<nocl;i++)
			{
				aa:
						cout<<"\n\n";
				  cout<<"  Enter the name of coulmn "<<(i+1)<<" :-";
				  gets(clnm[i]);
				  if(strlen(clnm[i])==0)
				  {
					  cout<<"  No data Entered kindly enter a Value........\n\n";
					  goto aa;
				  }
				  cout<<"\nEnter the data type:-\n";

				xxx:
				  cout<<endl;
				  cout<<"\t   Press 1 for INTEGER \n";
				  cout<<"\t   Press 2 for CHARACTER \n";
				  cout<<"\t   Press 3 for STRING \n";
				  cout<<"\t   Press 4 for DATE TYPE \n";
				  cout<<"\t   Press 5 for TIME TYPE \n";
				  cout<<"  Enter your choice:-";
				  cin>>choice;
				  if(choice=='1')
					{
					  strcpy(datatype[i],"integer");
					 mm:
						 cout<<"  Enter the maximum no of Digits(must be LESS than 20):-";
						 cin>>size[i];
						 if(size[i]==0)
						 {
							 cout<<"  The entire coulmn CANNOT be NULL";
							 clrscr();
							 goto mm;
						 }
					 }
				 else if(choice=='2')
					{
					strcpy(datatype[i],"Character");
					size[i]=1;
					}
				 else if(choice=='3')
					{
					 strcpy(datatype[i],"String");

					 nn:

						 cout<<"  Enter the size of the string(Must be LESS than 20):-";
						 cin>>size[i];
						 if(size[i]==0)
						 {
							 cout<<"  The entire coulmn CANNOT be NULL";
							 clrscr();
							 goto nn;
						 }
					}
				else if(choice=='4')
					{
				  strcpy(datatype[i],"Date");
				  size[i]=11;
					}
				else if(choice=='5')
					{
				  strcpy(datatype[i],"Time");
				  size[i]=9;
					}
				else
					{
					  cout<<" Not a valid entry...........";
					  goto xxx;
					}

			}


	clrscr();
	desctable();
	yn:
	 char yesno;
	 cout<<"Are you sure you want to confirm the structure of the table(y/n)?";
	 cin>>yesno;
	 if(yesno=='y' || yesno=='Y')
	 {
		  cout<<"CONFIGURATION SAVED..............\n";
		  cout<<"Press any key to continue..........";
		  getch();
	 }
	 else if(yesno=='n' || yesno=='N')
	 {
			cout<<"OOPS!!!!!!";
			getch();
			clrscr();
			create();
	 }
	 else
	 {
		 cout<<"Please enter a valid input..........";
		 goto yn;
	 }

}
void datastru :: desctable()
{
	int i;
	clrscr();
	cout<<"The name of table is:-"<<tbnm<<endl;
	cout<<"Dear user The structure of the table entered by you is:-\n";
	cout<<"|------------------------------------------------------------------|\n";
	cout<<"|SL. NO.|       COULMN NAME|        DATA TYPE|                 SIZE| \n";
	cout<<"|------------------------------------------------------------------|\n";
	for(i=0;i<nocl;i++)
	{
		cout<<"|"<<setw(7)<<(i+1)<<"|"<<setw(18)<<clnm[i]<<"|"<<setw(17)<<datatype[i];
		cout<<"|"<<setw(21)<<size[i]<<"|"<<"\n";
		cout<<"|------------------------------------------------------------------|\n";
	}

 }
void datastru :: showTable()
{
	 cout<<"                  ";
	 cout<<"|----------------------|\n";
	 cout<<"                  ";
	 cout<<"| "<<tbnm;
	 cout<<setw(22-strlen(tbnm))<<"|"<<endl;
}
void datastru :: alter()
{
  int i;
  char choice;
  clrscr();
  for(i=0;i<nocl;i++)
			{

				char a;
			  w:
				  cout<<"The name of coulmn is:-  "<<clnm[i]<<endl;
				  cout<<"The data type is:-  "<<datatype[i]<<endl;
				  if(strlen(clnm[i])==0)
				  {
					  cout<<"No data Entered kindly enter a Value........\n\n";
					  goto w;
				  }

				  cout<<"\t\t MENU \n 1.Press 1 to change the name\n 2.Press 2 to change the data type\n 3. Press 3 to change both datatype and coulmn name\n 4.Any OTHER key to continue without changing\n";
				  cin>>a;
				  if(a=='1')
				  {
					  jk:
					  cout<<"Enter the new coulmn name:-";
					  gets(clnm[i]);
					  for(int j=0;j<i;j++)
						  if(strcmpi(clnm[j],clnm[i])==0)
						  {
							  cout<<"same coulmn name exists..........\n";
							  cout<<"Please try another valid name......\n\n";
							  getch();
							  clrscr();
							  goto jk;
							}
					}
					if(a=='2')
					{
					  k:
					  cout<<"Enter the data type:-\n";
					  cout<<"\tPress 1 for INTEGER \n";
					  cout<<"\tPress 2 for CHARACTER \n";
					  cout<<"\tPress 3 for STRING \n";
					  cout<<"\tPress 4 for DATE TYPE \n";
					  cout<<"\tPress 5 for TIME TYPE \n\t";
					  cin>>choice;
					 if(choice=='1')
					 {
						strcpy(datatype[i],"integer");

						q:

						 cout<<"Enter the maximum no of Digits(must be LESS than 20):-";
						 cin>>size[i];
						 if(size[i]==0)
						 {
							 cout<<"The entire coulmn CANNOT be NULL";
							 clrscr();
							 goto q;
						 }
					}
					else if(choice=='2')
					{
							 strcpy(datatype[i],"Character");
							 size[i]=1;
					}
					else if(choice=='3')
					{
							 strcpy(datatype[i],"String");

							 o:

							 cout<<"Enter the size of the string(Must be LESS than 20):-";
							 cin>>size[i];
							 if(size[i]==0)
							 {
								cout<<"The entire coulmn CANNOT be NULL";
								clrscr();
								goto o;
							 }
				  }
				  else if(choice=='4')
				  {
					 strcpy(datatype[i],"Date");
					 size[i]=11;
				  }
				  else if(choice=='5')
				  {
					 strcpy(datatype[i],"Time");
					 size[i]=9;
				  }
				  else
				  {
					cout<<"Not a valid entry.....\n";
					goto k;
				  }
			}
			if(a=='3')
			{
				dk:
					  cout<<"Enter the new coulmn name:-";
					  gets(clnm[i]);
					  for(int j=0;j<i;j++)
						  if(strcmpi(clnm[j],clnm[i])==0)
						  {
							  cout<<"same coulmn name exists..........\n";
							  cout<<"Please try another valid name......\n\n";
							  getch();
							  clrscr();
							  goto dk;
							}
					  pk:
					  cout<<"Enter the data type:-\n";
					  cout<<"\tPress 1 for INTEGER \n";
					  cout<<"\tPress 2 for CHARACTER \n";
					  cout<<"\tPress 3 for STRING \n";
					  cout<<"\tPress 4 for DATE TYPE \n";
					  cout<<"\tPress 5 for TIME TYPE \n\t";
					  cin>>choice;
					 if(choice=='1')
					 {
						strcpy(datatype[i],"integer");

						e:

						 cout<<"Enter the maximum no of Digits(must be LESS than 20):-";
						 cin>>size[i];
						 if(size[i]==0)
						 {
							 cout<<"The entire coulmn CANNOT be NULL";
							 clrscr();
							 goto e;
						 }
					}
					else if(choice=='2')
					{
							 strcpy(datatype[i],"Character");
							 size[i]=1;
					}
					else if(choice=='3')
					{
							 strcpy(datatype[i],"String");

							 f:

							 cout<<"Enter the size of the string(Must be LESS than 20):-";
							 cin>>size[i];
							 if(size[i]==0)
							 {
								cout<<"The entire coulmn CANNOT be NULL";
								clrscr();
								goto f;
							 }
				  }
					else if(choice=='4')
				  {
					 strcpy(datatype[i],"Date");
					 size[i]=11;
				  }
				  else if(choice=='5')
				  {
					 strcpy(datatype[i],"Time");
					 size[i]=9;
				  }
				  else
				  {
					cout<<"Not a valid entry.....\n";
					goto pk;
				  }
			}



  }
		cout<<"\nFile sucessfully updated :-)";
		getch();
		return;
	}
void datastru :: showTableHead()
	{
		clrscr();
		int i,s=0;
		for(i=0;i<nocl;i++)
		  s+=(size[i]<6)?6:size[i];
		cout<<"Table: "<<tbnm<<endl;

		for(i=0;i<=s+nocl;i++)
				cout<<"_";
		cout<<endl<<"|";
		for(i=0;i<nocl;i++)
		 {
			 cout<<setw(((size[i]<6)?6:size[i]))<<clnm[i]<<"|";
		 }
		cout<<endl;
		for(i=0;i<=s+nocl;i++)
				cout<<"_";
		cout<<endl;
	}
void datastru::droptable()
{
			int found;

			datastru p;
	 delg:

			char tbnm1[20] ;
			cout<<"Enter the table name which you want to delete:- \n";
			gets(tbnm1);
			found=0;
			fstream fin("d:\\datastru.dat",ios::in|ios::binary);
			fstream foc("d:\\temp.dat",ios::out|ios::binary);
			while(fin.read((char*)&p,sizeof(p)))
			{
				if(strcmpi(p.tbnm,tbnm1)== 0)
					  found=1;

				else
					foc.write((char*)&p,sizeof(p));
			}

			if(!found)
				{
				 cout<<"File not found.....\n";
				 cout<<"Please try again\n";
				 getch();
				 goto delg;
				 }
				 foc.close();
			fin.close();
				remove("d:\\datastru.dat");
				rename("d:\\temp.dat","d:\\datastru.dat");
				cout<<"File sucessfully deleted :-)";
				getch();



}

class datavalue
 {


	char clval[20][20];

  public:
  char tbnm[20];
  void entervalue(datastru);
  void showvalues(datastru);
  void update(datastru);
  void show1Rec(datastru);
};
void datavalue :: entervalue(datastru ds)
{
	clrscr();
	strcpy(tbnm,ds.tbnm);
	int i,j,ctr=0;     //  to show the serial number
	ctr++;
	cout<<"\n\n\n\n";
	cout<<"Enter the values into the coulmns:-\n";
	for(i=0;i<ds.nocl;i++)
	{
		rl:

		cout<<"Enter the values for coulmn "<<ds.clnm[i]<<":-";

		if(strcmpi(ds.datatype[i],"date")==0)
		  cout<<"\n\n\n Enter date in format DD-MM-YYYY:-";

		else if(strcmpi(ds.datatype[i],"time")==0)
		  cout<<"\n\n\n Enter time in format HH:MM:SS :-";

		gets(clval[i]);
		if((strlen(clval[i]))>ds.size[i])
		  {
			  cout<<"Size error\n";
			  cout<<"Give input of specified size i.e not greater than "<<ds.size[i]<<" Units..\n";
			  getch();
			  clrscr();
			  goto rl;
		  }
		if(strcmpi(ds.datatype[i],"integer")==0)
		{
		  for(j=0;j<strlen(clval[i]);j++)
			 if(!isdigit(clval[i][j]))
			 {
				cout<<"Error\n";
				cout<<"The specified data type was integer.";
				cout<<j;
				getch();
				clrscr();
				goto rl;
			 }
		}

		else if(strcmpi(ds.datatype[i],"date")==0)
		{
		for(j=0;j<strlen(clval[i]);j++)
		 if(!isdigit(clval[i][j]) || clval[i][j] != '-')
			 {
				cout<<"Error\n Please try again \n";
				cout<<"The specified data type was date.";
				getch();
				clrscr();
				goto rl;
			 }
		}
		else if(strcmpi(ds.datatype[i],"time")==0)
		{
		for(j=0;j<strlen(clval[i]);j++)
		 if(!isdigit(clval[i][j]) || clval[i][j] != ':')
			 {
				cout<<"Error\n Please try again \n";
				cout<<"The specified data type was time.";
				getch();
				clrscr();
				goto rl;
			 }
		}
 }

  cout<<"The row entered is:-\n";
  cout<<"|----------------------------------------------------------------------------|\n";
  cout<<"|"<<setw(7)<<"SL NO|";
  for(i=0;i<ds.nocl;i++)
  {
	  cout<<setw(68/ds.nocl)<<ds.clnm[i];
	  cout<<"|";
  }
  cout<<"\n|----------------------------------------------------------------------------|\n";
  cout<<"|"<<setw(5)<<ctr<<".|";
  for(i=0;i<ds.nocl;i++)
  {
	  cout<<setw(68/ds.nocl)<<clval[i];
	  cout<<"|";
  }
  cout<<"\n|----------------------------------------------------------------------------|\n";


}
void datavalue :: showvalues(datastru d)
{
		int i,s=0;
		for(i=0;i<d.nocl;i++)
		  s+=(d.size[i]<6)?6:d.size[i];


		//for(i=0;i<=s+d.nocl;i++)
		 //		cout<<"_";
		cout<<"|";
		for(i=0;i<d.nocl;i++)
		 {
			 cout<<setw(((d.size[i]<6)?6:d.size[i]))<<clval[i]<<"|";
		 }
		cout<<endl;
		for(i=0;i<=s+d.nocl;i++)
				cout<<"-";
		cout<<endl;

 }
 void datavalue :: show1Rec(datastru db)
 {
		 int i,s=0;
	  for(i=0;i<db.nocl;i++)
		  s+=(db.size[i]<6)?6:db.size[i];


		for(i=0;i<=s+db.nocl;i++)
		 //		cout<<"_";
		cout<<"|";
		for(i=0;i<db.nocl;i++)
		 {
			 cout<<setw(((db.size[i]<6)?6:db.size[i]))<<clval[i]<<"|";
		 }
		cout<<endl;
		for(i=0;i<=s+db.nocl;i++)
				cout<<"-";
		cout<<endl;
 }
 void datavalue :: update(datastru db)
 {
	 int i;


	 for(i=0;i<db.nocl;i++)
	 {
		cout<<"\nThe old value is:- "<<clval[i]<<endl;
		x2:
		  cout<<"Please enter the new value:- ";
		  gets(clval[i]);
		  if((strlen(clval[i]))>db.size[i])
		  {
			  cout<<"Size error\n";
			  cout<<"Give input of specified size i.e not greater than "<<db.size[i]<<" Units..\n";
			  getch();
			  clrscr();
			  goto x2;
		  }
		}

 } 
void hdb()
 {
		int ctr=0;
		char ch;
		int found=0;
		char tbnm1[20];
		fstream dataapp,datain;
		datastru db;
		do
		{
		qw:

		clrscr();
		cout<<"\n  1.  Enter 1 for structure of the database\n\n  2.  Enter 2 for viewing in the tables\n\n  3.  Enter 3 for modifying a database \n\n  4.  Enter 4 to describe table\n\n  5.  Enter 5 to enter values in table\n\n  6.  Enter 6 to drop database\n\n  7.  Enter 7 to show values in fields\n\n  8.  Enter 8 to update values\n\n  9.  Enter 9 to to go back\n\n\n   Enter your choice:- ";
		cin>>ch;

		if(ch=='1' && login==1 )
		{
			datastru db,odb;
			db.create();

			x:
				clrscr();
				found=0;
				datain.open("d:\\datastru.dat",ios::in | ios::binary);
				while(datain.read((char*)&odb,sizeof(db)))
					if(strcmpi(db.tbnm,odb.tbnm)==0)
						found=1;
				datain.close();
				if(found)
				{
					 cout<<"Duplicate table name...Table not created\n";
					 cout<<"Change the table name:- ";
					 cin>>db.tbnm;
					 goto x;
				}

				dataapp.open("d:\\datastru.dat",ios::app | ios::binary);
				dataapp.write((char*)&db,sizeof(db));
				cout<<"Table created\n";
				dataapp.close();
		}

else if(ch=='2' && login==1)
{
		  found=0;
		  clrscr();
		  datain.open("d:\\datastru.dat",ios::in | ios::binary);
		  while(datain.read((char*)&db,sizeof(db)))
		  {
				  db.showTable();
				  found=1;
		  }

			if(!found)
				 cout<<"No database exists.......";
			else
			{

			  cout<<"                  |----------------------|\n";
			}
			datain.close();
			cout<<"\n\nPress any key to get back to the previous screen.........";
			getch();
}

 else if(ch=='3' && login==1)
 {
		po:

		clrscr();
		found=0;
		cout<<"The Existing Tables in Database are:-\n\n";
		datain.open("d:\\datastru.dat",ios::in | ios::binary);
		while(datain.read((char*)&db,sizeof(db)))
		{
			 db.showTable();
			 found=1;
		}
		if(!found)
		{
			 clrscr();
			 cout<<"No database exists.......";
			 getch();
			 datain.close();
			 goto qw;
		}
		else
		cout<<"                  |----------------------|\n";
		datain.close();
		cout<<"\n\nEnter the Name of table which you alter:-\n";
		gets(tbnm1);
		dataapp.open("d:\\datastru.dat",ios::out|ios::in | ios::binary);
		ctr=0;
		found=0;
		while(found==0&&dataapp.read((char*)&db,sizeof(db)))
		{
			 if(strcmpi(db.tbnm,tbnm1)==0)
			 {
					 found=1;
					 db.alter();
					 dataapp.seekp(ctr*sizeof(db));
					 dataapp.write((char*)&db,sizeof(db));
			 }
					 ctr++;
		}
		if(!found)
		{
			 cout<<"Database does not exist.........\n";
			 cout<<"Please retry..........\n";
			 getch();
			 dataapp.close();
			 clrscr();
			 goto po;
		}
			dataapp.close();
 }

 else if(ch=='4' && login==1)
 {
	  gh:
		clrscr();
		found=0;
		cout<<"The Existing Database are:-\n\n";
		datain.open("d:\\datastru.dat",ios::in | ios::binary);
		while(datain.read((char*)&db,sizeof(db)))
		{
			 db.showTable();
			 found=1;
		}
		if(!found)
		{
			 clrscr();
			 cout<<"No database exists.......";
			 getch();
			 datain.close();
			 goto qw;
		}
		else
			cout<<"                  |----------------------|\n";
			datain.close();
			cout<<"Enter the name of database which you want to describe:-\n";
			gets(tbnm1);
			found=0;
			datain.open("d:\\datastru.dat",ios::in | ios::binary);
			while(datain.read((char*)&db,sizeof(db)))
			if(strcmpi(db.tbnm,tbnm1)==0)
			{
				 found=1;
				 db.desctable();
			}
			if(!found)
			{
				cout<<"Database does not exist.........\n";
				cout<<"Please retry..........\n";
				getch();
				clrscr();
				datain.close();
				goto gh;
			}
			datain.close();
			getch();
}

else if(ch=='5'&& login==1)
 {
		  z:
					found=0;
					clrscr();
					datavalue value;
					cout<<"The Existing Database are:-\n\n";
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					while(datain.read((char*)&db,sizeof(db)))
					{
						 db.showTable();
						 found=1;
					}
					if(!found)
					{
					 clrscr();
					 cout<<"No database exists.......";
					 getch();
					 datain.close();
					 goto qw;
					}
					else
				cout<<"                  |----------------------|\n";
					datain.close();
					cout<<"Enter the name of table where you want to enter data:-";
					gets(tbnm1);
					found=0;
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					dataapp.open("d:\\datavalue.dat",ios::app | ios::binary);
					while(!found && datain.read((char*)&db,sizeof(db)))
						 if(strcmpi(db.tbnm,tbnm1)==0)
							 found=1;
					if(!found)
					{
						cout<<"Database does not exist.........\n";
						cout<<"Please retry..........\n";
						getch();
						datain.close();
						dataapp.close();
						goto z;
					}
					do
					{
					 value.entervalue(db);
					 dataapp.write((char*)&value,sizeof(value));
					 cout<<"Enter [+] to add more ";
					}while(getch()=='+');

					datain.close();
					dataapp.close();
					getch();
 }

else if(ch=='6' && login==1 && valuep==1)
	{
					found=0;
					clrscr();
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					while(datain.read((char*)&db,sizeof(db)))
					{
							  db.showTable();
							  found=1;
					}
					if(!found)
					{
					  cout<<"No database exists.......";
					  clrscr();
					  goto qw;
					}
					else
							cout<<"                  |----------------------|\n";
					datain.close();
					db.droptable();
	}

else if(ch=='7'&& login==1)
  {
			t:
					found=0;
					clrscr();
					datavalue values;
					cout<<"The Existing Database are:-\n\n";
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					while(datain.read((char*)&db,sizeof(db)))
					 {
						 db.showTable();
						 found=1;
					 }
					 if(!found)
					{
					  clrscr();
					  cout<<"No database exists.......";
					  getch();
					  datain.close();
					  goto qw;
					}
					else
					 cout<<"                  |----------------------|\n";
					datain.close();
					cout<<"Enter the name of table which you want to veiw:-";
					gets(tbnm1);
					found=0;
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					while(datain.read((char*)&db,sizeof(db)))
						 if(strcmpi(db.tbnm,tbnm1)==0)
						  {
							  db.showTableHead();
							  found=1;
						  }

					if(!found)
					{
						cout<<"Database does not exist.........\n";
						cout<<"Please retry..........\n";
						getch();
						datain.close();
						goto t;
					}
					else
					datain.close();

					datain.open("d:\\datavalue.dat",ios::in | ios::binary);
					while(datain.read((char*)&values,sizeof(values)))
						if(strcmpi(values.tbnm,tbnm1)==0)
										values.showvalues(db);
					getch();
					datain.close();
	}
else if(ch=='8'&& login==1 && valuep==1)
	{
			  fstream data;
			  x1:
					clrscr();
					datavalue val;
					cout<<"The Existing Database are:-\n\n";
					datain.open("d:\\datastru.dat",ios::in | ios::binary);
					while(datain.read((char*)&db,sizeof(db)))
					 {
						 db.showTable();
						 found=1;
					 }
					 if(!found)
					{
						cout<<"No database exists.........\n";
						cout<<"Please retry..........\n";
						getch();
						datain.close();
						goto x1;
					}
					else
						cout<<"                  |----------------------|\n";
					datain.close();
					cout<<"Enter the name of table where you want to update:-";
					gets(tbnm1);
					clrscr();
					datain.open("d:\\datavalue.dat",ios::in | ios::binary);
					found=0;
					char c;
					while(datain.read((char*)&val,sizeof(val)))
					 {
						 if(strcmpi(val.tbnm,tbnm1)==0)
						 {
							data.open("d:\\datastru.dat",ios::in | ios::binary);
							while(data.read((char*)&db,sizeof(db)))
							if(strcmpi(db.tbnm,tbnm1)==0)
						  {
							  db.showTableHead();
							  found=1;
						  }
						 }
					 }
					if(!found)
					{
						cout<<"Database does not exist.........\n";
						cout<<"Please retry..........\n";
						getch();
						data.close();
						goto t;
					}
					else
					data.close();
					found=0;
					data.open("d:\\datavalue.dat",ios::in | ios::binary);
					fstream data1("d:\\newdata.dat",ios::out | ios::binary);
					fstream data2("d:\\newdata1.dat",ios::out | ios::binary);
					while(data.read((char*)&val,sizeof(val)))
					{
					if(strcmpi(val.tbnm,tbnm1)==0)
						{
						  data1.write((char*)&val,sizeof(val));
						  found=1;
						}
					}
					data.close();
					data1.close();
					data1.open("d:\\newdata.dat",ios::in | ios::binary);
					while(data1.read((char*)&val,sizeof(val)))
					{
					  db.showTableHead();
					  val.showvalues(db);
					  cout<<"Press 1 to change any other key to continue without changing..\n";
					  cin>>c;
					  if(c=='1')
					  {
							val.update(db);
					  }
					  data2.write((char*)&val,sizeof(val));
					}

					if(!found)
					{
						cout<<"Database does not exist.........\n";
						cout<<"Please retry..........\n";
						getch();
						datain.close();
						goto x1;
					}
					data.close();
					datain.close();
					data1.close();
					data2.close();
					data1.open("d:\\temp.dat" , ios::out| ios::binary);
					data2.open("d:\\datavalue.dat" , ios:: in| ios::binary);
					while(data2.read((char*)&val,sizeof(val)))
					{
						if(strcmpi(val.tbnm,tbnm1)!=0)
							data1.write((char*)&val,sizeof(val)) ;
					}
					data1.close();
					data2.close();
					char ch;

					fstream f1("d:\\newdata1.dat", ios::in|ios::binary);
					fstream f2("d:\\datastru.dat", ios::in|ios::binary);
					while(f2.read((char*)&db,sizeof(db)))    // check
					{
						if(strcmpi(db.tbnm,tbnm1)==0)
							db.showTableHead();
					}
					f2.close();

					while(f1.read((char*)&val,sizeof(val)))
					{
						 if(strcmpi(val.tbnm,tbnm1)==0)
							val.showvalues(db);
					}
					kp:
					cout<<"Do you want to save changes?(y/n)";
					cin>>ch;
					if(ch=='n')
					  break;
					else if(ch!='y')
					{
					  cout<<"Please enter a valid input.........";
					  getch();
					  goto kp;
					}
					remove("d:\\datavalue.dat");
					rename("d:\\temp.dat","d:\\datavalue.dat");
					data2.close();
					data1.open("d:\\newdata1.dat" , ios::in| ios::binary);
					data2.open("d:\\datavalue.dat" , ios:: app| ios::binary);
					while(data1.read((char*)&val,sizeof(val)))
						 data2.write((char*)&val,sizeof(val));
					data1.close();
					data2.close();
}
else if(ch=='9' && login==1)
  {
			cout<<"\n   Thanks ";
			return;
  }
else
	{
		 cout<<"\n   Invalid choice"
		       "\n   Note:- Guests cannot perform operation 6 and 8 listed above";
		 goto qw;
	}

}while(1);
}
