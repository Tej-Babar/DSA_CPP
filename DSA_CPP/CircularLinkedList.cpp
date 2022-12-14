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
        next=NULL;
    }


};

class CircularLinkedList
{
    public:
    Node* head;

    CircularLinkedList()
    {
        head=NULL;
    }

    CircularLinkedList(Node* n)
    {
        head=n;
    }

    Node* NodeExist(int k)
    {
        Node* temp=NULL;
        Node* ptr=head;
        if (head==NULL)
        {
            return temp;
        }
        else
        {
             do
          {
            if (ptr->key==k)
            {
                temp=ptr;
            }
            ptr=ptr->next;
            
          } while (ptr!=head);
          return temp;

        }
       
    }

    // 2. Append Node
    void append(Node* n)
    {
        if (NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already exist with key value :"<<n->key<<"Please Enter different key value \n";

        }
        else
        {
            if (head==NULL)
            {
                head=n;
                head->next=head;
                cout<<"Node Appended as head !! \n";
            }
            else
            {
                Node* ptr=head;
                while (ptr->next!=head)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->next=head;
                cout<<"Node Appended !! \n";
               
            }
            
        }        
    }
    void prepend(Node* n)
    {
        if (NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already exist with key value :"<<n->key<<"Please Enter different key value \n";

        }
        else
        {
            Node* ptr=head;
            while (ptr->next!=head)
            {
                ptr=ptr->next;
            }
            ptr->next=n;
            n->next=head;
            head=n;
            cout<<"Node Prepended \n";
            
 
        }

    }
    void insert(int k,Node* n)
    {
        Node* ptr=NodeExist(k);
        if (ptr==NULL)
        {
            cout<<"key not found enter differrnt key \n";
        }
        else
        {
            if (NodeExist(n->key)!=NULL)
            {
            cout<<"Node Already exist with key value :"<<n->key<<"Please Enter different key value \n";

            }
            else
            {
                if (ptr->next==head)
                {
                    ptr->next=n;
                    n->next=head;
                    cout<<"Node inserted as tail \n";
                }
                else
                {
                    n->next=ptr->next;
                    ptr->next=n;
                    cout<<"Node inserted !! \n";
                }
                
            }
            
        }

    }
    void delate(int k)
    {
        if (head==NULL)
        {
            cout<<"Linked List is empty cant delete Node \n";
        }
        else
        {
            Node* ptr=NodeExist(k);
            if (ptr==NULL)
            {
                cout<<"No Node Exist with key value \n";
            }
            else
            {
              if (ptr==head)
              {
                head=head->next;
                cout<<"Head Node Deleted sussesfully !! \n";
              }
              else
              {
                Node* prev=head;
                Node* nextptr=head->next;
                while (nextptr!=head)
                {
                    if (ptr==nextptr)
                    {
                        prev=nextptr->next;
                        cout<<" Node Deleted sussesfully !! \n";
                    }
                    nextptr=nextptr->next;
                    prev=prev->next;
                }
                
               
              }
            }
          
        }

    }
    void update(int k,int d)
    {
        Node* ptr=NodeExist(k);
        if (ptr==NULL)
        {
            cout<<"No Node Exist with key value \n";
        }
        else
        {
            ptr->data=d;
            cout<<"Node Updated sussesfully ! \n";
        }        

    }

    void display()
    {
        if (head==NULL)
        {
            cout<<"Linked List is Empty \n";
        }
        else
        {
            Node* ptr=head;
            cout<<"Linked list is : \n";
            do
            {
                cout<<" ( "<<ptr->key<<" , "<<ptr->data<<" , "<<ptr<<" ) "<<"->>";
                ptr=ptr->next;
            } while (ptr!=head);
            cout<<endl;

        }
        
    }

};


int main(int argc, char const *argv[])
{
    CircularLinkedList s1;
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
        s1.append(n);
        break;

        case 2:
        cout<<"Enter key and data for Prepend node"<<endl;
        cin>>k;
        cin>>d;
        n->key=k;
        n->data=d;
        s1.prepend(n);
        
        break;

        case 3:
        cout<<"Enter The key value after which you want to insert node \n";
        cin>>k1;
        cout<<"Enter key and data for Insert node"<<endl;
        cin>>k;
        cin>>d;
        n->key=k;
        n->data=d;
        s1.insert(k1,n);
      
        break;

        case 4:
        cout<<"Enter key value for Delete node \n";
        cin>>k;
        s1.delate(k);
        
        break;

        case 5:
        cout<<"Enter key value for Update node \n";
        cin>>k;
        cout<<"Enter the data for update node \n";
        cin>>d;
        s1.update(k,d);
 
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
