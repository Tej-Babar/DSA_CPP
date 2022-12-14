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

bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    return true;
    else
    return false;
}


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
string infixtopostfix(string infix)
{
    stack <char> s;
    string postfix;
    for (int i = 0; i < infix.length(); i++)
    {
        
        if( (infix[i]>='a' && infix[i]<='z')
         || (infix[i]>='A' && infix[i]<='Z'))
        {
           postfix+=infix[i]; 
        }
        else if (infix[i]=='(')
        {
            s.push(infix[i]);
        }
        else if (infix[i]==')')
        {
             while(s.top() != '(' && !(s.empty()))
            {
                postfix += s.top();
                s.pop();
            }
            if(s.top()=='('){
                s.pop();
            }
            
          
        }
        else if (isOperator(infix[i]))
        {
            if (s.empty())
            {
                s.push((infix[i]));
            }
            else
            {
                if (precidance(infix[i])>precidance(s.top()))
                {
                    s.push(infix[i]);
                }
                else if (precidance(infix[i]==precidance(s.top())) && infix[i]=='^')
                {
                    s.push(infix[i]);
                }
                else 
                {
                    while((!s.empty())&&( precidance(infix[i])<=precidance(s.top())))
                    {
                     postfix+=s.top();
                     s.pop();
                    
                    }
                    s.push(infix[i]);
                }
            
            }
            
            
        }
     
        
    }
    while (!s.empty())
    {
        postfix+=s.top();
        s.pop();
    }
    
    return postfix;
    
    

}

string infixtoprefix(string infix)
{
    stack<char> s;
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
    string postfix,prefix,infix,ans;
    stack<string> stack;
    int op,ch;

     do
    {
        cout <<"1 . for infix to postfix \n";
        cout <<"2 . for infix to prefix \n";
        cout <<"3 . for postfix to infix \n";
        cout <<"4 . for prefix to infix \n";
        cout <<"5 . for postfix to prefix \n";
        cout <<"6 . for prefix to postfix \n";

        cout <<"0 . for Exit \n";
        cin>>ch;

        switch (ch)
        {
        case 1 :
        cout<<"Enter the infix Expression . \n";
        cin>>postfix;
        ans=infixtopostfix(postfix);
        cout<<"postfix Expression is :";
        cout<<ans<<endl;
        break;

        case 2:
        cout<<"Enter the infix Expression . \n";
        cin>>infix;
        ans=infixtoprefix(infix);
        cout<<"prefix Expression is :";
        cout<<ans<<endl;
        break;

        case 3:
        cout<<"Enter the postfix Expression . \n";
        cin>>postfix;
        ans=postfixtoinfix(stack,postfix);
        cout<<"infix Expression is :";
        cout<<ans<<endl;
        break;

        case 4:
        cout<<"Enter the prefix Expression . \n";
        cin>>prefix;
        ans=prefixtoinfix(stack,prefix);
        cout<<"infix Expression is :";
        cout<<ans<<endl;
        break;

        case 5:
        cout<<"Enter the postfix Expression . \n";
        cin>>postfix;
        ans=postfixtoprefix(stack,postfix);
        cout<<"prefix Expression is :";
        cout<<ans<<endl;
        break;

        case 6:
        cout<<"Enter the prefix Expression . \n";
        cin>>prefix;
        ans=prefixtopostfix(stack,prefix);
        cout<<"postfix Expression is :";
        cout<<ans<<endl;
        break;

        case 0:
        break;

        
        default:
        cout<<"Please Enter correct choice \n";
        break;
        }
    
    } while (ch!=0);

}