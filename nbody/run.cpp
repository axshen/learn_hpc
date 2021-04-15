#include <iostream>
#include <array>

#include "body.h"
#include "physics.h"

int main() {
    // initial conditions

    // initialise bodies
    Body sun( pow(10, 12), 2.0 * pow(10, 11), 0.0, 0.0, 2.0 * pow(10, 30), "Sun" );
    Body saturn( 2.3 * pow(10, 12), 9.5 * pow(10, 11), 0.0, 0.0, 6.0 * pow(10, 26), "Saturn" );

    // simulate dynamics
    double F = Physics::gravitationalForceMagnitude(sun, saturn);
    std::cout << "Total force: " << F << " N\n";

    pairwiseForce_t Fcomp = Physics::gravitationalForceComponents(sun, saturn);
    std::cout << "Components: (" << Fcomp.body1Fx << "," << Fcomp.body1Fy << ","
              << Fcomp.body2Fx << "," << Fcomp.body2Fy << ")\n";

    return 0;
}