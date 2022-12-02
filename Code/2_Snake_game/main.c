/*

    Features to be added
    1) gameover message improvement
    2) Warning to be Removed
    3) gameover on touching snake body
        * how to empty a structure data (NULL is showing error)
        * alternative of _sleep (because it's deprecated)
    4) printing message in box (in nested loop) dynamically with some line of code

*/
#include <stdio.h>
#include <conio.h>
#include <stdlib.h> // getch, kbhit
#include <math.h>
#include <string.h> // strcpy
#include <unistd.h> // _sleep,
#include <ctype.h>
#include <windows.h>

#define scrWidth 50
#define scrHeight 20
#define MAXMAINMENUOPTION 4
#define SNAKEHEAD "#"

int flag, gameover, gameoverScr;
int fruitx, fruity;
int score = 0;
int point = 0;
int contentCount = 0;
int level = 1;
int hiscore;
int headx,heady;

// structure for tail
struct Tail
{
    int x;
    int y;
} tail[90];

struct Content
{
    int x;
    int y;
    char string[100];
    int strlen;
} content[10];

// Declaration of user defined functions
void gameloop(), banner(), randomFruit(), mainMenuHandler(), mainMenu(int), printline(int, char), credits(), highscore(), refresh(), askLevel(),printMsg(int,int,char*);

int confirmQuit();

int main(void)
{
    banner();
    mainMenuHandler();
    return 0;
}

void mainMenuHandler()
{
    int ch;
    int i = 1;

    mainMenu(1);
    while (1)
    {
        ch = getch();
        switch (ch)
        {
        case 72: // up arrow key
            if (i != 1)
            {
                i--;
                mainMenu(i);
            }
            else
            {
                i = MAXMAINMENUOPTION;
                mainMenu(i);
            }
            break;

        case 80: // Down arrow key
            if (i != MAXMAINMENUOPTION)
            {
                i++;
                mainMenu(i);
            }
            else
            {
                i = 1;
                mainMenu(i);
            }
            break;

        case 13: // Enter key
            switch (i)
            {
            case 1:
                askLevel();
                gameloop();
                break;

            case 2:
                highscore();
                break;

            case 3:
                credits();
                break;

            case MAXMAINMENUOPTION:
                if(toupper(confirmQuit()) == 'Y'){
                    credits();
                    exit(0);
                }
                else{
                    i = 1;
                    system("cls");
                    mainMenu(i);
                }
                break;

            default:
                break;
            }
            mainMenuHandler();

        case 27: // Escape key
            (toupper(confirmQuit()) == 'Y') ? credits(), exit(0) : 1;
            break;

        default:
            break;
        }
    }
}

void mainMenu(int ch)
{
    int options = 4;
    char str[][20] = {"Start New Game", "Highscore", "Credits", "Exit Game"};
    int i = 0;

    system("cls");
    printf("\n");
    printline(50, '#');
    while (i < options)
    {
        if (ch == i + 1)
            printf("-->\t%s\n", str[i]);
        else
            printf("\t%s\n", str[i]);
        i++;
    }
    printline(50, '#');
}

void askLevel()
{
    system("cls");
    printf("\n");
    printline(50, '#');
    printf("Choose your level:\n\n");
    printf("\t1. Easy\n\t2. Medium\n\t3. Hard\n");
    printline(50, '#');
    scanf("%d", &level);
}

void credits()
{
    system("cls");
    printf("\n");
    printline(50, '#');
    printf("\n\tGame Developer\n");
    printf("\tPawan Kushwah\n\n");
    printf("\tThanks For Playing\n");
    printf("\tPress Any to continue\n");
    printline(50, '#');
    getch();
}

void highscore()
{
    system("cls");
    printf("\n");
    printline(50, '#');
    printf("\tHighscore : %d\n\n", hiscore);
    printf("\tPress Any to continue\n");
    printline(50, '#');
    getch();
}

void banner()
{
    system("cls");
    printf("\n");
    printline(50, '#');
    printf("\t Welcome to Snakes");
    printf("\n\t Press Any key to start\n");
    printline(50, '#');
    getch();
}

void randomFruit()
{
    int minx, maxx, miny, maxy;
    if (level == 1)
    {
        minx = 20;
        maxx = 30;
        miny = 8;
        maxy = 12;
    }
    else if (level == 2)
    {
        minx = 10;
        maxx = 40;
        miny = 4;
        maxy = 17;
    }
    else
    {
        minx = 2;
        maxx = 49;
        miny = 2;
        maxy = 19;
    }
    fruitx = (rand() % (maxx - minx + 1)) + minx;
    fruity = (rand() % (maxy - miny + 1)) + miny;
}

void printline(int x, char symbol)
{
    printf("\n");
    for (int i = 0; i < x; i++)
    {
        printf("%c", symbol);
    }
    printf("\n\n");
}

void printMsg(int x, int y, char string[]){
    content[contentCount].y = x;
    content[contentCount].x = y;
    content[contentCount].strlen = strlen(string);
    strcpy(content[contentCount++].string, string);
}

int confirmQuit()
{
    system("cls");
    printf("\n");
    printline(50, '#');
    printf("\tDo you really want to exit [y/n]: \n");
    printline(50, '#');
    return getch();
}

void refresh()
{
    score = 0;
    flag = 0;
    gameoverScr = 0;
    point = 0;
    headx = scrWidth / 2;
    heady = scrHeight / 2;
    for (int i = 0; i < point; i++)
    {
        tail[i].x = NULL;
        tail[i].y = NULL;
    }
    for (int i = 0; i < contentCount; i++)
    {
        content[i].x = NULL;
        content[i].y = NULL;
    }
    randomFruit();
}

void gameloop()
{
    int i, j;
    headx = scrWidth / 2;
    heady = scrHeight / 2;
    randomFruit();

    while (!gameover)
    {
        system("cls");
        printf("\n\n");
        // printf("\tW - up\t\tS - Down\tA - Left\tS - Right\n\tX - Exit\tESC - Pause/Resume\n");
        printf("\tMove snake with arrow keys\n");
        printf("\tHighscore:%15d", hiscore);
        printf("  Score:%15d\n", score);
        // printf("%s",content[0].string);
        // printf("  fruitx:%d\t", fruitx);
        // printf("  fruity:%d\n", fruity);
        for (j = 0; j <= scrHeight; j++)
        {
            for (i = 0; i <= scrWidth; i++)
            {
                if (i == 0 && j != 0)
                    printf("\t");
                else if (j == 0)
                    printf(" ");
                else if (j == 1 || j == scrHeight || i == 1 || i == scrWidth)
                    printf("#");
                else if (j == fruity && i == fruitx)
                {
                    char string[] = "@";
                    printf("%s", string);
                    if (strlen(string) > 2)
                        i += (strlen(string) - 2) / 2;
                }
                else if (j == heady && i == headx)
                {
                    char string[5] = SNAKEHEAD;
                    printf("%s", string);
                    if (strlen(string) >= 2)
                        i += strlen(string) - 1;
                }
                else if (j == content[0].y && i == content[0].x && gameoverScr == 1)
                {
                    printf("%s", content[0].string);
                    if (content[0].strlen >= 2)
                        i += content[0].strlen - 1;
                }
                else
                {
                    int temp = 0;
                    // ploting tail
                    for (int k = 0; k <= point; k++)
                    {
                        if (j == tail[k].y && i == tail[k].x)
                        {
                            char string = '0';
                            printf("%c", string);
                            temp = 1;
                        }
                    }
                    // ploting text
                    // for (int l = 0; l <= contentCount; l++)
                    // {
                    //     if (j == content[l].y && i == content[l].x && gameoverScr == 1)
                    //     {
                    //         printf("%s", content[i].string);
                    //     }
                    //     if (content[l].strlen > 2)
                    //         i += (content[i].strlen) - 1;
                    // }
                    if(temp != 1){
                        printf(" ");
                    }
                }
            }
            printf("\n");
        }

        _sleep(10);
        // logic for gamover on body touch
        // for(int i = 3; i < point; i++){
        //     if(point > 3 && headx == tail[i].x && heady == tail[i].y){
        //         goto gameoverLabel;
        //     }
        // }
        if(point >= 1){
            tail[0].x = headx;
            tail[0].y = heady;
            for (int i = point; i >= 0; i--)
            {

                tail[i].x = tail[i-1].x;
                tail[i].y = tail[i-1].y;
            }
        }

        if (gameoverScr == 1)
        {
            printf("Press Any Key 2 time to continue\n");
            getch();
            printf("1 ");
            getch();
            printf("2 ");
            printf("Press N for new game");

            if (getch() == 'n'){
                refresh();
                gameloop();
            }
            else
            {
                refresh();
                mainMenuHandler();
            }
        }

        if (kbhit())
        {
            int gameTemp = getch();
            int oldFlag = flag;
            int oppositeOldFlag = 0;

            switch (oldFlag)
            {
            case 1:
                oppositeOldFlag = 3;
                break;
            
            case 2:
                oppositeOldFlag = 4;
                break;
            
            case 3:
                oppositeOldFlag = 1;
                break;
            
            case 4:
                oppositeOldFlag = 2;
                break;
            
            default:
                break;
            }

            switch (gameTemp)
            {
            case 75: // left
                flag = 1; 
                break;

            case 80: // Down
                flag = 2;
                break;

            case 77: // right
                flag = 3;
                break;

            case 72: // up
                flag = 4;
                break;

            case 27: // Escape
                confirmQuit();
                int temp = getch();
                (toupper(temp) == 'Y') ? exit(0) : gameloop();
                break;

            default:
                break;
            }

            if(flag == oppositeOldFlag && point >= 1){
                flag = oldFlag;
            }
        }

        // usleep(1000);
        switch (flag)
        {
        case 1:
            headx--;
            break;

        case 2:
            heady++;
            _sleep(20);
            break;

        case 3:
            headx++;
            break;

        case 4:
            heady--;
            _sleep(20);
            break;

        default:
            break;
        }

        if (headx <= 1 || headx >= scrWidth || heady <= 1 || heady >= scrHeight)
        {
            // gameoverLabel:
            // printMsg(10,scrHeight/2,"Game over! Press N for new game");

            content[0].x = 10;
            content[0].y = scrHeight / 2;
            strcpy(content[0].string, "Game over! Press N for new game");
            content[0].strlen = strlen(content[0].string);

            gameoverScr = 1;
            fruitx = fruity = 0;
            if (score > hiscore)
                hiscore = score;
        }

        if (headx == fruitx && heady == fruity)
        {
            score += 100;
            tail[point].x = fruitx;
            tail[point].y = fruity;
            point++;
            randomFruit();
        }
    }
}
