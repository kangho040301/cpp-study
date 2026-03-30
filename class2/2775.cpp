#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int k, n; cin >> k >> n;
        vector<vector<int>> num(k + 1,vector<int>(n, 1));
        for(int i = 0; i < n; i++) {
            num[0][i] = i + 1;
        }
        for(int i = 1; i <= k; i++) {
            for(int j = 1; j < n; j++) {
                num[i][j] = num[i][j - 1] + num[i-1][j];
            }
        }
        cout << num[k][n - 1] << '\n';
    }
    return 0;
}
/*
0층 1 2 3 4 ..
1층 1 3 6 10 ...
2층 1 4 10 20 ...

1층 1, 1+2, 1+2+3, 1+2+3+4,
2층 1, 1 + 1+2, 1 + 1+2 + 1+2+3,  
*/