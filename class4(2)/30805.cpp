#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool compare(const pair<int, int> &a, const pair<int, int> &b) {
    if(a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<pair<int,int>> A(n); // {값, 인덱스}
    for(int i = 0; i < n; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }
    int m; cin >> m;
    vector<int> B(m);
    for(int i = 0; i < m; i++) {
        cin >> B[i];
    }
    sort(A.begin(), A.end(), compare);
    vector<int> ans;

    int A_idx = -1;
    int B_idx = 0;
    for(int i = 0; i < n; i++) {
        if(A[i].second < A_idx) continue;
        for(int j = B_idx; j < m; j++) {
            if(A[i].first == B[j]) {
                ans.push_back(A[i].first);
                A_idx = A[i].second;
                B_idx = j + 1;
                break;
            }
        }
    }
    cout << ans.size() << '\n';
    for(int x : ans) {
        cout << x << ' ';
    }
    cout << '\n';
    return 0;
}