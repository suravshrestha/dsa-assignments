#include <iostream>

using namespace std;

struct Node
{
    int value;
    Node *next = nullptr;
};

/* Singly linked list */
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList() : head(nullptr), tail(nullptr) {}

    /* Insert a new node with `value` at the beginning of 
    the list and return the new node
    Time: O(1)
    Space: O(1) */
    Node *push_front(int value)
    {
        Node *new_node = new Node{value};
        if (!head)
        {
            head = tail = new_node;
            return new_node;
        }

        new_node->next = head;
        head = new_node;

        return new_node;
    }

    /* Remove the last node and return its value
    Time: O(1)
    Space: O(1) */
    int pop_front()
    {
        if (!head)
        {
            cout << "Empty list!\n";
            return -1;
        }

        int value = head->value;
        Node *to_del = head;
        head = head->next;

        delete to_del;
        to_del = nullptr;
        
        if (!head)
        {
            /* Empty list */
            tail = nullptr;
        }

        return value;
    }

    /* Insert a new node with `value` at the end of 
    the list and return the new node
    Time: O(1)
    Space: O(1) */
    Node *push_back(int value)
    {
        Node *new_node = new Node{value};
        if (!head)
        {
            head = tail = new_node;
            return new_node;
        }

        tail->next = new_node;
        tail = new_node;

        return new_node;
    }

    /* Remove the first node and return its value
    Time: O(n)
    Space: O(1) */
    int pop_back()
    {
        if (!head)
        {
            cout << "Empty list!\n";
            return -1;
        }

        int value = tail->value;
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

    /* Insert a new node with `value` after
    the given `node` and return the new node
    Time: O(1)
    Space: O(1) */
    Node *insert_after(Node *node, int value)
    {
        if (!node)
        {
            cout << "Node insertion after `nullptr` not possible!\n";
            return nullptr;
        }

        Node *new_node = new Node{value};
        new_node->next = node->next;
        node->next = new_node;

        if (!new_node->next)
        {
            tail = new_node;
        }
    }

    /* Delete the node after the given `node` and
    return the value of the deleted node
    Time: O(1)
    Space: O(1) */
    int delete_after(Node *node)
    {
        if (!node || !node->next)
        {
            cout << "Node deletion not possible!\n";
            return -1;
        }

        int value = node->next->value;
        Node *to_del = node->next;
        node->next = node->next->next;

        if (!head->next)
        {
            tail = head;
        }

        delete to_del;
        to_del = nullptr;
    }

    /* Insert a new node with `value` before
    the given `node` and return the new node
    Time: O(1)
    Space: O(1) */
    Node *insert_before(Node *node, int value)
    {
        if (!node)
        {
            cout << "Node insertion before `nullptr` not possible!\n";
            return nullptr;
        }

        if (node == head)
        {
            Node *new_node = push_front(value);
            return new_node;
        }

        Node *curr = head;
        while(curr->next != node)
        {
            curr = curr->next;
        }

        /* `curr` is the node just before the given node */
        Node *new_node = new Node{value};
        new_node->next = curr->next;
        curr->next = new_node;
    }

    void print()
    {
        if (head == nullptr)
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
    LinkedList list;

    Node *node1 = list.push_back(1);
    Node *node2 = list.push_front(7);
    list.push_back(3);

    list.insert_after(node1, 5);
    list.insert_before(node2, 4);

    cout << "First node's value: " << list.pop_front() << '\n';
    cout << "Last node's value: " << list.pop_back() << '\n';

    cout << "\nAfter removing the elements:\n";
    list.print();

    return 0;
}
