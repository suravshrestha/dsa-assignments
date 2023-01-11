/* Implement queue using linked list */

#include <iostream>

using namespace std;

template <class T>
class Queue
{
private:
    struct Node
    {
        T value;
        Node *next = nullptr;
    };

    Node *head, *tail;
    int m_size;

public:
    Queue() : head(nullptr), tail(nullptr), m_size(0) {}

    /* Returns whether the queue is empty i.e. whether its size is zero */
    bool is_empty()
    {
        return m_size == 0;
    }

    /* Returns the number of elements in the queue */
    int size()
    {
        return m_size;
    }

    /* Returns the first element of the queue */
    T front()
    {
        if (!head)
        {
            cout << "Empty queue!\n";
            return -1;
        }

        return head->value;
    }

    /* Returns the last element of the queue */
    T back()
    {
        if (!tail)
        {
            cout << "Empty queue!\n";
            return -1;
        }

        return tail->value;
    }

    /* Inserts a new element at the top of the queue, above its current top element
    Time: O(1)
    Space: O(1) */
    void enqueue(T value)
    {   
        ++m_size;

        Node *new_node = new Node{value};
        if (!head)
        {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        tail = new_node;
    }

    /* Removes the element on top of the queue and returns its value
    Time: O(1)
    Space: O(1) */
    T dequeue()
    {
        if (!head)
        {
            cout << "Empty queue!\n";
            return -1;
        }

        T value = head->value;

        Node *to_del = head;
        head = head->next;

        delete to_del;
        to_del = nullptr;

        if (!head)
        {
            tail = nullptr;
        }

        --m_size;
        
        return value;
    }
};

int main()
{
    Queue<int> q;

    cout << "Inserting 1, 7, 5 to the queue...\n";
    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(5);

    cout << "Size of the queue: " << q.size() << '\n';
    cout << "Front of the queue: " << q.front() << '\n';
    cout << "Back of the queue: " << q.back() << '\n';

    cout << "Removing elements...\n";
    while (!q.is_empty())
    {
        cout << q.dequeue() << ' ';
    }

    cout << '\n';

    return 0;
}
