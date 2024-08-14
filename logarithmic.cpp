#include <iostream>
#include <vector>
#include <cmath>    // Includes the math library for mathematical functions like log
#include <iomanip>// Includes the iomanip library for controlling output format
using namespace std;

// Function to perform logarithmic regression
void performLogarithmicRegression(const vector<double>& x, const vector<double>& y, double& a, double& b) {
    int n = x.size(); // Gets the number of data points
    double sumXLog = 0.0, sumLogX = 0.0, sumY = 0.0, sumLogX2 = 0.0; // Initializes sums to 0

   // Loop through each data point to calculate sums needed for regression
    for (int i = 0; i < n; ++i) {
      double logX = log(x[i]);  // Calculates log(x) for the current data point
      sumXLog += logX * y[i];   // Accumulates sum of log(x) * y
      sumLogX += logX;          // Accumulates sum of log(x)
      sumY += y[i];              // Accumulates sum of y
      sumLogX2 += logX * logX;  // Accumulates sum of (log(x))^2
    }

    // Calculating the regression coefficients b and a using least squares formulas
    b = (n * sumXLog - sumLogX * sumY) / (n * sumLogX2 - sumLogX * sumLogX);
    a = (sumY - b * sumLogX) / n;
}

int main() {
    int n;
    double a, b;
    char choice;

    // Start of the do-while loop
    do {
        cout << "Enter the number of data points: ";
        cin >> n;   // Reads the number of data points from the us

        // Checks if there are fewer than 2 data points
        if (n < 2) { 
            cout << "You need at least 2 data points for regression." << endl;
            continue; // Skips to the next iteration of the loop
        }

        // Creates two vectors of size n to store x and y values
        vector<double> x(n), y(n);

         // Loop to get x and y values from the user
        cout << "Enter the data points (x and y):" << endl;
        for (int i = 0; i < n; ++i) {
            cout << "x[" << i + 1 << "] = ";
            cin >> x[i]; // Loop to get x and y values from the user
            cout << "y[" << i + 1 << "] = ";
            cin >> y[i]; // Reads the y value for the ith data point
        }

        // Calls the function to perform regression
        performLogarithmicRegression(x, y, a, b);

        // Sets the output format to fixed-point with 4 decimal places
        cout << fixed << setprecision(4);
        cout << "\nLogarithmic Regression Equation: y = " << a << " + " << b << " * log(x)" << endl;
        // Outputs the regression equation with calculated coefficients a and b

        cout << "Do you want to perform another regression? (y/n): ";
        cin >> choice;

    } while (choice == 'Y' || choice == 'y');

    cout << "Thank you for using the program!" << endl;

    return 0;
}
