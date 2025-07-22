#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern struct Item inventory[100];
extern int itemCount;

void checkLowStock() {
    FILE *fp = fopen("inventory.txt", "r");
    char line[200];
    int alertFound = 0;

    printf("\n--- Low Stock Alerts ---\n");
    while (fgets(line, sizeof(line), fp)) {
        int id, stock, reorder;
        char name[30], cat[20];
        float price;
        sscanf(line, "%d,%[^,],%[^,],%f,%d,%d", &id, name, cat, &price, &stock, &reorder);
        if (stock <= reorder) {
            printf("ALERT: %s (ID: %d) is low in stock (%d units).\n", name, id, stock);
            alertFound = 1;
        }
    }
    if (!alertFound) {
        printf("NO LOW STOCK ALERTS FOUND.\n");
    }
    fclose(fp);
}

void restockItem() {
    int id, qty, found = 0;
    printf("Enter Item ID to restock: ");
    scanf("%d", &id);
    printf("Enter quantity to add: ");
    scanf("%d", &qty);

    for (int i = 0; i < itemCount; i++) {
        if (inventory[i].id == id) {
            inventory[i].stock += qty;
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Item ID not found.\n");
        return;
    }

    FILE *fp = fopen("inventory.txt", "w");
    if (fp == NULL) {
        printf("Error opening inventory file for writing.\n");
        return;
    }

    for (int i = 0; i < itemCount; i++) {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%d\n",
                inventory[i].id,
                inventory[i].name,
                inventory[i].category,
                inventory[i].price,
                inventory[i].stock,
                inventory[i].reorderLevel);
    }

    fclose(fp);
    printf("Item restocked successfully.\n");
}
