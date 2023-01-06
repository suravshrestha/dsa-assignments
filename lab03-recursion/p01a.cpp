/* Find the factorial of a given integer n using recursion (non-tail) */

#include <iostream>

using namespace std;

/* Time: O(n)
Space: O(n) */
int fact(int n)
{
    if (n < 2)
    {
        return 1;
    }

    return n * fact(n - 1);
}

int main()
{
    int n;

    cout << "Enter an integer: ";
    cin >> n;

    if (n < 0)
    {
        cout << "Factorial of -ve number doesn't exist.\n";
        return -1;
    }

    cout << n << "! = " << fact(n) << '\n';

    return 0;
}
