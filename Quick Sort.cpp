Быстрая сортировка — эффективный алгоритм сортировки на месте, который обычно работает примерно в два-три раза быстрее, чем Сортировка слиянием а также сортировка кучей при хорошей реализации.
Быстрая сортировка — это сортировка сравнением, то есть она может сортировать элементы любого типа, для которых меньше, чем отношение определено. В эффективных реализациях это обычно нестабильная сортировка.

#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;
        
        for (int j = low; j < high; j++) {
            if (arr[j] < pivot) {
                i++;
                std::swap(arr[i], arr[j]);
            }
        }
        
        std::swap(arr[i + 1], arr[high]);
        
        int partitionIndex = i + 1;
        
        quickSort(arr, low, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, high);
    }
}

int main() {
    std::vector<int> arr = {7, 2, 1, 6, 8, 5, 3, 4};
    
    quickSort(arr, 0, arr.size() - 1);
    
    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    
    return 0;
}
