
#include <iostream>
#include <vector>
#include <complex>
#include <cmath>

const double PI = 3.14159265358979323846;

using namespace std;
typedef complex<double> Complex;
typedef vector<Complex> CVector;

// Function to compute FFT or IFFT (direction: 1 for FFT, -1 for IFFT)
void FFT(CVector &a, int direction) {
    int n = a.size();
    if (n <= 1) return;

    // Divide the array into even and odd parts
    CVector even(n / 2), odd(n / 2);
    for (int i = 0; i < n / 2; ++i) {
        even[i] = a[i * 2];
        odd[i] = a[i * 2 + 1];
    }

    // Recursive FFT/IFFT
    FFT(even, direction);
    FFT(odd, direction);

    // Compute FFT/IFFT using the divide and conquer approach
    for (int k = 0; k < n / 2; ++k) {
        Complex t = polar(1.0, direction * -2 * PI * k / n) * odd[k];
        a[k] = even[k] + t;
        a[k + n / 2] = even[k] - t;
    }

    // If computing IFFT, normalize the results
    if (direction == -1) {
        for (int i = 0; i < n; ++i) {
            a[i] /= 2;
        }
    }
}

int main() {
    // Define the frequency-domain signal (example values)
    CVector X = {Complex(1, 0), Complex(0, -1), Complex(-1, 0), Complex(0, 1)};
    
    // Compute the IFFT
    FFT(X, -1); // -1 indicates IFFT

    // Display the time-domain signal
    cout << "Time-domain signal (IFFT result):\n";
    for (const auto &val : X) {
        cout << val.real() << " + " << val.imag() << "i\n";
    }

    return 0;
}
