#include <iostream>
#include <omp.h>

using namespace std;

void matrixMultiplication(int** A, int** B, int** C, int size) {
    #pragma omp parallel for collapse(2)
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            C[i][j] = 0;
            for (int k = 0; k < size; k++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int main() {
    int num_processors;
    int dimensions[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000};
    int num_dimensions = sizeof(dimensions) / sizeof(dimensions[0]);

    cout << "Enter the number of processors (1 to 10): ";
    cin >> num_processors;

    if (num_processors < 1 || num_processors > 10) {
        cout << "Invalid number of processors. Please enter a number between 1 and 10." << endl;
        return 1;
    }

    cout << "Dimensions\tSpeedup\tEfficiency" << endl;

    for (int dim_index = 0; dim_index < num_dimensions; dim_index++) {
        int size = dimensions[dim_index];

        int** A = new int*[size];
        int** B = new int*[size];
        int** C = new int*[size];

        for (int i = 0; i < size; i++) {
            A[i] = new int[size];
            B[i] = new int[size];
            C[i] = new int[size];

            for (int j = 0; j < size; j++) {
                A[i][j] = 1; // Fill with arbitrary values
                B[i][j] = 1;
            }
        }

        double start_time = omp_get_wtime();
        matrixMultiplication(A, B, C, size);
        double end_time = omp_get_wtime();
        double serial_time = end_time - start_time;

        start_time = omp_get_wtime();
        omp_set_num_threads(num_processors);
        matrixMultiplication(A, B, C, size);
        end_time = omp_get_wtime();
        double parallel_time = end_time - start_time;

        double speedup = serial_time / parallel_time;
        double efficiency = speedup / num_processors;

        cout << size << "\t\t" << speedup << "\t\t" << efficiency << endl;

        for (int i = 0; i < size; i++) {
            delete[] A[i];
            delete[] B[i];
            delete[] C[i];
        }
        delete[] A;
        delete[] B;
        delete[] C;
    }

    return 0;
}
