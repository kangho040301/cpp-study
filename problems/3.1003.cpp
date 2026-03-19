#include <iostream>
#include <vector>
using namespace std;
vector<int> fib0(41), fib1(41);
void solve(int n) {
    for(int i = 2; i <= n; i++) {
        fib0[i] = fib0[i-1] + fib0[i-2];
        fib1[i] = fib1[i-1] + fib1[i-2];
    }
    cout << fib0[n] << ' ' << fib1[n] << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    fib0[0] = 1; fib1[0] = 0; fib0[1] = 0; fib1[1] = 1;
    while(t--) {
        int n;
        cin >> n;
        solve(n);
    }
    return 0;
}


/*
n = 0, 1 0
n = 1, 0 1
n = 2, 1 1
n = 3, 1 2
n = 4, 2 3
n = 5, 3 5
n = 6, 5 8
*/