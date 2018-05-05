//用回调函数编写冒泡函数

#include<stdio.h>
int int_cmp(void *str1, void *str2)
{
	return *(int *)str1 > *(int *)str2 ? 1 : 0;
}

int char_cmp(void *str1, void *str2)
{
	return *(char *)str1 > *(char *)str2 ? 1 : 0;
}

void swap(void *arr[], int x, int y)
{
	void *tmp;
	tmp = arr[x];
	arr[x] = arr[y];
	arr[y] = tmp;
}

void bubble_sort(void *arr[], int len, int(*cmp)(void *a, void *b)) //第三个参数为函数指针,应用了回调函数  
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)   //控制比较的趟数  
	{
		for (j = 0; j < len - i - 1; j++)   //控制每趟比较的次数  
		{
			if (cmp(arr[j], arr[j + 1]) == 1)
				swap(arr, j, j + 1);
		}
	}
}
int main()
{
	int i = 0;
	int sz = 10;
	void *arr[10];        //void 类型的指针数组  
	printf("请输入你要排序的元素>:");
	for (i = 0; i < sz; i++)
	{
		arr[i] = (int *)malloc(sizeof(int));
		scanf("%d", (int *)arr[i]);
	}
	bubble_sort(arr, sz, int_cmp);//  冒泡实现升序排列  
	printf("输出后的结果是>:");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(int *)arr[i]);
	}
	printf("\n");
	free(arr);
	system("pause");
	return 0;
}