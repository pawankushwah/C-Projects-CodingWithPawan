#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// declaration of menu function
void menu(int);

// Global variable
// chnange this variable according to the number of options
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
        // here you can either directly write the number of option or you can use the MAXOPT varialble like this so that you don;t have change it when ever you change the number of options
        if (i != MAXOPT)     // or you can use this for four options if (i != 4)
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
    // int MAXOPT = 4;
    // I have removed it because we can use MAXOPT variable to automatically change the number of options to be printed
    char options[][20] = {"Start Game","Graphics","Control","Exit"}; // you can these option as per your convenience

    for (int i = 0; i < MAXOPT; i++)
    {
        if(arrPos == i+1){
            printf("-->\t%s\n",options[i]);
        }else{
            printf("\t%s\n",options[i]);
        }
    }

    
}
