#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct Jewel {
    int m, v;
};
bool compare(const Jewel& a, const Jewel& b) {
    return a.m < b.m;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n, k; cin >> n >> k;
    vector<Jewel> jew(n);
    for(int i = 0; i < n; i++) {
        Jewel j;
        cin >> j.m >> j.v;
        jew[i] = j;
    }
    sort(jew.begin(),jew.end(),compare);
    vector<int> bag(k);
    for(int i = 0; i < k; i++) {
        cin >> bag[i];
    }
    sort(bag.begin(),bag.end());
    long long ans = 0;
    priority_queue<int> value;
    int i = 0;
    for(int m : bag) {
        while(i < n && m >= jew[i].m) {
            value.push(jew[i].v);
            i++;
        }
        if(!value.empty()) {
            ans += value.top();
            value.pop();
        }
    }
    cout << ans << '\n';
    return 0;
}