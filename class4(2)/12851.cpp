#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k; cin >> n >> k;
    queue<pair<int,int>> q; // {시간, 위치};
    vector<int> visited_time(100001, 1e8);
    q.push({0,n});
    int ans1 = 0, ans2 = 0;
    bool first_meet = false;
    while(!q.empty()) {
        int cnt_t = q.front().first;
        int cnt_l = q.front().second;
        q.pop();

        if(cnt_l == k) {
            if(!first_meet) {
                ans1 = cnt_t;
                ans2++;
                first_meet = true;
            }
            else if(cnt_t == ans1) {
                ans2++;
            }
            else break;
        }

        int dx[] = {cnt_l*2, cnt_l + 1, cnt_l - 1};
        for(int i = 0; i < 3; i++) {
            int next = dx[i];
            if(next >= 0 && next <= 100000 && visited_time[next] >= cnt_t + 1) {
                visited_time[next] = cnt_t + 1;
                q.push({cnt_t + 1, next});
            }
        }
    }
    cout << ans1 << '\n' << ans2 << '\n';
    return 0;
}
