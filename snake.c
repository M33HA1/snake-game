#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
int length = 15, breadth = 45, x, y, foodx, foody, flag, end, score;
int tailX[100], tailY[100];
int part = 0;
void logic()
{
    int i;
    int prevx, prevy, prev2x, prev2y;
    prevx = tailX[0];
    prevy = tailY[0];
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i <= part; i++)
    {
        prev2x = tailX[i];
        prev2y = tailY[i];
        tailX[i] = prevx;
        tailY[i] = prevy;
        prevx = prev2x;
        prevy = prev2y;
    }
    switch (flag)
    {
    case 1:
    {
        x--;
        break;
    }
    case 2:
    {
        y--;
        break;
    }
    case 3:
    {
        x++;
        break;
    }
    case 4:
    {
        y++;
        break;
    }
    }
}
void controls()
{
    if (kbhit())
    {
        switch (getch())
        {
        case 'w':
        {
            flag = 1;
            break;
        }

        case 'a':
        {
            flag = 2;
            break;
        }

        case 's':
        {
            flag = 3;
            break;
        }

        case 'd':
        {
            flag = 4;
            break;
        }
        }
    }
    if (x == 0 || x == length || y == 0 || y == breadth)
    {
        end = 1;
    }
    if (x == foodx && y == foody)
    {
    label3:
        foodx = rand() % length;
        if (foodx == 0)
        {
            goto label3;
        }

    label4:
        foody = rand() % breadth;
        if (foody == 0)
        {
            goto label4;
        }
        score += 10;
        part++;
    }
}
void snake()
{
    x = length / 2;
    y = breadth / 2;

label1:
    foodx = rand() % length;
    if (foodx == 0)
    {
        goto label1;
    }

label2:
    foody = rand() % breadth;
    if (foody == 0)
    {
        goto label2;
    }

    end = 0;
}
void outline()
{
    system("cls");
    int l, b, p, ch = 0;
    for (l = 0; l <= length; l++)
    {
        for (b = 0; b <= breadth; b++)
        {
            if (l == 0 || l == length || b == 0 || b == breadth)
            {
                printf("!");
            }
            else
            {
                if (l == x && b == y)
                {
                    printf("@");
                }
                else if (l == foodx && b == foody)
                {
                    printf("$");
                }
                else
                {
                    ch = 0;
                    for (int p = 0; p <= part; p++)
                    {
                        if (l == tailX[p] && b == tailY[p])
                        {
                            printf("o");
                            ch = 1;
                        }
                    }
                    if (ch == 0)
                    {
                        printf(" ");
                    }
                }
            }
        }
        printf("\n");
    }
    printf("score is \t %d", score);
}
int main()
{
    system("cls");
    snake();
    while (end != 1)
    {
        Sleep(100);
        outline();
        Sleep(100);
        controls();
        logic();
    }
    return score;
}