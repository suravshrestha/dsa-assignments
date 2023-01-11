/* Implement stack using linked list */

#include <iostream>

using namespace std;

template <class T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node *next = nullptr;
    };

    Node *head;
    int m_size;

public:
    Stack() : head(nullptr), m_size(0) {}

    /* Returns whether the stack is empty: i.e. whether its size is zero */
    bool is_empty()
    {
        return !head;
    }

    /* Returns the number of elements in the stack */
    int size()
    {
        return m_size;
    }

    /* Returns the top of the stack
    Time: O(1)
    Space: O(1) */
    T top()
    {
        if (!head)
        {
            cout << "Empty stack!\n";
            return -1;
        }

        return head->value;
    }

    /* Inserts a new element at the top of the stack, above its current top element
    Time: O(1)
    Space: O(1) */
    void push(T value)
    {   
        Node *new_node = new Node{value};
        new_node->next = head;
        head = new_node;

        ++m_size;
    }

    /* Removes the element on top of the stack and returns its value
    Time: O(1)
    Space: O(1) */
    T pop()
    {
        if (!head)
        {
            cout << "Empty stack!\n";
            return -1;
        }

        T value = head->value;

        Node *to_del = head;
        head = head->next;

        delete to_del;
        to_del = nullptr;

        --m_size;
        
        return value;
    }
};

int main()
{
    Stack<int> st;

    cout << "Pushing 1, 7, 5 to the stack...\n";
    st.push(1);
    st.push(7);
    st.push(5);

    cout << "Size of the stack: " << st.size() << '\n';
    cout << "Top of the stack: " << st.top() << '\n';

    cout << "Popping out elements...\n";
    while (!st.is_empty())
    {
        cout << st.pop() << ' ';
    }

    cout << '\n';

    return 0;
}
