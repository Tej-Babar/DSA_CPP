# include <iostream>
using namespace std ;
class Queue
{
private:
    int rear ;
    int front;
   
    int arr[5];
    
public:
    Queue()
    {
       
        rear=front=-1;
        for (int i = 0; i < 5; i++)
        {
            arr[i]=0;
        }
        
    }

    bool isFull()
    {
        if (rear==(4))
        {
           return true;
        }
        else
        return false;
        
    }

   bool isEmpty()
   {
       if (front==-1 && rear==-1)
       {
           return true;

       }
       else
       return false;
       
   }

   void EnQueue(int val)
   {
       if (isFull())
       {
           cout<<"Queue is full Cant Enqueue"<<endl;
           return;
       }
       else if(isEmpty())
       {
           front=rear=0;
           arr[rear]=val;

           cout<<val<<" Enueue susesfully !!"<<endl;
       }
       else
       {
           rear++;
           arr[rear]=val;
           cout<<val<<" Enueue susesfully !!"<<endl;
       }
       
   }

   int DeQueue()
   {
       int temp;
       if (isEmpty())
       {
           return 0;
       }
       else if (front==rear)
       {
           
           temp=arr[front];
           arr[front]=0;
           front=rear=-1;
           return temp;
       }
       else
       {
           temp=arr[front];
           arr[front]=0;
           front++;
           return temp;
       }
       
       
   }

   void Display()
   {
       cout<<"Items in Queue are "<<endl;
       for (int i = 0; i < 5; i++)
       {
           cout<<arr[i]<<"  ";
       }
       cout<<endl;
       
   }

   int count()
   {
       return (rear-front+1);
   }
    

    
    
};

int main(int argc, char const *argv[])
{
    int val,option;
   
    Queue s1;

    do
    {
        cout<<"Enter your choice to perform operetion . Enter 0 for exit"<<endl;
        cout<<"1 . for EnQueue()"<<endl;
        cout<<"2 . for DeQueue()"<<endl;
        cout<<"3 . for isEmpty()"<<endl;
        cout<<"4 . for isFull()"<<endl;
        cout<<"5 . for Display()"<<endl;
        cout<<"6 . for count()"<<endl;
        cout<<"7 . for clear"<<endl;
        cin>>option;

        switch (option)
        {
        case 0:
            
            break;
        case 1:
        cout<<"Enter value for Enqueue"<<endl;
        cin>>val;
        s1.EnQueue(val);

        break;

        case 2:
       
        cout<<" DeQueue "<<s1.DeQueue()<<" Sussesfully !! "<<endl;
        break;

        case 3:
        if(s1.isEmpty()){
            cout<<"Queue is Empty"<<endl;
        }
        else
        cout<<"Queue is not Empty"<<endl;
        break;

        case 4:
          if(s1.isFull()){
            cout<<"Queue is Full"<<endl;
        }
        else
        cout<<"Queue is not Full"<<endl;
        break;

        case 5:
        s1.Display();
        break;

        case 6:
       cout<<"Total Elements are "<<s1.count()<<endl;
        break;

        case 7:
        system("cls");
        break;

        default:
        cout<<"Please Enter correct choise"<<endl;
            break;
        }

    } while (option!=0);

    return 0;
}

