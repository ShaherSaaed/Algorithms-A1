#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

template<typename T>
int seq_search(vector<T> vc, T key) {
    for (int i = 0; i < vc.size(); i++) {
        if (vc[i] == key)
            return i;
    }
    return -1;
}

template<typename T>
int req_seq_search(vector<T> vc, T key, int ind) {
    if (vc[ind] == key)
        return ind;
    else if (ind == 0)
        return -1;
    return req_seq_search(vc, key, ind - 1);
}

template<typename T>
int binary_search(vector<T> vc, T key) {
    int l = 0, r = vc.size() - 1;
    while (r >= l) {
        int middle = l + (r - l) / 2;
        if (vc[middle] == key)
            return middle;
        if (key > vc[middle]) {
            l = middle + 1;
        } else {
            r = middle - 1;
        }
    }
    return -1;
}

template<typename T>
int req_binary_search(vector<T> vc, T key, int l, int r) {
    if (r >= l) {
        int mid = l + (r - l) / 2;
        if (vc[mid] == key)
            return mid;
        if (key > vc[mid])
            return req_binary_search(vc, key, mid + 1, r);
        else
            return req_binary_search(vc, key, l, mid - 1);
    }
    return -1;

}

int main() {
    vector<int> vc = {1, 3, 5, 7, 9, 5};

    // Sequential Search Test Cases
    cout << "Testing seq_search:" << endl;
    cout << "Index of 5: " << (seq_search(vc, 5) != -1 ? to_string(seq_search(vc, 5)) : "Element is not in list")
         << endl;
    cout << "Index of 7: " << (seq_search(vc, 7) != -1 ? to_string(seq_search(vc, 7)) : "Element is not in list")
         << endl;
    cout << "Index of 10: " << (seq_search(vc, 10) != -1 ? to_string(seq_search(vc, 10)) : "Element is not in list")
         << endl;

    // Recursive Sequential Search Test Cases
    cout << "\nTesting req_seq_search:" << endl;
    cout << "Index of 5 (last occurrence): "
         << (req_seq_search(vc, 5, vc.size() - 1) != -1 ? to_string(req_seq_search(vc, 5, vc.size() - 1))
                                                        : "Element is not in list") << endl;
    cout << "Index of 3: "
         << (req_seq_search(vc, 3, vc.size() - 1) != -1 ? to_string(req_seq_search(vc, 3, vc.size() - 1))
                                                        : "Element is not in list") << endl;
    cout << "Index of 10: "
         << (req_seq_search(vc, 10, vc.size() - 1) != -1 ? to_string(req_seq_search(vc, 10, vc.size() - 1))
                                                         : "Element is not in list") << endl;

    // Binary Search Test Cases
    // Note: Binary search requires sorted input
    sort(vc.begin(), vc.end());  // Sorting the vector for binary search
    cout << "\nTesting binary_search (sorted vector):" << endl;
    cout << "Index of 5: " << (binary_search(vc, 5) != -1 ? to_string(binary_search(vc, 5)) : "Element is not in list")
         << endl;
    cout << "Index of 9: " << (binary_search(vc, 9) != -1 ? to_string(binary_search(vc, 9)) : "Element is not in list")
         << endl;
    cout << "Index of 2: " << (binary_search(vc, 2) != -1 ? to_string(binary_search(vc, 2)) : "Element is not in list")
         << endl;

    // Recursive Binary Search Test Cases
    cout << "\nTesting req_binary_search (sorted vector):" << endl;
    cout << "Index of 5: "
         << (req_binary_search(vc, 5, 0, vc.size() - 1) != -1 ? to_string(req_binary_search(vc, 5, 0, vc.size() - 1))
                                                              : "Element is not in list") << endl;
    cout << "Index of 9: "
         << (req_binary_search(vc, 9, 0, vc.size() - 1) != -1 ? to_string(req_binary_search(vc, 9, 0, vc.size() - 1))
                                                              : "Element is not in list") << endl;
    cout << "Index of 2: "
         << (req_binary_search(vc, 2, 0, vc.size() - 1) != -1 ? to_string(req_binary_search(vc, 2, 0, vc.size() - 1))
                                                              : "Element is not in list") << endl;

    return 0;

}