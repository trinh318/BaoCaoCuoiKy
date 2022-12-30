#include "graphics.h"
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct DATA
{
	int l, r;
	DATA* next;
};

struct Stack
{
	DATA* Top;

	void Init()
	{
		Top = nullptr;
	}

	bool isEmpty()
	{
		return Top == nullptr;
	}

	bool Push(int l, int r)
	{
		DATA* x = new DATA();
		x->l = l;
		x->r = r;

		if (this->isEmpty())
		{
			Top = x;
			Top->next = nullptr;
			return true;
		}
		x->next = Top;
		Top = x;
		return true;
	}

	DATA* Pop()
	{
		if (this->isEmpty())
			return nullptr;

		DATA* result = Top;
		Top = Top->next;
		return result;
	}
};

void draw(int M[], int n, int t, int h)
{
	setcolor(14);
	for (int j = n - 1; j >= 0; j--)
	{
		if (j == t || j == h)
			continue;
		rectangle(235 + j * 65, (25 - M[j]) * 20, 275 + j * 65, 500);
		char str[100];
		sprintf_s(str, "%d", M[j]);
		if (M[j] > 9)
			drawText(238 + j * 65, 472, str);
		else
			drawText(243 + j * 65, 472, str);
	}
}

void swap(int* x, int* y)
{
	int tmp = *x;
	*x = *y;
	*y = tmp;
}

void quickSort(int M[], int l, int r, int n)
{
	char str[100];
	Stack S;
	S.Init();
	S.Push(l, r);

	while (!S.isEmpty())
	{
		int l = S.Top->l;
		int r = S.Top->r;
		S.Pop();
		int key = M[l];
		Sleep(1000);
		setcolor(9);
		rectangle(235 + r * 65, (25 - M[r]) * 20, 275 + r * 65, 500);
		sprintf_s(str, "%d", M[r]);
		if (M[r] > 9)
			drawText(238 + r * 65, 472, str);
		else
			drawText(243 + r * 65, 472, str);
		int i = l, j = r;
		while (i <= j)
		{
			while (M[i] < key) 
				i++;
			while (M[j] > key) 
				j--;

			if (i <= j)
			{
				if (i < j)
				{
					Sleep(1000);
					setcolor(12);
					for (int m = 0; m <= 40; m++)
						line(234 + i * 65 + m, (25 - M[i]) * 20 - 1, 234 + i * 65 + m, 499);
					sprintf_s(str, "%d", M[i]);
					if (M[i] > 9)
						drawText(238 + i * 65, 472, str);
					else
						drawText(243 + i * 65, 472, str);
					setcolor(12);
					for (int m = 0; m <= 40; m++)
						line(234 + j * 65 + m, (25 - M[j]) * 20 - 1, 234 + j * 65 + m, 499);
					sprintf_s(str, "%d", M[j]);
					if (M[j] > 9)
						drawText(238 + j * 65, 472, str);
					else
						drawText(243 + j * 65, 472, str);
					Sleep(1000);
					setcolor(14);
					rectangle(235 + r * 65, (25 - M[r]) * 20, 275 + r * 65, 500);
					for (int m = 0; m <= (j - i) * 65; m = m + 2)
					{
						draw(M, n, i, j);
						setcolor(5);
						rectangle(235 + i * 65 + m, (25 - M[i]) * 20, 275 + i * 65 + m, 500);
						rectangle(235 + j * 65 - m, (25 - M[j]) * 20, 275 + j * 65 - m, 500);
						sprintf_s(str, "%d", M[i]);
						if (M[i] > 9)
							drawText(238 + i * 65 + m, 472, str);
						else
							drawText(243 + i * 65 + m, 472, str);
						sprintf_s(str, "%d", M[j]);
						if (M[j] > 9)
							drawText(238 + j * 65 - m, 472, str);
						else
							drawText(243 + j * 65 - m, 472, str);
						Sleep(1);
						system("cls");
					}
					swap(&M[i], &M[j]);		
					draw(M, n, n, n);
				}
				i++;
				j--;
			}
		}
		if (l < j)
			S.Push(l, j);
		if (i < r)
			S.Push(i, r);
		setcolor(14);
		rectangle(235 + r * 65, (25 - M[r]) * 20, 275 + r * 65, 500);
		draw(M, n, n, n);
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
    quickSort(M, 0, n - 1, n);
	draw(M, n, n, n);
    return 0;

}