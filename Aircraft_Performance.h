#ifndef AIRCRAFT_PERFORMANCE_H
#define AIRCRAFT_PERFORMANCE_H

// Purpose of header files: Header files are used to share functions and
//      variables between multiple files. The header file is included in the
//      file that needs the functions and variables. The header file is not
//      compiled by itself. It is compiled when it is included in another file.


//NOTES: #ifndef AIRCRAFT_PERFORMANCE_H: This line checks if AIRCRAFT_PERFORMANCE
//      is defined. If it is not defined, then the code between the #ifndef and
//      #endif is compiled. If it is defined, then the code is not compiled.

//      #define AIRCRAFT_PERFORMANCE_H: This line defines AIRCRAFT_PERFORMANCE_H
//      so that the next time the #ifndef AIRCRAFT_PERFORMANCE_H is called, it
//      will be defined and the code between the #ifndef and #endif will not be
//      compiled.

#include <cmath>

double Calculate_Required_Thrust(double W, double LD, double alpha_T);

double Airspeed_for_LD_Max(double e, double A_r, double CD_0, double CD_0L, double W, double rho, double Sw, double alpha_T);

double Power_Required(double CD_0, double CL, double e, double A_R, double W, double Sw, double rho);

double Power_Required(double CD_0, double CL, double e, double A_R, double W, double Sw, double rho);

#endif // AIRCRAFT_PERFORMANCE_H