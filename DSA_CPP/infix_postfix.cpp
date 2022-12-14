# include <iostream>
# include <stack>
using namespace std;
bool isOperator(char c)
{
    if(c=='+' || c=='-' || c=='*' || c=='/')
    return true;
    else
    return false;
}
int presidance(char c)
{
    if (c=='+' || c=='-')
    return 1;
    else if(c=='*' || c=='/') 
    return 2;
    else if(c=='^')
    return 3;
    else
    return -1;
    
}
string infixtopostfix(stack<char> s,string infix)
{
    
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
                if (presidance(infix[i])>presidance(s.top()))
                {
                    s.push(infix[i]);
                }
                else if (presidance(infix[i]==presidance(s.top())) && infix[i]=='^')
                {
                    s.push(infix[i]);
                }
                else 
                {
                    while((!s.empty())&&( presidance(infix[i])<=presidance(s.top())))
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

int main()
{
    stack <char> s;
    string in,ans;
    cout<<"Enter the infix expression : \n";
    cin>>in;
    ans=infixtopostfix(s,in);
    cout<<"Postfix expression is : ";
    cout<<ans;
    return 0;
}
