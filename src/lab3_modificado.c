#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int XDIM = 10000;
int YDIM = 10000;
FILE *outFile;

// We return the pointer
double **alloc_matrix(void) /* Allocate the array */
{
    /* Check if allocation succeeded. (check for NULL pointer) */
    int i, j, k;
    double **array;
    array = malloc((size_t)(XDIM * (int)sizeof(double *)));
    for (i = 0; i < XDIM; i++){
        array[i] = malloc((size_t)(YDIM * (int)sizeof(double)));
    }

    for (j = 0; j < XDIM - 1; j++){
        for (k = 0; k < YDIM - 1; k++){
            memset(&array[k][j], j, sizeof(double));
        }
    }
    return array;
}

void fill(double **arr)
{
    int i, j;
    srand((unsigned)25);
    for (i = 0; i < XDIM; i++)
        for (j = 0; j < YDIM; j++)
            arr[i][j] = (double)(rand() % 100);
}

void compute(double **arr, int kern[3][3])
{
    double tmp_sum[9];
    double accum;
    int i, j, k;
    for (i = 1; i < XDIM - 1; i++){
        for (j = 1; j < YDIM - 1; j++){
            accum = 0;
            for (k = 0; k < 3; k++){
                int y = j + (k - 1);
                tmp_sum[k]      = 2 * (2 * kern[0][k] * arr[i - 1][y]) / 1000 + 1;
                tmp_sum[k + 3]  = 2 * (2 * kern[1][k] * arr[i][y]) / 1000 + 1;
                tmp_sum[k + 6]  = 2 * (2 * kern[2][k] * arr[i + 1][y]) / 1000 + 1;

                accum += tmp_sum[k * 3] + tmp_sum[k * 3 + 1] + tmp_sum[k * 3 + 2];
            }
        arr[i][j] = accum;
        }
    }
}

void print(double **arr)
{
    int i, j;
    for (i = 0; i < XDIM - 1; i++)
        for (j = 0; j < YDIM - 1; j++)
            fprintf(outFile, "array[%d][%d] = %f\n", i, j, arr[i][j]);
}

int main(void)
{
    outFile = fopen("./bin/printsOrigin.txt", "w+");
    double **arr;
    int kern[3][3] = {{0, -1, 0}, {-1, 5, -1}, {0, -1, 0}};

    arr = alloc_matrix();
    fill(arr);
    compute(arr, kern);
    print(arr);
    fclose(outFile);

    return 0;
}