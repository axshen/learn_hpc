#ifndef BODY_H
#define BODY_H

#include <string>
#include "physics.h"


class Body {
    private:
        double m_x;
        double m_y;
        double m_vx;
        double m_vy;
        double m_mass;
        std::string m_name;

    public:
        Body(double x, double y, double vx, double vy, double mass, std::string name)
        : m_x(x), m_y(y), m_vx(vx), m_vy(vy), m_mass(mass), m_name(name) {}
        Body(double x, double y, double vx, double vy, double mass)
        : m_x(x), m_y(y), m_vx(vx), m_vy(vy), m_mass(mass) {}

        friend double Physics::distance(const Body &b1, const Body &b2);
        friend double Physics::gravitationalForceMagnitude(const Body &b1, const Body &b2);
        friend pairwiseForce_t Physics::gravitationalForceComponents(const Body &b1, const Body &b2);
};

#endif