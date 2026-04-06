#include<iostream>
using namespace std;

class Queue
{    public:
    int *arr;
    int front=-1;
    int rear=-1;
    int size=5;

    Queue()
    {
        arr = new int[size];
    }

    bool isEmpty()
    {
        if(front==-1 && rear==-1)
        {
            return true;
        }
        else 
            return false;

    }
    bool isFull()
    {
        if(rear==size-1)
        {
            return true;
        }
        else
           return false;
    }
    void Display()
    {
        if(isEmpty())
        {
            cout<<"empty"<<endl;
        }
        else if(isFull())
        {
            cout<<"full"<<endl;
        }
        else
        {
            for(int i = front; i<= rear ; i++)
            {
                cout<<arr[i]<<"  ";
            }
            cout<<endl;
        }
    }
    void Enqueue(int value)
    {
        if(isFull())
        {
            return;

        }
        else if(isEmpty())
        {
            front =rear=0;
            arr[rear]=value;
        }
        else
        {
            rear++;
            arr[rear]=value;
        }
    }
    void dequeue()
    {
        if(isEmpty())
        {
            return;
        }
        else if(front==rear)// incase there is only 1 element
        {
            front=rear=-1;
        }
        else
        {
            front++;
        }
    }
};

int main()
{
    Queue q;
    q.Enqueue(10);
    q.Enqueue(20);
    q.Enqueue(30);
    q.Enqueue(40);
    q.Display();

    q.dequeue();
    q.Display();
    q.dequeue();
    q.Display();
    q.dequeue();
    q.Display();
    q.dequeue();
    q.Display();
   
}