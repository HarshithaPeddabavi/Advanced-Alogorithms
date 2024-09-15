#include <iostream>
using namespace std;

// Structure to represent a node in the linked list
struct MatrixNode {
    int rowIndex;
    int colIndex;
    int dataValue;
    MatrixNode* nextNode;

    MatrixNode(int row, int col, int value)
        : rowIndex(row), colIndex(col), dataValue(value), nextNode(nullptr) {}
};

// Function to convert a matrix to a linked list representation
MatrixNode* convertMatrixToLinkedList(int** matrix, int rows, int cols) {
    MatrixNode* head = nullptr;
    MatrixNode* tail = nullptr;

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (matrix[i][j] != 0) {
                MatrixNode* newNode = new MatrixNode(i, j, matrix[i][j]);
                if (head == nullptr) {
                    head = newNode;
                    tail = newNode;
                } else {
                    tail->nextNode = newNode;
                    tail = newNode;
                }
            }
        }
    }
    return head;
}

// Function to print the linked list
void displayLinkedList(MatrixNode* head) {
    MatrixNode* current = head;
    while (current != nullptr) {
        cout << "(" << current->rowIndex << ", " << current->colIndex << ", " << current->dataValue << ") -> ";
        current = current->nextNode;
    }
    cout << "NULL" << endl;
}

int main() {
    int rows, cols;

    cout << "Enter the number of rows and columns for the matrix: ";
    cin >> rows >> cols;

    // Allocate memory for the matrix
    int** matrix = new int*[rows];
    for (int i = 0; i < rows; ++i) {
        matrix[i] = new int[cols];
    }

    cout << "Enter the elements of the sparse matrix (0 for empty cells): " << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> matrix[i][j];
        }
    }

    // Convert the matrix to a linked list
    MatrixNode* head = convertMatrixToLinkedList(matrix, rows, cols);
    cout << "Linked list representation of the sparse matrix: " << endl;
    displayLinkedList(head);

    // Free allocated memory
    for (int i = 0; i < rows; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;

    return 0;
}