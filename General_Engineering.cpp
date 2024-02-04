#include <iostream> // The iostream library is used for input and output
#include <fstream>  // The fstream library is used for file export and import functions
#include <vector>   // The vector library is used for arrays
#include <string>   // The string library is used for strings

#include "General_Engineering.h"


// General Engineering Functions:
// --------------------------------------------------------------------------------
double grav_acel(double altitude) {
    const double G = 6.67430e-11; // Gravitational constant in m^3 kg^−1 s^−2
    const double M = 5.972e24; // Mass of the Earth in kg
    const double R = 6371000; // Radius of the Earth in meters

    double g = (G * M) / std::pow((R + altitude), 2);
    return g;
}


// --------------------------------------------------------------------------------
// Array Generation/Manipulation Functions:
std::vector<double> linspace(double x1, double x2, int n) {
    // General Description: This function generates a vector of n equally spaced
    //      values between x1 and x2.
    // Inputs:
    //  > x1: The first value in the vector
    //  > x2: The last value in the vector
    //  > n: The number of elements in the vector
    // Outputs:
    //  > result: The vector of equally spaced values
    
    std::vector<double> result;

    if (n <= 0) {
        std::cerr << "Error: The number of elements must be positive." << std::endl;
        return result;
    }
    if (n == 1) {
        result.push_back(x1);
        return result;
    }

    double dx = (x2 - x1) / (n - 1);
    for (int i = 0; i < n; ++i) {
        result.push_back(x1 + i * dx);
    }
    return result;
}




// --------------------------------------------------------------------------------
// Data Input/Output Functions:

// This function takes two vectors and exports them to a .csv file.
void write_2_CSV(const std::vector<double>& vec1, const std::vector<double>& vec2,
 const std::string& filename) {
    // Check if the vectors are of equal size
    if (vec1.size() != vec2.size()) {
        std::cerr << "Error: Vectors have different sizes." << std::endl;
        return;
    }

    // Open the file
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Could not open file " << filename << std::endl;
        return;
    }

    // Assuming both vectors are of the same size
    for (unsigned int i = 0; i < vec1.size(); ++i) {
        file << vec1[i] << "," << vec2[i] << "\n";
    }
    std::cout << "Data Write Complete.\n";
    file.close();
}