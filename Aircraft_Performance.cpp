#include "Aircraft_Performance.h"
#include <cmath>

// Aircraft Performance - Thrust Required:
//  >> Reference: Phillips, C. R. (2013). Mechanics of Flight (2nd ed.). Wiley.
//       --> Section 3.2

double Calculate_Required_Thrust(double W, double LD, double alpha_T) {
    // General Description: Calculates the required thrust
    // for an aircraft to maintain level flight with no 
    // acceleration.
    //Inputs:
    //  > W: Aircraft weight, N
    //  > LD: L/D ratio
    //  > alpha_T: Thrust incline angle, [deg]
    //Outputs:
    //  > Tr: Required thrust, N


    return W / (LD * cos(alpha_T * M_PI/180.0) + sin(alpha_T * M_PI/180.0));
}

double Maximum_LD_Ratio(double e, double A_R, double CD_0, double CD_0L){
    // This function calculates the maximum L/D ratio for steady level flight 
    // with no acceleration.
    // Inputs:
    //  > e:    Oswald efficiency factor, [-]
    //  > A_R:  Aspect ratio, [-]
    //  > CD_0: Zero-lift drag coefficient, [-]
    //  > CD_0L: Derivative of CL_0 with respect to lift coefficient, [-]
    // Outputs:
    //  > LD_max: Maximum L/D ratio, [-]

    double pi = M_PI;
    double LD_max = sqrt(pi*e*A_R) / (2.0*sqrt(CD_0) + CD_0L*sqrt(pi*e*A_R));
    return LD_max;
}

double Airspeed_for_LD_Max(double e, double A_r, double CD_0, double CD_0L,
 double W, double rho, double Sw, double alpha_T){
    // This function calculates the airspeed at which the maximum L/D ratio occurs.
    // Inputs:
    //  > e:    Oswald efficiency factor, [-]
    //  > A_R:  Aspect ratio, [-]
    //  > CD_0: Zero-lift drag coefficient, [-]
    //  > CD_0L: Derivative of CL_0 with respect to lift coefficient, [-]
    //  > W:    Aircraft weight, N
    //  > rho:  Air density, kg/m^3
    //  > Sw:   Wing area, m^2
    //  > alpha_T: Thrust incline angle, [deg]
    // Outputs:
    //  > V_LD_max: Airspeed at which maximum L/D ratio occurs, m/s

    double pi = M_PI;
    double x1 = pi*e*A_r;
    double x2 = sqrt(2)/pow(x1*CD_0, 1.0/4.0) * sqrt(W / (rho*Sw));
    double x3 = 1 / (1 + (2*sqrt(CD_0 / x1) + CD_0L)*tan(alpha_T*pi/180.0));
    double V_LD_max = x2 * sqrt(x3);
    return V_LD_max;
}


double Power_Required(double CD_0, double CL, double e, double A_R, double W, double Sw, double rho){
 // This function calculates the power required for an aircraft to maintain level flight.
    // Inputs:
    //  > CD_0: Zero-lift drag coefficient
    //  > CL:   Lift coefficient
    //  > e:    Oswald efficiency factor
    //  > A_R:  Aspect ratio
    //  > W:    Aircraft weight, N
    //  > Sw:   Wing area, m^2
    //  > rho:  Air density, kg/m^3
    // Outputs: 
    //  > P_R:  Power required, W

    double Pr = sqrt(2)*(CD_0 / pow(CL, 3.0/2.0) + sqrt(CL) / (M_PI*e*A_R)) * W * sqrt(W / (rho*Sw));
    return Pr;
}






