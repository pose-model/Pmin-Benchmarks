#include <mpi.h>

int main(int argc, char *argv[]) {
    MPI_Init(&argc, &argv);

    __asm__ volatile ("nop: jmp nop");

    MPI_Finalize();
}


