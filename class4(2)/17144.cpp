#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct Dust {
    int r, c, d;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int r, c, t; cin >> r >> c >> t;
    int ans = 0;
    vector<vector<int>> house(r+1,vector<int>(c+1));
    vector<pair<int,int>> purifier;
    for(int i = 1; i <= r; i++) {
        for(int j = 1; j <= c; j++) {
            cin >> house[i][j];
            if(house[i][j] == -1) purifier.push_back({i,j});
            else ans += house[i][j];
        }
    }
    queue<Dust> q;
    while(t--) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if(house[i][j] > 0) {
                    q.push({i,j,house[i][j]});
                }
            }
        }
        //미세 먼지가 퍼짐
        while(!q.empty()) {
            int cntr = q.front().r;
            int cntc = q.front().c;
            int spread = q.front().d/5;
            q.pop();

            int spread_num = 0;
            int dr[] = {-1, 1, 0, 0};
            int dc[] = {0, 0, -1, 1};
            for(int i = 0; i < 4; i++) {
                int nr = cntr + dr[i];
                int nc = cntc + dc[i];
                if(nc > 0  && nr > 0 && nc <= c && nr <= r) {
                    if(house[nr][nc] != -1) {
                        house[nr][nc] += spread;
                        spread_num++;
                    }
                }
            }
            house[cntr][cntc] -= spread*spread_num;
        }
        //공기 청정 위쪽
        int cntr = purifier[0].first;
        int cntc = purifier[0].second;
        while(true) {
            if(cntr == purifier[0].first && cntc > 1) {
                if(house[cntr][cntc - 1] == -1) {
                    house[cntr][cntc] = 0;
                    break;
                }
                if(house[cntr][cntc] == -1) {
                    ans -= house[cntr][cntc - 1];
                }
                else {
                    house[cntr][cntc] = house[cntr][cntc - 1];
                }
                cntc--;
            }
            else if(cntc == 1 && cntr > 1) {
                if(house[cntr][cntc] == - 1) {
                    ans -= house[cntr - 1][cntc];
                }
                else {
                    house[cntr][cntc] = house[cntr - 1][cntc];
                }
                cntr--;
            }
            else if(cntr == 1 && cntc < c) {
                house[cntr][cntc] = house[cntr][cntc + 1];
                cntc++;
            }
            else if(cntc == c && cntr < purifier[0].first) {
                house[cntr][cntc] = house[cntr + 1][cntc];
                cntr++;
            }
        }
        //공기 청정 아래쪽
        cntr = purifier[1].first;
        cntc = purifier[1].second;
        while(true) {
            if(cntr == purifier[1].first && cntc > 1) {
                if(house[cntr][cntc - 1] == -1) {
                    house[cntr][cntc] = 0;
                    break;
                }
                if(house[cntr][cntc] == -1) {
                    ans -= house[cntr][cntc - 1];
                }
                else {
                    house[cntr][cntc] = house[cntr][cntc - 1];
                }
                cntc--;
            }
            else if(cntc == 1 && cntr < r) {
                if(house[cntr][cntc] == -1) {
                    ans -= house[cntr + 1][cntc];
                }
                else {
                    house[cntr][cntc] = house[cntr + 1][cntc];
                }
                cntr++;
            }
            else if(cntr == r && cntc < c) {
                house[cntr][cntc] = house[cntr][cntc + 1];
                cntc++;
            }
            else if(cntc == c && cntr > purifier[1].first) {
                house[cntr][cntc] = house[cntr - 1][cntc];
                cntr--;
            }
        }
    }
    cout << ans << '\n';
    return 0;
}