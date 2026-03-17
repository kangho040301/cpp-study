#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t;
    cin >> t;
    vector<long long> memo(101);
    memo[1] = memo[2] = memo[3] = 1;
    memo[4] = memo[5] = 2;
    while(t--) {
        int n;
        cin >> n;
        for(int i = 6; i <= n; i++) {
            memo[i] = memo[i-1] + memo[i-5];
        }
        cout << memo[n] << '\n';
    }
    return 0;
}
/*
n = 1, 1
n = 2, 1
n = 3, 1
n = 4, 2
n = 5, 2
n = 6, p(5) + p(1) = 3
n = 7, p(6) + p(2) = 4
n = 8, p(7) + p(3) = 5
n = 9, p(8) + p(4) = 7
n = 10, p(9) + p(5) = 9
-> p(n) = p(n-1) + p(n-5) ; n > 5
*/