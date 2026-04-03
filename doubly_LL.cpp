#include<iostream>
using namespace std;
class Node
{
    public:
    int Data;
    Node *Next;
    Node *Prev;

    Node(int data)
    {
        Data = data;
        Next = NULL;
        Prev = NULL;
    }
};
class Doubly_LL
{
    Node *Head;
    Node *Tail;
    public:
    Doubly_LL()
    {
        Head = NULL;
        Tail = NULL;
    }
    void InsertAtHead(int data)
    {
       Node *newNode = new Node(data);
       if(Head==NULL)
       {
        Head=Tail=newNode;
       }
       else
       {
        Head->Prev = newNode;
        newNode->Next = Head;
        Head = newNode; 
       }
    }
    void InsertAtTail(int data)
    {
        Node *newNode = new Node(data);
        if(Head==NULL)
        {
            Head=Tail=newNode;
        }
        else
        {
            newNode->Prev = Tail;
            Tail->Next = newNode;
            Tail = newNode;
        }
    }
    void DeleteAtHead()
    {
        if(Head==NULL)
        {
            cout<<"list is empty"<<endl;
        }
        else
        {
            Node *Temp = Head;
            Head=Head->Next;
            Head->Prev = NULL;
            Temp->Next = NULL;
            delete Temp;
   
        }
    }
    void DeleteAtTail()
    {
        if(Head==NULL)
        {
            cout<<"empty"<<endl;
        }
        else
        {
            Node * Temp = Tail;
            Tail = Tail-> Prev;
            Tail->Next= NULL;
            Temp->Prev = NULL;
            delete Temp;    
        }

    }
    void Display()
    {
        Node *temp=Head;
        while(temp!=NULL)
        {
            cout<<temp->Data<<" ";
            temp=temp->Next;
        }
        cout<<endl;
    }
};  
int main()
{
    Doubly_LL dl;
    dl.InsertAtHead(10);
    dl.InsertAtHead(20);
    dl.InsertAtHead(30);
    dl.Display();

    dl.InsertAtTail(40);
    dl.InsertAtTail(50);
    dl.Display();

    dl.DeleteAtHead();
    dl.Display();

    dl.DeleteAtTail();
    dl.Display();
 
    return 0;
}