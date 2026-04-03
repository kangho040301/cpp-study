#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
unordered_map<char,char> left_child;
unordered_map<char,char> right_child;
string ans1, ans2, ans3;
void before(char p) {
    if(p == '.') return;
    ans1 += p;
    before(left_child[p]);
    before(right_child[p]);
}
void mid(char p) {
    if(p == '.') return;
    mid(left_child[p]);
    ans2 += p;
    mid(right_child[p]);
}
void after(char p) {
    if(p == '.') return;
    after(left_child[p]);
    after(right_child[p]);
    ans3 += p;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    for(int i = 0; i < n; i++) {
        char p, l, r;
        cin >> p >> l >> r;
        left_child[p] = l;
        right_child[p] = r;
    }
    before('A');
    mid('A');
    after('A');
    cout << ans1 << '\n' << ans2 << '\n' << ans3 << '\n';
    return 0;
}