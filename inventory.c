#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Item 
{
    int id;
    char name[50];
    char category[30];
    float price;
    int stock;
    int reorderLevel;
};

struct Item inventory[100];
int itemCount = 0;
const char *inventoryFile = "inventory.txt";

void addItem()
{
    if (itemCount >= 100)
    {
        printf("Inventory capacity reached!\n");
        return;
    }

    struct Item newItem;
    printf("\nEnter Item ID: ");
    scanf("%d", &newItem.id);

    for (int i = 0; i < itemCount; i++)
    {
        if (inventory[i].id == newItem.id)
        {
            printf("Item ID already exists!\n");
            return;
        }
    }

    printf("Enter Name: ");
    scanf(" %[^\n]s", newItem.name);
    printf("Enter Category: ");
    scanf("%s", newItem.category);
    printf("Enter Price: ");
    scanf("%f", &newItem.price);
    printf("Enter Stock: ");
    scanf("%d", &newItem.stock);
    printf("Enter Reorder Level: ");
    scanf("%d", &newItem.reorderLevel);

    inventory[itemCount++] = newItem;
    printf("Item added successfully!\n");
}

void updateItem()
{
    int id, found = 0;
    printf("\nEnter Item ID to update: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++)
    {
        if (inventory[i].id == id)
        {
            printf("Enter new Name: ");
            scanf(" %[^\n]s", inventory[i].name);
            printf("Enter new Category: ");
            scanf("%s", inventory[i].category);
            printf("Enter new Price: ");
            scanf("%f", &inventory[i].price);
            printf("Enter new Stock: ");
            scanf("%d", &inventory[i].stock);
            printf("Enter new Reorder Level: ");
            scanf("%d", &inventory[i].reorderLevel);

            printf("Item updated successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Item not found!\n");
    }
}

void removeItem()
{
    int id, found = 0;
    printf("\nEnter Item ID to remove: ");
    scanf("%d", &id);

    for (int i = 0; i < itemCount; i++)
    {
        if (inventory[i].id == id)
        {
            for (int j = i; j < itemCount - 1; j++)
            {
                inventory[j] = inventory[j + 1];
            }
            itemCount--;
            printf("Item removed successfully!\n");
            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Item not found!\n");
    }
}

void viewInventory()
{
    printf("\n--- Inventory ---\n");
    printf("%-8s %-15s %-15s %-10s %-7s %-7s\n", "ID", "Name", "Category", "Price", "Stock", "Reorder");
    for (int i = 0; i < itemCount; i++)
    {
        printf("%-8d %-15s %-15s %-10.2f %-7d %-7d\n",
               inventory[i].id,
               inventory[i].name,
               inventory[i].category,
               inventory[i].price,
               inventory[i].stock,
               inventory[i].reorderLevel);
    }
}

void loadInventory()
{
    FILE *fp = fopen(inventoryFile, "r");
    if (fp == NULL)
        return;

    char line[200];
    while (fgets(line, sizeof(line), fp))
    {
        struct Item item;
        sscanf(line, "%d,%[^,],%[^,],%f,%d,%d",
               &item.id, item.name, item.category, &item.price, &item.stock, &item.reorderLevel);
        inventory[itemCount++] = item;
    }

    fclose(fp);
}

void saveInventory()
{
    FILE *fp = fopen(inventoryFile, "w");
    if (fp == NULL)
    {
        printf("Error saving inventory!\n");
        return;
    }

    for (int i = 0; i < itemCount; i++)
    {
        fprintf(fp, "%d,%s,%s,%.2f,%d,%d\n",
                inventory[i].id,
                inventory[i].name,
                inventory[i].category,
                inventory[i].price,
                inventory[i].stock,
                inventory[i].reorderLevel);
    }

    fclose(fp);
}
