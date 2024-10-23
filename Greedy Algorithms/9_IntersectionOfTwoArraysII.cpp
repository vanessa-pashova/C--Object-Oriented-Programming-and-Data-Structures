#include <iostream>
#include <cassert>

void merge(int *arr, int low, int mid, int high) {
    int n1 = mid - low + 1;     //size of the first part of the array
    int n2 = high - mid;        //size of the second part of the array

    assert(n1 > 0 && n2 > 0);

    int *left  = nullptr,
            *right = nullptr;

    try {
        //creating copies of the first and second part of the array
        left = new int[n1];
        right = new int[n2];
    }

    catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        delete [] left;
        delete [] right;
        throw;      //this stops the whole program
    }

    //copying the values into the temp arr's left and right
    for(std::size_t i = 0; i < n1; ++i)
        left[i] = arr[low + i];

    for(std::size_t i = 0; i < n2; ++i)
        right[i] = arr[mid + i + 1];

    //merging the temp arr's into the initial one
    std::size_t i = 0, j = 0, k = low;

    while(i < n1 && j < n2) {
        if(left[i] <= right[j])
            arr[k++] = left[i++];

        else
            arr[k++] = right[j++];
    }

    while(i < n1)
        arr[k++] = left[i++];

    while(j < n2)
        arr[k++] = right[j++];

    delete [] left;
    delete [] right;
}

void mergeSort(int *arr, int low, int high) {
    assert(low >= 0 && high >= 0);

    if(low < high) {
        int mid = low + (high - low) / 2;
        assert(mid >= low && mid < high);

        mergeSort(arr, low, mid);          // Sort the left half
        mergeSort(arr, mid + 1, high);     // Sort the right half
        merge(arr, low, mid, high);             // Merge the two halves
    }
}

int *intersect(int *arr1, std::size_t size1, int *arr2, std::size_t size2, std::size_t &resultSize) {
    int *result = new int[std::min(size1, size2)];
    std::size_t index1 = 0, index2 = 0, k = 0;

    while(index1 < size1 && index2 < size2) {
        if(arr1[index1] == arr2[index2]) {
            result[k++] = arr1[index1];  //we add the mutual element to the result
            index1++;
            index2++;
        }

        else if(arr1[index1] < arr2[index2])
            index1++;

        else
            index2++;
    }

    resultSize = k;     //we've found the size of the result array during the process
    return result;
}

int main() {
    std::size_t first = 0, second = 0;
    std::cout << "Insert the length of nums1[] and nums2[]: " ;
    std::cin >> first >> second;

    assert(first > 0 && second > 0);

    try {
        int *nums1 = new int[first],
                *nums2 = new int[second];

        std::cout << "Insert the values of nums1[]:\n";
        for(std::size_t i = 0; i < first; ++i)
            std::cin >> nums1[i];

        std::cout << "Insert the values of nums2[]:\n";
        for(std::size_t i = 0; i < second; ++i)
            std::cin >> nums2[i];

        mergeSort(nums1, 0, first - 1);
        mergeSort(nums2, 0, second - 1);

        std::size_t resultSize = 0;
        int *result = intersect(nums1, first, nums2, second, resultSize);

        if(resultSize > 0) {
            std::cout << "Result of the intersection: [ ";
            for(std::size_t i = 0; i < resultSize - 1; ++i)
                std::cout << result[i] << ", ";

            std::cout << result[resultSize - 1] << " ]\n";
        }

        else
            std::cout << "No intersection found.\n";

        delete [] nums1;
        delete [] nums2;
        delete [] result;
    }

    catch(const std::bad_alloc&) {
        std::cerr << "Memory allocation problem\n";
        return 1;
    }

    return 0;
}
