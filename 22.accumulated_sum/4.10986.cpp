#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    vector<long long> count(m);
    int sum = 0;
    for(int i = 0; i < n; i++) {
        int a; cin >> a;
        sum = (sum + a) % m;
        count[sum]++;
    }
    long long ans = count[0];
    for(int i = 0; i < m; i++) {
        ans += (count[i]*(count[i]-1))/2;
    }
    cout << ans << '\n';
    return 0;
}