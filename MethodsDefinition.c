#include "Methods.h"

int getIntegerValue() {
	int number;
	scanf("%d", &number);
	return number;
}

int** initializeArrayOfSpecificSize(int rowsNumber)
{
	int** matrix = (int**)malloc(rowsNumber * sizeof(int*));
	int i = 0;
	for (i = 0; i < rowsNumber; i++)
		matrix[i] = (int*)malloc(rowsNumber * sizeof(int));
	return matrix;
}

int** createMatrix(int rowsNumber) {
	int i = 0,
        j = 0;
	int** matrix = initializeArrayOfSpecificSize(rowsNumber);
	for (i = 0; i < rowsNumber; i++)
		for (j = 0; j < rowsNumber; j++) {
			printf("\n%d | %d = ", i, j);
			matrix[i][j] = getIntegerValue();
		}
	return matrix;
}

void createMatrixRandom(int rowsNumber) {
	int i = 0,
        j = 0;
	int** matrix = initializeArrayOfSpecificSize(rowsNumber);
	srand(time(NULL));
	for (i = 0; i < rowsNumber; i++)
		for (j = 0; j < rowsNumber; j++)
			matrix[i][j] = rand() % MAX_NUMBER_LIMIT;
    writeToFile(INPUT_DATA_FILENAME, matrix, rowsNumber);
}

int** multiply(int** leftMatrix, int** rightMatrix, int rowsNumber) {
	int i,
        j,
        k,
        sum = 0;
	int** finalMatrix = initializeArrayOfSpecificSize(rowsNumber);
	for (i = 0; i < rowsNumber; i++) {
		for (j = 0; j < rowsNumber; j++) {
			for (k = 0; k < rowsNumber; k++) {
				sum += (leftMatrix[i][k] * rightMatrix[k][j]);
			};
			finalMatrix[i][j] = sum;
			sum = 0;
		}
	}
	return finalMatrix;
}

int** multiplyMatrixes(int** startingMatrix, int power, int rowsNumber) {
	int i = 0,
        j = 0,
        k = 0,
        currentPower = 0,
        sum = 0;
	int** tempMatrix = initializeArrayOfSpecificSize(rowsNumber);
	tempMatrix = startingMatrix;
	while (++currentPower < power) {
		tempMatrix = multiply(startingMatrix, tempMatrix, rowsNumber);
	}
	return tempMatrix;
}

int** readMatrixFromFile(int rowsNumber) {
    FILE* filePointer = fopen(INPUT_DATA_FILENAME, "r");
    int i = 0,
        j = 0;
    int** matrix = initializeArrayOfSpecificSize(rowsNumber);

    for(i=0; i<rowsNumber; i++)
        for(j=0; j<rowsNumber; j++)
            fscanf(filePointer, "%d\t", &matrix[i][j]);

    fclose(filePointer);
    return matrix;
}

void writeMatrix(int** matrix, int rowsNumber) {
	int i = 0,
        j = 0;
	for (i = 0; i < rowsNumber; i++) {
		for (j = 0; j < rowsNumber; j++)
			printf("%d\t", matrix[i][j]);
		printf("\n\n");
	}
}

void writeToFile(const char* destinationFile, int** matrix, int rowsNumber){
    FILE *filePointer = fopen(destinationFile,"w");
    int i = 0,
        j = 0;
    for (i = 0; i < rowsNumber; i++){
		for (j = 0; j < rowsNumber; j++) {
			fprintf(filePointer,"%d\t", matrix[i][j]);
		}
		fprintf(filePointer,"\n");
    }
    fclose(filePointer);
}
