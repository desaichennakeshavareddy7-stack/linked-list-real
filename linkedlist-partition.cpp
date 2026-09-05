#include <bits/stdc++.h>
using namespace std;
class node
{
    public:
        int data;
        node* next;
    node(int v)
    {
        data=v;
        next=NULL;
    }
};

void insertatbegin(node* &head,int value)
{
    node* newnode=new node(value);
    newnode->next=head;
    head=newnode;
}
void insertatend(node* &head,int value)
{
    node* newnode=new node(value);
    if(head==NULL)
    {
        head=newnode;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=newnode;
    }
}
void deleteatbegin(node* &head)
{
    if(head==NULL)
    {
        cout<<"there is no element to delete"<<endl;
        return;
    }
    node* temp;
    temp=head;
    head=head->next;
    delete temp;
}
void deleteatend(node* &head)
{
    if(head==NULL)
    {
        cout<<"there is no to delete"<<endl;
        return;
    }
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;
}
void display(node* &head)
{
    if(head == NULL)
    {
        cout<<"there is no elemnet to display"<<endl;
    }
    else{
        node* temp=head;
        while(temp->next!=NULL)
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        }
        cout<<temp->data;
    }
}
void swapnodes(node* &head)
{
    node* prev=head;
    node* first=prev->next;
    prev->next=first->next;
    first->next=prev;
    head=first;
    first=prev->next;
    node* sec=first->next;
    while(first->next!=NULL)
    {
        prev->next=sec;
        first->next=sec->next;
        sec->next=first;
        if(first->next!=NULL)
        {
            prev=sec->next;
            first=prev->next;
            sec=first->next;
        }
    }
}
void rotatelist(node* &head)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }
    node* temp1=temp->next;
    temp1->next=head;
    head=temp1;
    temp->next=NULL;
}
void parti(node* &head)
{
    node* dummy=head;
    node* prev=head;
    node* curr=prev->next;
    int k;
    cout<<"enter k value"<<endl;
    cin>>k;
    while(curr!=NULL)
    {
        if(curr->data>=k)
        {
            prev=prev->next;
            curr=curr->next;
        }
        else
        {
            prev->next=curr->next;
            if(dummy->data >= k)
            {
                curr->next=dummy;
                head=curr;
                dummy=curr;
                curr=prev->next;
            }
            else{
                curr->next=dummy->next;
                dummy->next=curr;
                dummy=dummy->next;
                curr=prev->next;
            }
        }
    }
}
int main()
{
    node* head=NULL;
    insertatend(head,4);
    insertatend(head,4);
    insertatend(head,3);
    insertatend(head,2);
    insertatend(head,5);
    insertatend(head,2);
    //insertatend(head,7);
    //insertatend(head,8);
    display(head);
    cout<<endl;
    parti(head);
    display(head);
    return 0;
}

