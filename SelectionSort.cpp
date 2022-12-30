#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void draw(int M[], int n, int t, int h, int x)
{
    for (int j = n - 1; j >= 0; j--)
    {
        if (j == t || j == h)
            continue;
        if (j >= x)
            setcolor(9);
        else
            setcolor(14);
        rectangle(235 + j * 65, (25 - M[j]) * 20, 275 + j * 65, 500);     
        char str[100];
        sprintf_s(str, "%d", M[j]);
        if (M[j] > 9)
            drawText(238 + j * 65, 472, str);
        else
            drawText(243 + j * 65, 472, str);
    }
}

void selectionSort(int M[], int n)
{
    int i, j, t = 0;
    char str[100];
    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();
    draw(M, n, n, n, n);

    for (j = n - 1; j >= 0; j--)
    {
        if (j == 0)
        {
            draw(M, n, n, n, j);
            break;
        }

        int max = M[j];
        t = j;
        for (int k = j; k >= 0; k--)
            if (M[k] > max)
            {
                max = M[k];
                t = k;
            }

        char s1[] = "Max";
        int maxindex = j;
        Sleep(500);
        arrow(255 + maxindex * 65, 510, 30, 9);
        drawText(233 + maxindex * 65, 550, s1);
        setcolor(12);
        for (int m = 0; m <= 40; m++)
            line(234 + j * 65 + m, (25 - M[j]) * 20 - 1, 234 + j * 65 + m, 499);
        sprintf_s(str, "%d", M[j]);
        if (M[j] > 9)
            drawText(238 + j * 65, 472, str);
        else
            drawText(243 + j * 65, 472, str);
        int h = j;
        while (h >= 0)
        {
            setcolor(1);
            for (int m = 0; m <= 40; m++)
                line(234 + h * 65 + m, (25 - M[h]) * 20 - 1, 234 + h * 65 + m, 499);
            sprintf_s(str, "%d", M[h]);
            if (M[h] > 9)
                drawText(238 + h * 65, 472, str);
            else
                drawText(243 + h * 65, 472, str);

            if (j != h)
            {
                setcolor(12);
                for (int m = 0; m <= 40; m++)
                    line(234 + j * 65 + m, (25 - M[j]) * 20 - 1, 234 + j * 65 + m, 499);
                sprintf_s(str, "%d", M[j]);
                if (M[j] > 9)
                    drawText(238 + j * 65, 472, str);
                else
                    drawText(243 + j * 65, 472, str);
            }
                       
            if (M[h] > M[maxindex])
            {
                arrow(255 + maxindex * 65, 510, 30, 13);
                deldrawText(233 + maxindex * 65, 550, s1);

                arrow(255 + h * 65, 510, 30, 9);
                drawText(233 + h * 65, 550, s1);
                Sleep(500);
                maxindex = h;
            }

            Sleep(500);
            setcolor(14);
            for (int m = 0; m <= 40; m++)
                line(234 + h * 65 + m, (25 - M[h]) * 20 - 1, 234 + h * 65 + m, 499);
            sprintf_s(str, "%d", M[h]);
            if (M[h] > 9)
                drawText(238 + h * 65, 472, str);
            else
                drawText(243 + h * 65, 472, str);

            if (h == t)
            {
                setcolor(12);
                for (int m = 0; m <= 40; m++)
                    line(234 + t * 65 + m, (25 - M[t]) * 20 - 1, 234 + t * 65 + m, 499);
                sprintf_s(str, "%d", M[t]);
                if (M[t] > 9)
                    drawText(238 + t * 65, 472, str);
                else
                    drawText(243 + t * 65, 472, str);
                Sleep(500);
            }
            h--;
        }

        if (t >= j)
            for (i = 0; i <= (t - j) * 65; i = i + 2)
            {
                draw(M, n, t, j, j);
                setcolor(5);
                rectangle(235 + j * 65 + i, (25 - M[j]) * 20, 275 + j * 65 + i, 500);
                rectangle(235 + t * 65 - i, (25 - M[t]) * 20, 275 + t * 65 - i, 500);
                sprintf_s(str, "%d", M[j]);
                if (M[j] > 9)
                    drawText(238 + j * 65 + i, 472, str);
                else
                    drawText(243 + j * 65 + i, 472, str);
                sprintf_s(str, "%d", M[t]);
                if (M[t] > 9)
                    drawText(238 + t * 65 - i, 472, str);
                else
                    drawText(243 + t * 65 - i, 472, str);
                Sleep(1);
                system("cls");
            }
        else
            for (i = 0; i <= (j - t) * 65; i = i + 2)
            {
                draw(M, n, t, j, j);
                setcolor(5);
                rectangle(235 + j * 65 - i, (25 - M[j]) * 20, 275 + j * 65 - i, 500);
                rectangle(235 + t * 65 + i, (25 - M[t]) * 20, 275 + t * 65 + i, 500);
                sprintf_s(str, "%d", M[t]);
                if (M[t] > 9)
                    drawText(238 + t * 65 + i, 472, str);
                else
                    drawText(243 + t * 65 + i, 472, str);
                sprintf_s(str, "%d", M[j]);
                if (M[j] > 9)
                    drawText(238 + j * 65 - i, 472, str);
                else
                    drawText(243 + j * 65 - i, 472, str);
                Sleep(1);
                system("cls");
            }
        int tmp = M[j];
        M[j] = max;
        M[t] = tmp;
        draw(M, n, n, n, j);
    }
}

int main()
{
    int n;
    int M[100];
    printf("So luong phan tu: ");
    scanf_s("%d", &n);
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &M[i]);
    selectionSort(M, n);
    return 0;
}
