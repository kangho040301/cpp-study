#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
vector<vector<pair<int,int>>> adj(2001); //{[i]가 갈 수 있는곳, 거리}
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
void shortway(vector<int>& dist, int s) {
    dist[s] = 0;
    q.push({0,s}); // {누적 거리, 당시 정점}
    while(!q.empty()) { //출발점에서 각 노드까지 최단거리
        int d = q.top().first;
        int cnt_node = q.top().second;
        q.pop();
            
        if(dist[cnt_node] < d) continue;

        for(auto& next : adj[cnt_node]) {
            int next_node = next.first;
            int cost = next.second;
            if(dist[next_node] > d + cost) {
                dist[next_node] = d + cost;
                q.push({d + cost, next_node});
            } 
        }
    }
    return;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int T; cin >> T;
    while(T--) {
        int n, m, t; cin >> n >> m >> t; //정점, 도로, 목적지 후보 수
        int s, g, h; cin >> s >> g >> h; //출발점, g - h를 지나감
        
        for(int i = 0; i <= 2000; i++) adj[i].clear();
        
        vector<int> dist_s(n+1,1e8), dist_g(n+1,1e8), dist_h(n+1,1e8);
        for(int i = 0; i < m; i++) {
            int a, b, d; cin >> a >> b >> d; //a - b : d의 거리
            adj[a].push_back({b,d}); 
            adj[b].push_back({a,d});
        }
        vector<int> end(t);
        for(int i = 0; i < t; i++) {
            cin >> end[i]; //목적지 후보
        }
        shortway(dist_s, s);
        shortway(dist_g, g);
        shortway(dist_h, h);
        sort(end.begin(),end.end());
        for(int e : end) {
            if(dist_s[e] >= 1e8) continue;
            int path1 = dist_s[g] + dist_g[h] + dist_h[e];
            int path2 = dist_s[h] + dist_h[g] + dist_g[e];
            int shortpath = min(path1,path2);
            if(dist_s[e] == shortpath) cout << e << ' ';
        }
        cout << '\n';
    }
    return 0;
}