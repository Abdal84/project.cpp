#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

using namespace std;

const double PI = 3.14159265358979323846;

// Function to compute the Fast Fourier Transform (FFT)
void FFT(vector<complex<double>>& a) {
    int N = a.size();
    if (N <= 1) return;
    
    // Split even and odd indices
    vector<complex<double>> even(N / 2), odd(N / 2);
    for (int i = 0; i < N / 2; i++) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }
    
    // Recursive FFT calls
    FFT(even);
    FFT(odd);
    
    // Combine results
    for (int k = 0; k < N / 2; k++) {
        complex<double> t = polar(1.0, -2 * PI * k / N) * odd[k];
        a[k] = even[k] + t;
        a[k + N / 2] = even[k] - t;
    }
}

int main() {
    // Example input signal (must be power of 2 in length)
    vector<complex<double>> x = {1, 2, 3, 4, 5, 6, 7, 8};
    
    // Compute FFT
    FFT(x);
    
    // Display FFT result
    cout << "FFT Result:" << endl;
    for (size_t k = 0; k < x.size(); k++) {
        cout << "X[" << k << "] = " << x[k] << endl;
    }
    
    return 0;
}
