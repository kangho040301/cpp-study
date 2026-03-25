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
    Minheap() {
        heap.push_back(0);
        idx = 0;
    }

    void push(int x) {
        heap.push_back(x); idx++;
        int i = idx;
        while(i > 1 && abs(x) <= abs(heap[i/2])) {
            if(abs(x) == abs(heap[i/2]) && x >= heap[i/2]) break;
            swap(heap[i], heap[i/2]);
            i /= 2;
        }
    }

    int pop() {
        if(idx == 0) return 0;
        int root = heap[1];
        heap[1] = heap.back();
        heap[idx] = INT_MAX;
        
        int i = 1;
        while(2 * i + 1 <= idx) {
            int child = 2*i;
            if(abs(heap[child]) > abs(heap[child + 1]) ||
            (abs(heap[child]) == abs(heap[child + 1]) && heap[child] > heap[child + 1])) {
                child++;
            }

            if(abs(heap[child]) < abs(heap[i]) ||
            (abs(heap[child]) == abs(heap[i]) && heap[child] < heap[i])) {
                swap(heap[child], heap[i]);
                i = child;
            }
            else break;
        }
        heap.pop_back(); idx--;
        return root;
    }
};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);

    int n; cin >> n;
    Minheap heap;
    while(n--) {
        int x; cin >> x;
        if(x != 0) {
            heap.push(x);
        }
        else {
            cout << heap.pop() << '\n';
        }
    }
    return 0;
}