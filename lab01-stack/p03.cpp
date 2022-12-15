/* Evaluation of postfix expression */

#include <iostream>
#include <cmath> /* For pow() */
#include <string>
#include <stack>

using namespace std;

/* Time: O(n)
Space: O(n) */
float evaluate(string postfix)
{
    stack<float> st;

    for (const auto &ch: postfix)
    {
        if (ch >= '0' && ch <= '9')
        {
            /* Operand */
            st.push(ch - '0');
        }
        else
        {
            /* Operator */
            float b = st.top();
            st.pop();

            float a = st.top();
            st.pop();

            if (ch == '^')
            {
                st.push(pow(a, b));
            }
            else if (ch == '/')
            {
                st.push(a / b);
            }
            else if (ch == '*')
            {
                st.push(a * b);
            }
            else if (ch == '+')
            {
                st.push(a + b);
            }
            else if (ch == '-')
            {
                st.push(a - b);
            }
        }
    }

    return st.top();
}

int main()
{
    cout << evaluate("123*+84/+1+") << '\n';
    cout << evaluate("12+3+") << '\n';

    return 0;
}
