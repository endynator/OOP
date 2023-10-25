#include "../headers/individual_work1.h"

int Calculate::countCalculations{ 0 };

void module2_IW1() {
    
    uint16_t a = 3, b = 4, c = 5;
    uint16_t width = 6, height = 8;
    uint16_t side = 4;
    uint16_t side1 = 5, side2 = 6;

    double triangleArea = Calculate::calculateTriangleArea(a, b, c);
    double rectangleArea = Calculate::calculateRectangleArea(width, height);
    double squareArea = Calculate::calculateSquareArea(side);
    double rhombusArea = Calculate::calculateRhombusArea(side1, side2);

    std::cout << "Triangle Area: " << triangleArea << std::endl;
    std::cout << "Rectangle Area: " << rectangleArea << std::endl;
    std::cout << "Square Area: " << squareArea << std::endl;
    std::cout << "Rhombus Area: " << rhombusArea << std::endl;

    std::cout << "Number of calculations: " << Calculate::getCountCalculations() << std::endl;
}