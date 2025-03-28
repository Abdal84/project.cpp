#include <iostream>
#include <vector>

using namespace std;

// Function to apply a Low-Pass Filter (LPF) using a simple moving average
vector<double> lowPassFilter(const vector<double>& input, int filterSize) {
    vector<double> output(input.size(), 0.0);
    
    // Compute the filter kernel (moving average weights)
    vector<double> h(filterSize, 1.0 / filterSize);

    // Convolution process
    for (size_t n = 0; n < input.size(); n++) {
        for (size_t k = 0; k < filterSize; k++) {
            if (n >= k) {
                output[n] += input[n - k] * h[k];
            }
        }
    }

    return output;
}

int main() {
    // Sample input signal (noisy sine wave, for example)
    vector<double> input = {3, 5, 6, 8, 10, 12, 15, 17, 16, 14, 12, 10, 8, 5, 3};

    // Define LPF size (number of points in moving average)
    int filterSize = 3;

    // Apply the Low-Pass Filter
    vector<double> output = lowPassFilter(input, filterSize);

    // Display the filtered output
    cout << "Filtered Signal: ";
    for (double val : output) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
