/* Convert infix expression to prefix expression */

#include <iostream>
#include <string>
#include <stack>

using namespace std;

int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '/' || ch == '*')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;

    return -1;
}

/* Time: O(n) 
Space: O(n) */
string infixToPrefix(string infix)
{
    infix = '(' + infix + ')';
    int l = infix.size();

    /* Reverse the infix expression */
    for (int i = 0; i < l / 2; ++i)
    {
        char temp = infix[i];
        infix[i] = infix[l - 1 - i];
        infix[l - 1 - i] = temp;
    }

    stack<char> st;
    string res;

    for (const char &ch: infix)
    {
        if ((ch >= 'a' && ch <= 'z') ||
            (ch >= 'A' && ch <= 'Z') ||
            (ch >= '0' && ch <= '9'))
        {
            /* Operand */
            res += ch;
        }
        else if (ch == ')')
        {
            st.push(')');
        }
        else if (ch == '(')
        {
            /* Append stack elements to the result until '(' is encountered */
            while (st.top() != ')')
            {
                res += st.top();
                st.pop();
            }
            
            st.pop();
        }
        else
        {
            /* Operator */
            while (!st.empty() && 
                    precedence(st.top()) >= precedence(ch))
            {
                res += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        /* Append the remaining stack elements to the result */
        res += st.top();
        st.pop();
    }

    /* Reverse the postfix expression to obtain the infix expression */
    l = res.size();
    for (int i = 0; i < l / 2; ++i)
    {
        char temp = res[i];
        res[i] = res[l - 1 - i];
        res[l - 1 - i] = temp;
    }

    return res;
}

int main()
{
    cout << infixToPrefix("A*B-(C+D)+E") << '\n';
    cout << infixToPrefix("(1+(2*3)+((8)/4))+1") << '\n';
    cout << infixToPrefix("(1)+((2))+(((3)))") << '\n';

    return 0;
}
