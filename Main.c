#include "Methods.h"

void main() {
	int rows = getIntegerValue();
	int power = getIntegerValue();
	int** matrix = createMatrixRandom(rows);
	writeMatrix(matrix, rows);
	int** finalMatrix = initializeArrayOfSpecificSize(rows);
	finalMatrix = multiplyMatrixes(matrix, power, rows);
	writeMatrix(finalMatrix, rows);
}