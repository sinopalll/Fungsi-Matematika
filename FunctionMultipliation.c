#include <stdio.h>
#include <math.h>

int get_int_input(const char *prompt) {
    int value;
    printf("%s", prompt);
    while (scanf("%d", &value) != 1) {
        while (getchar() != '\n');
        printf("Invalid input!\n%s", prompt);
    }
    return value;
}

int f_function(int a, int b, int x) {
    // f(x) = ax + b
    return a * x + b;
}

int f_function_square(int a, int b, int c, int x) {
    // f(x) = ax^2 + bx + c
    return a * x * x + b * x + c;
}

int g_function(int a, int b, int x) {
    // f(x) = ax + b
    return a * x + b;
}

int g_function_square(int a, int b, int c, int x) {
    // f(x) = ax^2 + bx + c
    return a * x * x + b * x + c;
}

int fog_function(int a, int b, int c, int a1, int b1, int c1, int x, int f_choice, int g_choice) {
    // fog(x) = a * g(x) + b 
    // fog(x) = a * g(x)^2 + b * g(x) + c
    if (f_choice == 1 && g_choice == 1) {
        return a * g_function(a1, b1, x) + b;
    } else if (f_choice == 1 && g_choice == 2) {
        return a * g_function_square(a1, b1, c1, x) + b;
    } else if (f_choice == 2 && g_choice == 1) {
        return a * pow(g_function(a1, b1, x), 2) + b * g_function(a1, b1, x) + c;
    } else if (f_choice == 2 && g_choice == 2) {
        return a * pow(g_function_square(a1, b1, c1, x), 2) + b * g_function_square(a1, b1, c1, x) + c;
    } else {
        return 0;
    }
}

void print_fog_function(int a, int b, int c, int a1, int b1, int c1, int x, int f_choice, int g_choice) {
    if (f_choice == 1 && g_choice == 1) {
        printf("fog(x) = %dx + %d\n", a * a1, a * b1 + b);
    } else if (f_choice == 1 && g_choice == 2) {
        printf("fog(x) = %dx^2 + %dx + %d\n", a * a1, a * b1, a * c1 + b);
    } else if (f_choice == 2 && g_choice == 1) {
        printf("fog(x) = %dx^2 + %dx + %d\n", a * a1 * a1, a * 2 * a1 * b1 + b * a1, b * b1 + a * b1 * b1 + c);
    } else if (f_choice == 2 && g_choice == 2) {
        printf("fog(x) = %dx^4 + %dx^3 + %dx^2 + %dx + %d\n", a * a1 * a1, a * (2 * a1 * b1), a * (2 * a1 * c1 + b1 * b1) + b * a1, a * (2 * b1 * c1) + b * b1, a * c1 * c1 + b * c1 + c);
    }
}

int main() {
    int a , a1, b, b1, c, c1, x, f_choice, g_choice;

    printf("~COMPOSITIONS FUNCTIONS {fog(x) = f(g(x))}~\n");

    printf("f(x)\n1. Linear Function\n2. Square Function\n");
    while (f_choice != 1 && f_choice != 2) {
        f_choice = get_int_input("Input choice: ");
        if (f_choice != 1 && f_choice != 2) {
            printf("Invalid choice!\n");
        }
    }
    if (f_choice == 1) {
        printf("\nLinear Function\n");
        printf("f(x) = ax + b\n");
        a = get_int_input("Input a: ");
        b = get_int_input("Input b: ");
        printf("f(x) = %dx + %d\n\n", a,b);
    } else if (f_choice == 2) {
        printf("\nSquare Function\n");
        printf("f(x) = ax^2 + bx + c\n");
        a = get_int_input("Input a: ");
        b = get_int_input("Input b: ");
        c = get_int_input("Input c: ");
        printf("f(x) = %dx^2 + %dx + %d\n\n", a, b, c);
    }
    
    printf("g(x)\n1. Linear Function\n2. Square Function\n");
    while (g_choice != 1 && g_choice != 2) {
        g_choice = get_int_input("Input choice: ");
        if (g_choice != 1 && g_choice != 2) {
            printf("Invalid choice!\n");
        }
    }
    if (g_choice == 1) {
        printf("\nLinear Function\n");
        printf("\ng(x) = ax + b\n");
        a1 = get_int_input("Input a: ");
        b1 = get_int_input("Input b: ");
        printf("g(x) = %dx + %d\n\n", a1,b1);
    } else if (g_choice == 2) {
        printf("\nSquare Function\n");
        printf("\nf(x) = ax^2 + bx + c\n");
        a1 = get_int_input("Input a: ");
        b1 = get_int_input("Input b: ");
        c1 = get_int_input("Input c: ");
        printf("f(x) = %dx^2 + %dx + %d\n\n", a1, b1, c1);
    }
    
    print_fog_function(a, b, c, a1, b1, c1, x, f_choice, g_choice);
    x = get_int_input("Input x: ");

    int result = fog_function(a, b, c, a1, b1, c1, x, f_choice, g_choice);
    printf("fog(%d) = %d\n", x, result);
    
    return 0;
}