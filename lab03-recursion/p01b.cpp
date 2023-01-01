/* Find the factorial of a given integer n using tail recursion */

#include <iostream>

using namespace std;

int fact_aux(int m, int n)
{
    if (n == 0)
    {
        return m;
    }

    return fact_aux(m * n, n - 1);
}

/* Time: O(n)
Space: O(n) */
int fact(int n)
{
    return fact_aux(1, n);
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
