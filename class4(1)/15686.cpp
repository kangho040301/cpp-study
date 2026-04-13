#include <iostream>
#include <vector>
using namespace std;
struct Point {
    int r, c;
};
int n, m;
int ans = 1e8;
vector<Point> house, chicken;
vector<Point> selected;
void solve() {
    int size = house.size();
    vector<int> dist(size,1e8);
    for(Point cp : selected) {
        for(int i = 0; i < size; i++) {
            Point hp = house[i];
            dist[i] = min(dist[i], abs(cp.c - hp.c) + abs(cp.r - hp.r));
        }
    }
    int dist_sum = 0;
    for(int i = 0; i < size; i++) {
        dist_sum += dist[i];
    }
    ans = min(ans, dist_sum);
    return;
}
void SelectChicken(int cnt, int x) {
    if(cnt == m) {
        solve();
        return;
    }
    
    for(int i = x; i < chicken.size(); i++) {
        selected.push_back(chicken[i]);
        SelectChicken(cnt + 1, i + 1);
        selected.pop_back();
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            int x; cin >> x;
            if(x == 1) house.push_back({i,j});
            if(x == 2) chicken.push_back({i,j});
        }
    }
    SelectChicken(0, 0);
    cout << ans << '\n';
    return 0;
}