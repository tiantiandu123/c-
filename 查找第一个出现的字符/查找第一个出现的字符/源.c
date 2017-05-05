//在字符串中找出第一个只出现一次的字符。
//如输入“abaccdeff”，则输出’b’，这道题目曾是2006年一家公司的笔试题。
//下面为简单的代码实现：
#include<stdio.h>
int find(const char*str)
{
	const char *tmp = str;
	unsigned char arr[256] = { 0 };
	while (*tmp)
	{
		arr[*tmp]++;//以*tmp为下标的元素  *tmp为字符串中第一个元素ASCII值为下表的元素
		tmp++;
	}
	tmp = str;
	while (*tmp)
	{
		if (arr[*tmp] == 1)
			return *tmp;
		tmp++;
	}
	return -1;
}

int main()
{
	char *p = "abaccedff";//d b
	char ret = find(p);
	printf("%c\n", ret);
	system("pause");
	return 0;
}
//说明一下为什么两次使用tmp：
//因为在第一次str++之后再次使用的话会导致查找的字符串有误，因为str的值已经改变了。所以第二次再将str赋给tmp, 保证了其使用时的正确性。