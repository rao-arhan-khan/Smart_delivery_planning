#include <stdio.h>

int main() {
    int n = 0, choice, i, j;
    float m = 0, p[100], w[100], pw[100], x[100], temp, total_profit = 0.0;

    while (1) {
        printf("\n--- MENU ---\n");
        printf("1. Enter Package Details\n");
        printf("2. Display Package Details\n");
        printf("3. Calculate Value/Weight Ratio\n");
        printf("4. Sort Packages by Ratio\n");
        printf("5. Find Maximum Value\n");
        printf("6. Display Selected Packages\n");
        printf("7. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("How many packages: ");
                scanf("%d", &n);
                printf("Max vehicle capacity: ");
                scanf("%f", &m);
                printf("Enter profit (value) of packages: ");
                for (i = 0; i < n; i++) scanf("%f", &p[i]);
                printf("Enter weight of packages: ");
                for (i = 0; i < n; i++) scanf("%f", &w[i]);
                break;

            case 2:
                printf("\nPackage Details:\n");
                for (i = 0; i < n; i++) {
                    printf("Package %d -> Profit: %.2f, Weight: %.2f\n", i + 1, p[i], w[i]);
                }
                break;

            case 3:
                printf("\nCalculated Value/Weight Ratios:\n");
                for (i = 0; i < n; i++) {
                    pw[i] = p[i] / w[i];
                    printf("Package %d -> Profit: %.2f, Weight: %.2f, Ratio (P/W): %.2f\n",
                           i + 1, p[i], w[i], pw[i]);
                }
                break;

            case 4:
                for (i = 0; i < n - 1; i++) {
                    for (j = 0; j < n - i - 1; j++) {
                        if (pw[j] < pw[j + 1]) {
                           
                            temp = pw[j]; pw[j] = pw[j + 1]; pw[j + 1] = temp;
                           
                            temp = p[j]; p[j] = p[j + 1]; p[j + 1] = temp;
                           
                            temp = w[j]; w[j] = w[j + 1]; w[j + 1] = temp;
                        }
                    }
                }
                printf("\nPackages Sorted by Ratio (Decreasing Order):\n");
                for (i = 0; i < n; i++) {
                    printf("Position %d -> Profit: %.2f, Weight: %.2f, Ratio: %.2f\n",
                           i + 1, p[i], w[i], pw[i]);
                }
                break;

            case 5:
                total_profit = 0.0;
                float temp_m = m;
                for (i = 0; i < n; i++) x[i] = 0.0;

                for (i = 0; i < n; i++) {
                    if (temp_m >= w[i]) {
                        x[i] = 1.0;
                        total_profit += p[i];
                        temp_m -= w[i];
                    } else {
                        x[i] = temp_m / w[i];
                        total_profit += p[i] * x[i];
                        break;
                    }
                }
                printf("\nMaximum Profit = %.2f\n", total_profit);
                break;

            case 6:
                printf("\nSelected Packages:\n");
                for (i = 0; i < n; i++) {
                    printf("Profit: %.2f, Weight: %.2f, Ratio: %.2f -> Fraction Taken: %.2f\n",
                           p[i], w[i], pw[i], x[i]);
                }
                break;

            case 7:
                return 0;

            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}