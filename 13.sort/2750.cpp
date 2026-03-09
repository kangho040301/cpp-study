#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        for(int x = 0; x < i; x++) {
            if(v[x] > v[i]) swap(v[x],v[i]);
        }
    }
    for(int i = 0; i < n; i++) {
        cout << v[i] << '\n';
    }
    return 0;
}