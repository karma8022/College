#include <iostream>
using namespace std; 

class Heap {
    int *heap;
    int size;
};

void heapify(int *heap, int size, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }
    if (largest != index) {
        swap(heap[index], heap[largest]);
        heapify(heap, size, largest);
    }
}

void buildHeap(int *heap, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        heapify(heap, size, i);
    }
}

void heapSort(int *heap, int size) {
    buildHeap(heap, size);
    for (int i = size - 1; i >= 0; i--) {
        swap(heap[0], heap[i]);
        heapify(heap, i, 0);
    }
}

void insert(int *heap, int size, int value) {
    heap[size] = value;
    int index = size;
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void remove(int *heap, int size, int index) {
    swap(heap[index], heap[size - 1]);
    heapify(heap, size - 1, index);
}

void print(int *heap, int size) {
    for (int i = 0; i < size; i++) {
        cout << heap[i] << " ";
    }
    cout << endl;
}
int main() {
    int heap[100];
    int size = 0;
    insert(heap, size++, 10);
    insert(heap, size++, 20);
    insert(heap, size++, 30);
    insert(heap, size++, 40);
    insert(heap, size++, 50);
    insert(heap, size++, 60);
    insert(heap, size++, 70);
    insert(heap, size++, 80);
    insert(heap, size++, 90);
    insert(heap, size++, 100);
    print(heap, size);
}
