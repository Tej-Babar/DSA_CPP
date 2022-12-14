# include <iostream>
using namespace std;
#define SPACE 10
class Node
{

public:
    int data;
    Node* left;
    Node* right;
    Node(int);
    Node();
    
};

Node::Node()
{
   //data=NULL;
   left=NULL;
   right=NULL; 

}

Node::Node(int d)
{
   data=d;
   left=NULL;
   right=NULL;

}



class BST
{

public:
    Node *root;
    
    BST();
    bool isEmpty();
    void insertNode(Node *n);
    Node* insertRecursive(Node *r, Node *new_node);
    void print2D(Node * r, int space);
    void printPreorder(Node * r);
    void printInorder(Node *r);
    void printPostorder(Node* r);
    bool itretiveSearch(int v);
    int height(Node* r);
    void printLevelOrderBFS(Node *r);
    void printBFS(Node* r,int l);
    Node* deleteNode(Node* r,int v);
    Node* minvalue(Node *r);
   

    
};

BST::BST()
{
    root=NULL;
}

bool BST ::isEmpty()
{
    if (root==NULL)
    return true;
    else
    return false;
    
}

void BST::insertNode(Node* n)
{
    if (root==NULL)
    {
        root=n;
        cout<<"node inserted \n";
    }
    else
    {
        Node* temp=root;
        while (temp!=NULL)
        {
            if (n->data==temp->data)
            {
                cout<<"No dublicate value allowed .\n";
                return;
            }
            else if ((n->data<temp->data) && (temp->left==NULL))
            {
                temp->left=n;
                cout<<"Node inserted at left !! \n";
                break;
            }
            else if (n->data<temp->data)
            {
                temp=temp->left;
            }
            else if ((n->data>temp->data) && (temp->right==NULL))
            {
                temp->right=n;
                cout<<"Node inserted at right !! \n";
                break;
            }
            else
            {
                temp=temp->right;
            }
            
         
        }
        
    }
    
}
Node* BST:: insertRecursive(Node *r, Node *new_node)
 {
  if(r==NULL)
  {
   r=new_node;
   cout <<"Insertion successful"<<endl;
   return r;
  }
	
  if(new_node->data < r->data)
  {
   r->left = insertRecursive(r->left,new_node);
  }
  else if (new_node->data > r->data)  
  {
   r->right = insertRecursive(r->right,new_node);
  }
    else
    {
       cout << "No duplicate values allowed!" << endl;
       return r; 
  }
  return r;
 }

void BST::print2D(Node * r, int space) {
    if (r == NULL) // Base case 1
      return;
    space += SPACE; // Increase distance between levels 2
    print2D(r -> right, space); // Process right child first 3 
    cout << endl;
    for (int i = SPACE; i < space; i++) // 5 
      cout << " "; // 5.1  
    cout << r -> data << "\n"; // 6
    print2D(r -> left, space); // Process left child 7
}

void BST::printPreorder(Node* r)
{
  if(r==NULL)
  return;

  cout<<r->data<<" ";

  printPreorder(r->left);

  printPreorder(r->right);
}

void BST::printInorder(Node * r)
{
  if(r==NULL)
  return;

  printInorder(r->left);

  cout<<r->data<<" ";

  printInorder(r->right);

}

void BST ::printPostorder(Node* r)
{
  if(r==NULL)
  return;

  printPostorder(r->left);

  printPostorder(r->right);

  cout<<r->data<<" ";

}


void BST::printLevelOrderBFS(Node *r)
{
  int h= height(r);
  for (int i = 0; i<=h; i++)
  {
    printBFS(r,i);
  }
  

}

 void BST:: printBFS(Node* r,int l)
{
  if (r==NULL)
  {
    return;
  }
  else if(l==0)
  cout<<r->data<<" ";

  else
  {
    printBFS(r->left,l-1);
    printBFS(r->right,l-1);
  }

  


}
bool BST :: itretiveSearch(int v)
{
  bool exist=false;
  Node* temp=root;
  if (root->data==v)
  {
    exist=true;
  }
  else
  {
    while (temp!=NULL)
    {
      if(v==temp->data)
      {
        exist=true;
        break;

      }
      else if (v<temp->data)
      {
        temp=temp->left;
      }
      else
      {
        temp=temp->right;
      }
      
    }
    
  }
  return exist;
}

int BST::height(Node* r)
{
  if (r==NULL)
  {
    return -1;
  }
  else
  {
    int lheight = height(r->left);
    int rheight = height(r->right);
    if (lheight>rheight)
    {
      return lheight+1;
    }
    else
    return rheight+1;

  }
  

}
Node* BST:: deleteNode(Node * r, int v)
 {
    // base case 
    if (r == NULL) {
      return NULL;
    }
    // If the key to be deleted is smaller than the root's key, 
    // then it lies in left subtree 
    else if (v < r -> data) {
      r -> left = deleteNode(r -> left, v);
    }
    // If the key to be deleted is greater than the root's key, 
    // then it lies in right subtree 
    else if (v > r -> data) {
      r -> right = deleteNode(r -> right, v);
    }
    // if key is same as root's key, then This is the node to be deleted 
    else {
      // node with only one child or no child 
      if (r -> left == NULL) 
      {
       Node * temp = r -> right;
        delete r;
        return temp;
      }
       else if (r -> right == NULL)
       {
        Node * temp = r -> left;
        delete r;
        return temp;
      }
       else {
        // node with two children: Get the inorder successor (smallest 
        // in the right subtree) 
        Node * temp = minvalue(r -> right);
        // Copy the inorder successor's content to this node 
        r -> data = temp -> data;
        // Delete the inorder successor 
        r -> right = deleteNode(r -> right, temp -> data);
        //deleteNode(r->right, temp->value); 
      }
    }
    return r;
  }
Node* BST::minvalue(Node * r)
{
  Node* ptr=r;
  while (ptr->left!=NULL)
  {
    ptr=ptr->left;
  }
  return ptr;
  
}

int main() {
  BST obj;
  int option, val;

  do {
    cout << "What operation do you want to perform? " <<
      " Select Option number. Enter 0 to exit." << endl;
    cout << "1. Insert Node" << endl;
    cout << "2. Search Node" << endl;
    cout << "3. Delete Node" << endl;
    cout << "4. Print/Traversal BST values" << endl;
    cout << "5. Height of Tree" << endl;
    cout << "6. Clear Screen" << endl;
    cout << "0. Exit Program" << endl;

    cin >> option;
    //Node n1;
    Node * new_node = new Node();

    switch (option) {
    case 0:
      break;
    case 1:
       cout <<"INSERT"<<endl;
       cout <<"Enter VALUE of TREE NODE to INSERT in BST: ";
       cin >> val;
       new_node->data = val;
       obj.root= obj.insertRecursive(obj.root,new_node);
       //obj.insertNode(new_node);
       cout<<endl;
      break;
      
    case 2:
      cout << "SEARCH" << endl;
      cout << "Enter VALUE of TREE NODE to SEARCH in BST: ";
      cin >> val;
      if (obj.itretiveSearch(val)) {
        cout << "Value found" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;

    case 3:
      cout << "DELETE" << endl;
      cout << "Enter VALUE of TREE NODE to DELETE in BST: ";
      cin >> val;
      //new_node = obj.iterativeSearch(val);
      if (obj.itretiveSearch(val)) {
        obj.root=obj.deleteNode(obj.root, val);
        cout << "Value Deleted" << endl;
      } else {
        cout << "Value NOT found" << endl;
      }
      break;
    case 4:
      cout << "PRINT 2D: " << endl;
      obj.print2D(obj.root, 5);
      cout << endl;
      cout << "Print Level Order BFS: \n";
      obj.printLevelOrderBFS(obj.root);
      cout << endl;
      cout <<"PRE-ORDER: ";
      obj.printPreorder(obj.root);
      cout<<endl;
      cout <<"IN-ORDER: ";
      obj.printInorder(obj.root);
      cout<<endl;
      cout <<"POST-ORDER: ";
      obj.printPostorder(obj.root);
      cout<<endl;
      break;

    case 5:
      cout << "TREE HEIGHT" << endl;
      cout << "Height : " << obj.height(obj.root) << endl;
      break;
    case 6:
      system("cls");
      break;
    default:
      cout << "Enter Proper Option number " << endl;
    }

  } while (option != 0);

  return 0;
}
