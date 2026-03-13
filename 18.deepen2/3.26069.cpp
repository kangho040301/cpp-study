#include <iostream>
#include <unordered_set>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    unordered_set<string> dance;
    dance.insert("ChongChong");
    while(n--) {
        string n1, n2;
        cin >> n1 >> n2;
        if(dance.find(n1) != dance.end()) {
            dance.insert(n2);
        }
        else if(dance.find(n2) != dance.end()) {
            dance.insert(n1);
        }
    }
    cout << dance.size() << '\n';
    return 0;
} 
/*
if(dance.count(n1) || dance.count(n2)) {
    dance.insert(n1);
    dance.insert(n2);    
}
*/