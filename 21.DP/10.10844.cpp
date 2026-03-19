#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    int memo[101][10]; // memo[n][i] == 뒤에서 n번째자리수는 i
    for(int i = 0; i <= 9; i++) {
        memo[1][i] = 1;
    }
    for(int i = 2; i <= n; i++) {
        for(int j = 0; j <= 9; j++) {
            if (j == 0) memo[i][j] = (memo[i-1][j+1])%1000000000;
            else if (j == 9) memo[i][j] = (memo[i-1][j-1])%1000000000;
            else memo[i][j] = (memo[i-1][j-1]%1000000000 + memo[i-1][j+1]%1000000000)%1000000000;
        }
    }
    int ans = 0;
    for(int i = 1; i <= 9; i++) {
        ans += memo[n][i];
        ans %= 1000000000;
    }
    cout << ans << '\n';
    return 0;
}