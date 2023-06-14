#define _CRT_SECURE_NO_WARNINGS	
#include<stdio.h>
#include<stdlib.h>
#include<vector>
#include"strswi.h"

typedef struct book
{
	char name[65];
	char isbn[14];
	unsigned short price;
	unsigned int svo;
	unsigned int inventory;
};
int ifinsert(char *arra)
{
	unsigned int i=0;
	while (1)
	{
		if (arra[i] != cr[i])break;//判断字符串是否符合插入命令要求
		else { i++; }
	}
	return i;//返回该命令在字符串的最后元素下标
}
int strsecpy(char* a1, char* a2, int ch1, int ch2)
{
	register int i = 0, j = 0;
	char str_arr[1024] = { 0 };
	for (i = ch1; i <= ch2; i++)
	{
		str_arr[j] = a2[i];//把字符串2中满足条件的字符串截取出来存放到临时数组中
		j++;
	}
	strcpy(a1, str_arr);//把值赋值给外部内存空间。
	return j;//返回字符串长度。
}
int strsecpy(char* a1, char* a2, int ch1)
{
	register int i = 0, j = 0;
	char str_arr[1024] = { 0 };
	for (i = ch1; 1; i++)
	{
		if (a2[i]==','||a2[i] == ';')break;
		str_arr[j] = a2[i];//把字符串2中满足条件的字符串截取出来存放到临时数组中
		j++;
	}
	strcpy(a1, str_arr);//把值赋值给外部内存空间。
	return j;//返回字符串长度。
}
void insertdata(book& pinbook,char* isd,unsigned int len)
{
	int i = len, s = 0, sj = 0, v = 0;
	int start[5];//存储五个字段数据分别在字符串中的各个起始下标和末尾下标。
	
	while (1)
	{
		switch (sj)
		{
		case 1:
			strsecpy(pinbook.name, isd, start[0]);//字段一赋值
			sj = 0;
			break;
		case 2:
			strsecpy(pinbook.isbn, isd, start[1]);//字段二赋值
			sj = 0;
			break;
		case 3:
			char ssarry[6];
			strsecpy(ssarry, isd, start[2]);//字段三截取值
			pinbook.price = atoi(ssarry);//字段三转换赋值
			sj = 0;
			break;
		case 4:
			char arr4[10];
			strsecpy(arr4, isd, start[3]);//字段4截取值
			pinbook.svo = atoi(arr4);//字段4转换赋值
			sj = 0;
			break;
		case 5:
			char arr5[10];
			strsecpy(arr5, isd, start[4]);//字段5截取值
			pinbook.inventory = atoi(arr5);//字段5转换赋值
			sj = 0;
			break;
		defautl:
			//abort();
			break;
		}

		if (isd[i] == '\0')break;//输入数据遍历完毕退出循环。
		else
		{
			if (isd[i] == ',' || isd[i] == ' ')//
			{
				start[s] = i+1;
				s++;
				sj = s;
			}
		}
		i++;

	}
	*pars++;
}
int main(int argc, char* argv[])
{
	unsigned int ars = 1;//控制数据记录的数量
	unsigned int* pars = &ars;
	register int i, j;
	char arraystring[1024] = { 1 };//缓冲区处理
	std::vector<book> booka(ars);//数据存放
	while (1)
	{
		gets_s(arraystring);//获取缓冲区数据
		insertdata(booka[ars], arraystring, ifinsert(arraystring));
		std::vector<book> booka(ars);
		for (i = 0; i <ars; i++)printf("%s,%s,%d,%d,%d\r\n", booka[i].name, booka[i].isbn, booka[i].price, booka[i].svo, booka[i].inventory);
	}
	
	return 0;
}