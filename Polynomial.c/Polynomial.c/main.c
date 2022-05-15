#include <stdio.h>

#define MAX(a,b) ((a>b)?a:b)
#define MAX_DEGREE 50

typedef struct
{
    int degree;
    float coef[MAX_DEGREE];
}Polynomial;

Polynomial addPoly(Polynomial, Polynomial);
void printPoly(Polynomial);

int main()
{
    Polynomial A = {3, {4, 3, 5, 0}};
    Polynomial B = {4,{3,1,0,2,1}};
    
    Polynomial C;
    C = addPoly(A, B);
    
    printf("\n A(x) = "); printPoly(A);
    printf("\n B(x) = "); printPoly(B);
    printf("\n C(x) = "); printPoly(C);
    
    getchar();
}


Polynomial addPoly(Polynomial A, Polynomial B)
{
    Polynomial C;
    int A_index = 0, B_index = 0, C_index = 0;
    int A_degree = A.degree, B_degree = B.degree;
    C.degree = MAX(A.degree, B.degree);
    
    while(A_index <= A.degree && B_index <= B.degree)
    {
        if(A_degree > B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++];
            A_degree--;
        }
        
        else if(A_degree == B_degree)
        {
            C.coef[C_index++] = A.coef[A_index++] + B.coef[B_index++];
            A_degree--;
            B_degree--;
        }
        
        else
        {
            C.coef[C_index++] = B.coef[B_index++];
            B_degree--;
        }
    }
    return C;
    
}

void printPoly(Polynomial P)
{
    int degree;
    degree = P.degree;
    
    for(int i = 0;i<=P.degree;i++)
    {
        printf("%3.0fx^%d", P.coef[i], degree--);
        if(i<P.degree)
            printf("+");
    }
    printf("\n");
}
