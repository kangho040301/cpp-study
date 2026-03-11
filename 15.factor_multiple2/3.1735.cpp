#include <iostream>
#include <vector>
#include <numeric>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    vector<int> v1(2);
    vector<int> v2(2);
    cin >> v1[0] >> v1[1] >> v2[0] >> v2[1];
    int top = v1[0]*v2[1] + v2[0]*v1[1];
    int bottom = v1[1]*v2[1];
    int g = gcd(top, bottom);
    cout << top/g << ' ' << bottom/g << '\n';
    return 0;
}