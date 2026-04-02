#include <iostream>
#include <set>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        multiset<int> ms;
        while(n--) {
            char a; cin >> a;
            if(a == 'I') {
                int x; cin >> x;
                ms.insert(x);
            }
            else if(a == 'D') {
                int x; cin >> x;
                if(ms.empty()) continue;
                if(x == 1) {
                    int max_val = *ms.rbegin();
                    ms.erase(ms.find(max_val));
                }
                else {
                    int min_val = *ms.begin();
                    ms.erase(ms.find(min_val));
                }
            }
        }
        if(ms.empty()) cout << "EMPTY" << '\n';
        else {
            cout << *ms.rbegin() << ' ' << *ms.begin() << '\n';
        }
    } 
    return 0;
}