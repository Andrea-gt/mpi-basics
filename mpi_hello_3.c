/**
 * @file mpi_hello_3.c
 * @brief A simple MPI program demonstrating bidirectional communication between processes.
 * 
 * This program illustrates two-way communication in an MPI environment. All non-root processes (i.e., processes 
 * with rank greater than 0) send a message to the root process (rank 0), and the root process sends an acknowledgment 
 * back to each sender. This demonstrates both message sending and receiving for each process in the MPI communicator.
 * 
 * @details
 * The program follows these steps:
 * 1. Initializes the MPI environment using `MPI_Init`.
 * 2. Determines the total number of processes in the MPI communicator using `MPI_Comm_size`.
 * 3. Determines the rank (ID) of each process using `MPI_Comm_rank`.
 * 4. Each non-root process (rank > 0):
 *    - Sends a message to the root process (rank 0) using `MPI_Send`.
 *    - Waits for a response from the root process using `MPI_Recv`.
 * 5. The root process (rank 0):
 *    - Receives messages from all other processes using `MPI_Recv`.
 *    - Sends an acknowledgment back to each process using `MPI_Send`.
 * 6. Finalizes the MPI environment using `MPI_Finalize`.
 * 
 * @note 
 * - This code should be compiled with an MPI compiler (e.g., `mpicc`).
 * - To run the program across multiple processes, use the `mpirun` or `mpiexec` command.
 * 
 * Example usage:
 * @code
 * mpicc -o mpi_hello_3 mpi_hello_3.c
 * mpirun -np 4 ./mpi_hello_3
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
    char MESSAGE_ITEM[100];
    char RESPONSE[100];  // Buffer for process 0's response

    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    // Get the total number of processes in the MPI communicator
    MPI_Comm_size(MPI_COMM_WORLD, &CLUSTER_SIZE);

    // Get the rank of the current process
    MPI_Comm_rank(MPI_COMM_WORLD, &PROCESS_RANK);

    if (PROCESS_RANK != 0) {
        // Non-root processes prepare a message and send it to the root process
        sprintf(MESSAGE_ITEM, "Hello from process %d of %d!", PROCESS_RANK, CLUSTER_SIZE);
        printf("(Process %d) Sending message: \"%s\" to process 0.\n", PROCESS_RANK, MESSAGE_ITEM);
        MPI_Send(MESSAGE_ITEM, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD);

        // Non-root processes wait for a response from the root process
        MPI_Recv(RESPONSE, 100, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("(Process %d) Received response: \"%s\" from process 0.\n", PROCESS_RANK, RESPONSE);

    } else {
        // Root process (rank 0) receives messages from all other processes
        for (int i = 1; i < CLUSTER_SIZE; i++) {
            MPI_Recv(MESSAGE_ITEM, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            printf("(Process 0) Received message: \"%s\" from process %d\n", MESSAGE_ITEM, i);

            // Root process prepares a response and sends it back
            sprintf(RESPONSE, "Acknowledgment from process 0 to process %d", i);
            printf("(Process 0) Sending message: \"%s\" to process %d\n", RESPONSE, i);
            MPI_Send(RESPONSE, 100, MPI_CHAR, i, 0, MPI_COMM_WORLD);
        }
    }

    // Finalize the MPI environment to gracefully exit
    MPI_Finalize();

    return 0;
}
