#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <windows.h>

const int LEN = 100;
const int white = 7;
const int grey = 8;
const int red = 4;

void showArray(int nums[], int statues[], int searchNUM, int target)
{
	int i;
	Sleep(1000);
	system("cls");

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	printf("在数组中查找：%d\n", target);

	for (i = 0; i < LEN; i++)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), statues[i]);
		printf("%4d", nums[i]);
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	printf("\n查找次数：%d次", searchNUM);
}

int main()
{
	srand((unsigned)time(NULL));
	int nums[LEN];
	int i;


	for (i = 0; i < LEN; i++)
		nums[i] = i + 1;

	/*
	* 根据查找状态设定颜色
	* 未查找的数字是白色
	* 已查找的数字是灰色
	* 正在查找的数字是红色
	*/

	int statues[LEN];
	for (i = 0; i < LEN; i++)
		statues[i] = white;

	int target = rand() % LEN + 1;
	int id = 0;

	int l = 0, r = LEN - 1, mid = l + r >> 1;
	int searchNUM = 0;

	while (l <= r)
	{
		mid = l + r >> 1;
		if (target != nums[mid])
		{
			if (target > nums[mid])
				l = mid + 1;
			else
				r = mid - 1;
		}
		searchNUM++;
		statues[mid] = red;
		showArray(nums, statues, searchNUM, target);

		for (i = 0; i < LEN; i++)
			statues[i] = grey;
		for (i = l; i <= r; i++)
			statues[i] = white;

		if (target != nums[mid])
			statues[mid] = grey;
		else
			statues[mid] = red;
		showArray(nums, statues, searchNUM, target);

		if (target == nums[mid])
			break;
	}
	_getch();

	return 0;
}