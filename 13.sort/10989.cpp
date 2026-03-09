#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v(10001,0);
    for(int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v[a] += 1;
    } 
    for(int i = 0; i < 10001; i++) {
        if(v[i] != 0) {
            cout << i << '\n';
            v[i]--;
            i--;
        }
    }
    return 0;
}