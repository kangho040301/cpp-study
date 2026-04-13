#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> a;
void solve(int start, int end) {
    if(start >= end) {
        return;
    }

    int root = a[start];

    int mid = upper_bound(a.begin() + start + 1, a.begin() + end, root) - a.begin();    
    solve(start + 1, mid);
    solve(mid, end);

    cout << root << '\n';
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    for(int x; cin >> x;) {
        a.push_back(x);
    }
    solve(0,a.size());
    return 0;
}
