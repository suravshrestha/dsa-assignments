#include <iostream>

using namespace std;

/* Singly linked list */
template <class T>
class LinkedList
{
private:
    struct Node
    {
        T value;
        Node *next = nullptr;
    };

    Node *head;
    Node *tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    /* Insert a new node with `value` at the beginning of the list
    Time: O(1)
    Space: O(1) */
    void push_front(T value)
    {
        ++size;

        Node *new_node = new Node{value};
        if (!head)
        {
            head = tail = new_node;
            return;
        }

        new_node->next = head;
        head = new_node;
    }

    /* Delete the first node and return its value
    Time: O(1)
    Space: O(1) */
    T pop_front()
    {
        if (!head)
        {
            cout << "Empty list!\n";
            return -1;
        }

        T value = head->value;
        Node *to_del = head;
        head = head->next;

        delete to_del;
        to_del = nullptr;
        
        if (!head)
        {
            /* Empty list */
            tail = nullptr;
        }

        --size;
        return value;
    }

    /* Insert a new node with `value` at the end of the list
    Time: O(1)
    Space: O(1) */
    void push_back(T value)
    {   
        ++size;

        Node *new_node = new Node{value};
        if (!head)
        {
            head = tail = new_node;
            return;
        }

        tail->next = new_node;
        tail = new_node;
    }

    /* Delete the last node and return its value
    Time: O(n)
    Space: O(1) */
    T pop_back()
    {
        if (!head)
        {
            cout << "Empty list!\n";
            return -1;
        }

        --size;
        T value = tail->value;
        Node *curr = head;

        if (!head->next)
        {
            /* Only one node */
            delete curr;
            curr = nullptr;

            head = tail = nullptr;
            return value;
        }

        while (curr->next->next)
        {
            curr = curr->next;
        }

        /* `curr` is the 2nd last node */
        delete curr->next;
        curr->next = nullptr;
        tail = curr;

        return value;
    }

    /* Insert a new node with `value` after given index `idx`
    Time: O(n)
    Space: O(1) */
    void insert_after(int idx, T value)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid index!\n";
            return;
        }

        Node *curr = head;
        while (idx--)
        {
            curr = curr->next;
        }

        Node *new_node = new Node{value};
        new_node->next = curr->next;
        curr->next = new_node;

        if (curr == tail)
        {
            /* Inserted after the last node */
            tail = new_node;
        }

        ++size;
    }

    /* Delete the node after the given index `idx` and return its value
    Time: O(n)
    Space: O(1) */
    T delete_after(int idx)
    {
        if (idx < 0 || idx >= size - 1)
        {
            cout << "Invalid index!\n";
            return -1;
        }

        Node *curr = head;
        while (idx--)
        {
            curr = curr->next;
        }

        Node *to_del = curr->next;
        T value = curr->next->value;
        curr->next = curr->next->next;

        delete to_del;
        to_del = nullptr;

        if (!curr->next)
        {
            /* Deleted the last node */
            tail = curr;
        }

        --size;
        return value;
    }

    /* Insert a new node with `value` before given index `idx`
    Time: O(n)
    Space: O(1) */
    void insert_before(int idx, T value)
    {
        if (idx < 0 || idx >= size)
        {
            cout << "Invalid index!\n";
            return;
        }

        if (idx == 0)
        {
            push_front(value);
            return;
        }

        Node *curr = head;
        while (--idx)
        {
            curr = curr->next;
        }

        Node *new_node = new Node{value};
        new_node->next = curr->next;
        curr->next = new_node;

        ++size;
    }

    void print()
    {
        if (!head)
        {
            cout << "Empty list!\n";
            return;
        }

        Node *curr = head;
        while (curr)
        {
            cout << curr->value << "->";
            curr = curr->next;
        }

        cout << "null\n";
    }
};

int main()
{
    LinkedList<int> list;

    list.push_back(1);
    list.push_front(7);
    list.push_back(3);

    list.insert_after(1, 5);
    list.insert_before(0, 4);

    cout << "Before removing elements:\n";
    list.print();

    cout << "\nRemoving elements...\n";
    cout << "First node's value: " << list.pop_front() << '\n';
    cout << "Last node's value: " << list.pop_back() << '\n';

    cout << "\nAfter removing the elements:\n";
    list.print();

    return 0;
}
