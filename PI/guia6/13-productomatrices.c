int
filaPorCol(unsigned int dim, const int fila[], const int mat2[][dim], int col) {
	int i;
	int total = 0;

	for(i = 0; i < dim; i++)
		total += fila[i]* mat2[i][col];    //Hace la suma de los productos de fila[i] por la fila i de la columna constante de la segunda matriz
	return total;
}

void 
producto(unsigned int dim, const int m1[][dim], const int m2[][dim], int m3[][dim]) {
	int i,j;

	for (i = 0; i < dim; i++)
		for (j = 0; j < dim; j++)
			m3[i][j] = filaPorCol(dim, m1[i], m2, j);   // le paso la fila de la primera matriz par que multiplique por la columna de la segunda

	return;
}