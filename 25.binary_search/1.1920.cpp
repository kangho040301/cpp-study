#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i++) {
        cin >> num[i];
    }
    sort(num.begin(),num.end());
    int m;
    cin >> m;
    while(m--) {
        int find;
        cin >> find;
        int low = 0, high = n - 1;
        bool isfind = false;
        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(find == num[mid]) {
                cout << 1 << '\n';
                isfind = true;
                break;
            }
            if(find < num[mid]) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        if(!isfind) cout << 0 << '\n';
    }
    return 0;
}
