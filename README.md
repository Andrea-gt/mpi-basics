# MPI Basics 📄
## Overview
This repository contains a simple demonstration of bidirectional communication between processes using the **Message Passing Interface (MPI)**. The program allows multiple processes to communicate with each other, where non-root processes send messages to the root process, and the root process acknowledges each message. This showcases basic MPI functionalities such as **point-to-point communication** using `MPI_Send` and `MPI_Recv`.

## Features
- **Multi-process communication**: Non-root processes (rank > 0) send messages to the root process (rank 0).
- **Acknowledgment system**: The root process sends a response back to each non-root process.
- Demonstrates essential MPI operations:
  - `MPI_Init()`: Initializes the MPI environment.
  - `MPI_Comm_size()`: Retrieves the total number of processes in the communicator.
  - `MPI_Comm_rank()`: Retrieves the rank (ID) of each process.
  - `MPI_Send()` and `MPI_Recv()`: Point-to-point communication between processes.
  - `MPI_Finalize()`: Gracefully finalizes the MPI environment.

## Example Workflow

### Files
- `mpi_hello_3.c`: The main C program demonstrating process communication with MPI.
- `mpi_hello.c` and `mpi_hello_2.c`: Simpler versions showing one-way communication with MPI.

### Compilation
To compile the C programs in this repository, you must use an MPI compiler such as `mpicc`. Below is the example for compiling `mpi_hello_3.c`:

```bash
mpicc -o mpi_hello_3 mpi_hello_3.c
```

### Execution
You can run the compiled program across multiple processes using the `mpirun` or `mpiexec` command. In this case, we'll run the program with 4 processes:

```bash
mpirun -np 4 ./mpi_hello_3
```

## Prerequisites

### Tools
- **MPI library**: Install MPI on your machine. You can install `OpenMPI` using:
  - **Ubuntu**: `sudo apt-get install libopenmpi-dev openmpi-bin`
  - **CentOS**: `sudo yum install openmpi openmpi-devel`
  - **macOS**: `brew install open-mpi`

### Compilation
To compile the program, you will need an MPI-compatible C compiler such as `mpicc` (part of OpenMPI).

```bash
sudo apt install mpich
```

## Example Files

### `mpi_hello.c`
The simplest version of the "Hello World" MPI program, where each process prints its rank and the total number of processes.

### `mpi_hello_2.c`
An extension of `mpi_hello.c` where non-root processes send messages to the root process, but without receiving any acknowledgment back.

### `mpi_hello_3.c`
The final version that implements **bidirectional communication**, where the root process not only receives messages from non-root processes but also sends back acknowledgment messages.

## Resources
- [MPI Documentation](https://www.mpi-forum.org/docs/): The official documentation for the MPI standard.
- [MPI Programming Tutorial](https://curc.readthedocs.io/en/latest/programming/MPI-C.html): A comprehensive guide to MPI programming in C.

## Author
- **Ramirez R. Andrea**  
  - Created the code for learning purposes in September 2024.
