#include <iostream>
#include <vector>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    while(true) {
        int n;
        cin >> n;
        if(n == -1) break;

        vector<int> factor;
        int sum = 0;
        for(int i = 1; i <= n/2; i++) {
            if(n%i == 0) {
                factor.push_back(i);
                sum += i;
            }
        }
        if(n == sum) {
            cout << n << " = " << factor[0];
            for(int i = 1; i < factor.size(); i++) {
                cout << " + " << factor[i];
            }
            cout << '\n';
        }
        else {
            cout << n << " is NOT perfect.\n";
        }
    }
    return 0;
}