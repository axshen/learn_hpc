#include "body.h"
#include "physics.h"

double Physics::distance(const Body &b1, const Body &b2) {
    double dx = b2.m_x - b1.m_x;
    double dy = b2.m_y - b1.m_y;
    double r2 = pow(dx, 2) + pow(dy, 2);
    return r2;
}

double Physics::gravitationalForceMagnitude(const Body &b1, const Body &b2) {
    double F = G * b1.m_mass * b2.m_mass / distance(b1, b2);
    return F;
}

pairwiseForce_t Physics::gravitationalForceComponents(const Body &b1, const Body &b2) {
    double F = gravitationalForceMagnitude(b1, b2);
    double r = std::sqrt(distance(b1, b2));
    double b1Fx = F * (b2.m_x - b1.m_x) / r;
    double b1Fy = F * (b2.m_y - b1.m_y) / r;
    double b2Fx = -b1Fx;
    double b2Fy = -b1Fy;
    return { b1Fx, b1Fy, b2Fx, b2Fy };
}