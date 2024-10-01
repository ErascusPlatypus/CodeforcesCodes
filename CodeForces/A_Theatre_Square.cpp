#include <bits/stdc++.h>
using namespace std;

#define int long long
int32_t main() {
    int n , m , a ;
    cin >> n >> m >> a ;

    int rows = n / a ;
    int cols = m / a ;

    if(n % a > 0) rows++ ;
    if(m % a > 0) cols++ ;

    cout << rows * cols << endl ;
    return 0;
}

#include <iostream>
using namespace std;

int main() {
    long long n, m, a;
    cin >> n >> m >> a;

    // Calculate the number of rows and columns needed
    long long rows = n / a + (n % a != 0); // Add 1 if there is a remainder
    long long cols = m / a + (m % a != 0); // Add 1 if there is a remainder

    // Output the total number of flagstones needed
    cout << rows * cols << endl;

    return 0;
}
