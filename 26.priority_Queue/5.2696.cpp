#include <iostream>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int t; cin >> t;
    while(t--) {
        int m; cin >> m;
        priority_queue<int> max_pq; //중앙값 포함 작은 값들 (루트 : 중앙값)
        priority_queue<int,vector<int>,greater<int>> min_pq; //중앙값 초과 큰 값들 (루트 : 중앙값 다음)
        cout << m/2 + 1 << '\n';
        for(int i = 1; i <= m; i++) {
            int x; cin >> x;
            if(i%2 != 0) {
                max_pq.push(x);
                if(!(min_pq.empty()) && max_pq.top() > min_pq.top()) {
                    min_pq.push(max_pq.top());
                    max_pq.push(min_pq.top());
                    min_pq.pop(); max_pq.pop();
                }
                cout << max_pq.top() << ' ';
            }
            else {
                min_pq.push(x);
                if(max_pq.top() > min_pq.top()) {
                    min_pq.push(max_pq.top());
                    max_pq.push(min_pq.top());
                    min_pq.pop(); max_pq.pop();
                }
            }
        }
        cout << '\n';
    }
    return 0;
}