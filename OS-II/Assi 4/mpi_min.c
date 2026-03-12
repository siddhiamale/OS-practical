#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000

int main(int argc, char *argv[])
{
    int rank, size;
    int numbers[N];
    int local_min, global_min;
    int chunk;

    MPI_Init(&argc,&argv);

    MPI_Comm_rank(MPI_COMM_WORLD,&rank);
    MPI_Comm_size(MPI_COMM_WORLD,&size);

    chunk = N/size;

    if(rank == 0)
    {
        srand(time(NULL));
        for(int i=0;i<N;i++)
            numbers[i] = rand()%1000;
    }

    int local_numbers[chunk];

    MPI_Scatter(numbers,chunk,MPI_INT,local_numbers,chunk,MPI_INT,0,MPI_COMM_WORLD);

    local_min = local_numbers[0];

    for(int i=1;i<chunk;i++)
    {
        if(local_numbers[i] < local_min)
            local_min = local_numbers[i];
    }

    MPI_Reduce(&local_min,&global_min,1,MPI_INT,MPI_MIN,0,MPI_COMM_WORLD);

    if(rank == 0)
        printf("Minimum number = %d\n",global_min);

    MPI_Finalize();
    return 0;
}
