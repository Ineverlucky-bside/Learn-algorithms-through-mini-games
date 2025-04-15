//Linear Search
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

const int LEN = 100;

int main()
{
	srand((unsigned)time(NULL));
	int nums[LEN];
	int i;

	for (i = 0; i < LEN; i++)
		nums[i] = i + 1;

	//随机交换数组中元素的顺序
	for (i = 0; i < 50; i++)
	{
		int ri = rand() % LEN;
		int rj = rand() % LEN;
		int temp = nums[ri];
		nums[ri] = nums[rj];
		nums[rj] = temp;
	}

	printf("随机数组为：");
	for (i = 0; i < LEN; i++)
		printf("%4d", nums[i]);
	printf("\n");

	int target = rand() % 100 + 1; //目标数字
	int id = 0; //当前查找到的数组元素的索引

	//顺序查找
	for (id = 0; id < LEN; id++)
	{
		Sleep(500);
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		printf("在数组中查找：%d\n", target);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 8);
		for (i = 0; i < id; i++)
			printf("%4d", nums[i]);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
		printf("%4d", nums[id]);

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		for (i = id + 1; i < LEN; i++)
			printf("%4d", nums[i]);
		printf("\n查找次数: %d次\n", id);

		if (target == nums[id])
			break;
	}
	_getch();
	return 0;
}