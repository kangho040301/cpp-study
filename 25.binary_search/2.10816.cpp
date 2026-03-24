#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    int m; cin >> m;
    while(m--) {
        int find;
        cin >> find;
        auto low = lower_bound(num.begin(),num.end(),find);
        auto high = upper_bound(num.begin(),num.end(),find);
        cout << high - low << ' ';       
    }
    cout << '\n';
    return 0;
}