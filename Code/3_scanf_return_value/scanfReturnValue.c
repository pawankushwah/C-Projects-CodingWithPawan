#include <stdio.h> // printf(), scanf()
#include <stdlib.h> // system()

int main(void)
{
    int a, b, c;
    char c1[5], c2[5];
    int scanf_return_value;

    system("cls");
    // scanf returns the number of variable enter correctly

    printf("Enter the variable in the format of %%d %%s %%d %%s %%d: ");

    scanf_return_value = scanf("%d %s %d %s %d",&a, &c1, &b, &c2, &c);

    printf("Scanf return value: %d", scanf_return_value);

    return 0;
}