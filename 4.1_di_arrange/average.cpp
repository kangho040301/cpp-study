#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<double> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    auto it = max_element(v.begin(),v.end());
    double max = *it;
    double sum = 0;
    for(int i = 0; i < n; i++) {
        v[i] = (v[i]/max)*100;
        sum += v[i];
    }
    cout << sum/n << '\n';
    return 0;
}