//
//  main.cpp
//  inserting_in_doubly_linked_list
//
//  Created by Uby H on 26/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *prev,*next;
}*first=NULL;
void create(int A[],int n)
{
    struct Node *t,*last;
    first=(struct Node*)malloc(sizeof(struct Node));
    first->data=A[0];
    first->prev=NULL;
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct Node*)malloc(sizeof(struct Node));
        t->data=A[i];
        t->next=NULL;
        t->prev=last;
        last->next=t;
        last=t;
    }
}
void display()
{
    struct Node *p=first;
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void insert (int pos, int x)
{
    struct Node *p=first;
    struct Node *t=NULL;
    t=new Node;
    t->prev=NULL;
    t->next=NULL;
    t->data=x;
    if(pos==0)
    {
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else
    {
        for(int i=0;i<pos-1;i++)
            p=p->next;
        t->prev=p;
        t->next=p->next;
        if(p->next)
            p->next->prev=t;
        p->next=t;
    }
}
int main()
{
    int n,x,pos;
    cout<<"Enter the number of elements in the doubly linked list : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements in the linked list : "<<endl;
    for(int i=0;i<n;i++)
        cin>>A[i];
    create(A,n);
    cout<<"The original linked list is given by : "<<endl;
    display();
    cout<<"Enter the element to be inserted in the linked list : "<<endl;
    cin>>x;
    cout<<"Enter the position at which the element must be inserted in the linked list : "<<endl;
    cin>>pos;
    insert(pos,x);
    cout<<"The updated linked list is given by : "<<endl;
    display();
    return 0;
}
