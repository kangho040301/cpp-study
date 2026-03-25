#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Maxheap {
private:
    vector<int> heap;
    int idx;
public:
    Maxheap() {
        heap.push_back(0);
        idx = 0;
    }

    void push(int x) {
        heap.push_back(x); idx++;
        int i = idx;
        while(i > 1 && x > heap[i/2]) {
            swap(heap[i], heap[i/2]);
            i /= 2;
        }
    }

    int pop() {
        if(idx == 0) return 0;
        int root = heap[1];
        heap[1] = heap.back();
        heap[idx] = 0;
        
        int i = 1;
        while(2*i + 1 <= idx && heap[i] < max(heap[2*i],heap[2*i + 1])) {
            if(heap[2*i] > heap[2*i + 1]) {
                swap(heap[i], heap[2*i]);
                i *= 2;
            }
            else {
                swap(heap[i], heap[2*i + 1]);
                i = 2*i + 1;
            }
        }
        heap.pop_back(); idx--;
        return root;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    Maxheap heap;
    while(n--) {
        int x; cin >> x;
        if(x > 0) {
            heap.push(x);
        }
        else {
            cout << heap.pop() << '\n';
        }
    }
    return 0;
}