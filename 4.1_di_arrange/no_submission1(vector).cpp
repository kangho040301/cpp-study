#include <iostream>
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(30);
    iota(v.begin(),v.end(),1);
    for(int i=0;i<28;i++) {
        int a;
        cin >> a;
        v[a-1] = 0;
    }
    v.erase(remove(v.begin(),v.end(), 0), v.end());
    cout << v[0] << '\n' << v[1] << '\n';
    return 0;
}
