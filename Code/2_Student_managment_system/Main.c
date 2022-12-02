#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

// Declaration of Function
void mainMenu(int);
void mainMenuEnterKeyHandler(int);
void feeManagment();
void updateStudentInfo();
void newStudentRegistration();

// Global variable for easy use
int MAX_MAIN_MENU_OPTION = 3;
struct student
{
    char name[20];
    int class;
    char section;
    char fatherName[20];
    char motherName[20];
    char address[50];
    char district[20];
    char subDistrict[20];
    char state[20];
    char UID[12];
    char samagra[10];
};


int main(void)
{
    int i = 1;
    char ch;
    mainMenu(1);
    while (1) // For infinite loop
    {
        ch = getch();
        switch (ch)
        {
        case 13: // ASCII Code for Enter Key
            mainMenuEnterKeyHandler(i); 
            break;
        
        case 27: // ASCII Code for Escape Key
            exit(0); // For quit program normally
            break;
        
        case 72: // ASCII Code for Up Arrow Key
            if(i != 1){
                i--;
                mainMenu(i);
            }
            else{
                i = MAX_MAIN_MENU_OPTION;
                mainMenu(i);
            }
            break;
        
        case 80: // ASCII Code for Down Arrow Key
            if(i != MAX_MAIN_MENU_OPTION){
                i++;
                mainMenu(i);
            }
            else{
                i = 1;
                mainMenu(i);
            }
            break;
        
        default:
            break;
        }
    }
    
    return 0;
}

void mainMenu(int arrPos){
    int maxOptions = 3;
    char options[][30] = {"New Student Registration","Update Student Information","Fee managment"};

    system("cls");
    for (int i = 0; i < maxOptions; i++)
    {
        if (arrPos == i+1)
        {
            printf("-->\t%s\n",options[i]);            
        }else{
            printf("\t%s\n",options[i]);            
        }
    }
    
}

void mainMenuEnterKeyHandler(int arrPos){
    switch (arrPos)
    {
    case 1:
        newStudentRegistration();
        break;
    
    case 2:
        // updateStudentInfo();
        break;
    
    case 3:
        // feeManagment();
        break;
    
    default:
        break;
    }
}

void newStudentRegistration(){
    system("cls");
    struct student s1;   
    FILE *fp;
    fp = fopen("studentData.info","a+");
    if(fp == NULL) printf("File can't be opened"); 
    
    printf("Student Name: \t");
    scanf(" %20[^\n]s",&s1.name);
    printf("Class: \t");
    scanf(" %d",&s1.class);
    printf("section: \t");
    scanf(" %c",&s1.section);
    printf("Mother's Name: \t");
    scanf(" %20[^\n]s",&s1.motherName);
    printf("Father's Name: \t");
    scanf(" %20[^\n]s",&s1.fatherName);
    printf("Address: \t");
    scanf(" %20[^\n]s",&s1.address);
    printf("District: \t");
    scanf(" %20[^\n]s",&s1.district);
    printf("Sub-District: \t");
    scanf(" %20[^\n]s",&s1.subDistrict);
    printf("State: \t");
    scanf(" %20[^\n]s",&s1.state);
    printf("Addhar Card Number (UID): \t");
    scanf(" %12[^\n]s",&s1.UID);
    printf("Samagra: \t");
    scanf(" %9[^\n]s",&s1.samagra);

    fprintf(fp,"{'%s','%d','%c','%s','%s','%s','%s','%s','%s','%s','%s'}\n",s1.name,s1.class,s1.section,s1.fatherName,s1.motherName,s1.address,s1.district,s1.subDistrict,s1.state,s1.UID,s1.samagra);
    fclose(fp);

    printf("Data is successfully stored\n");
    printf("Press Any Key for main menu...");
    getch();
    main();
}