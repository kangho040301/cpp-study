#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Meeting {
    int start, end;
    bool operator <(const Meeting& other) const {
        if(end == other.end) {
            return start < other.start;
        }
        return end < other.end;
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<Meeting> meet(n);
    for(int i = 0; i < n; i++) {
        cin >> meet[i].start >> meet[i].end;
    }
    sort(meet.begin(), meet.end());
    int standard = meet[0].end;
    int ans = 1;
    for(int i = 1; i < n; i++) {
        if(meet[i].start >= standard) {
            standard = meet[i].end;
            ans++;
        }
    }
    cout << ans << '\n';
    return 0;
}