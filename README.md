# Matrix Multiplication using OpenMP

This repository contains C++ code for matrix multiplication using OpenMP and Python code to generate graphs analyzing the performance metrics.

## Matrix Multiplication Code (matrix_multiplication.cpp)

The `multiplication.cpp` file contains the C++ code for matrix multiplication using OpenMP. It performs matrix multiplication on square matrices of dimensions ranging from 100x100 to 1000x1000.

## Python Code for Generating Graphs (generate_graphs.py)

The `plotting.ipynb` file contains Python code to calculate and generate two types of graphs:
1. Speedup vs. N: For different values of N, it plots the speedup with respect to the number of processing elements.
2. Speedup vs. Number of Processors: For different numbers of processing elements, it plots the speedup with respect to N.

## Usage

1. Compile and run the C++ code `multiplication.cpp`.
2. Execute the Python script `plotting.ipynb` to generate performance analysis graphs.

Ensure you have the necessary dependencies installed to run both C++ and Python code.

## Performance Metrics

The performance metrics analyzed include speedup and parallel efficiency for matrix multiplication using OpenMP.

## Results

The results of the performance analysis are included in the generated graphs.

