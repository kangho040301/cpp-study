#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;
vector<int> tmp(500001);
int ans = 0;
void merge(vector<int> &v, int p, int q, int r,const int &k) {
    int i = p;
    int j = q + 1;
    int t = 0;
    while(i <= q && j <= r) {
        if(v[i] <= v[j]) tmp[t++] = v[i++];
        else tmp[t++] = v[j++];
    }
    while(i <= q) tmp[t++] = v[i++];
    while(j <= r) tmp[t++] = v[j++];
    i = p; t = 0;
    while(i <= r) {
        v[i++] = tmp[t++];
        ans++;
        if(ans == k) {
        cout << v[i - 1] << '\n';
        exit(0);
        }
    }

}
void merge_sort(vector<int> &v, int p, int r,const int &k) {
    if(p < r) {
        int q = (p+r)/2;
        merge_sort(v, p, q, k);
        merge_sort(v, q+1, r, k);
        merge(v, p, q, r, k);
    }
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    merge_sort(v, 0, n-1, k);
    cout << -1 << '\n';
    return 0;
}