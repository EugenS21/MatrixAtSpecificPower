#include <stdio.h> 
#include <stdlib.h> 
#include <time.h>

#define MAX_NUMBER_LIMIT 20

int getIntegerValue();

int** initializeArrayOfSpecificSize(int rowsNumber);

int** createMatrix(int rowsNumber);

int** createMatrixRandom(int rowsNumber);

int** multiply(int** leftMatrix, int** rightMatrix, int rowsNumber);

int** multiplyMatrixes(int** matrix, int power, int rowsNumber);

void readMatrixFromFile();

void writeMatrix(int** matrix, int rowsNumber);