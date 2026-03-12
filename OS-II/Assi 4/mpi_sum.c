#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[])
{
    int rank, size;
    int numbers[N];
    int local_sum = 0, total_sum = 0;
    int chunk;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    chunk = N / size;

    if(rank == 0)
    {
        srand(time(NULL));
        for(int i=0;i<N;i++)
            numbers[i] = rand()%100;
    }

    int local_numbers[chunk];

    MPI_Scatter(numbers, chunk, MPI_INT, local_numbers, chunk, MPI_INT, 0, MPI_COMM_WORLD);

    for(int i=0;i<chunk;i++)
        local_sum += local_numbers[i];

    MPI_Reduce(&local_sum, &total_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

    if(rank == 0)
        printf("Total Sum = %d\n", total_sum);

    MPI_Finalize();
    return 0;
}
