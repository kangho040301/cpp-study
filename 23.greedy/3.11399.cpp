#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> time(n); 
    for(int i = 0; i < n; i++) {
        cin >> time[i];
    }
    sort(time.begin(),time.end());
    vector<int> sum(n);
    sum[0] = time[0];
    int ans = sum[0];
    for(int i = 1; i < n; i++) {
        sum[i] = sum[i-1] + time[i];
        ans += sum[i];
    }
    cout << ans << '\n';
    return 0;
} 