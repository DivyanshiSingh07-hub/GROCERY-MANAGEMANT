#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void generateSalesReport() {
    FILE *fp = fopen("receipt.txt", "r");
    char line[200];

    if (fp == NULL) {
        printf("No sales data available.\n");
        return;
    }

    printf("\n--- Sales Report ---\n");
    while (fgets(line, sizeof(line), fp)) {
        printf("%s", line);
    }
    fclose(fp);
}

