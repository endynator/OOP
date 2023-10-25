#pragma once
#include <iostream>
#include <stdexcept>

struct side_values {
    uint16_t a;
    uint16_t b;
    uint16_t c;
};

class Calculate {
private:
    static int countCalculations;
    side_values side;
public:
    /*Calculate(uint16_t a, uint16_t b, uint16_t c) : side{ a, b, c }
    {
        if (!a + b > c &&
            !b + c > a &&
            !c + a > b) throw std::exception("Impossible shape.");
    }

    Calculate(uint16_t a, uint16_t b) : side{ a, b }
    {

    }*/

    static int getCountCalculations() {
        return countCalculations;
    }

    static double calculateTriangleArea(uint16_t a, uint16_t b, uint16_t c) {
        countCalculations++;
        double s = (a + b + c) / 2;
        return std::sqrt(s * (s - a) * (s - b) * (s - c));
    }

    static uint16_t calculateRectangleArea(uint16_t width, uint16_t height) {
        countCalculations++;
        return width * height;
    }

    static uint16_t calculateSquareArea(uint16_t side) {
        countCalculations++;
        return side * side;
    }

    static double calculateRhombusArea(uint16_t side1, uint16_t side2) {
        countCalculations++;

        double diagonal1 = side1 * sqrt(2);

        double diagonal2 = side2 * sqrt(2);

        double area = (diagonal1 * diagonal2) / 2;

        return area;
    }
};

void module2_IW1();

