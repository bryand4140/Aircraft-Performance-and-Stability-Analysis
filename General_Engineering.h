#ifndef GENERAL_ENGINEERING_H
#define GENERAL_ENGINEERING_H

#include <cmath>
#include <vector>
#include <iostream>
#include <string>

// General Engineering Functions:
double grav_acel(double altitude);


// --------------------------------------------------------------------------------
// Array Generation/Manipulation Functions:
std::vector<double> linspace(double x1, double x2, int n);



// --------------------------------------------------------------------------------
// File and data input/output functions:
void write_2_CSV(const std::vector<double>& vec1, const std::vector<double>& vec2,
 const std::string& filename);

#endif // GENERAL_ENGINEERING_H
