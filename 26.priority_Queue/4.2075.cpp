#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;
class Minheap {
private:
    vector<int> heap;
    int idx;
public:
    Minheap(int n) : idx(0) {
        heap.reserve(n+2);
        heap.push_back(0);
    }
    
    void push(int x) {
        heap.push_back(x); idx++;
        int i = idx;
        while(i > 1 && x < heap[i/2]) {
            swap(heap[i], heap[i/2]);
            i /= 2;
        }
    }
    
    void replace(int x) {
        if(x > heap[1]) {
            heap.push_back(x); idx++;
            heap[1] = x;
            heap[idx] = INT_MAX;
            int i = 1;
            while(2*i + 1 <= idx && heap[i] > min(heap[2*i],heap[2*i + 1])) {
                if(heap[2*i] < heap[2*i + 1]) {
                    swap(heap[i],heap[2*i]);
                    i = 2*i;
                }
                else {
                    swap(heap[i],heap[2*i + 1]);
                    i = 2*i + 1;
                }
            }
            heap.pop_back(); idx--;
        }
        else return;
    }
    int front() {
        return heap[1];
    }
};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    
    int n;
    cin >> n;
    Minheap heap(n);

    for(int i = 0; i < n; i++) {
        int x; cin >> x;
        heap.push(x);
    }
    for(int i = 1; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int x; cin >> x;
            heap.replace(x);
        }
    }
    cout << heap.front() << '\n';
}