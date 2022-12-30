#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

void draw(int M[], int n, int N[])
{
    setcolor(14);
    for (int j = n - 1; j >= 0; j--)
    {
        if (N[j] != 0)
        {
            rectangle(235 + j * 65, (15 - N[j]) * 20 + 260, 275 + j * 65, 300 + 260);
            char str[100];
            sprintf_s(str, "%d", N[j]);
            if (N[j] > 9)
                drawText(238 + j * 65, 272 + 260, str);
            else if (N[j] != 0)
                drawText(243 + j * 65, 272 + 260, str);
        }
        rectangle(235 + j * 65, (15 - M[j]) * 20, 275 + j * 65, 300);
        char str[100];
        sprintf_s(str, "%d", M[j]);
        if (M[j] > 9)
            drawText(238 + j * 65, 272, str);
        else if (M[j] != 0)
            drawText(243 + j * 65, 272, str);
    }
}

void moveRight(int M[], int n, int k, int t, int N[], int Q[])
{
    char str[100];
    int x, y, m = (k - t) * 65;
    for (y = 0; y <= 260; y += 4)
    {
        draw(N, n, Q);
        setcolor(9);
        rectangle(235 + t * 65, (15 - M[t]) * 20 + y, 275 + t * 65, 300 + y);
        sprintf_s(str, "%d", M[t]);
        if (M[t] > 9)
            drawText(238 + t * 65, 272 + y, str);
        else if (M[t] != 0)
            drawText(243 + t * 65, 272 + y, str);
        Sleep(1);
        system("cls");
    }
    for (x = 0; x <= m; x += 2)
    {
        if (m == 0)
            break;
        draw(N, n, Q);
        setcolor(9);
        rectangle(235 + t * 65 + x, (15 - M[t]) * 20 + 260, 275 + t * 65 + x, 300 + 260);
        sprintf_s(str, "%d", M[t]);
        if (M[t] > 9)
            drawText(238 + t * 65 + x, 272 + 260, str);
        else if (M[t] != 0)
            drawText(243 + t * 65 + x, 272 + 260, str);
        Sleep(1);
        system("cls");
    }
    draw(N, n, Q);
}

void moveLeft(int M[], int n, int k, int t, int N[], int Q[])
{
    char str[100];
    int x, y, m = (t - k) * 65;
    for (y = 0; y <= 260; y += 4)
    {
        draw(N, n, Q);
        setcolor(9);
        rectangle(235 + t * 65, (15 - M[t]) * 20 + y, 275 + t * 65, 300 + y);
        sprintf_s(str, "%d", M[t]);
        if (M[t] > 9)
            drawText(238 + t * 65, 272 + y, str);
        else if (M[t] != 0)
            drawText(243 + t * 65, 272 + y, str);
        Sleep(1);
        system("cls");
    }
    for (x = 0; x <= m; x += 2)
    {
        if (m == 0)
            break;
        draw(N, n, Q);
        setcolor(9);
        rectangle(235 + t * 65 - x, (15 - M[t]) * 20 + 260, 275 + t * 65 - x, 300 + 260);
        sprintf_s(str, "%d", M[t]);
        if (M[t] > 9)
            drawText(238 + t * 65 - x, 272 + 260, str);
        else if (M[t] != 0)
            drawText(243 + t * 65 - x, 272 + 260, str);
        Sleep(1);
        system("cls");
    }  
    draw(N, n, Q);
}

void _move(int M[], int n, int N[], int Q[])
{
    char str[100];
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (Q[i] != 0)
        {
            tmp = Q[i];
            for (int y = 0; y <= 260; y += 4)
            {
                Q[i] = 0;
                draw(N, n, Q);
                setcolor(9);
                rectangle(235 + i * 65, (15 - M[i]) * 20 + 260 - y, 275 + i * 65, 300 + 260 - y);
                sprintf_s(str, "%d", M[i]);
                if (M[i] > 9)
                    drawText(238 + i * 65, 272 + 260 - y, str);
                else if (M[i] != 0)
                    drawText(243 + i * 65, 272 + 260 - y, str);
                Sleep(1);
                system("cls");
            }
            N[i] = tmp;
        }
    }
    draw(N, n, Q);
}

void merge(int M[], int l, int m, int r, int n)
{
    char str[100];
    int i, j, k, t;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[100], R[100], A[100], B[100], C[100] = { 0 };
    for (i = 0; i < n1; i++)
        L[i] = M[l + i];
    for (j = 0; j < n2; j++)
        R[j] = M[m + 1 + j];
    for (i = 0; i < n; i++)
    {
        A[i] = M[i];
        B[i] = M[i];
    }

    i = 0;
    j = 0;
    k = l;
    Sleep(1000);
    while (i < n1 && j < n2)
    {
        setcolor(12);
        for (int q = 0; q <= 40; q++)
            line(234 + (l + i) * 65 + q, (15 - M[l + i]) * 20 - 1, 234 + (l + i) * 65 + q, 299);
        sprintf_s(str, "%d", M[l + i]);
        if (M[l + i] > 9)
            drawText(238 + (l + i) * 65, 272, str);
        else if (M[l + i] != 0)
            drawText(243 + (l + i) * 65, 272, str);
        for (int q = 0; q <= 40; q++)
            line(234 + (m + 1 + j) * 65 + q, (15 - M[m + 1 + j]) * 20 - 1, 234 + (m + 1 + j) * 65 + q, 299);
        sprintf_s(str, "%d", M[m + 1 + j]);
        if (M[m + 1 + j] > 9)
            drawText(238 + (m + 1 + j) * 65, 272, str);
        else if (M[m + 1 + j] != 0)
            drawText(243 + (m + 1 + j) * 65, 272, str);
        Sleep(1000);
        if (L[i] <= R[j])
        {
            B[l + i] = 0;
            moveRight(A, n, k, l + i, B, C);
            C[k] = L[i];
            M[k] = L[i];
            i++;
        }
        else
        {
            B[m + 1 + j] = 0;
            moveLeft(A, n, k, m + 1 + j, B, C);
            C[k] = R[j];
            M[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        B[l + i] = 0;
        moveRight(A, n, k, l + i, B, C);
        C[k] = L[i];
        M[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        B[m + 1 + j] = 0;
        moveLeft(A, n, k, m + 1 + j, B, C);
        C[k] = R[j];
        M[k] = R[j];
        j++;
        k++;
    }
    _move(M, n, B, C);
}

void mergeSort(int M[], int l, int r, int n)
{    
    if (l < r) 
    {
        int m = l + (r - l) / 2;
        mergeSort(M, l, m, n);
        mergeSort(M, m + 1, r, n);
        merge(M, l, m, r, n);
    }
}

int main()
{
    int n;
    int M[100], N[100] = { 0 };
    printf("So luong phan tu: ");
    scanf_s("%d", &n);
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++)
        scanf_s("%d", &M[i]);
    char ini[] = "C:\\TURBOC3\\BGI";
    initgraph();
    draw(M, n, N);
    mergeSort(M, 0, n - 1, n);
    draw(M, n, N);
    return 0;
}
