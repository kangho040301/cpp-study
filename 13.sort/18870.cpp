#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vector<int> answer_v(n);
    answer_v = v;
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    for(int i = 0; i < n; i++) {
        auto it = lower_bound(v.begin(),v.end(),answer_v[i]);
        cout << it - v.begin() << ' ';
    }
    cout << '\n';
    return 0;
}