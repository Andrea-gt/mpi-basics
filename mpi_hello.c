/**
 * @file mpi_hello.c
 * @brief A simple MPI program that demonstrates basic usage of MPI functions.
 * 
 * This program initializes an MPI environment and prints a message from each process.
 * Each process reports its rank (ID) and the total number of processes in the MPI communicator.
 * It serves as an introduction to distributed programming using the Message Passing Interface (MPI).
 * 
 * @details
 * The program performs the following steps:
 * 1. Initializes the MPI environment using `MPI_Init`.
 * 2. Determines the size of the cluster (i.e., the total number of processes) using `MPI_Comm_size`.
 * 3. Determines the rank (ID) of each process in the communicator using `MPI_Comm_rank`.
 * 4. Each process prints a message that includes its rank and the total number of processes.
 * 5. Finalizes the MPI environment using `MPI_Finalize`, ensuring all processes exit gracefully.
 * 
 * This program can be used to test basic MPI installations and to observe parallel execution
 * across multiple processes.
 * 
 * @note 
 * - This code should be compiled with an MPI compiler (e.g., `mpicc`).
 * - To run the program across multiple processes, use the `mpirun` or `mpiexec` command.
 * 
 * Example usage:
 * @code
 * mpicc -o mpi_hello mpi_hello.c
 * mpirun -np 4 ./mpi_hello
 * @endcode
 * 
 * @authors
 * - Ramirez R. Andrea
 * 
 * @date 
 * - September 2024
 * 
 * @see
 * - Official MPI documentation: https://www.mpi-forum.org/docs/
 * - Reference for building this code: https://curc.readthedocs.io/en/latest/programming/MPI-C.html
 * 
 */

#include <mpi.h>
#include <stdio.h>

int main(int argc, char** argv) {
    // Variables to store the rank of the process and the total number of processes
    int PROCESS_RANK, CLUSTER_SIZE;

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the total number of processes in the MPI communicator
    MPI_Comm_size(MPI_COMM_WORLD, &CLUSTER_SIZE);

    // Get the rank of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &PROCESS_RANK);

    // Print a message from each process, showing its rank and the total number of processes
    printf("Hello World from process %d of %d\n", PROCESS_RANK, CLUSTER_SIZE);

    // Finalize the MPI environment to gracefully exit
    MPI_Finalize();

    return 0;
}
