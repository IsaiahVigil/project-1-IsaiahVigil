#include "capacitor.h"
#include <iostream>
#include <iomanip>

Capacitor::Capacitor(int num_tsteps, double capacitance)
    : t(num_tsteps, 0.0), v(num_tsteps, 0.0), cur(num_tsteps, 0.0), C(capacitance) {}

void sim_const_cur(Capacitor &cap, double I_con, double tstep, int num_tsteps) {
    for (int t = 1; t < num_tsteps; ++t) {
        cap.t[t] = t * tstep;
        cap.v[t] = cap.v[t - 1] + I_con * tstep / cap.C;
        if (t % 200 == 0) {
            std::cout << std::fixed << std::setprecision(6) //values are all zero if not. researched solution
                      << "Time: " << cap.t[t] << "sec, Voltage: " << cap.v[t] << "Volts\n";
        }
    }
}

void sim_const_v(Capacitor &cap, double R, double Vi, double tstep, int num_tsteps) {
    for (int t = 1;t < num_tsteps;++t) {
        cap.t[t] = t*tstep;
        cap.cur[t] = cap.cur[t - 1]-cap.cur[t - 1]*tstep/(R * cap.C);
        cap.v[t] = cap.v[t - 1]+cap.cur[t]*tstep/cap.C;
        if (t % 200 == 0) {
            std::cout << std::fixed << std::setprecision(6)
                      << "Time: " << cap.t[t] << " sec, Voltage: " << cap.v[t]
                      << " Volts, Current: " << cap.cur[t] << " Amps\n";
        }
    }
}
