#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Function to compute the Discrete Fourier Transform (DFT)
vector<complex<double>> DFT(const vector<complex<double>>& x) {
    int N = x.size();
    vector<complex<double>> X(N);
    
    for (int k = 0; k < N; k++) {
        complex<double> sum(0.0, 0.0);
        for (int n = 0; n < N; n++) {
            double angle = -2.0 * PI * k * n / N;
            sum += x[n] * polar(1.0, angle);
        }
        X[k] = sum;
    }
    return X;
}

int main() {
    // Input signal (time domain)
    vector<complex<double>> x = {1, 2, 3, 4};
    
    // Compute DFT
    vector<complex<double>> X = DFT(x);
    
    // Display result
    cout << "DFT Result:" << endl;
    for (size_t k = 0; k < X.size(); k++) {
        cout << "X[" << k << "] = " << X[k] << endl;
    }
    
    return 0;
}
