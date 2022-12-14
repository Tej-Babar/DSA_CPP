#include <iostream>  
using namespace std; 
class Stack
{
private:
    int top;
    int arr[5];

public:
    Stack()
    {
        top = -1;
        
        
    }

    bool isFull()
    {
        if (top==4)
        {
            return true;
        }
        else
        return false;
        

    }

    bool isEmpty()
    {
        if (top==-1)
        {
            return true;
        }
        else
        return false;
        
    }
    void push(int val)
    {
        if (isFull())
        {
            cout<<"Stack in overflow codition"<<endl;
        }
        else
        {
            top++;
            arr[top]=val;
            cout<<"Push operation done of value "<<val<<endl;
        }
        
    }
    int pop()
    {
        if (isEmpty())
        {
            cout<<"Stack is empty";
            return 0;
        }
        else
        {
            int temp = arr[top];
            arr[top]=0;
            top--;
            return temp;

        }
        
    }
    void display()
    {
        if(isEmpty()){
            cout<<"Stack is Empty";
        }
        else{
            cout<<"Stack Element are "<<endl;
        for (int i = top; i>= 0; i--)
        {
            cout<<arr[i]<<endl;
        }
        }
        
    }
    int peek(int index)
    {
        if (isEmpty())
        {
           cout<<"Stack is Empty";
           return 0;
        }
        else{
            return arr[index];
        }
        
    }
    int count()
    {
        return top+1;
    }
     void change(int index , int val)
     {
         if (isEmpty())
         {
            cout<<"Stack is Empty"<<endl;
         }
         else{
            int temp = arr[index];
            arr[index]=val;
             cout<<"Replace "<<temp<<" with "<<val<<" Sussesfully"<<endl;
         }
         
     }

  
};
int main()
{
    Stack s1;
    int val,index,option;
    do
    {
        cout<<"Enter your choice to perform operetion . Enter 0 for exit"<<endl;
        cout<<"1 . for push()"<<endl;
        cout<<"2 . for pop()"<<endl;
        cout<<"3 . for isEmpty()"<<endl;
        cout<<"4 . for isFull()"<<endl;
        cout<<"5 . for Display()"<<endl;
        cout<<"6 . for peek()"<<endl;
        cout<<"7 . for count()"<<endl;
        cout<<"8 . for change()"<<endl;
        cout<<"9 . for clear"<<endl;
        cin>>option;

        switch (option)
        {
        case 0:
            
            break;
        case 1:
        cout<<"Enter value for push on top of stack"<<endl;
        cin>>val;
        s1.push(val);
        break;

        case 2:
        cout<<s1.pop()<<endl;
        cout<<" pop from top of satck of value"<<endl;
        break;

        case 3:
        if(s1.isEmpty()){
            cout<<"Stack is Empty"<<endl;
        }
        else
        cout<<"Stack is not Empty"<<endl;
        break;

        case 4:
          if(s1.isFull()){
            cout<<"Stack is Full"<<endl;
        }
        else
        cout<<"Stack is not Full"<<endl;
        break;

        case 5:
        s1.display();
        break;

        case 6:
        cout<<"Enter the Position of Element"<<endl;
        cin>>index;
        cout<<"The element at position "<<index<<" is "<<s1.peek(index)<<endl;
        break;

        case 7:
        cout<<"Total Elements are "<<s1.count()<<endl;
        break;

        case 8:
        cout<<"Enter the position for change the value"<<endl;
        cin>>index;
        cout<<"Enter the value for change "<<endl;
        cin>>val;
        s1.change(index,val);
        break;

        case 9:
        system("cls");
        break;

        default:
        cout<<"Please Enter correct choise"<<endl;
            break;
        }

    } while (option!=0);
    
   
    return 0;
}




