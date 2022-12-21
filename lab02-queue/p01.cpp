#include <iostream>

using namespace std;

/* Linear queue */
template <class T>
class Queue
{
private:
    T *arr;
    int front, back;
    int capacity;

public:
    Queue(int capacity)
    {
        arr = new int[capacity];
        front = -1;
        back = -1;
        this->capacity = capacity;
    }

    ~Queue()
    {
        delete[] arr;
    }

    /* Check whether the queue is empty */
    bool empty()
    {
        return front == -1 || front > back;
    }

    /* Insert an element with given value at the end of the queue
    Time: O(1)
    Space: O(1) */
    void enqueue(T value)
    {
        if (back == capacity - 1)
        {
            cout << "Queue is full!\n";
            return;
        }

        arr[++back] = value;
        front = (front == -1) ? 0 : front;
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

        return arr[front++];
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
