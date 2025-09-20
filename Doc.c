#include <stdio.h>

int main(void) {
    double a, b, c;
    double Xstart, Xend, dX;

    printf("Введите a: ");
    if (scanf("%lf", &a) != 1) return 1;

    printf("Введите b: ");
    if (scanf("%lf", &b) != 1) return 1;

    printf("Введите c: ");
    if (scanf("%lf", &c) != 1) return 1;

    printf("X нач. = ");
    if (scanf("%lf", &Xstart) != 1) return 1;

    printf("X кон. = ");
    if (scanf("%lf", &Xend) != 1) return 1;

    printf("dX = ");
    if (scanf("%lf", &dX) != 1 || dX == 0.0) {
        printf("Некорректный шаг!\n");
        return 1;
    }

    // целые части (берём просто преобразованием к long)
    long Ai = (long)a;
    long Bi = (long)b;
    long Ci = (long)c;

    printf("\n  x\t\tF\n");
    printf("------------------------\n");
    // Праверка правльноли задан интервал
    if (dX > 0 && Xstart < Xend && dX <= (Xend - Xstart)) {
        for (double x = Xstart; x <= Xend + 1e-9; x += dX) {
            double F;

            if (x < 1.0 && c != 0.0) {
                if (b == 0.0) {
                    printf("x = %7.4f\tделение на ноль\n", x);
                    continue;
                }
                F = (a * x * x + c / b);
                printf("x = %7.4f\tF1 = %10.4f\n", x, F);

            }
            else if (x > 1.5 && c == 0.0) {
                F = (x - a) / ((x - c)*(x - c));
                printf("x = %7.4f\tF2 = %10.4f\n", x, F);

            }
            else if( c != 0.0) {
                F = (x * x) / (c * c);
                printf("x = %7.4f\tF3 = %10.4f\n", x, F);
            }

            long bitOp = (Ai & Bi) ^ Ci;
            // if (bitOp != 0)
                // printf("x = %7.4f\tF = %10.4f\n", x, F);
            // else
                // printf("x = %7.4f\tF = %10.0f\n", x, F);
        }
    } else {
        for (double x = Xstart; x >= Xend - 1e-9; x += dX) {
            double F;

            if (x < 1.0 && c != 0.0) {
                if (b == 0.0) {
                    printf("x = %7.4f\tделение на ноль\n", x);
                    continue;
                }
                F = (a * x * x + c / b) / 2.0;
            }
            else if (x > 1.5 && c == 0.0) {
                F = 0.0;
            }
            else {
                F = 2.0 * c * x;
            }

            long bitOp = (Ai & Bi) ^ Ci;
            if (bitOp != 0)
                printf("x = %7.4f\tF = %10.4f\n", x, F);
            else
                printf("x = %7.4f\tF = %10.0f\n", x, F);
        }
    }

    return 0;
}
