#include <iostream>

#include "maxheap.h"

using namespace std;

int main() {
    int arr[10] = { 1, 3, 4, 9, 8, 7, 6, 5, 2, 0};
    maxheap<int> heap(arr, 10);

    heap.insert(11);
    for (int i=0; i<100; ++i) {
        int r = rand() % 100;
        heap.insert(r);
    }

    cout << "capacity: " << heap.capacity() << ", size: " << heap.size() << endl;
    int size = heap.size();
    while (!heap.empty()) {
        cout << heap.extractMax() << " "; //实现堆排序
    }
    cout << endl; 

    cout << "capacity: " << heap.capacity() << ", size: " << heap.size() << endl;

    system("pause");
    return 0;
}