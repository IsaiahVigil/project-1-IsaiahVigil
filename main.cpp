#include "capacitor.h"
#include <iostream>

int main() {
    double R = 1e3;              // 1kOhm
    double C = 100e-12;         // 100pF
    double I_con = 1e-2;       // 10mA
    double Vi = 10.0;         // 10V
    double tstep = 1e-10;    // time step
    int num_tsteps = 50000;

    Capacitor cap(num_tsteps, C);
    cap.t[0] = 0.0;
    cap.v[0] = 0.0;
    cap.cur[0] = I_con;

    std::cout << "Constant Current:\n";
    sim_const_cur(cap, I_con, tstep, num_tsteps);

    cap.v[0] = 0.0;
    cap.cur[0] = Vi/R;

    std::cout << "\nConstant Voltage:\n";
    sim_const_v(cap, R, Vi, tstep, num_tsteps);
    return 0;
}
