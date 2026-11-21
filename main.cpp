#include <iostream>
#include <vector>
void heapify(std::vector<int>& a, int heap_size, int root_index) {
    int largest = root_index;
    int left = 2 * root_index + 1;
    int right = 2 * root_index + 2;
    if (left < heap_size && a[left] > a[largest]) {
        largest = left;
    }
    if (right < heap_size && a[right] > a[largest]) {
        largest = right;
    }
    if (largest != root_index) {
        std::swap(a[root_index], a[largest]);
        heapify(a, heap_size, largest);
    }
}
void heapSort(std::vector<int>& a) {
    int n = a.size();
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(a, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        std::swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n;
    if (!(std::cin >> n)) return 0;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }
    heapSort(a);
    for (int num : a) {
        std::cout << num << " ";
    }
    
}