#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

// Function to compute the impulse response h(n)
double impulseResponse(int n) {
    // The impulse response is h(n) = (0.5)^n for n >= 0, otherwise 0
    return (n >= 0) ? pow(0.5, n) : 0;
}

// Function to compute the system output y(n) using convolution
vector<double> computeOutput(const vector<int>& x, int N) {
    vector<double> y(N, 0); // Initialize output vector y with N zeros

    // Iterate over each element of the input sequence x
    for (int k = 0; k < x.size(); k++) {
        // Compute the convolution sum for each n
        for (int n = 0; n < N; n++) {
            y[n] += x[k] * impulseResponse(n - k);
        }
    }
    return y; // Return the computed output sequence
}

int main() {
    // Define the input sequence x[n]
    vector<int> x = {3, 2, -1};

    // Define the length of the output sequence
    int N = 10;

    // Compute the output sequence y(n) using convolution
    vector<double> y = computeOutput(x, N);

    // Display the output sequence
    cout << "System Output y(n): ";
    for (double val : y) {
        cout << val << " ";
    }
    cout << endl;

    return 0; // Exit the program
}
