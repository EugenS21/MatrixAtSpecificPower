#include "Methods.h"

void main(int argc, char **argv) {
	int rows = getIntegerValue();
	int power = getIntegerValue();
	createMatrixRandom(rows);
	int** matrix = readMatrixFromFile(rows);
	writeToFile(OUTPUT_DATA_FILENAME,multiplyMatrixes(matrix, power, rows), rows);
}
