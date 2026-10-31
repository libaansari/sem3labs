#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

// Helper function to create sample input files for demonstration
void createSampleFiles() {
    std::ofstream src1("Source 1.txt");
    src1 << "10 25 40 55 70";
    src1.close();

    std::ofstream src2("Source 2.txt");
    src2 << "15 20 35 60 80 95";
    src2.close();
}

int main() {
    // Generate sample files (Source 1.txt and Source 2.txt)
    createSampleFiles();

    // Open source files for reading
    std::ifstream file1("Source 1.txt");
    std::ifstream file2("Source 2.txt");
    std::ofstream targetFile("Target.txt");

    // File validation check
    if (!file1.is_open() || !file2.is_open() || !targetFile.is_open()) {
        std::cerr << "Error: Failed to open one or more files." << std::endl;
        return 1;
    }

    int val1, val2;
    bool hasVal1 = static_cast<bool>(file1 >> val1);
    bool hasVal2 = static_cast<bool>(file2 >> val2);

    // Two-pointer merge algorithm: O(N + M) Time Complexity
    while (hasVal1 && hasVal2) {
        if (val1 <= val2) {
            targetFile << val1 << " ";
            hasVal1 = static_cast<bool>(file1 >> val1);
        } else {
            targetFile << val2 << " ";
            hasVal2 = static_cast<bool>(file2 >> val2);
        }
    }

    // Write remaining elements from Source 1 (if any)
    while (hasVal1) {
        targetFile << val1 << " ";
        hasVal1 = static_cast<bool>(file1 >> val1);
    }

    // Write remaining elements from Source 2 (if any)
    while (hasVal2) {
        targetFile << val2 << " ";
        hasVal2 = static_cast<bool>(file2 >> val2);
    }

    // Close all file streams
    file1.close();
    file2.close();
    targetFile.close();

    std::cout << "Successfully merged 'Source 1.txt' and 'Source 2.txt' into 'Target.txt'." << std::endl;

    // Display the merged contents from 'Target.txt'
    std::ifstream resultFile("Target.txt");
    std::cout << "Contents of Target.txt: ";
    int temp;
    while (resultFile >> temp) {
        std::cout << temp << " ";
    }
    std::cout << std::endl;

    resultFile.close();
    return 0;
}