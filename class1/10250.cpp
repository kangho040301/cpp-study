#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int h, w, n;
        cin >> h >> w >> n;
        if(n%h != 0) {
            cout << n%h * 100 + (n/h + 1) << '\n';
        }
        else {
            cout << h * 100 + n/h << '\n';
        }
    }
    return 0;
}