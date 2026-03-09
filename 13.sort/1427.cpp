#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> v;
    while(n > 0) {
        v.push_back(n%10);
        n /= 10;
    }
    sort(v.begin(),v.end());
    int len = v.size();
    for(int i = 1; i <= len; i++) {
        cout << v[len - i];
    }
    cout << '\n';
    return 0;
}