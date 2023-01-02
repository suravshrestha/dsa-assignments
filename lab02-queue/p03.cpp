#include <iostream>

using namespace std;

/* Double-ended queue */
template <class T>
class Deque
{
private:
    T *arr;
    int front, back;
    int capacity, size;

public:
    Deque(int capacity)
    {
        arr = new T[capacity];
        front = -1;
        back = -1;
        this->capacity = capacity;
        size = 0;
    }

    ~Deque()
    {
        delete[] arr;
    }

    /* Check whether the deque is empty */
    bool empty()
    {
        return size == 0;
    }

    /* Insert an element with given value at the end of the deque
    Time: O(1)
    Space: O(1) */
    void push_back(T value)
    {
        if (size == capacity)
        {
            cout << "Deque is full!\n";
            return;
        }

        back = (back + 1) % capacity;
        arr[back] = value;

        front = (front == -1) ? 0 : front;
        ++size;
    }

    /* Insert an element with given value at the beginning of the deque
    Time: O(1)
    Space: O(1) */
    void push_front(T value)
    {
        if (size == capacity)
        {
            cout << "Deque is full!\n";
            return;
        }

        if (front == -1)
        {
            front = 0;
        }
        else if (front == 0) 
        {
            front = capacity - 1;
        }
        else 
        {
            --front;
        }

        arr[front] = value;
        ++size;
    }

    /* Remove the first element from the deque and return its value
    Time: O(1)
    Space: O(1) */
    T pop_front()
    {
        if (size == 0)
        {
            cout << "Deque is empty!\n";
            return -1;
        }

        int value = arr[front];
        --size;
        if (size == 0)
        {
            front = back = -1;
            return value;
        }

        front = (front + 1) % capacity;
        return value;
    }

    /* Remove the last element from the deque and return its value
    Time: O(1)
    Space: O(1) */
    T pop_back()
    {
        if (size == 0)
        {
            cout << "Deque is empty!\n";
            return -1;
        }

        int value = arr[back];
        --size;
        if (size == 0)
        {
            front = back = -1;
            return value;
        }

        back = (back == 0) ? (capacity - 1) : --back;
        return value;
    }
};

int main()
{
    Deque<int> d(4);

    d.push_back(1);
    d.push_front(7);
    d.push_back(5);
    d.push_front(3);

    cout << "Insering an element to completely filled deque...\n";
    d.push_back(9);

    cout << "Removing elements...\n";
    while (!d.empty())
    {
        cout << d.pop_front() << ' ' << d.pop_back() << ' ';
    }

    cout << '\n';

    return 0;
}
