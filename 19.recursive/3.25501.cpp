#include <iostream>
#include <string>
using namespace std;
int t = 0;
int recursion(const string &s, int l, int r) {
    t++;
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

int isPalindrome(const string &s) {
    return recursion(s, 0, s.size()- 1);
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    while(n--) {
        string s;
        cin >> s;
        cout << isPalindrome(s) << ' ' << t << '\n'; 
        t = 0;
    }
    return 0;
}