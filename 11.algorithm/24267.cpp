#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    long long n;
    cin >> n;
    cout << (n-2)*(n-1)*n/6 << '\n' << 3 << '\n';
    return 0;
}
/*
n = 3 , i (1 to 1) j (i+1 to 2) k (j+2 to 3); 1
n = 4 , i (1 to 2) j (i+1 to 3) k (j+1 to 4) 2+1 + 1 = 4
n = 5 , i (1 to 3) j (i+1 to 4) k (j+1 to 5) 3+2+1 + 2+1 + 1 = 10
.
.
.
n = k, S(1~k-2) + S(1~k-3) + ... + 1 = (k-2)(k-1)k/6
*/