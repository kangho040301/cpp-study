#include <iostream>
#include <deque>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int n, m; cin >> n >> m;
        deque<int> q;
        for(int i = 0; i < n; i++) {
            int x; cin >> x;
            q.push_back(x);
        }
        int idx = m;
        int ans = 0;
        while(!q.empty()) {
            bool havebigger = false;
            for(int i = 1; i < q.size(); i++) {
                if(q.front() < q[i]) {
                    havebigger = true;
                    q.push_back(q.front());
                    q.pop_front();
                    if(idx != 0) {
                        idx--;
                    }
                    else {
                        idx = q.size() - 1;
                    }
                    break;
                }
            }
            if(!havebigger) {
                q.pop_front();
                ans++;
                if(idx != 0) {
                    idx--;
                }
                else {
                    break;
                }
            }
        }
        cout << ans << '\n';
    }
    return 0;
}