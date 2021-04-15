#ifndef PHYSICS_H
#define PHYSICS_H

#include <cmath>
#include <tuple>
#include <string>

#define G 6.67 * std::pow(10, -11)

class Body;

struct pairwiseForce_t {
    double body1Fx;
    double body1Fy;
    double body2Fx;
    double body2Fy;
};

class Physics {
    public:
        static double distance(const Body &b1, const Body &b2);
        static double gravitationalForceMagnitude(const Body &b1, const Body &b2);
        static pairwiseForce_t gravitationalForceComponents(const Body &b1, const Body &b2);
};

#endif