#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<pair<int, int>> line(n);
    vector<int> dp(n, 1);
    for(int i = 0; i < n; i++) {
        cin >> line[i].first >> line[i].second;
    }
    sort(line.begin(),line.end());
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(line[i].second > line[j].second) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        
    }
    auto it = max_element(dp.begin(),dp.end());
    cout << n - *it << '\n';
    return 0;
}