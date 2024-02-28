// hangman game project
#include <graphics.h>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <ctime>
#include <windows.h>
#include <dos.h>
void system();
int lives = 4;
static int score = 0;
int DuplicateWordList[25];     // stores the randomly generated number
static int duplicateIndex = 0; // index for the randomNumber that have already been used
                               // this is done to stop same word from displaying again and again
using namespace std;

int duplicateChecker(int randomNumber)
{
    int count = 0;
    for (int i = 0; i < 25; i++) // here 25 is the total word in dictonary
    {
        if (DuplicateWordList[i] == randomNumber)
            count++; // increasing the value of count if duplicate randomNumber is found in the list
    }
    if (count == 0) // new number
        return 0;
    else // duplicate number
        return 1;
}
// loading animation
int loadingAnimation()
{
    system("cls");
    char msg[10] = {"LOADING"};
    int position = 0;
    outtextxy(205, 160, msg);
    rectangle(200, 180, 270, 190);
    setcolor(CYAN);
    for (int i = 0; i <= 66; i++)
    {
        line(202 + i, 182, 202 + i, 188);
        delay(10);
    }
    setcolor(15);
    outtextxy(150, 350, "Press any key to continue:");
    int choice;
    while (!kbhit())
    {
        cout << ".";
    }
    choice = getch();
    if (choice != NULL)
        cleardevice();
    return 1;
}

// draw boarder
void drawBorder()
{
    system("cls");
    int a = 0;
    setlinestyle(SOLID_LINE, 0, THICK_WIDTH);
    for (int i = 10; i < 600; i++)
    {
        if (i <= 450)
        {
            putpixel(10, i, RED);        // to bottom from 10,10
            putpixel(600, 450 - a, RED); // to top from 600,450
        }
        putpixel(i, 10, RED);        // to right from 10,10
        putpixel(600 - a, 450, RED); // to left from 600,450
        // delay(1);
        a++;
    }
    rectangle(11, 11, 599, 449);
    setfillstyle(1, 10);
    floodfill(200, 200, WHITE);
}

// Fixture stand display logic
void drawFixture()
{
    system("cls");
    // outtextxy(150, 70, "HANGMAN GAME");
    line(100, 100, 100, 400); // main bar
    line(50, 400, 150, 400);  // main bar stand
    line(100, 100, 300, 100); // main bar woodwork
    line(300, 100, 300, 130); // hanging rope
}

// to draw the parts of body as per mistakes
int bodyDraw(int n)
{
    // cleardevice();
    setlinestyle(SOLID_LINE, 0, NORM_WIDTH); // changing the width of man's body
    switch (n)
    {
    case 15:
        return 1;
        break;
    case 4:
        circle(300, 150, 20); // head
        break;
    case 3:
        line(300, 170, 300, 240); // body
        break;
    case 2:
        line(270, 210, 300, 190); // left hand
        line(330, 210, 300, 190); // right hand
        break;
    case 1:
        line(270, 260, 300, 240); // left leg
        line(330, 260, 300, 240); // right leg
        delay(1000);
        break;
    default:
        return 1;
    }
}

// display end message, whether won or lost
void displayFinalMsg(char msg[30], char word[15])
{
    cleardevice();
    setbkcolor(14);
    cleardevice();
    // settextstyle(10, 0, 2);
    rectangle(190, 100, 460, 140);
    int sum = 0;
    for (int i = 0; i < strlen(msg); i++)
    {
        char text[2] = {msg[i], 0}; // coder propmt
        if (msg[0] == 'C')
            outtextxy(215 + sum, 110, text);
        else
            outtextxy(200 + sum, 110, text);
        sum += 15;
        delay(50);
    }
    delay(250);
    outtextxy(220, 150, "The word is:");
    outtextxy(350, 150, word);
    string scoreStr = "Score is: " + to_string(score);
    char res[20];
    strcpy(res, scoreStr.c_str());
    outtextxy(300, 50, res);
}

// main program
int main()
{
    int gd = DETECT, gm;
    initgraph(&gd, &gm, (char *)"");
    int response = loadingAnimation();
    while (1)
    {
        // adding animation to the prompt text
        char prompt1[20] = "HANGMAN GAME";
        char prompt2[40] = "---Coder: Deepesh---";
        int sum = 0;

        drawBorder();
        setbkcolor(10);
        setcolor(0);
        fflush(stdin);
        // propmt1--HANGMAN GAME
        for (int i = 0; i < strlen(prompt1); i++)
        {
            char text[2] = {prompt1[i], 0}; // hangman propmt
            outtextxy(200 + sum, 55, text);
            sum += 10;
            delay(50);
        }
        // prompt2--coder:Deepesh
        for (int i = 0; i < strlen(prompt2); i++)
        {
            char text[2] = {prompt2[i], 0}; // coder propmt
            outtextxy(40 + sum, 70, text);
            sum += 10;
            delay(50);
        }

        // calling drawFixture to draw the hangman pole
        drawFixture();

        // dictonary file for hangman
        string dictonary[50] = {"apple", "banana", "mango", "voldemort", "harrypotter", "hermoini", "education", "instruction", "institution", "structure", "dejavu", "document", "wonderland", "pikachu", "snake", "wonderful", "nation", "countryland", "cockroaches", "doraemon", "pubg", "freefire", "computer", "yatrusir", "cyberspace"};
        // current word no.= 25
        srand(time(0));

        int randomNumber;
        do
        {
            // random number generator between 1 to dictonary.length()
            randomNumber = (rand() % 25) + 1;

            randomNumber--;                               // decreasing the randomNumber for the indexing purpose
        } while (duplicateChecker(randomNumber) != 0);    // continuing the loop until non duplicate number arrives
        DuplicateWordList[duplicateIndex] = randomNumber; // storing the randomNumbers
        duplicateIndex++;
        int len2 = dictonary[randomNumber].length();

        // copying string to char
        char *char_array = new char[len2];
        strcpy(char_array, dictonary[randomNumber].c_str());

        char tempo;
        int *printPosition = new int[len2]; // hold the keystroke pressed
        int boolean = 0, len3 = len2;

        char hintword[50];
        strcpy(hintword, dictonary[randomNumber].c_str());
        int hintGap = 0;
        for (int i = 0; i < len2; i++)
        {
            int position;
            if (i == 0)
                position = ((i) + (i + 1) + (i + 2)) / 2;
            else if (i == len2 - 1)
                position = ((i) + (i - 1) + (i - 2)) / 2;
            else
                position = ((i) + (i - 1) + (i + 1)) / 2;

            // if the 3 consucutive sum of i divided by 2 == i then print the letters
            // otherwise print *
            if (i == position)
            {
                char hintChar[2] = {hintword[position], '\0'};
                outtextxy(380 + hintGap, 110, hintChar);
            }
            else
                outtextxy(380 + hintGap, 110, "*");
            hintGap += 15;
        }
        rectangle(350, 100, 580, 140);
        memset(printPosition, 0, sizeof(printPosition));
        // Check if the first letter of the word matches the input
        for (int k = 0; k < len2; k++)
        {
            if (toupper(tempo) == toupper(char_array[k]))
            {
                printPosition[k] = k + 1; // Set to 1 to indicate the letter is already printed
                len2--;                   // Decrease remaining letters count
                break;                    // Exit the loop after finding the first letter
            }
        }
        while (len2 != 0 && lives != 0)
        {
            // delay(2000);
            while (!kbhit())
            {
                cout << "Hit me!";
            }
            tempo = getch();
            cout << "you entered: " << tempo;

            // for counting the no. of matched letter
            for (int k = 0; k < len3; k++)
            {
                if (toupper(tempo) == toupper(char_array[k]) && printPosition[k] == 0)
                {
                    boolean++;
                    printPosition[k] = k + 1;
                }
                else
                    printPosition[k] = 0;
            }
            len2 -= boolean;
            if (boolean == 0)
            {
                int res = bodyDraw(lives);
                lives--; // Increment incorrect guess counter
            }
            else
            {
                while (boolean != 0)
                {
                    for (int j = 0; j < len3; j++)
                    {
                        if (printPosition[j] != 0)
                        {
                            sum = 20 * j;
                            char text[2] = {tempo, '\0'};
                            outtextxy(200 + sum, 400, text);
                            delay(50);
                        }
                    }
                    boolean--; // ressetting the counter
                }
            }
        }

        // displaying message after word is guessed
        if (lives != 0)
        {
            score++;
            char message[20] = {"CONGRATULATIONS"};
            displayFinalMsg(message, char_array);
        }
        else
        {
            // breaking out of main if no lifes
            char message[20] = {"You lost the game"};
            displayFinalMsg(message, char_array);
        }
        outtextxy(250, 200, "Press Space to continue.");
        while (!kbhit())
        {
            cout << ".";
        }
        char choice2 = getch();
        if (choice2 == 32)
        {
            lives = 4;
            setbkcolor(0);
            setcolor(15);
        }
        else
            exit(0);
        cleardevice();
    }
    getch();
    closegraph();
}
