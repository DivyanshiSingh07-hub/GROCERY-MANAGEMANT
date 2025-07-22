#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "auth.c"
#include "inventory.c"
#include "sales.c"
#include "reporting.c"
#include "stock.c"

void adminMenu()
{
    int choice;
    do
    {
        printf("\n--- ADMIN MENU ---\n");
        printf("1. Add Item\n2. Update Item\n3. Remove Item\n4. View Inventory\n");
        printf("5. Check Low Stock\n6. Restock Item\n7. Generate Sales Report\n");
        printf("8. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            addItem();
            saveInventory();
            break;
        case 2:
            updateItem();
            saveInventory();
            break;
        case 3:
            removeItem();
            saveInventory();
            break;
        case 4:
            viewInventory();
            break;
        case 5:
            checkLowStock();
            break;
        case 6:
            restockItem();
            saveInventory();
            break;
        case 7:
            generateSalesReport();
            break;

        case 8:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice!\n");
        }
    } while (1);
}

void cashierMenu()
{
    int choice;
    do
    {
        printf("\n--- CASHIER MENU ---\n");
        printf("1. Process Sale\n2. View Inventory\n3. Check Low Stock\n4. Logout\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            processSale();
            break;
        case 2:
            viewInventory();
            break;
        case 3:
            checkLowStock();
            break;
        case 4:
            printf("Logging out...\n");
            return;
        default:
            printf("Invalid choice!\n");
        }
    } while (1);
}

int main()
{
    loadInventory();

    int role = login();
    if (role == 1)
    {
        adminMenu();
    }
    else if (role == 2)
    {
        cashierMenu();
    }
    else
    {
        printf("Login failed. Exiting...\n");
    }

    saveInventory();
    return 0;
}
