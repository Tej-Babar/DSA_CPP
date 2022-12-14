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

string postfixtoprefix(stack<string> s, string postfix)
{
    for (int i = 0; i < postfix.length(); i++)
    {
        char c= postfix[i];

        if (isoperend(c))
        {
            string op(1,c);
            s.push(op);
        }
        else
        {
            string op1=s.top();
            s.pop();
            string op2= s.top();
            s.pop();
            string ex = c + op2 + op1;
            s.push(ex);
        }
        
    }

    return s.top();
    

}

string prefixtopostfix(stack<string> s,string prefix)
{
    reverse(prefix.begin(),prefix.end());

     for (int i = 0; i < prefix.length(); i++)
    {
        char c= prefix[i];

        if (isoperend(c))
        {
            string op(1,c);
            s.push(op);
        }
        else
        {
            string op1=s.top();
            s.pop();
            string op2= s.top();
            s.pop();
            string ex =  op1 + op2 + c;
            s.push(ex);
        }
        
    }

    return s.top();
}

int main()
{
    string postfix,prefix,ans1,ans2;
    stack<string> stack;
    int op,ch;
    
    do
    {
        cout <<"1 . for postfix to prefix \n";
        cout <<"1 . for prefix to postfix \n";
        cout <<"0 . for Exit \n";
        cin>>ch;

        switch (ch)
        {
        case 1 :
        cout<<"Enter the postfix Expression . \n";
        cin>>postfix;
        ans1=postfixtoprefix(stack,postfix);
        cout<<"prefix Expression is :";
        cout<<ans1<<endl;
        break;

        case 2:
        cout<<"Enter the prefix Expression . \n";
        cin>>prefix;
        ans2=prefixtopostfix(stack,prefix);
        cout<<"postfix Expression is :";
        cout<<ans2<<endl;

        case 0:
        break;

        
        default:
        cout<<"Please Enter correct choice \n";
        break;
        }
    
    } while (ch!=0);

    return 0;
}