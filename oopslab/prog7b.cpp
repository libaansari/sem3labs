#include <iostream>
#include <stdexcept> 

// Function that performs division and throws an exception on error
double divide(double numerator, double denominator) {
    if (denominator == 0) {
        // Throwing a standard exception type
        throw std::invalid_argument("Error: Division by zero is not allowed.");
    }
    return numerator / denominator;
}

int main() {
    double x = 10.0;
    double y = 0.0;

    // 1. Basic try-catch block
    try {
        std::cout << "Attempting to divide " << x << " by " << y << "...\n";
        double result = divide(x, y);
        
        // This line will be skipped if an exception is thrown above
        std::cout << "Result: " << result << "\n";
    } 
    catch (const std::invalid_argument& e) {
        // Catches specific std::invalid_argument exceptions
        std::cerr << "Caught an exception: " << e.what() << "\n";
    } 
    catch (const std::exception& e) {
        // Catches any other exception derived from std::exception
        std::cerr << "Caught a general standard exception: " << e.what() << "\n";
    } 
    catch (...) {
        // Catch-all handler for non-standard exception types
        std::cerr << "Caught an unknown exception.\n";
    }

    // 2. Demonstration with valid input
    y = 2.0;
    try {
        std::cout << "\nAttempting to divide " << x << " by " << y << "...\n";
        double result = divide(x, y);
        std::cout << "Result: " << result << "\n";
    } 
    catch (const std::exception& e) {
        std::cerr << "Caught exception: " << e.what() << "\n";
    }

    std::cout << "\nProgram execution continues safely.\n";
    return 0;
}