#include <mpi.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {
int rank, size, i;
int *array = NULL;
int array_size = 60003;
int local_sum = 0;
int global_sum = 0;
int *local_array;
int local_size;

MPI_Init(&argc, &argv);
MPI_Comm_rank(MPI_COMM_WORLD, &rank);
MPI_Comm_size(MPI_COMM_WORLD, &size);

local_size = array_size / size;

if (rank == 0) {
array = (int*)malloc(array_size * sizeof(int));
for(i = 0; i < array_size; i++) {
array[i] = i;
}
}
local_array = (int*)malloc(local_size * sizeof(int));

MPI_Scatter(array, local_size, MPI_INT, local_array, local_size, MPI_INT, 0, MPI_COMM_WORLD);
double start_time = MPI_Wtime();

for(i = 0; i < local_size; i++) {
local_sum += local_array[i];
}

MPI_Reduce(&local_sum, &global_sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);

double end_time = MPI_Wtime();
double elapsed_time = end_time - start_time;
if(rank == 0) {
float average = (float)global_sum / array_size;
printf("\nRuntime: %.6f seconds\n", elapsed_time);
printf("Average of the array: %.2f\n\n", average);
free(array);
}
free(local_array);
MPI_Finalize();
return 0;
}
