/* Write a program to solve the Tower of Hanoi problem.*/

#include <iostream>

using namespace std;

/* Disks are labelled from 1 (smallest, topmost) to n (largest, bottom-most)
Time: O(2^n)
Space: O(n) */
void tower_of_hanoi(int n, char src='A', char des='C', char aux='B')
{
    if (n > 0)
    {
        /* Move the n-1 disks from source rod to auxiliary rod using destination rod */
        tower_of_hanoi(n - 1, src, aux, des);
        
        /* Move the last disc from source rod to destination rod */
        cout << "Move disc " << n << " from rod " << src << " to " << des << '\n';

        /* Move the n-1 disks that we kept on auxiliary rod to target rod using source rod */
        tower_of_hanoi(n - 1, aux, des, src);
    }
}

int main()
{
    tower_of_hanoi(3);

    return 0;
}
