// Bubble Sort 

#include <iostream>
#include <vector>
#include <omp.h>

void bubbleSortParallel(std::vector<int>& arr) {
    int n = arr.size();
    bool swapped;

    for (int i = 0; i < n - 1; ++i) {
        swapped = false;

        // Parallelize the loop using OpenMP
        #pragma omp parallel for shared(arr, swapped)
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // If no two elements were swapped in the inner loop, the array is already sorted
        if (!swapped) {
            break;
        }
    }
}

int main() {
    int size;
    std::cout << "Enter the number of elements: ";
    std::cin >> size;

    std::vector<int> arr(size);
   std::cout << "Enter the elements: ";
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    // std::cout << "Original array: ";
    // for (int num : arr) {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    bubbleSortParallel(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}

