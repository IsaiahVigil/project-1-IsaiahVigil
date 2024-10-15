#ifndef CAPACITOR_H
#define CAPACITOR_H
#include <vector>

struct Capacitor {
    std::vector<double> t;     //time
    std::vector<double> v;    // voltage
    std::vector<double> cur; // current
    double C;               // capacitance

    Capacitor(int num_tsteps, double capacitance);
};
// Functions
void sim_const_cur(Capacitor &cap, double I_con, double tstep, int num_tsteps); //con vs const reason: wordplay
void sim_const_v(Capacitor &cap, double R, double Vi, double tstep, int num_tsteps);

#endif
