#include<iostream>
using namespace std;

class Node {
    public:
    int data;
    Node *next;
    Node(int value) //constructor
    {
        data = value ;
        next = NULL;
    }
};

class List
{
    public :
    Node *head;
    Node *tail;
    List()
    {
        head = NULL;
        tail = NULL;
    }
    //push_front (adding a node at the beginning of the list)
    void addAtHead(int value)
    {
       Node *newNode = new Node(value);
       if(head == NULL )
       {
        head = tail = newNode;
        return; 
       } 
       else
       {
        newNode->next = head;
        head = newNode;
       }

    }
    void addAtTail(int value)
    {
       Node *newNode = new Node(value);
       if(head==NULL)
       {
        head=tail=NULL;
        return;
       }
       else
       {
        tail->next=newNode;
        tail = newNode;
       }

    }
    void addAtSpecific(int value,int position)
    {
        if(position<0)
        {
            cout<<"invalid position"<<endl;
            return;
        }
        else if (position == 0)
        {
            addAtHead(value);
            return;
        }
        Node * temp = head;
        for(int i=0; i<position -1 ; i ++)
        {
            if(temp==NULL)
            {
                return; // if position>size of list 
            }
            temp = temp->next;
        }
        Node *newNode = new Node(value);
        newNode->next = temp->next;
        temp->next = newNode;
    }
    

    void deleteAtHead()
    {
        if(head==NULL)
        {
            cout<<"list empty"<<endl;
            return;

        }
        else
        {
            Node *temp=head;
            head= head->next;
            temp->next= NULL;
            delete temp;

        }
    }
    void deleteAtTail()
    {
        if(head== NULL)
        {
            head=tail=NULL;
            return;
        
        }
        else
        {
            Node *temp=head;
            while(temp->next!=tail)
            {
                temp= temp->next;
            }
            temp->next= NULL;
            delete tail;
            tail = temp;
        }
    }

    int Search(int key)
    {
        
        Node *temp= head;
        int position = 0;
        while(temp!=NULL)
        {
            if(temp->data==key)
            {
                
                return position;
            }
            else
            {

                temp = temp->next;
                position++;
            }
        }
        return -1; // if key is not found
    }
    void Update(int value,int position)
    {
        if(position<0)
        {
            return;//invalid position
        }
        if(position==0)
        {
            head->data=value;
            return;
        }
        Node *temp = head;
        for(int i =0; i<position; i++)
        {
            if(temp== NULL)
            {
                return; // if position>size of list
            }
            temp = temp->next;

        }
        temp->data = value;

    }
    void PrintLL()
    {
        Node *temp = head;
        while(temp != NULL)
        {
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<" "<<endl;

    }
};

int main()
 {
    List ll;
    ll.addAtHead(10);
    ll.addAtHead(20);
    ll.addAtHead(30); 
    ll.PrintLL();

    ll.addAtTail(40);
    ll.addAtTail(50);
    ll.PrintLL();

    ll.deleteAtHead();
    ll.PrintLL();

    ll.deleteAtTail();
    ll.PrintLL();

    ll.addAtSpecific(25,2);
    ll.PrintLL();

    cout<<"key found at index "<<ll.Search(25);
    ll.PrintLL();
    ll.Update(100,2);
    ll.PrintLL();


    return 0;
 }