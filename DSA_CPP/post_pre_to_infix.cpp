#include <iostream>
# include <stack>
#include <algorithm>
using namespace std;

bool isoperend(char c)
{
    if ((c>='a' && c<='z')
     || (c>='A' && c<='Z'))
    {
        return true;
    }
    else{
       return false;
    }
    
    
}

string postfixtoinfix(stack<string> s, string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
       char c= postfix[i];

       if (isoperend(c))
       {
           string op = string(1,c);
           s.push(op);
       }
       else
       {
           string op1,op2;
           op1=s.top();
           s.pop();

           op2=s.top();
           s.pop();

           s.push('(' + op2 + c + op1 + ')');

       }
       
    }
    return s.top();
    

}

string prefixtoinfix(stack<string> s, string prefix)
{
    reverse(prefix.begin(),prefix.end());

    for (int i = 0; i < prefix.length(); i++)
    {
       char c= prefix[i];

       if (isoperend(c))
       {
           string op = string(1,c);
           s.push(op);
       }
       else
       {
           string op1,op2;
           op1=s.top();
           s.pop();

           op2=s.top();
           s.pop();

           s.push('(' + op1 + c + op2 + ')');

       }
       
    }
    return s.top();

}

int main()
{
    string infix,postfix,prefix;
    stack<string> stack;
    int op,ch;
    
    do
    {
        cout <<"1 . for postfix to infix \n";
        cout <<"1 . for prefix to infix \n";
        cout <<"0 . for Exit \n";
        cin>>ch;

        switch (ch)
        {
        case 1 :
        cout<<"Enter the postfix Expression . \n";
        cin>>postfix;
        infix=postfixtoinfix(stack,postfix);
        cout<<"infix Expression is :";
        cout<<infix<<endl;
        break;

        case 2:
        cout<<"Enter the prefix Expression . \n";
        cin>>prefix;
        infix=prefixtoinfix(stack,prefix);
        cout<<"infix Expression is :";
        cout<<infix<<endl;

        case 0:
        break;

        
        default:
        cout<<"Please Enter correct choice \n";
        break;
        }
    
    } while (ch!=0);

    return 0;
}