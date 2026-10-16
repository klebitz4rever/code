#include <stdio.h>

int main() 
{
    int AMOUNT = 100;
    int price = 0;

    printf("Enter the price of the item: ");
    scanf("%d", &price);

    printf("Enter the AMOUNT: ");
    scanf("%d", &AMOUNT);

    int change = AMOUNT - price;

    printf("Change to be returned: %d\n", change);

    return 0;
}