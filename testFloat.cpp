#include <iostream>
#include <cmath>
#include <vector>

bool areAlmostEqualAbs(float a, float b, float epsilon) {
    return std::fabs(a - b) < epsilon;
}

bool areAlmostEqualRel(float a, float b, float epsilon) {
    return std::fabs(a - b) < epsilon * std::max(std::fabs(a), std::fabs(b));
}

bool areAlmostEqualCombined(float a, float b, float epsilon) {
    return areAlmostEqualAbs(a, b, epsilon) || areAlmostEqualRel(a, b, epsilon);
}

void testComparisons(float x, float y, float epsilon) {
    std::cout << "Testing with x = " << x << ", y = " << y << ", epsilon = " << epsilon << std::endl;
    std::cout << "Absolute comparison: " << (areAlmostEqualAbs(x, y, epsilon) ? "Pass" : "Fail") << std::endl;
    std::cout << "Relative comparison: " << (areAlmostEqualRel(x, y, epsilon) ? "Pass" : "Fail") << std::endl;
    std::cout << "Combined comparison: " << (areAlmostEqualCombined(x, y, epsilon) ? "Pass" : "Fail") << std::endl;
}

int main() {
    float x, y, epsilon;

    std::cout << "Enter first number: ";
    std::cin >> x;
    std::cout << "Enter second number: ";
    std::cin >> y;
    std::cout << "Enter epsilon: ";
    std::cin >> epsilon;

    testComparisons(x, y, epsilon);
    return 0;
}
