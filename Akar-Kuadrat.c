#include <stdio.h>
#include <math.h>

typedef struct {
    float real1;
    float imag1;
    float real2;
    float imag2;
} AkarKompleks;

AkarKompleks hitungAkar(float a, float b, float c) {
    AkarKompleks hasil;
    float diskriminan = b*b - 4*a*c;

    if (diskriminan > 0) {
        hasil.real1 = (-b + sqrt(diskriminan)) / (2*a);
        hasil.imag1 = 0;
        hasil.real2 = (-b - sqrt(diskriminan)) / (2*a);
        hasil.imag2 = 0;
    } else if (diskriminan == 0) {
        hasil.real1 = hasil.real2 = -b / (2*a);
        hasil.imag1 = hasil.imag2 = 0;
    } else {
        hasil.real1 = hasil.real2 = -b / (2*a);
        hasil.imag1 = sqrt(-diskriminan) / (2*a);
        hasil.imag2 = -hasil.imag1;
    }
    return hasil;
}

int main() {
    float a, b, c;
    printf("ax^2 + bx + c = 0\n");
    printf("Masukkan nilai a, b, c: ");
    scanf("%f %f %f", &a, &b, &c);

    if (a == 0) {
        printf("Bukan persamaan kuadrat.\n");
        return 0;
    }

    AkarKompleks akar = hitungAkar(a, b, c);

    if (akar.imag1 == 0 && akar.imag2 == 0) {
        if (akar.real1 == akar.real2) {
            printf("Akar kembar: x = %.2f\n", akar.real1);
        } else {
            printf("Akar real berbeda:\n");
            printf("x1 = %.2f\nx2 = %.2f\n", akar.real1, akar.real2);
        }
    } else {
        printf("Akar kompleks:\n");
        printf("x1 = %.2f + %.2fi\n", akar.real1, akar.imag1);
        printf("x2 = %.2f - %.2fi\n", akar.real2, -akar.imag2); 
    }

    return 0;
}
