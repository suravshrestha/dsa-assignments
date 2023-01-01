/* Find the nth Fibonacci number using tail recursion */

#include <iostream>

using namespace std;

int fib_aux(int n, int a, int b)
{
    if (n == 0)
    {
        return a;
    }

    return fib_aux(n - 1, b, a + b);
}

/* fib(0)=0, fib(1)=1
Time: O(2^n)
Space: O(n) */
int fib(int n)
{
    return fib_aux(n, 0, 1);
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
