#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
/* Matrice con 2 righe e 4 colonne (ogni elemento è un double)
rows = 2, cols = 4
    c 0      1      2     3
     -----------------------
r 0 |3.2	27		4     7
  1 |1		5.9		-2    8
    
    +---+---+---+---+---+---+---+---+
    |3.2| 27| 4 | 7 | 1 |5.9|-2 | 8 | per righe / row major
    +---+---+---+---+---+---+---+---+
   i  0   1   2   3   4   5   6   7
    
(r,c) -> i : i = r*cols + c

i -> (r,c) : r = i / cols
             c = i % cols
*/

typedef struct matrix {
	size_t rows, cols;
	double *data;
} matrix;

struct matrix *matrix_construct(struct matrix *m, size_t rows, size_t cols) {
	m->rows = rows;
	m->cols = cols;
	m->data = malloc(rows * cols * sizeof(double));
	return m;
}
struct matrix *matrix_destruct(struct matrix *m) {
	free(m->data);
	return m;
}
struct matrix *new_matrix(size_t rows, size_t cols) {
	return matrix_construct(malloc(sizeof(struct matrix)), rows, cols);
}
void delete_matrix(struct matrix *m) {
	free(matrix_destruct(m));
}

double matrix_get(const struct matrix *m, size_t r, size_t c) {
	return m->data[r * m->cols + c];
}
double matrix_set(struct matrix *m, size_t r, size_t c, double val) {
	return m->data[r * m->cols + c] = val;
}
void matrix_print(const struct matrix *m, FILE *f) {
	for (size_t r = 0; r < m->rows; ++r) {
		for (size_t c = 0; c < m->cols; ++c) {
			fprintf(f, "%.2f\t", matrix_get(m, r, c));
		}
		fprintf(f, "\n");
	}
}
bool matrix_sum_inplace(struct matrix* lhs, const struct matrix* rhs)
{
	if(lhs==NULL ||rhs==NULL|| lhs->rows!=rhs->rows||lhs->rows!=rhs->cols)
	{
		return false;
	}
		
	size_t rows = lhs->rows;
	size_t cols = lhs->cols;
	
	for (size_t r = 0;r < rows; ++r) 
	{
		for (size_t c = 0;c < cols; ++c)
		{
			lhs->data[r * cols + c] += rhs->data[r*cols+c];
		}
	}
	return  true;
}
/*

	Esegue l'operazione tra matrici
	ovvero somma gli elementi di posizione corrsipondente.
	Ritorna NULL e uno dei due puntatori è NULL o se le dimensioni non sono uguali.
	Altrimenti una nuova matrice allocata dinamicamente.

*/
struct matrix* matrix_sum(const struct matrix *a, const struct matrix *b) 
{
	if (a == NULL || b == NULL || a->rows != b->rows || a->cols != a->cols)
		return NULL;
	size_t rows = a->rows;
	size_t cols = b->cols;
	//IMPORTANTE: CREAZIONE MATRICI!!!!!!!!
	//ALLOCA MATRICE
	//CREA RIGHE E COLONNE
	//ALLOCA I DATI
	struct matrix *out= malloc(sizeof(struct matrix)); //out deve puntare ad una struct matrix quindi allochero la dimensione di una struct matrix
	
	out->rows = rows;
	out->cols = cols;
	out->data = malloc(sizeof(double)*rows*cols);

	for (int r = 0;r < rows; ++r) 
	{
		for (int c = 0; c < cols; ++c) 
		{
			out->data[r * cols + c] = a->data[r * cols + c] + b->data[r * cols + c];
		}
	}
	return out;
}
int main(void)
{
	struct matrix *m = new_matrix(2, 4);
	matrix_set(m, 0, 0, 3.2);
	matrix_set(m, 0, 1, 27);
	matrix_set(m, 0, 2, 4);
	matrix_set(m, 0, 3, 7);
	matrix_set(m, 1, 0, 1);
	matrix_set(m, 1, 1, 5.9);
	matrix_set(m, 1, 2, -2);
	matrix_set(m, 1, 3, 8);

	struct matrix b = {.rows=2,.cols=4,.data=NULL}; 
	/*
	definisco b, una variabile automatica che verrà distrutta automaticamente che contiene 2 righe
	*/

	double bdata[8] = {
	100,200,300,400,
	500,600,700,800
	};

	b.data = bdata;
	
	printf("Matrice m:\n");
	matrix_print(m, stdout);
	printf("Matrice b:\n");
	matrix_print(&b, stdout);

	/*
	SUM IN PLACE
	matrix_sum_inplace(m,&b);

	printf("Matrice m+b:\n");
	matrix_print(m, stdout);
	*/

	//SUM 
	struct matrix *ris=	matrix_sum(m,&b);
	printf("ris= m + b:\n");
	matrix_print(ris,stdout);

	
	delete_matrix(m);
	delete_matrix(ris);
	return EXIT_SUCCESS;
}