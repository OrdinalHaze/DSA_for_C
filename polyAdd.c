#include <stdio.h>

#define MAX 100


struct Term {
    int coeff;
    int expo;
};


void addPoly(struct Term a[], int m, struct Term b[], int n, struct Term result[], int *resSize) {
    int i = 0, j = 0, k = 0;

    while (i < m && j < n) {
        if (a[i].expo == b[j].expo) {
            result[k].coeff = a[i].coeff + b[j].coeff;
            result[k].expo = a[i].expo;
            i++; j++; k++;
        } else if (a[i].expo > b[j].expo) {
            result[k] = a[i];
            i++; k++;
        } else {
            result[k] = b[j];
            j++; k++;
        }
    }

    
    while (i < m) {
        result[k++] = a[i++];
    }


    while (j < n) {
        result[k++] = b[j++];
    }

    *resSize = k;
}


void displayPoly(struct Term poly[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%dx^%d", poly[i].coeff, poly[i].expo);
        if (i != size - 1)
            printf(" + ");
    }
    printf("\n");
}

int main() {
    struct Term poly1[MAX], poly2[MAX], result[MAX];
    int m, n, resSize;

    
    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &m);
    printf("Enter terms in decreasing order of exponents (coeff exponent):\n");
    for (int i = 0; i < m; i++) {
        scanf("%d%d", &poly1[i].coeff, &poly1[i].expo);
    }

    
    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);
    printf("Enter terms in decreasing order of exponents (coeff exponent):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &poly2[i].coeff, &poly2[i].expo);
    }

    
    addPoly(poly1, m, poly2, n, result, &resSize);


    printf("Resultant Polynomial after addition:\n");
    displayPoly(result, resSize);

    return 0;
}