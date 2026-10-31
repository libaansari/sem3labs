#include <iostream>
#include <vector>
#include <string>


template <typename T>
int linearSearch(const std::vector<T>& arr, const T& key) {
    for (size_t i = 0; i < arr.size(); ++i) {
        if (arr[i] == key) {
            return static_cast<int>(i); // Element found
        }
    }
    return -1; // Element not found
}

int main() {
    // 1. Searching in an integer array
    std::vector<int> intArr = {10, 25, 30, 45, 50};
    int intKey = 45;
    int intIndex = linearSearch(intArr, intKey);

    if (intIndex != -1) {
        std::cout << "Integer " << intKey << " found at index " << intIndex << "\n";
    } else {
        std::cout << "Integer " << intKey << " not found\n";
    }

    // 2. Searching in a floating-point array
    std::vector<double> doubleArr = {1.1, 2.5, 3.8, 4.2};
    double doubleKey = 2.5;
    int doubleIndex = linearSearch(doubleArr, doubleKey);

    if (doubleIndex != -1) {
        std::cout << "Double " << doubleKey << " found at index " << doubleIndex << "\n";
    } else {
        std::cout << "Double " << doubleKey << " not found\n";
    }

    // 3. Searching in a string array
    std::vector<std::string> stringArr = {"apple", "banana", "cherry", "date"};
    std::string stringKey = "cherry";
    int stringIndex = linearSearch(stringArr, stringKey);

    if (stringIndex != -1) {
        std::cout << "String \"" << stringKey << "\" found at index " << stringIndex << "\n";
    } else {
        std::cout << "String \"" << stringKey << "\" not found\n";
    }

    return 0;
}