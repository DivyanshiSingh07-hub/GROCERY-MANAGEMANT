#include <stdio.h>
#include <string.h>

int login()
{
    char username[30], password[30];
    int attempts = 0;

    while (attempts < 3)
    {
        printf("Login as (admin/cashier): ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmpi(username, "admin") == 0 && strcmp(password, "pass123") == 0)
        {
            printf("WELCOME ADMIN\n");
            return 1;
        }
        else if (strcmpi(username, "cashier") == 0 && strcmp(password, "cash") == 0)
        {
            printf("WELCOME CASHIER\n");
            return 2;
        }
        else
        {
            printf("Invalid username or password. Try again.\n");
            attempts++;
        }
    }
    printf("Maximum login attempts exceeded.\n");
    return 0;
}
