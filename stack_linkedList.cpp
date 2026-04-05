#include<iostream>
using namespace std;
 class Node
 {
    public:    //if we dont specify public it'll be considered private by default
    int data;
    Node *Next;
   
 };
 class Stack
 {
public:
    Node *top = NULL;

    bool IsFull()
    {
        Node *temp = new Node;
        if(temp==NULL)//temp null tab hoga jab memory full hogi to ye bany ga hi nhi
        {
            cout<<"stack is full"<<endl;
            return true;
        }
        else delete temp; //delete after checking
        return false;
    }
    bool IsEmpty()
    {
        if(top==NULL)
        {
            cout<<"stack is empty"<<endl;
            return true;
        }else return false;
    }
    void Push(int x)
    {
        Node *newNode = new Node();
        if(IsFull())
        {
            cout<<"stack is full "<<endl;
        }
        else
        {
            newNode->data=x;
            newNode->Next=top;
            top=newNode;
            return;
        }
    }
    void Pop()
    {
        if(IsEmpty())
        {
            cout<<"stack is empty"<<endl;
            return;

        }
        else
        {
            /*yahan pahly 1 temp var le len gy taky top ko vo point kary
            or top apny sy agy waly ko phir ham temp ko delet kar den gy*/
           Node * temp;
           temp = top;
           top= top->Next;
           cout<<"the element "<< temp->data<<" is popped"<<endl;
           delete temp;
           return;

        }
    }
    void Display()
    {
        if(IsEmpty())
        {
            cout<<"stack is empty nothing to display"<<endl;
            return;
        }
        else
        {
            cout<<"STACK: \n ";
            Node* temp = top;
           for(int i =0; temp!=NULL ; i++)
            {
                cout<<temp->data<<" ";
                temp = temp->Next;
            }
            return;
        }
    }

 };

int main()
{
    Stack s;
    s.Push(10);
    s.Push(20);
    s.Push(30);
    s.Display();
 
    s.Pop();
    s.Display();
    s.Pop();
    s.Display();
    s.Pop();
    s.Display();

    return 0;
}