
#include <stdio.h>
typedef struct Complex
{
    float real;
    float imag;
} Complex;
Complex add(Complex n1, Complex n2)
{
    Complex temp;
    temp.real = n1.real + n2.real;
    temp.imag = n1.imag + n2.imag;
    return (temp);
}
int main()
{
    Complex n1, n2, temp;
    printf("Enter 1st complex number: \n");
    printf("Enter real, imaginary parts respectively:\n");
    scanf("%f %f", &n1.real, &n1.imag);
    printf("Enter 2nd complex number: \n");
    printf("Enter real, imaginary parts respectively:\n");
    scanf("%f%f", &n2.real, &n2.imag);
    temp = add(n1, n2);
    printf("Sum=%.1f %.1fi", temp.real, temp.imag);
    return 0;
}