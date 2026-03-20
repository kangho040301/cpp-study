#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> sum(n+1);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        sum[i + 1] = sum[i] + a;
    }
    vector<int> ans(n-k+1);
    int max = sum[k];
    for(int i = 0; i < n-k+1; i++) {
        ans[i] = sum[i+k] - sum[i];
        if(ans[i] > max) max = ans[i];
    }
    cout << max << '\n';
    return 0;
}