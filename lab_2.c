#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n = 5;

    double *arr = malloc(n * sizeof(double));
    if (!arr) {
        printf("Ошибка выделения памяти.\n");
        return 1;
    }

    // Исходные значения массива
    double temp[5] = {-5, 11, 14, -48, 56};
    for (int i = 0; i < n; i++) {
        arr[i] = temp[i];
    }

    printf("Массив:");
    for (int i = 0; i < n; i++){
        printf("%.0f, ", temp[i]);
    }
    printf("\n\n");

    // 1. Номер минимального по модулю элемента массива (по индексу, начиная с 1)
    int min_abs_index = 0;
    for (int i = 1; i < n; i++) {
        if (fabs(arr[i]) < fabs(arr[min_abs_index])) {
            min_abs_index = i;
        }
    }
    printf("Номер минимального по модулю элемента: %d\n", min_abs_index + 1);

    // 2. Сумма модулей элементов, расположенных после первого отрицательного элемента
    int first_neg_index = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0) {
            first_neg_index = i;
            break;
        }
    }

    double sum_after_first_neg = 0.0;
    if (first_neg_index != -1 && first_neg_index < n - 1) {
        for (int i = first_neg_index + 1; i < n; i++) {
            sum_after_first_neg += fabs(arr[i]);
        }
    }
    printf("Сумма модулей элементов после первого отрицательного: %.2f\n", sum_after_first_neg);

    // 3. Сжатие массива: удаление элементов в интервале [a, b]
    double a, b;
    printf("Введите границы интервала a и b (a <= b): \nЭлементы из этого промежутка будут удалены: ");
    if (scanf("%lf %lf", &a, &b) != 2 || a > b) {
        printf("Некорректный ввод границ интервала.\n");
        free(arr);
        return 1;
    }

    int write_index = 0;
    for (int read_index = 0; read_index < n; read_index++) {
        if (arr[read_index] < a || arr[read_index] > b) {
            arr[write_index] = arr[read_index];
            write_index++;
        }
    }

    // Заполняем оставшуюся часть массива нулями
    for (int i = write_index; i < n; i++) {
        arr[i] = 0.0;
    }

    printf("Сжатый массив:\n");
    for (int i = 0; i < n; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    free(arr);
    return 0;
}