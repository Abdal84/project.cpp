#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

double impulseResponse(int n) {
    return (n >= 0) ? pow(0.5, n) : 0;
}

vector<double> computeOutput(const vector<int>& x, int N) {
    vector<double> y(N, 0);
    for (int k = 0; k < x.size(); k++) {
        for (int n = 0; n < N; n++) {
            y[n] += x[k] * impulseResponse(n - k);
        }
    }
    return y;
}

int main() {
    vector<int> x = {3, 2, -1};
    int N = 10;
    vector<double> y = computeOutput(x, N);

    cout << "System Output y(n): ";
    for (double val : y) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
