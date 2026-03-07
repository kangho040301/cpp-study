#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long n;
    cin >> n;
    cout << n*(n-1)/2 << '\n' << 2 << '\n';
    return 0; 
}
/*
n = 2, i = 1 2 to 2 -> 1
n = 3, i = 1 2 to 3 i = 2 3 to 3 -> 2 + 1
n = 4, i = 1 2 to 4 i = 2 3 to 4 i = 3 4 to 4 -> 3 + 2 + 1
.
.
.
n = k, (k-1) + (k-2) + (k-3) . . . 3 + 2 + 1 = (k-1)(k)/2
*/