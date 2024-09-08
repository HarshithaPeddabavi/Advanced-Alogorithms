#include <iostream>
#include <sstream>
#include <limits>

using namespace std;

// Function to validate user input for integer values
bool validateInput(int& value) {
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Sorry, you have given wrong input. Can you re-try or to quit enter 'quit'." << endl;
        return false;
    }
    return true;
}

int main() {
    int rows, cols;

    // Input for number of rows
    cout << "Enter the number of rows: ";
    while (!validateInput(rows)) {}

    // Input for number of columns
    cout << "Enter the number of columns: ";
    while (!validateInput(cols)) {}

    // Initialize the matrix with zeros
    int matrix[rows][cols] = {0};

    // Input matrix elements
    cout << "Enter the elements of the matrix row by row (use spaces between numbers): " << endl;

    for (int i = 0; i < rows; i++) {
        string inputLine;
        bool validInput = false;
        while (!validInput) {
            validInput = true;
            getline(cin >> ws, inputLine);

            stringstream ss(inputLine);
            int element;
            for (int j = 0; j < cols; j++) {
                if (!(ss >> element)) {
                    cout << "Sorry, you have given wrong input. Can you re-try or to quit enter 'quit'." << endl;
                    validInput = false;
                    break;
                }
                matrix[i][j] = element;
            }
        }
    }

    // Convert the matrix to its sparse representation
    int nonZeroCount = 0;
    int compactMatrix[3][rows * cols];  // Maximum size assuming no zeros

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] != 0) {
                compactMatrix[0][nonZeroCount] = i;
                compactMatrix[1][nonZeroCount] = j;
                compactMatrix[2][nonZeroCount] = matrix[i][j];
                nonZeroCount++;
            }
        }
    }

    // Display the sparse matrix representation
    cout << "Representation of sparse matrix is: " << endl;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < nonZeroCount; j++) {
            cout << compactMatrix[i][j] << " ";
        }
        cout << endl;
    }

    // Count the number of zeros in the matrix
    int zeroCount = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] == 0) {
                zeroCount++;
            }
        }
    }

    // Determine if the matrix is sparse
    cout << "Number of zeros = " << zeroCount << endl;
    if (zeroCount > (rows * cols) / 2) {
        cout << "The matrix is a sparse matrix." << endl;
    } else {
        cout << "The matrix is not a sparse matrix." << endl;
    }

    return 0;
}
