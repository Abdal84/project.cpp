#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Function to compute the Inverse Discrete Fourier Transform (IDFT)
vector<complex<double>> IDFT(const vector<complex<double>>& X) {
    int N = X.size();
    vector<complex<double>> x(N);
    
    for (int n = 0; n < N; n++) {
        complex<double> sum(0.0, 0.0);
        for (int k = 0; k < N; k++) {
            double angle = 2.0 * PI * k * n / N;
            sum += X[k] * polar(1.0, angle);
        }
        x[n] = sum / static_cast<double>(N);
    }
    return x;
}

int main() {
    // Example frequency domain signal
    vector<complex<double>> X = {10.0, complex<double>(-2, 2), -2.0, complex<double>(-2, -2)};
    
    // Compute IDFT
    vector<complex<double>> x = IDFT(X);
    
    // Display IDFT result
    cout << "IDFT (Reconstructed Signal):" << endl;
    for (size_t n = 0; n < x.size(); n++) {
        cout << "x[" << n << "] = " << x[n] << endl;
    }
    
    return 0;
}
