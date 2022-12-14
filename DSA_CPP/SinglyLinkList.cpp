# include <iostream>
using namespace std;

class Node
{
    public :
    int key;
    int data;
    Node* next;

    Node()
    {
        key=0;
        data=0;
        next=NULL;
    }

    Node(int k, int d)
    {
        key=k;
        data=d;
    }


};

class SinglyLinkList
{
    public:
    Node* head;

    SinglyLinkList()
    {
        head=NULL;
    }

    SinglyLinkList(Node * n)
    {
        head=n;
    }
  // 1. Check if node Exist
    Node * nodeExist(int k)
    {
        Node *temp=NULL;
        Node *ptr=head;
        while (ptr!=NULL)
        {
            if(ptr->key==k)
            {
                temp=ptr;
            }
           
            ptr=ptr->next;
            
        
        }
        return temp;
      
    }

    // 2. Append node at the last

    void appendNode(Node *n)
    {
        if (nodeExist(n->key)!=NULL)
        {
            cout<<"Node Already exist with key value :"<<n->key<<"Please Enter different key value \n";

        }
        else
        {
            if (head==NULL)
            {
                head=n;
                cout<<"Node Appended !! \n";
            }
            else
            {
                Node *ptr=head;
                while (ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                cout<<"Node Appended !! \n";
               
            }

         
        }
        
    }

    // 3. Prepend Node
    void prependNode(Node *n)
    {
         if (nodeExist(n->key)!=NULL)
        {
            cout<<"Node Already exist with key value :"<<n->key<<"Please Enter different key value \n";

        }
        else
        {
         n->next=head;
         head=n;
         cout<<"Node Prepended !! \n";
        }
    }

    // 4.Insert node after key value
    void insertNode(int k,Node *n)
    {
        Node *ptr=nodeExist(k);
        if (ptr==NULL)
        {
            cout<<" No node Exist with key value :"<<k<<endl;
        }
        else
        {
           if (nodeExist(n->key)!=NULL)
           {
               cout<<"Node Already exist with key value :"<<n->key<<" Please Enter different key value \n";
           }
           else
           {
              n->next=ptr->next;
              ptr->next=n;
              cout<<"Node Inserted After key value : "<<k<<"\n";
  
           }
           
       

        }
        
    }
    void deleteNode(int k)
    {
        if(head==NULL)
        {
            cout<<"Linked List is empty cant delete node \n"; 
        }
        else
        {
            if (head->key==k)
            {
                head=head->next;
                cout<<"Node Unlinked with key value :"<<k<<endl;
            }
            else
            {
                Node *temp=NULL;
                Node *pre=head;
                Node *current=head->next;
                while (current!=NULL)
                {
                    if(current->key==k)
                    {
                        temp=current;
                        current=NULL;
                    }
                    else
                    {
                        current=current->next;
                        pre=pre->next;
                    }
                }
                if (temp!=NULL)
                {
                    pre->next=temp->next;
                    cout<<"Node Unlinked with key value :"<<k<<endl;
                }
                else
                {
                    cout<<"No Node Exist  with key value :"<<k<<endl;
                }
                
                

            }
            
            
        }
    }

    void updateNode(int k , int d)
    {
         if(head==NULL)
        {
            cout<<"Linked List is empty cant update node \n"; 
        }
        else
        {
             Node *ptr=nodeExist(k);
            if (ptr==NULL)
            {
              cout<<" No node Exist with key value :"<<k<<endl;
            }
            else
            {
                ptr->data=d;
                cout<<"Node data updated Sussesfully !! \n";
            }
        
        }

     
    }
    void display()
    {
        Node *ptr=head;
        if (ptr==NULL)
        {
            cout<<"Linked List is Empty \n";
        }
        else
        {
            cout<<"Linked List is : \n";
            while (ptr!=NULL)
            {
                cout<<"( "<<ptr->key<<" , "<<ptr->data<<" )"<<" --> ";
                ptr=ptr->next;
            }
            cout<<endl;
            
        }
        
        
    }

};
int main(int argc, char const *argv[])
{
    SinglyLinkList s1;
    int option,d,k,k1;
    do
    {
        cout<<"Enter your choice to perform operetion . Enter 0 for exit"<<endl;
        cout<<"1 . for Append Node"<<endl;
        cout<<"2 . for Prepend Node"<<endl;
        cout<<"3 . for insert Node"<<endl;
        cout<<"4 . for Delete Node"<<endl;
        cout<<"5 . for Update Node"<<endl;
        cout<<"6 . for Display Linked List"<<endl;
        cout<<"7 . for clear"<<endl;
        cin>>option;
        
        Node *n = new Node;

        switch (option)
        {
        case 0:
            
            break;
        case 1:
        cout<<"Enter key and data for Append node"<<endl;
        cin>>k;
        cin>>d;
        n->key=k;
        n->data=d;
        s1.appendNode(n);
        break;

        case 2:
        cout<<"Enter key and data for Prepend node"<<endl;
        cin>>k;
        cin>>d;
        n->key=k;
        n->data=d;
        s1.prependNode(n);
        
        break;

        case 3:
        cout<<"Enter The key value after which you want to insert node \n";
        cin>>k1;
        cout<<"Enter key and data for Insert node"<<endl;
        cin>>k;
        cin>>d;
        n->key=k;
        n->data=d;
        s1.insertNode(k1,n);
      
        break;

        case 4:
        cout<<"Enter key value for Delete node \n";
        cin>>k;
        s1.deleteNode(k);
        
        break;

        case 5:
        cout<<"Enter key value for Update node \n";
        cin>>k;
        cout<<"Enter the data for update node \n";
        cin>>d;
        s1.updateNode(k,d);
 
        break;

        case 6:
       s1.display();
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



