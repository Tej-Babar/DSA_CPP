# include <iostream>
using namespace std;

class Node
{
    public :
    int key;
    int data;
    Node* next;
    Node* prev;

    Node()
    {
        key=0;
        data=0;
        next=NULL;
        prev=NULL;
    }

    Node(int k, int d)
    {
        key=k;
        data=d;
    }
   

};
class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList(){
        head=NULL;
    }

    DoublyLinkedList(Node* n)
    {
        head=n;
    }

    Node* NodeExist(int k)
    {
        Node* temp=NULL;
        Node* ptr=head;
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

    // 2.Appeand

    void append(Node* n)
    {
        if (NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already Exist with key value :"<<n->key<<"Enter Different key value \n";
        }
        else
        {
            if (head==NULL)
            {
                head=n;
                cout<<"Node Append as Head!! \n";
            }
            else
            {
                Node* ptr=head;
                while (ptr->next!=NULL)
                {
                    ptr=ptr->next;
                }
                ptr->next=n;
                n->prev=ptr;
                cout<<"Node Append !! \n";
                
            }
            
        }
        
    }

    // 3. Prepend
    void prepend(Node* n)
    {
         if (NodeExist(n->key)!=NULL)
        {
            cout<<"Node Already Exist with key value :"<<n->key<<"Enter Different key value \n";
        }
        else
        {
            if (head==NULL)
            {
                head=n;
                cout<<"Node Prepend as Head !! \n";
            }
            
            head->prev=n;
            n->next=head;
            head=n;
            cout<<"Node Prepend !! \n";
        }
        
    }
    // 4. Insert Node
    void insert(int k,Node* n)
    {
        Node* ptr=NodeExist(k);
        if (ptr==NULL)
        {
            cout<<"Node Not Exist with key value :"<<k<<"Enter Different key value \n";     
        }
        else
        {
            if (NodeExist(n->key)!=NULL)
            {
            cout<<"Node Already Exist with key value :"<<n->key<<"Enter Different key value \n";
            }
            else
            {

              Node* nextNode=ptr->next;
              if (nextNode==NULL)
              {
                  ptr->next=n;
                  n->prev=ptr;
                  cout<<"Node inserted !!";
                  
              }
              else
              {
                n->next=nextNode;
                nextNode->prev=n;
                n->prev=ptr;
                ptr->next=n;
                cout<<"Node inserted !!";

              }
            

            }

        }
        

    }
    // 5. DeleteNode
    void delate(int k)
    {
        Node* ptr=NodeExist(k);
        if (ptr==NULL)
        {
            cout<<"Node Not Exist with key value :"<<k<<"cant delete \n";     
        }
        else
        {
            if (head->key==k)
            {
                head=head->next;
                 cout<<"Node delate sussesfully !! \n";
                
            }
            else
            {
                Node* nextNode=ptr->next;
                Node* preNode=ptr->prev;

                if (nextNode==NULL)
                {
                    preNode->next==NULL;
                    cout<<"Node delate sussesfully !! \n";
                }
                else
                {
                    preNode->next=nextNode;
                    nextNode->prev=preNode;
                    cout<<"Node delate sussesfully !! \n";

                }
                
            }
            
        }



    }


   // 6. Update
    void update(int k,int d)
    {
        Node* ptr=NodeExist(k);
        if (ptr==NULL)
        {
            cout<<"Node Not Exist with key value :"<<k<<"cant delete \n"; 
        }
        else
        {
            ptr->data=d;
            cout<<"Node Updated !! \n";

        }
        
    }

    // 7. display
    void display()
    {
        Node* ptr=head;
        if (head==NULL)
        {
            cout<<"DoublyLinkedList is Empty \n";
        }
        else
        {
            cout<<"DoublyLinkList is :\n";
            while (ptr!=NULL)
            {
                cout<<" ( "<<ptr->prev<<" , "<<ptr->key<<" , "<<ptr->data<<" , "<<ptr->next<<" )"<<"-->";
                ptr=ptr->next;
            }
            cout<<endl;
            
        }
        
        
    }






};


int main(int argc, char const *argv[])
{
    DoublyLinkedList s1;
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
