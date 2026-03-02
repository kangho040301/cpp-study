#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string alphabet = "abcdefghijklmnopqrstuvwxyz";
    string s;
    cin >> s;
    for(int i = 0; i < alphabet.length(); i++) {
        if(s.find(alphabet[i]) != string::npos) cout << s.find(alphabet[i]) << " ";
        else cout << -1 << " ";
    }
    return 0;
}