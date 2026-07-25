#include "triangle.h"

bool is_triangle(triangle_t t) {
    if (t.a <= 0 || t.b <= 0 || t.c <= 0) {
        return false;
    }
    
    if (t.a + t.b <= t.c || 
        t.b + t.c <= t.a || 
        t.a + t.c <= t.b) {
        return false;
    }
    
    return true;
}

bool is_equilateral(triangle_t t) {
    if (!is_triangle(t)) {
        return false;
    }
    
    if (t.a == t.b && t.b == t.c) {
        return true;
    }
    
    return false;
}

bool is_isosceles(triangle_t t) {
    if (!is_triangle(t)) {
        return false;
    }
    
    if (t.a == t.b || t.a == t.c || t.b == t.c) {
        return true;
    }
    
    return false;
}

bool is_scalene(triangle_t t) {
    if (!is_triangle(t)) {
        return false;
    }
    
    if (t.a != t.b && t.b != t.c && t.a != t.c) {
        return true;
    }
    
    return false;
}