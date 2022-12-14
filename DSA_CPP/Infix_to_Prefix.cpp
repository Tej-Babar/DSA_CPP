#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

int precidance(char c)
{
    if (c=='+' || c=='-')
        return 1;

    else if (c=='*' || c=='/')
        return 2;

    else if (c=='^')
        return 3;
    else
    return -1;

    
}

string infixtoprefix(stack<char> s,string infix)
{
    string prefix;
    reverse(infix.begin(),infix.end());

    for (int i = 0; i <infix.length(); i++)
    {
        if (infix[i]=='(')
        {
            infix[i]=')';
        }
        else if (infix[i]==')')
        {
            infix[i]='(';
        }
                
    }

    for (int i = 0; i <infix.length(); i++)
    {
        char c = infix[i];
        if ((c>='a' && c<='z') || (c>='A' && c<='Z') )
        {
            prefix+=c;
        }

        else if (c=='(')
        {
            s.push(c);
        }

        else if (c==')')
        {
            while ((s.top())!='(' && (!s.empty()))
            {
                prefix+=s.top();
                s.pop();
            }
            if(s.top()=='(')
            {
                s.pop();
            }
            
        }

        else if (c=='+' || c=='-' || c=='*' || c=='/')
        {
            if (s.empty())
            {
                s.push(c);
            }
            else
            {

            if (precidance(c)>precidance(s.top()))
            {
                s.push(c);
            }

            else if(precidance(c)==precidance(s.top()) && c=='^')
            {
                while (precidance(c)==precidance(s.top()) && c=='^')
                {
                    prefix+=s.top();
                    s.pop();
                }

                s.push(c);
                
            }

            else if (precidance(c)==precidance(s.top()))
            {
                s.push(c);
            }

            else
            {
                while ((!s.empty()) && precidance(c)<precidance(s.top()))
                {
                    prefix+=s.top();
                    s.pop();

                }
                s.push(c);
                
            }

            }
         
        }
       
    }

    while (!s.empty())
    {
        prefix+=s.top();
        s.pop();
    }
    

    reverse(prefix.begin(),prefix.end());
    
    return prefix;
  
}

int main()
{
    string infix,prefix;
    stack<char> stack;
    cout<<"Enter the Infix Expression . \n";
    cin>>infix;
    prefix=infixtoprefix(stack,infix);
    cout<<"Prefix Expression is :";
    cout<<prefix;
    return 0;
}
