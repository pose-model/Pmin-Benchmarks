#include <mpi.h>
#include <stdlib.h>

/* Single rank sits in a nop loop,
 * all other ranks sit waiting on a barrier.
 */
int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    int rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);

    if (rank == 0) {
        __asm__ volatile ("nop: jmp nop");
    }

    MPI_Barrier(MPI_COMM_WORLD);
    MPI_Finalize();
}


