
#include <iostream>
#include<stdlib.h>
//#include<conio.h>
#include<string>
using namespace std;
class phonebook
{
struct record
{
    string name;
    string email;
    string number;
   record* next;
}*first;
public:
    int sno=0;
phonebook()
{
 first=NULL;
 sno=0;
}
void add();
void delete1();
void display();
void searchwithnumber();
void searchwithname();
void update();
};
void phonebook::add()
{
    record *newrecord,*temp;
    int n;
    newrecord=new(struct record);//creating a new record
    if(newrecord==NULL)//checking for memory location
    cout<<"error in allocating memory"<<endl;
    else{
            cout<<"\nEnter Following Details(Without Spaces)"<<endl;
    cout<<"\nEnter the name:";
    cin>>newrecord->name;
    cout<<"\nEnter the number:";
    cin>>newrecord->number;
    cout<<"\nEnter the mail id:";
    cin>>newrecord->email;
    newrecord->next=NULL;
    sno++;
    if(first==NULL)
    {
      first=newrecord;
    }
  else
  {

    temp=first;
      while(temp->next!=NULL)
      {
        temp=temp->next;
      }
       temp->next=newrecord;
       newrecord->next=NULL;
    }
   cout<<"\n Contact Added"<<endl;
    }
}
void phonebook::display()
{
    struct record *temp;
    if(first==NULL)
    {
        cout<<"\n NO CONTACTS"<<endl;
    }
    else
    {
       temp=first;int i=1;
       cout<<"===========================================\n";
       cout<<"S.NO\tNAME\tNUMBER\t\tEMAIL\n";
       cout<<"===========================================\n";
       while(temp!=NULL)
       {
       cout<<i++<<"\t"<<temp->name<<"\t"<<temp->number<<"\t"<<temp->email<<"\n";
        temp=temp->next;
        }
    }
}

int main()
{
    phonebook s;
        int choice;
    do
    {
    cout<<"\t===================================\n";
    cout<<"\t            MENU\n";
    cout<<"\t===================================\n";
    cout<<"\t\nENTER YOUR CHOICE:"<<endl;
    cout<<"\t1)Add Contact"<<endl;
    cout<<"\t2)Display All"<<endl;
    cout<<"\t3)Search with name"<<endl;
    cout<<"\t4)Search with number"<<endl;
    cout<<"\t5)Delete"<<endl;
    cout<<"\t6)Edit/Update a Contact"<<endl;
    cout<<"\t7)Exit\nChoice:";
    cin>>choice;
    switch(choice)
    {
        case 1:s.add();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
              break;
        case 2:s.display();
                cout<<"\nPRESS ANY KEY TO CONTINUE.....";
                break;
        case 7:exit(0);
         default:cout<<"Invalid choice";
   }

    }
   while(choice<7&&choice >0);

return 0;
}
