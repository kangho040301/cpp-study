#include <iostream>
#include <vector>
using namespace std;
struct People {
    int w, h, rank;
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n; cin >> n;
    vector<People> p(n);
    for(int i = 0; i < n; i++) {
        cin >> p[i].w >> p[i].h;
        p[i].rank = 1;
    }
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            if(p[i].w < p[j].w && p[i].h < p[j].h) {
                p[i].rank++;
            }
        }
    }
    for(int i = 0; i < n; i++) {
        cout << p[i].rank << ' ';
    }
    return 0;
}