#include <iostream>

using namespace std;

/* Static implementation of stack using array */
template <class T>
class Stack
{
public:
    T *arr;
    int capacity;
    int size;

public:
    Stack(int capacity)
    {
        arr = new T[capacity];
        this->capacity = capacity;
        size = 0;
    }

    ~Stack()
    {
        delete[] arr;
    }

    /* Check whether the stack is empty */
    bool empty()
    {
        return size == 0;
    }

    /* Insert an element with given value to the top of the stack 
    Time: O(1)
    Space: O(1) */
    void push(T value)
    {
        if (size == capacity)
        {
            cout << "Stack is full!\n";
            return;
        }

        arr[size++] = value;
    }

    /* Remove the item from top of the stack and return its value
    Time: O(1)
    Space: O(1) */
    T pop()
    {
        if (size == 0)
        {
            cout << "Stack is empty!\n";
            return -1;
        }
        
        return arr[--size];
    }
};

int main()
{
    Stack<int> st(3);

    st.push(1);
    st.push(7);
    st.push(5);

    cout << "Pushing an element to completely filled stack...\n";
    st.push(3);

    cout << "Popping out elements...\n";
    while (!st.empty())
    {
        cout << st.pop() << ' ';
    }

    cout << '\n';

    return 0;
}
