#include <iostream>
#include <cmath>

bool isStable(double a) {
    return std::abs(a) < 1.0;
}

void printStabilityCheck(double a) {
    std::cout << "Analyzing system with impulse response h[n] = a^n u[n]\n";
    std::cout << "Given a = " << a << std::endl;

    if (isStable(a)) {
        std::cout << " The system is STABLE. (|a| < 1 ⇒ ROC includes unit circle)\n";
    } else {
        std::cout << " The system is UNSTABLE. (|a| >= 1 ⇒ ROC does not include unit circle)\n";
    }
}

int main() {
    double a;

    std::cout << "Enter value of 'a' for h[n] = a^n u[n]: ";
    std::cin >> a;

    printStabilityCheck(a);

    return 0;
}
