/* Given a mathematical expression including the characters '(', ')', '{', '}', '[' and ']',
determine if the parentheses are balanced or not. */

#include <iostream>
#include <stack>

using namespace std;

/* Time: O(n)
Space: O(n) */
bool isValidParentheses(string s){ 
    stack<char> st;

    for (const auto &ch : s)
    {
        if (ch == '(' || ch == '{' || ch == '[' )
        {
            st.push(ch);
        }
        else if ((ch == ')' && st.top() == '(') ||
                 (ch == '}' && st.top() == '{') ||
                 (ch == ']' && st.top() == '['))
        {
            st.pop();
        }
    }

    return st.empty();
}

int main()
{
    cout << isValidParentheses("[a+{(c+d)-e*f}]") << '\n';
    cout << isValidParentheses("(a+b*(c+d)-e") << '\n';

    return 0;
}
