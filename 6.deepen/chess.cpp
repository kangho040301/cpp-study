#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> v(6);
    for(int i = 0; i < 6; i++) {
        cin >> v[i];
    }
    cout << 1-v[0] << ' ' << 1-v[1] << ' ' << 2-v[2] << ' ' << 2-v[3] << ' ' << 2-v[4] << ' ' << 8-v[5] << '\n';
    return 0;
}