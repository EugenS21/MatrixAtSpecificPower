#include <mpi/mpi.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_NUMBER_LIMIT 100
#define INPUT_DATA_FILENAME "dataToProcess.sav"
#define OUTPUT_DATA_FILENAME "outputData.txt"

int getIntegerValue();

int** initializeArrayOfSpecificSize(int rowsNumber);

int** createMatrix(int rowsNumber);

void createMatrixRandom(int rowsNumber);

int** multiply(int** leftMatrix, int** rightMatrix, int rowsNumber);

int** multiplyMatrixes(int** matrix, int power, int rowsNumber);

int** readMatrixFromFile();

void writeMatrix(int** matrix, int rowsNumber);

void writeToFile(const char* destination, int** matrix, int rowsNumber);
