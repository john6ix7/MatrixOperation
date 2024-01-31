#include <iostream>

using namespace std;

class Matrix {
private:
    int** data;
    int rows;
    int cols;
public:
    //default constructor
    Matrix(){
    }

    // Constructor
    Matrix(int r, int c) {
        // Initialize attributes and allocate memory for the matrix data
        rows = r;
        cols = c;
        data = new int*[rows];
        for (int i = 0; i < rows; i++) {
            data[i] = new int[cols];
        }
    }

    // Destructor
    ~Matrix() {
        for (int i = 0; i < rows; i++) {
            delete[] data[i];// Deallocate memory for each row
        }
        delete[] data;// Deallocate the array of row pointers
        // Deallocate memory for the matrix data
    }

    // Method to get value at row and col
    int get(int row, int col) {
        // Return the value at the given row and column indices
        return data[row][col];
    }

    // Method to set value at row and col
    void set(int row, int col, int value) { 
        data[row][col] = value;
    // Set the value at the given row and column indices
    }

    // Method to add two matrices
    Matrix add(const Matrix &other) { //takes another Matrix object (other) as a parameter and returns a new Matrix object that represents the sum of the current matrix and the other matrix

        Matrix result(rows, cols); // store the sum of the two matrices

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                result.data[i][j] = data[i][j] + other.data[i][j]; // result matrix = matrixA + matrixB
            }
        }
        return result;
    }

    // Method to multiply two matrices
    Matrix multiply(const Matrix &other) {//takes another Matrix object (other) as a parameter and returns a new Matrix object that represents the sum of the current matrix and the other matrix

        Matrix result(rows, cols); // store the sum of the two matrices

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                int sum = 0;
                for (int k = 0; k < cols; k++)
                {
                    sum += data[i][k] * other.data[k][j];// multiply a matrix by another matrix  with dot product 
                }
                result.data[i][j] = sum;
            }
        }
        return result;
    }

    // Method to display the matrix
    void display() {
         for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                cout << data[i][j] << " ";
            }
        cout << endl;
        // Display the matrix elements
        }
    }
};
int main() {
    // Input dimensions for Matrix A
    int rowA, colA, elementA;

    cout << "Enter dimensions of matrix A(rows, cols): " << endl;
    cin >> rowA;
    cin >> colA;
    // Create Matrix A with the given dimension
    Matrix matrixA(rowA,colA);

    // Input matrix elements for Matrix A
    cout << "Enter matrix elements for matrix A: " << endl;
    for (int i = 0; i < rowA; i++) {
        for (int j = 0; j < colA; j++) {
            cout << "Element(" << i + 1 << "," << j + 1 << "): ";
            cin >> elementA;
            matrixA.set(i,j,elementA);
        }
    }

    int rowB, colB, elementB;
    // Input dimensions for Matrix B

    cout << "Enter dimensions of matrix B(rows, cols): " << endl;
    cin >> rowB;
    cin >> colB;

    // Create Matrix B with the given dimensions
    Matrix matrixB(rowB,colB);


    // Input matrix elements for Matrix B
    cout << "Enter matrix elements for matrix B: " << endl;
    for (int i = 0; i < rowB; i++) {
        for (int j = 0; j < colB; j++) {
            cout << "Element(" << i + 1 << "," << j + 1 << "): ";
            cin >> elementB;
            matrixB.set(i,j,elementB);
        }
    }

    // Display Matrix A
    cout << "Matrix A: " << endl;
    matrixA.display();

    // Display Matrix B
    cout << "Matrix B: " << endl;
    matrixB.display();

    // Perform matrix addition and display the result
    Matrix resultAdd = matrixA.add(matrixB);
    cout << "Matrix A + Matrix B: " << endl;
    resultAdd.display();

    // Perform matrix multiplication and display the result

    Matrix resultMultiply = matrixA.multiply(matrixB);
    cout << "Matrix A * Matrix B: " << endl;
    resultMultiply.display();

    cout << "Hello";
    cout << "This is a branch test";

    return 0;
}
