#include<iostream>
#include<stdio.h>
#include<conio.h>
using namespace std;
typedef class doubly_link_list
{
public:
    int info;
    doubly_link_list *next;
    doubly_link_list *prev;
} node;
node* creat(int data)
{
    node *ptr= new node;
    ptr->info=data;
    return ptr;
}
void display(node *head)
{
    node *ptr= head->next;
    while(ptr!=NULL)
    {
        cout<<" "<< ptr->info;
        ptr=ptr->next;
    }
    getch();
}
void insertat_index(node *head,int key,int data)
{

    node *ptr=head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    ptr->info=data;
}
void insertat_last(node *head,int data)
{
    node *ptr= head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    node *p1= creat(data);
    ptr->next=p1;
    p1->prev=ptr;
    p1->next=NULL;
}
node* insertat_start(node *head,int data)
{
    head->info=data;
    node *p1=  new node;
    p1->next=head;
    head->prev=p1;
    return p1;
}
void insertafter_node(node *head,int key,int data)
{
    node *ptr=head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    node *p1= creat(data);
    p1->next=ptr->next;
    ptr->next=p1;
    p1->prev=ptr;
}
void deleteat_last(node *head)
{
    node *ptr=head;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=NULL;
    delete ptr;
}
void deleteat_start(node *head)
{
    head->next=head->next->next;
}
void deleteat_index(node *head,int key)
{
    node *ptr=head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    ptr->prev->next=ptr->next;
}
void deleteafter_node(node *head,int key)
{
    node *ptr= head;
    while(ptr->info!=key)
    {
        ptr=ptr->next;
    }
    ptr->next=ptr->next->next;
}
int main()
{
    int cmd,data1,data2,data3,data4,index1,index2,index3,index4;
    node *head,*p1,*p2,*p3,*p4;
    head= new node;
    p1=creat(00);
    head->next=p1;
    p1->prev=head;
    p1->next=NULL;
    while(1)
    {
        clrscr();
        cout<<"1.inserat at start"<<endl;
        cout<<"2.inserat at index"<<endl;
        cout<<"3.inserat after the index"<<endl;
        cout<<"4.inserat at last"<<endl;
        cout<<"5.delete at start"<<endl;
        cout<<"6.delete at index"<<endl;
        cout<<"7.delete after index"<<endl;
        cout<<"8.delete at last"<<endl;
        cout<<"9.display"<<endl;
        cout<<"10.exit"<<endl;
        cout<<"11.reset the program"<<endl;
        cout<<"enter the command ==>>"<<endl;
        cin>>cmd;
        switch(cmd)
        {
        case 1:
            cout<<"enter the data=>"<<endl;
            cin>>data1;
            head=insertat_start(head,data1);
            break;
        case 2:
            cout<<"enter the index=>"<<endl;
            cin>>index1;
            cout<<"enter the data=>"<<endl;
            cin>>data2;
            insertat_index(head,index1,data2);
            break;
        case 3:
            cout<<"enter the index=>"<<endl;
            cin>>index2;
            cout<<"enter the data=>"<<endl;
            cin>>data3;
            insertafter_node(head,index2,data3);
            break;
        case 4:
            cout<<"enter the data=>"<<endl;
            cin>>data4;
            insertat_last(head,data4);
            break;
        case 5:
            deleteat_start(head);
            break;
        case 6:
            cout<<"enter the index=>"<<endl;
            cin>>index3;
            deleteat_index(head,index3);
            break;
        case 7:
            cout<<"enter the index=>"<<endl;
            cin>>index4;
            deleteafter_node(head,index4);
            break;
        case 8:
            deleteat_last(head);
            break;
        case 9:
            display(head);
            break;
        case 10:
            return 0;
            break;
        case 11:
            main();
            break;
        default:
            cout<<"command is not found ?"<<endl;
            break;
        }
        getch();
    }
    return 0;
}