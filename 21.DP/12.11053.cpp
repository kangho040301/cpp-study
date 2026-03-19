#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
     int n;
     cin >> n;
     vector<int> array(n);
     for(int i = 0; i < n; i++) {
        cin >> array[i];
     }
     vector<int> dp(n);
     int max_dp = 0;
     dp[0] = 1;
     for(int i = 1; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j]) {
                if(dp[j] > max_dp) max_dp = dp[j];
            }
        }
        dp[i] = max_dp + 1;
        max_dp = 0;
     }
     auto it = max_element(dp.begin(),dp.end());
     cout << *it << '\n';
     return 0;
}