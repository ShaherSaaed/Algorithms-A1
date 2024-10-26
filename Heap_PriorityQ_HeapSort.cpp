#include <iostream>
#include <vector>
#include <stdexcept> // Can't use only 'return;' in class, so I used throw instead
#include <algorithm>

using namespace std;

class MinHeap {
private:
    vector<int> heap;

    void maxHeapify(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int smallest = index;
        
        if (leftChild < heap.size() && heap[leftChild] < heap[smallest])
            smallest = leftChild;
        
        if (rightChild < heap.size() && heap[rightChild] < heap[smallest])
            smallest = rightChild;
        
        if (smallest != index) {
            swap(heap[index], heap[smallest]);
            maxHeapify(smallest);
        }
    }
    
    void fixInsert() {
        for(int i = heap.size() - 1; i > 0 && heap[i] < heap[(i - 1) / 2]; i = (i - 1) / 2)
            swap(heap[i], heap[(i - 1) / 2]);
    }

public:
    void insert(int value) {
        heap.push_back(value);
        
        fixInsert();
    }

    int extractMinimum() {
        if (this->isEmpty())
            throw out_of_range("Min Heap is empty.");

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);

        return root;
    }

    int getMinimum() const {
        if (this->isEmpty())
            throw out_of_range("Min Heap is empty.");

        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    signed int size() const {
        return heap.size();
    }

    void buildHeap(const vector<int>& array) {
        heap = array;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i)
            maxHeapify(i);
    }
};

class MaxHeap {
private:
    vector<int> heap;

    void maxHeapify(int index) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;
        
        if (leftChild < heap.size() && heap[leftChild] > heap[largest])
            largest = leftChild;

        
        if (rightChild < heap.size() && heap[rightChild] > heap[largest])
            largest = rightChild;
        
        if (largest != index) {
            swap(heap[index], heap[largest]);
            maxHeapify(largest);
        }
    }

    void fixInsert() {
        for (int i = heap.size() - 1; i > 0 && heap[i] > heap[(i - 1) / 2]; i = (i - 1) / 2)
            swap(heap[i], heap[(i - 1) / 2]);
    }
    
public:
    void insert(int value) {
        heap.push_back(value);
        fixInsert();
    }

    int extractMaximum() {
        if (this->isEmpty())
            throw out_of_range("Max Heap is empty.");

        int root = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        maxHeapify(0);

        return root;
    }

    int getMaximum() const {
        if (this->isEmpty())
            throw out_of_range("Max Heap is empty.");

        return heap[0];
    }

    bool isEmpty() const {
        return heap.empty();
    }

    signed int size() const {
        return heap.size();
    }

    void buildHeap(const vector<int>& array) {
        heap = array;
        for (int i = (heap.size() / 2) - 1; i >= 0; --i)
            maxHeapify(i);
    }
};


class PriorityQueue {
private:
    MinHeap minHeap;
    MaxHeap maxHeap;

public:
    void push(int value) {
        minHeap.insert(value);
        maxHeap.insert(value);
    }

    int popMin() {
        return minHeap.extractMinimum();
    }

    int getMin() const {
        return minHeap.getMinimum();
    }

    int popMax() {
        return maxHeap.extractMaximum();
    }

    int getMax() const {
        return maxHeap.getMaximum();
    }

    signed int getSize() {
        return min(minHeap.size(), maxHeap.size());
    }

    bool isEmpty() const {
        return minHeap.isEmpty() && maxHeap.isEmpty();
    }
};


vector<int> heapSortMin(vector<int>& array) {
    MinHeap minHeap;
    minHeap.buildHeap(array);

    vector<int> sortedArray;
    while (!minHeap.isEmpty()) {
        sortedArray.push_back(minHeap.extractMinimum());
    }

    return sortedArray;
}

// Heap Sort using MaxHeap
vector<int> heapSortMax(vector<int>& array) {
    MaxHeap maxHeap;
    maxHeap.buildHeap(array); // Build a max heap

    vector<int> sortedArray;
    while (!maxHeap.isEmpty()) {
        sortedArray.push_back(maxHeap.extractMaximum());
    }

    reverse(sortedArray.begin(), sortedArray.end());
    return sortedArray;
}

int main() {
    MinHeap minHeap;
    MaxHeap maxHeap;

    cout << "MIN/MAX HEAP IMPLEMENTATION: \n";
    minHeap.insert(1); maxHeap.insert(1);
    minHeap.insert(5); maxHeap.insert(5);
    minHeap.insert(3); maxHeap.insert(3);
    minHeap.insert(7); maxHeap.insert(7);

    cout << "Minimum: " << minHeap.getMinimum() << endl;
    cout << "Maximum: " << maxHeap.getMaximum() << endl;

    cout << "Popped Minimum: " << minHeap.extractMinimum() << endl;
    cout << "New Minimum: " << minHeap.getMinimum() << endl;

    cout << "Popped Maximum: " << maxHeap.extractMaximum() << endl;
    cout << "New Maximum: " << maxHeap.getMaximum() << endl << endl;

//-------------------------------------------------------------------------

    cout << "\nPRIORITY QUEUE IMPLEMENTATION: \n";
    PriorityQueue pq;

    pq.push(10);
    pq.push(20);
    pq.push(15);

    cout << "Maximum: " << pq.getMax() << endl; // 20

    // return 20 and then removes it
    cout << "Extracted Max: " << pq.popMax() << endl;
    cout << "New Maximum: " << pq.getMax() << endl; // 15

//------------------------------------------------------------------------

    cout << "\nHEAP SORT IMPLEMENTATION: \n";
    vector<int> array = {3, 5, 1, 10, 2, 7};

    cout << "Original unsorted Array: ";
    for (int num : array)
        cout << num << ' ';
    cout << endl;

    vector<int> sortedArrayMin = heapSortMin(array);
    cout << "Sorted Array Using (MinHeap): ";
    for (int num : sortedArrayMin)
        cout << num << ' ';
    cout << endl;

    vector<int> sortedArrayMax = heapSortMax(array);
    cout << "Sorted Array Using (MaxHeap): ";
    for (int num : sortedArrayMax)
        cout << num << ' ';
    cout << endl;

    return 0;
}
