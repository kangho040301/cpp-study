#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<vector<int>> num(n);
    for(int i = 0; i < n; i++) {
        for(int j = 0; j <= i; j++) {
            int x;
            cin >> x;
            num[i].push_back(x);
        }
    }
    vector<vector<int>> memo(n);
    memo[0].push_back(num[0][0]);
    for(int i = 1; i < n; i++) {
        memo[i].push_back(num[i][0] + memo[i-1][0]);
        for(int j = 1; j <= i; j++) {
            if(j == i) memo[i].push_back(num[i][j] + memo[i-1][j-1]);
            else memo[i].push_back(num[i][j] + max(memo[i-1][j-1], memo[i-1][j]));
        }
    }
    auto it = max_element(memo[n-1].begin(),memo[n-1].end());
    cout << *it << '\n';
    return 0;
}