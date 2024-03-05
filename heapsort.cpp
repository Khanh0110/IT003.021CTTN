#include <bits/stdc++.h>
using namespace std;

void heapify(vector<int>& arrs, int n, int i) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest = i;
    if (l < n && arrs[l] > arrs[largest]) {
        largest = l;
    }
    if (r < n && arrs[r] > arrs[largest]) {
        largest = r;
    }
    if (largest != i) {
        swap(arrs[i], arrs[largest]);
        heapify(arrs, n, largest);
    }
}

void heapsort(vector<int>& arrs, int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arrs, n, i);
    }
    for (int i = n - 1; i >= 0; i--) {
        swap(arrs[i], arrs[0]);
        heapify(arrs, i, 0);
    }
}

int main() {
    ifstream input("songaunhien_1.txt");
    ofstream output("heapsort1.txt");
    if (!input.is_open() || !output.is_open()) {
        cout << "Error opening files" << endl;
        return 1;
    }

    vector<int> arrs;
    int arr;
    while (input >> arr) {
        arrs.push_back(arr);
    }
    heapsort(arrs, arrs.size());
    for (int i = 0; i < arrs.size(); i++) {
        output << arrs[i] << " ";
    }

    input.close();
    output.close();

    return 0;
}
