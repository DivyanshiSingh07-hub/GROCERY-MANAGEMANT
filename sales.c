#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

extern struct Item inventory[100];
extern int itemCount;

void processSale()
{
    int id, qty;
    float total = 0;
    time_t now;
    time(&now);

    FILE *receipt = fopen("receipt.txt", "w");
    if (receipt == NULL)
    {
        printf("Error creating receipt!\n");
        return;
    }

    fprintf(receipt, "=== GROCERY STORE RECEIPT ===\n");
    fprintf(receipt, "Date: %s", ctime(&now));
    fprintf(receipt, "----------------------------\n");
    fprintf(receipt, "%-15s %5s %8s %10s\n", "Item", "Qty", "Price", "Subtotal");

    while (1)
    {
        printf("\nEnter Item ID (Enter 0 to finish): ");
        scanf("%d", &id);
        if (id == 0)
            break;

        printf("Enter Quantity: ");
        scanf("%d", &qty);

        int found = 0;
        for (int i = 0; i < itemCount; i++)
        {
            if (inventory[i].id == id)
            {
                if (inventory[i].stock >= qty)
                {
                    float subtotal = inventory[i].price * qty;
                    total += subtotal;
                    inventory[i].stock -= qty;

                    printf("Added: %s x%d = %.2f\n", inventory[i].name, qty, subtotal);
                    fprintf(receipt, "%-15s %5d %8.2f %10.2f\n",
                            inventory[i].name, qty, inventory[i].price, subtotal);
                    found = 1;
                }
                else
                {
                    printf("Insufficient stock! Available: %d\n", inventory[i].stock);
                }
                break;
            }
        }

        if (!found)
        {
            printf("Item not found!\n");
        }
    }

    fprintf(receipt, "----------------------------\n");
    fprintf(receipt, "%-15s %23.2f\n", "TOTAL:", total);
    fprintf(receipt, "============================\n");
    fclose(receipt);

    printf("\nSale complete. Total: %.2f\n", total);
    printf("Receipt generated as receipt.txt\n");
}
