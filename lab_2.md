# В случае ввода масива через консоль

printf("Введите количество элементов массива n: ");
if (scanf("%d", &n) != 1 || n <= 0) {
    printf("Некорректный ввод n.\n");
    return 1;
}

double* arr = (double*)malloc(n * sizeof(double));
if (arr == NULL) {
    printf("Ошибка выделения памяти.\n");
    return 1;
}

printf("Введите %d вещественных чисел:\n", n);
for (int i = 0; i < n; i++) {
    if (scanf("%lf", &arr[i]) != 1) {
        printf("Некорректный ввод элемента массива.\n");
        free(arr);
        return 1;
    }
}