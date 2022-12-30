#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void draw(int M[], int n, int x, int y)
{
    char str[100];
    setcolor(14);
    for (int j = n - 1; j >= 0; j--)
    {
        if (j == x || j == y)
            continue;
        rectangle(235 + j * 65, (25 - M[j]) * 20, 275 + j * 65, 500);
        sprintf_s(str, "%d", M[j]);
        if (M[j] > 9)
            drawText(238 + j * 65, 472, str);
        else
            drawText(243 + j * 65, 472, str);
    }
}

void shellSort(int M[], int N)
{
    char str[100];
    int t = 4;
    int h[4] = { 1,3,5,7 };
    int i, j, h_, K;

    for (int s = t - 1; s >= 0; s--)
    {
        h_ = h[s];
        for (j = h_; j < N; j++)
        {
            i = j - h_;
            K = M[j];
            while (i >= 0)
            {
                if (K >= M[i])
                {
                    M[i + h_] = K;
                    break;
                }
                Sleep(1000);
                setcolor(12);
                for (int m = 0; m <= 40; m++)
                    line(234 + (i + h_) * 65 + m, (25 - M[i + h_]) * 20 - 1, 234 + (i + h_) * 65 + m, 500);
                for (int m = 0; m <= 40; m++)
                    line(234 + i * 65 + m, (25 - M[i]) * 20 - 1, 234 + i * 65 + m, 500);
                sprintf_s(str, "%d", M[i]);
                if (M[i] > 9)
                    drawText(238 + i * 65, 472, str);
                else
                    drawText(243 + i * 65, 472, str);
                sprintf_s(str, "%d", M[i + h_]);
                if (M[i + h_] > 9)
                    drawText(238 + (i + h_) * 65, 472, str);
                else
                    drawText(243 + (i + h_) * 65, 472, str);
                Sleep(1000);
                for (int m = 0; m <= h_ * 65; m = m + 2)
                {
                    draw(M, N, i + h_, i);
                    setcolor(5);
                    rectangle(235 + i * 65 + m, (25 - M[i]) * 20, 275 + i * 65 + m, 500);
                    rectangle(235 + (i + h_) * 65 - m, (25 - M[i + h_]) * 20, 275 + (i + h_) * 65 - m, 500);
                    sprintf_s(str, "%d", M[i]);
                    if (M[i] > 9)
                        drawText(238 + i * 65 + m, 472, str);
                    else
                        drawText(243 + i * 65 + m, 472, str);
                    sprintf_s(str, "%d", M[i + h_]);
                    if (M[i + h_] > 9)
                        drawText(238 + (i + h_) * 65 - m, 472, str);
                    else
                        drawText(243 + (i + h_) * 65 - m, 472, str);
                    Sleep(1);
                    system("cls");
                }
                int M_ = M[i + h_];
                M[i + h_] = M[i];
                M[i] = M_;
                draw(M, N, N, N);
                i = i - h_;
            }
        }
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
    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();
    draw(M, n, n, n);
    shellSort(M, n);
    draw(M, n, n, n);
    return 0;
}
