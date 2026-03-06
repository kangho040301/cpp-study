#include <iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n;
    cin >> n;
    int prime = n;
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        if(num == 1) {
            prime--;
            continue;
        }
        if(num == 2) continue;
        for(int a = 2; a <= num/2; a++) {
            if(num%a == 0) {
                prime--;
                break;
            }
        }
    }
    cout << prime << '\n';
}