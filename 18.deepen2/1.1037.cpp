#include <iostream>
#include <set>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    set<int> s;
    while(n--) {
        int a;
        cin >> a;
        s.insert(a);
    }
    cout << *s.begin() * *s.rbegin() << '\n';
    return 0;
}