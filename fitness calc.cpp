#include<iostream>
#include<string>
#include<fstream>
#include<stdio.h>

using namespace std;
void welcome();

class calc{
char name[30];
int erno,age,height,weight;
float bmi;
public: void getdata()
{cout<<"\n\n\tEnter enrollment number :";
cin>>erno;
cin.ignore();
cout<<"\n\tEnter your name :";
cin.getline(name,30);
do{
cout<<"\n\tAge :";
cin>>age;
if(age>200||age<0)
cout<<"\n\tEnter any existing age!";}while(age>200||age<0);
do{
cout<<"\n\tWeight(in kg) :";
cin>>weight;
if(weight>250||weight<2)
cout<<"\n\tEnter valid weight!";
}while(weight>250||weight<2);
do{
cout<<"\n\tHeight(in cm's) :";
cin>>height;
if(height>300||height<20)
cout<<"\n\tEnter valid height!";
}while(height>300||height<20);

}
void calbmi()
{ bmi=weight*10000/(height*height);
 cout<<"\n\tBMI :"<<bmi;
 if(bmi<=20)
 { cout<<"\n\n\t\tYou are under weight.";
   cout<<"\n\t\t\t\t1) You should take heavy diet ";
   cout<<"\n\t\t\t\t2) Eat more calories than your body burns";
 }
 else if(bmi>20&&bmi<=25)
 {cout<<"\n\n\t\t\tYou are healthy weighted.";
   cout<<"\n\t\t\t\t1)You should take normal diet";
   cout<<"\n\t\t\t\t2)Be punctual with your current routine";
 }
 else if(bmi>30)
 {cout<<"\n\t\t\tYou are in obese category.";
  cout<<"\n\t\t\t1) You should take normal diet ";
  cout<<"\n\t\t\t2) Take less calory foods";
  cout<<"\n\t\t\t3) Must engage in some sports or exercises";
 }
 
}
void display()
{ cout<<"\n\n\tEnrollment no. :"<<erno; 
  cout<<"\n\tName :"<<name;
  cout<<"\n\tAge :"<<age<<" years";
  cout<<"\n\tWeight :"<<weight<<" kg";
  cout<<"\n\tBMI :"<<bmi;
}

void writecdetail();
void readcdetail();
int displaycrecord(int);
int deletecrecord(int);
void modifycrecord(int);

};





void calc:: writecdetail()
{ 
fstream fil;

fil.open( "fitness.dat" ,ios::binary|ios::app);
getdata();
calbmi();
fil.write((char *)this,sizeof(*this));
fil.close();
}

void calc::readcdetail()
{ 
  ifstream fil;
  fil.open("fitness.dat",ios::in|ios::binary);
  if(!fil)
  { cout<<"\tFile not found !!";
  }
  else{
  
  while(fil.read((char *)this,sizeof(*this))!=NULL)
{
    display();}}
  fil.close();
}


int calc::displaycrecord(int n)
           { int count =0;
             fstream frec;
             frec.open("fitness.dat" ,ios::in|ios::binary);
             if(!frec)
             { cout<<"\n\n\tFile not found ";
             return 0;
			 }
			 while(frec.read((char *)this,sizeof(*this))!=NULL)
			 { if(erno==n)
			 { display();
			   count++;
			 }
			 }
			 if(count==0)
 			 {  cout<<"\n\n\tRecord not found .";
			 }
			 frec.close();
			 return 1;
			 	 
		   }
		   
int calc::deletecrecord(int a)
           { fstream fin;
             fstream fout;
             fin.open("fitness.dat",ios::in|ios::app);
             if(!fin)
             { cout<<"\n\n\tFile not found !";
               return 0;
			 }
			 while(fin.read((char*)this,sizeof(*this))!=NULL)
			 { if(erno!=a)
			   {
			   fout.open("temp.dat",ios::app|ios::binary);
			   fout.write((char*)this,sizeof(*this));
			 }
					  }
				fin.close();
				fout.close();
				remove("fitness.dat");
				rename("temp.dat","fitness.dat");	  
				return 1;
			}   
			
void calc:: modifycrecord(int a)
           { fstream fin;
             fin.open("fitness.dat",ios::in|ios::out|ios::ate|ios::binary);
             fin.seekg(0);
             while(fin.read((char*)this,sizeof(*this))!=NULL)
             { if(a==erno)
             {   getdata();
                 calbmi();
                 //display();
			 fin.seekg(fin.tellg()-sizeof(*this));
               fin.write((char*)this,sizeof(*this));
			 }
			 }
				   }		




int main()
{
	welcome();
}


void welcome()
{   calc c;	
system("color 0F");
cout<<"\n\n\n\t\t  FITNESS CALCULATOR";
	cout<<"\n\n\n\tMADE BY :MANAS GUPTA";
int ch,ch1=1;
 int er;
  //getchar();
do{
	
	cout<<"\n\n\n\tENTRY MENU";
	cout<<"\n\n\t1.CREATE CLIENT RECORD FOR HEALTH DETAILS";
	cout<<"\n\n\t2.DISPLAY ALL CLIENTS RECORDS";
	cout<<"\n\n\t3.SEARCH CLIENTS RECORD ";
	cout<<"\n\n\t4.MODIFY CLIENTS RECORD";
	cout<<"\n\n\t5.DELETE CLIENTS RECORD";
	cout<<"\n\n\t6.Exit";
	
	cout<<"\n\n\tPlease Enter Your Choice (1-6) ";
	cin>>ch;
	system("cls");
	switch(ch){
	case 1: c.writecdetail();
	        cout<<"\n\n\tPress 1 for Main menu any key for exit :";
	        cin>>ch1;
	        
	        system("cls");
	        if(ch1!=1)
	        {cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
			}
	        break;
	case 2: c.readcdetail();
	        cout<<"\n\n\tPress 1 for Main menu anykey for exit :";
	        cin>>ch1; 
	        system("cls");
	          if(ch1!=1)
	        {cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
			}
	        break;
	case 3:  cout<<"\n\n\tEnter Enrollment ID to display clients record :";
	        
	         cin>>er;
	        c.displaycrecord(er);
	        cout<<"\n\n\tPress 1 for Main menu any key for exit :";
	        cin>>ch1;
	        system("cls");
	          if(ch1!=1)
	        {cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
			}
	        break;
	case 4:   cout<<"\n\n\tAll records before updation :";
	          c.readcdetail();  
	          cout<<"\n\n\tEnter Enrollment ID to modify its data :";
	          cin>>er;
	          c.modifycrecord(er);
	          cout<<"\n\n\t\tRecord modified!\n\n\t\t";
	         // getchar();
	         system("pause");
	          cout<<"\n\n\tRecords after modification :";
	          c.readcdetail();
	          cout<<"\n\n\tPress 1 for Main menu any key for exit :";
	          cin>>ch1;
	            if(ch1!=1)
	        {cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
			}
	          break;
	case 5:   cout<<"\n\n\tAll records before deletion :";
	          c.readcdetail();  
	          cout<<"\n\n\tEnter Enrollment ID to delete clients record :";
	          cin>>er;
	        
	         c.deletecrecord(er);
	         cout<<"\n\n\t\tRECORD DELETED !";
	         getchar();
	         cout<<"\n\n\tRecord after deletion :";
	         c.readcdetail();
	        cout<<"\n\n\tPress 1 for Main menu any key for exit :";
	         cin>>ch1;
	        system("cls");
	          if(ch1!=1)
	        {cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
			}
			break;
	case 6: cout<<"\n\t\t\tThank you for using this application! \n\n\n" ;
	         exit(1);
	       break;	
	default: cout<<"\n\n\t\tWRONG CHOICE";	   			
	}
}while(ch!=6&&ch1==1);
getchar();
}
