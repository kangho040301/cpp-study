#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<int> A(n), lst;
    cin >> A[0];
    lst.push_back(A[0]);
    for(int i = 1; i < n; i++) {
        cin >> A[i];
        if(lst.back() < A[i]) {
            lst.push_back(A[i]);
        }
        else {
            auto it = lower_bound(lst.begin(), lst.end(), A[i]);
            lst[it - lst.begin()] = A[i];
        }
    }
    cout << lst.size() << '\n';
    return 0;
}