#include <stdio.h>
#define MAX 100

struct Element {
    int row;
    int col;
    int value;
};

void convertToTriplet(int rows, int cols, int mat[rows][cols], struct Element triplet[MAX]) {
    int k = 1;
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            if (mat[i][j] != 0) {
                triplet[k].row = i;
                triplet[k].col = j;
                triplet[k].value = mat[i][j];
                k++;
            }

    triplet[0].row = rows;
    triplet[0].col = cols;
    triplet[0].value = k - 1;
}

void print(struct Element a[]) {
    printf("\nRow Col Value\n");
    for (int i = 0; i <= a[0].value; i++)
        printf("%3d %4d %5d\n", a[i].row, a[i].col, a[i].value);
}

void transpose(struct Element a[], struct Element b[]) {
    int i, j, k = 1;
    int rows = a[0].row;
    int cols = a[0].col;
    int num = a[0].value;

    b[0].row = cols;
    b[0].col = rows;
    b[0].value = num;

    for (i = 0; i < cols; i++) {
        for (j = 1; j <= num; j++) {
            if (a[j].col == i) {
                b[k].row = a[j].col;
                b[k].col = a[j].row;
                b[k].value = a[j].value;
                k++;
            }
        }
    }
}

void add(struct Element a[], struct Element b[], struct Element result[]) {
    if (a[0].row != b[0].row || a[0].col != b[0].col) {
        printf("The given matrices can't be added.\n");
        result[0].value = 0;
        return;
    }

    int i = 1, j = 1, k = 1;
    while (i <= a[0].value && j <= b[0].value) {
        if (a[i].row == b[j].row && a[i].col == b[j].col) {
            result[k].row = a[i].row;
            result[k].col = a[i].col;
            result[k].value = a[i].value + b[j].value;
            i++, j++, k++;
        } else if ((a[i].row < b[j].row) || 
                  (a[i].row == b[j].row && a[i].col < b[j].col)) {
            result[k++] = a[i++];
        } else {
            result[k++] = b[j++];
        }
    }

    while (i <= a[0].value) result[k++] = a[i++];
    while (j <= b[0].value) result[k++] = b[j++];

    result[0].row = a[0].row;
    result[0].col = a[0].col;
    result[0].value = k - 1;
}

int main() {
    int r1, c1, r2, c2;
    int mat1[MAX][MAX], mat2[MAX][MAX];
    struct Element a[MAX], b[MAX], result[MAX], transposed[MAX];

    // Input first matrix
    printf("Enter rows and columns of first matrix: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter elements of first matrix:\n");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);

    // Input second matrix
    printf("\nEnter rows and columns of second matrix: ");
    scanf("%d %d", &r2, &c2);
    printf("Enter elements of second matrix:\n");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);

    // Convert to sparse triplet
    convertToTriplet(r1, c1, mat1, a);
    convertToTriplet(r2, c2, mat2, b);

    printf("\nSparse Triplet of First Matrix:");
    print(a);

    printf("\nSparse Triplet of Second Matrix:");
    print(b);

    // Add the sparse matrices
    add(a, b, result);
    if (result[0].value > 0) {
        printf("\nResult of Addition (Sparse):");
        print(result);
    }

    // Transpose first matrix
    transpose(a, transposed);
    printf("\nTranspose of First Matrix (Sparse):");
    print(transposed);

    return 0;
}
