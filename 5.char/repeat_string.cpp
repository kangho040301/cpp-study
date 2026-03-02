#include <iostream>
#include <string>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string alpha = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ\\$%*+-./:";
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        int r;
        string s;
        cin >> r >> s;
        for(int j = 0; j < s.length(); j++) {
            string repeat(r,s[j]);
            cout << repeat;
        }
        cout << '\n';
    }
    return 0;
}