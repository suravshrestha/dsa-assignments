#include <iostream>

using namespace std;

/* Circular queue */
template <class T>
class Queue
{
private:
    T *arr;
    int front, back;
    int capacity, size;

public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        front = -1;
        back = -1;
        this->capacity = capacity;
        size = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    /* Check whether the queue is empty */
    bool empty()
    {
        return size == 0;
    }

    /* Insert an element with given value at the end of the queue
    Time: O(1)
    Space: O(1) */
    void enqueue(T value)
    {
        if (size == capacity)
        {
            cout << "Queue is full!\n";
            return;
        }

        back = (back + 1) % capacity;
        arr[back] = value;

        front = (front == -1) ? 0 : front;
        ++size;
    }

    /* Remove the first element from the queue and return its value
    Time: O(1)
    Space: O(1) */
    T dequeue()
    {
        if (empty())
        {
            cout << "Queue is empty!\n";
            return -1;
        }

        int value = arr[front];
        front = (front + 1) % capacity;
        --size;

        return value;
    }
};

int main()
{
    Queue<int> q(3);

    q.enqueue(1);
    q.enqueue(7);
    q.enqueue(5);

    cout << "Insering an element to completely filled queue...\n";
    q.enqueue(3);

    cout << "Removing elements...\n";
    while (!q.empty())
    {
        cout << q.dequeue() << ' ';
    }

    cout << '\n';

    return 0;
}
