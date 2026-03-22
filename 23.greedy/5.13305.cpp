#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<long long> length(n-1);
    for(int i = 0; i < n - 1; i++) {
        cin >> length[i];
    }
    vector<long long> price(n);
    cin >> price[0];
    long long ans = price[0] * length[0];
    for(int i = 1; i < n - 1; i++) {
        cin >> price[i];
        if(price[i] > price[i-1]) {
            price[i] = price[i-1];
        }
        ans += price[i] * length[i];
    }
    cin >> price[n-1];
    cout << ans << '\n';
    return 0;
}