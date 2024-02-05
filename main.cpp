#include <iostream> // The iostream library is used for input and output
#include <vector>   // The vector library is used for arrays
#include <cmath>    // Basic C++ library for mathematical functions
#include <iomanip>  // The iomanip library is used for formatting outputs
#include <fstream>  // File export and import functions

// Custom Header files:
#include "Aircraft_Performance.h"
#include "General_Engineering.h"

// To run from the terminal window:
//  > g++ -o main main.cpp Aircraft_Performance.cpp General_Engineering.cpp
//  > ./main

int main() {
    std::cout << "Aircraft Performance Main:\n\n";

    //--------------------------------------------------------------------------------
    // Variable Declarations:
    double  m, W, LD, alpha_T, Tr, CL, CD, CD_0, e, rho, V, S, A_R, Pr;
    double g, altitude;

    int i;
    int n = 100;

    std::vector<double> V_LD_Max_array(n);

    std::string filename = "CO_AC_Performance_main.csv";

    //--------------------------------------------------------------------------------
    // Parameter Assignments:
    altitude = 10.0e3;  //Altitude, [m]
    g = grav_acel(altitude); //Gravitational acceleration, [m/s^2]
    
    m = 12.0e3;    // Aircraft mass, [kg]
    W = m*g;       // Aircraft weight, [N]
    LD = 5.0;      // L/D ratio
    alpha_T = 2.5; // Thrust incline angle, [deg]
    CL   = 2.2;    // Lift coefficient
    CD   = 0.5;    // Drag coefficient
    CD_0 = 0.02;   // Zero-lift drag coefficient
    e    = 0.8;    // Oswald efficiency factor
    rho  = 1.225;  // Air density, [kg/m^3]
    A_R  = 8.0;    // Aspect ratio (A_R = b^2/S)
    S    = 20.0;   // Wing area, [m^2]

    //---------------------------------------------------------------------------------
    // Calculations:
    // Loop over a range of air densities
    double rho_start = 0.100;   // Starting density, [kg/m^3]
    double rho_end   = 1.225;   // Ending density, [kg/m^3]

    std::vector<double> rho_array = linspace(rho_start, rho_end, n);

    for(i = 0; i < n; i++){
        V_LD_Max_array[i] = Airspeed_for_LD_Max(e, A_R, CD_0, CL, W, rho_array[i],
         S, alpha_T);
    }


    // // Output:
    std::cout << std::fixed << std::setprecision(4);
    std::cout << "Thrust Required: " << Tr/1e3 << " kN\n";
    std::cout << "Power Required: " << Pr/1e6 << " MW\n";

    //---------------------------------------------------------------------------------
    // Export data to a .csv file
    
    write_2_CSV(rho_array, V_LD_Max_array, filename);


    std::cout << "\n\nEnd Program.\n\n";
    return 0;
}