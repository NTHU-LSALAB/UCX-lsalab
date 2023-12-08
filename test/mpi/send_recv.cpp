#include <mpi.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    // Get the number of processes and check if at least 2 processes are used
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    if (world_size < 2) {
        fprintf(stderr, "World size must be greater than 1 for %s\n", argv[0]);
        MPI_Abort(MPI_COMM_WORLD, 1);
    }

    // Get the rank of the process
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    const int MAX_STRING = 100;
    char message[MAX_STRING];

    if (world_rank == 0) {
        // If rank 0, send a message
        strcpy(message, "Hello from rank 0");
        MPI_Send(message, strlen(message) + 1, MPI_CHAR, 1, 0, MPI_COMM_WORLD);
        printf("Process 0 sent message '%s' to process 1\n", message);
    } else if (world_rank == 1) {
        // If rank 1, receive the message
        MPI_Recv(message, MAX_STRING, MPI_CHAR, 0, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        printf("Process 1 received message '%s' from process 0\n", message);
    }

    MPI_Finalize();
    return 0;
}

