#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// declaration of menu function
void menu(int);

// Global variable
int MAXOPT = 4;

int main(void)
{
    system("cls");
    int i = 1;
    char ch;
    menu(1); //for printing basic view
    while (1) // for infinte loop
    {
        ch = getch();
        switch (ch)
        {
        case 27: // for Escape key
            exit(0); // Exiting program normally
            break;
        
        case 72: // for up arrow key
        if (i != 1)
        {
            i--;
            menu(i);
        }
        else{
            i = MAXOPT;
            menu(MAXOPT);
        }
        break;
    
        
        case 80: // for Down arrow key
        if (i != 4)
        {
            i++;
            menu(i);
        }
        else{
            i = 1;
            menu(1);
        }
        break;
        
        default:
            break;
        }
    }
    
    return 0;
}

// Defination of menu funcition
void menu(int arrPos){
    system("cls");
    int MAXOPT = 4;
    char options[][20] = {"Start Game","Graphics","Control","Exit"};

    for (int i = 0; i < MAXOPT; i++)
    {
        if(arrPos == i+1){
            printf("-->\t%s\n",options[i]);
        }else{
            printf("\t%s\n",options[i]);
        }
    }

    
}