/* Find the nth Fibonacci number using recursion (non-tail) */

#include <iostream>

using namespace std;

/* fib(0)=0, fib(1)=1
Time: O(2^n)
Space: O(n) */
int fib(int n)
{
    if (n < 2)
    {
        return n;
    }

    return fib(n - 1) + fib(n - 2);
}

int main()
{
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Invalid input.\n";
        return -1;
    }

    cout << "Fibonacci number at index " << n << " = " << fib(n) << '\n';

    return 0;
}
