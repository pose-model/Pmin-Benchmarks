MPICC=mpicc
MPICFLAGS=-O3 -xHost

CC=icc
OMPFLAGS=-O3 -xHost -qopenmp

all:
	$(MPICC) $(MPICFLAGS) -o mpi_parallel_test.x mpi_parallel_test.c
	$(MPICC) $(MPICFLAGS) -o mpi_barrier_test.x mpi_barrier_test.c
	$(CC) $(OMPFLAGS) -o omp_critical_test.x omp_critical_test.c
	$(CC) $(OMPFLAGS) -o omp_parallel_test.x omp_parallel_test.c

nop:
	nasm -f elf64 nop.asm
	ld -s -o nop.x nop.o

clean:
	rm -f *.o *.x
