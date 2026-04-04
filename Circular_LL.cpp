#include<iostream>
using namespace std;

class Node
{
    public:
    int Data;
    Node *Next;
    Node(int data)
    {
        Data = data;
        Next = NULL;
    }
};
class Circular_LL
{

    Node * Head;
    Node * Tail;
    public:
    Circular_LL()
    {
    Head = Tail = NULL;
    }
    void InsertAtHead(int data)
    {
        Node *newNode = new Node(data);
        if(Head==NULL)
        {
            Head=Tail=newNode;
            Tail->Next=Head;
        }
        else
        {
            
            newNode->Next=Head;
            Head=newNode;
            Tail->Next=Head;

        }
        
    }
     void InsertAtTail(int data)
     {
         if(Head==NULL)
         {
            Head=Tail=new Node(data);
            Tail->Next=Head;
         }
         else
         {
            Node *newNode = new Node(data);
            Tail->Next = newNode;
            Tail=newNode;
            newNode->Next=Head;
         }
     }
    void DeleteAtHead()
    {
        if(Head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else if(Head==Tail)
        {
            delete Head; 
            Head=Tail=NULL;
        }
        else
        {
            Node * Temp = Head;
            Head= Head->Next;
            Tail->Next=Head;
            cout<<"the element "<<Temp->Data<<" is deleted"<<endl;
            Temp->Next=NULL; //to break the cycle before deleting
            delete Temp;
        }

    }
    void DeleteAtTail()
    {
        if(Head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else if(Head==Tail)
        {
            delete Head; 
            Head=Tail=NULL;
        }
        else
        {
           Node *Temp=Tail;
           Node *Prev=Head;
           while(Prev->Next!=Tail)
           {
            Prev=Prev->Next;
           } 
           Tail= Prev;
           Tail->Next = Head;
           cout<<"the element "<<Temp->Data<<" is deleted"<<endl;
           Temp->Next=NULL; //to break the cycle before deleting
           delete Temp; 

        }
    }
    void Display()
    {
        
        if(Head==NULL)
        {
            cout<<"list is empty"<<endl;
            return;
        }
        else
        {
            Node *Temp=Head;
            cout<<Head->Data<<" ";
            Temp=Head->Next;

            while(Temp!=Head)
            {
                cout<<Temp->Data<<" ";
                Temp=Temp->Next;
            }
            cout<<Temp->Data<<endl; //to show that the cycle exists 
        }
    }
};

int main()
{
    Circular_LL list;
    cout<<"Inserting at head: "<<endl;
    list.InsertAtHead(10);
    list.InsertAtHead(20);
    list.InsertAtHead(30);
    list.Display();

    cout<<"Inserting at tail: "<<endl;
    list.InsertAtTail(40);
    list.InsertAtTail(50);
    list.InsertAtTail(60);
    list.Display();

    cout<<"Deleting at head: "<<endl;
    list.DeleteAtHead();
    list.Display();
    list.DeleteAtHead();
    list.Display();

    cout<<"Deleting at tail: "<<endl;
    list.DeleteAtTail();
    list.Display();

    return 0;
}