#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void draw(int M[], int n, int k, int i, int COUNT[])
{
    for (int j = n - 1; j >= 0; j--)
    {
        if (j == k || j == i)
            continue;
        setcolor(14);
        rectangle(235 + j * 65, (20 - M[j]) * 20, 275 + j * 65, 400);
        rectangle(235 + j * 65, 440, 275 + j * 65, 480);
        char str[100];
        sprintf_s(str, "%d", COUNT[j]);
        drawText(243 + j * 65, 452, str);
    }
}

void comparisonCounting(int M[], int n)
{
    int i, j;
    char str[100];
    int COUNT[100] = { 0 };
    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();
    draw(M, n, n, n, COUNT);
    Sleep(1000);

    for (i = n - 1; i >= 1; i--)
    {       
        setcolor(9);
        for (int m = 0; m <= 40; m++)
            line(234 + i * 65 + m, (20 - M[i]) * 20 - 1, 234 + i * 65 + m, 400);
        Sleep(1000);
        for (j = i - 1; j >= 0; j--)
        {
            setcolor(12);
            for (int m = 0; m <= 40; m++)
                line(234 + j * 65 + m, (20 - M[j]) * 20 - 1, 234 + j * 65 + m, 400);
            Sleep(1000);
            if (M[i] <= M[j])
            {
                sprintf_s(str, "%d", COUNT[j]);
                deldrawText(243 + j * 65, 452, str);
                COUNT[j] += 1;
                sprintf_s(str, "%d", COUNT[j]);
                drawText(243 + j * 65, 452, str);
            }
            else
            {
                sprintf_s(str, "%d", COUNT[i]);
                deldrawText(243 + i * 65, 452, str);
                COUNT[i] += 1;
                sprintf_s(str, "%d", COUNT[i]);
                drawText(243 + i * 65, 452, str);
            }
            setcolor(14);
            for (int m = 0; m <= 40; m++)
                line(234 + j * 65 + m, (20 - M[j]) * 20 - 1, 234 + j * 65 + m, 400);
            Sleep(1000);
        }
        setcolor(14);
        for (int m = 0; m <= 40; m++)
            line(234 + i * 65 + m, (20 - M[i]) * 20 - 1, 234 + i * 65 + m, 400);
    }
    
    for (i = 0; i < n; i++)
    {
        for (int k = 0; k < n; k++)
        {
            if (i == COUNT[k])
            {
                if (k >= i)
                    for (int m = 0; m <= (k - i) * 65; m = m + 2)
                    {
                        draw(M, n, k, i, COUNT);
                        setcolor(5);
                        rectangle(235 + i * 65 + m, (20 - M[i]) * 20, 275 + i * 65 + m, 400);
                        rectangle(235 + k * 65 - m, (20 - M[k]) * 20, 275 + k * 65 - m, 400);
                        rectangle(235 + i * 65 + m, 440, 275 + i * 65 + m, 480);
                        rectangle(235 + k * 65 - m, 440, 275 + k * 65 - m, 480);
                        sprintf_s(str, "%d", COUNT[i]);
                        drawText(243 + i * 65 + m, 452, str);
                        sprintf_s(str, "%d", COUNT[k]);
                        drawText(243 + k * 65 - m, 452, str);
                        Sleep(1);
                        system("cls");
                    }
                else
                    for (int m = 0; m <= (i - k) * 65; m = m + 2)
                    {
                        draw(M, n, k, i, COUNT);
                        setcolor(5);
                        rectangle(235 + k * 65 + m, (20 - M[k]) * 20, 275 + k * 65 + m, 400);
                        rectangle(235 + i * 65 - m, (20 - M[i]) * 20, 275 + i * 65 - m, 400);
                        rectangle(235 + k * 65 + m, 440, 275 + k * 65 + m, 480);
                        rectangle(235 + i * 65 - m, 440, 275 + i * 65 - m, 480); 
                        sprintf_s(str, "%d", COUNT[k]);
                        drawText(243 + k * 65 + m, 452, str);
                        sprintf_s(str, "%d", COUNT[i]);
                        drawText(243 + i * 65 - m, 452, str); 
                        Sleep(1);
                        system("cls");
                    }
                int tmp = M[i];
                M[i] = M[k];
                M[k] = tmp;
                int temp = COUNT[i];
                COUNT[i] = COUNT[k];
                COUNT[k] = temp;
            }
        }
    }
    draw(M, n, n, n, COUNT);
}

int main()
{
    int n;
    scanf_s("%d", &n);
    int M[100];
    for (int i = 0; i < n; i++)
        scanf_s("%d", &M[i]);
    comparisonCounting(M, n);
    return 0;
}
