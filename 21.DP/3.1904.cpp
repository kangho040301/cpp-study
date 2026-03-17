#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    if(n == 1) {
        cout << 1 << '\n';
        return 0;
    }
    vector<int> memo(4);
    memo[1] = 1;
    memo[2] = 2;
    for(int a = 3; a <= n; a++) {
        memo[3] = (memo[2] + memo[1])%15746;
        memo[1] = memo[2];
        memo[2] = memo[3];
    }
    cout << memo[2] << '\n';
    return 0;
}
/*
01타일 == 피보나치 수열
N = 1, 1  1  
N = 2, 00 11  2
N = 3, 100 001 111  3
N = 4, 0000 1100 1001 0011 1111  5
why? N의 수 = N-2의 수에 00을 붙힌 수 + N-1의 수에 1을 붙힌 수
*/