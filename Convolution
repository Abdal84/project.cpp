#include <iostream>
#include <vector>

using namespace std;

// Function to perform linear convolution
vector<double> convolution(const vector<double>& x, const vector<double>& h) {
    int n = x.size();
    int m = h.size();
    int conv_size = n + m - 1;
    vector<double> y(conv_size, 0.0);
    
    // Perform convolution
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            y[i + j] += x[i] * h[j];
        }
    }
    return y;
}

int main() {
    // Input signal
    vector<double> x = {1, 2, 3, 4};
    
    // Impulse response
    vector<double> h = {1, -1, 2};
    
    // Perform convolution
    vector<double> result = convolution(x, h);
    
    // Display result
    cout << "Convolution result: ";
    for (double val : result) {
        cout << val << " ";
    }
    cout << endl;
    
    return 0;
}
