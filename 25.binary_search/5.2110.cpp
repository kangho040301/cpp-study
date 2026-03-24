#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, c; cin >> n >> c;
    vector<int> dot(n);
    for(int i = 0; i < n; i++) {
        cin >> dot[i];
    }
    sort(dot.begin(),dot.end());
    int low = 1, high = dot[n-1] - dot[0]; // 초기값 설정 : 거리의 최소, 최대
    int ans = 0;
    while(low <= high) {
        int start = dot[0];
        int mid = low + (high - low) / 2;
        int cNum = 1;
        for(int i = 1; i < n; i++) {
            int end = dot[i];
            if(end - start >= mid) {
                start = dot[i];
                cNum++;
            }
        }
        if(cNum >= c) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    cout << ans << '\n';
    return 0;
}