#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> array(n);
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> array[i];
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < i; j++) {
            if(array[i] > array[j] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                pre[i] = j; //i의 직전은 j
            }
        }
    }
    auto it = max_element(dp.begin(),dp.end());
    cout << *it << '\n';
    vector<int> ans;
    ans.push_back(it - dp.begin());
    int i = 0;
    while(pre[ans[i]] > - 1) {
        ans.push_back(pre[ans[i]]);
        i++;
    }
    for(int x = i - 1; i >= 0; i--) {
        cout << array[ans[i]] << ' ';
    }
    return 0;
}
