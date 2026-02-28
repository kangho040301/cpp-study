#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v;
    for(int i = 0; i<10; i++) {
        int a;
        cin >> a;
        int rest = a%42;
        auto it = find(v.begin(), v.end(), rest);
        if(it == v.end()) v.push_back(rest);
    }
    cout << v.size() << '\n';
    return 0;
}