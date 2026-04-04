#include<iostream>
using namespace std;
class stack 
{
    int *arr;
    int top =-1;
    int n=100;
    public:
    stack()
    {
    arr = new int[n];
    }

    void Push(int x)
    {
        if(top== n-1)
        {
            cout<<"stack full"<<endl;
            return;
        }
        else
        {
            top++;
            arr[top]=x;
        }
        return;
    } 
    void Pop()
    {
        if(top==-1)
        {
            cout<<"stack empty"<<endl;
            return;
        }
        else
        {
            top--;
            cout<<"the element "<<arr[top+1]<<" is poped"<<endl;
            return;
        }
        
    }

    void Display()
    {
        if(top == -1)
        {
            cout<<"stack empty"<<endl;
            return;
        }
        else 
        {
            for(int i = 0 ; i<=top;i++)
            {
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            return;
        }

    }
};
int main()
{
    stack s1 = stack(); 
    s1.Push(10);
    s1.Push(20);
    s1.Push(30);
    s1.Display();

    s1.Pop();
    s1.Display();
    s1.Pop();
    s1.Display();
    s1.Pop();
    s1.Display();
        

}