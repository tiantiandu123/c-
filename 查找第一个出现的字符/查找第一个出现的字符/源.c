//���ַ������ҳ���һ��ֻ����һ�ε��ַ���
//�����롰abaccdeff�����������b���������Ŀ����2006��һ�ҹ�˾�ı����⡣
//����Ϊ�򵥵Ĵ���ʵ�֣�
#include<stdio.h>
int find(const char*str)
{
	const char *tmp = str;
	unsigned char arr[256] = { 0 };
	while (*tmp)
	{
		arr[*tmp]++;//��*tmpΪ�±��Ԫ��  *tmpΪ�ַ����е�һ��Ԫ��ASCIIֵΪ�±��Ԫ��
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
//˵��һ��Ϊʲô����ʹ��tmp��
//��Ϊ�ڵ�һ��str++֮���ٴ�ʹ�õĻ��ᵼ�²��ҵ��ַ���������Ϊstr��ֵ�Ѿ��ı��ˡ����Եڶ����ٽ�str����tmp, ��֤����ʹ��ʱ����ȷ�ԡ�