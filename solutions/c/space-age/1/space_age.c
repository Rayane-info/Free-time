#include "space_age.h"

float age(planet_t planet, int64_t seconds){
    int oneyear_to_seconds = 31557600;
    if (planet == MERCURY) return (seconds/oneyear_to_seconds) / 0.2408467;
    if (planet == VENUS) return (seconds/oneyear_to_seconds) / 0.61519726;
    if (planet == EARTH) return (seconds/oneyear_to_seconds) / 1.0;
    if (planet == MARS) return (seconds/oneyear_to_seconds) / 1.8808158;
    if (planet == JUPITER) return (seconds/oneyear_to_seconds) / 11.862615;
    if (planet == SATURN) return (seconds/oneyear_to_seconds) / 29.447498;
    if (planet == URANUS) return (seconds/oneyear_to_seconds) / 84.016846;
    if (planet == NEPTUNE) return (seconds/oneyear_to_seconds) / 164.79132;
    return -1;
}    