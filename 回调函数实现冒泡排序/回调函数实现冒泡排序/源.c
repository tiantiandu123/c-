//�ûص�������дð�ݺ���

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

void bubble_sort(void *arr[], int len, int(*cmp)(void *a, void *b)) //����������Ϊ����ָ��,Ӧ���˻ص�����  
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)   //���ƱȽϵ�����  
	{
		for (j = 0; j < len - i - 1; j++)   //����ÿ�˱ȽϵĴ���  
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
	void *arr[10];        //void ���͵�ָ������  
	printf("��������Ҫ�����Ԫ��>:");
	for (i = 0; i < sz; i++)
	{
		arr[i] = (int *)malloc(sizeof(int));
		scanf("%d", (int *)arr[i]);
	}
	bubble_sort(arr, sz, int_cmp);//  ð��ʵ����������  
	printf("�����Ľ����>:");
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(int *)arr[i]);
	}
	printf("\n");
	free(arr);
	system("pause");
	return 0;
}