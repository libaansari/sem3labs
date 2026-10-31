#include <iostream>
using namespace std;

long long power(int a, int n) {
    // Base case
    if (n == 0)
        return 1;

    // Calculate a^(n/2)
    long long half = power(a, n / 2);

    // If n is even
    if (n % 2 == 0)
        return half * half;

    // If n is odd
    return a * half * half;
}

int main() {
    int a, n;

    cout << "Enter the base: ";
    cin >> a;

    cout << "Enter the power: ";
    cin >> n;

    cout << a << "^" << n << " = " << power(a, n);

    return 0;
}
