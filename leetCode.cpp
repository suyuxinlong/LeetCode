#include <iostream>
#include <string.h>

using namespace std;

/*
	算法题，第十二题
	题目：罗马数字转整型

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000

思路：首先，创建一个hashMap来映射符号和值；
*/
int romanToInt(string s)
{
	int out = 0, i = 0, len = s.length();

	while (i < len)
	{
		switch (s[i])
		{
		case 'M':
			out += 1000;
			break;
		case 'D':
			out += 500;
			break;
		case 'L':
			out += 50;
			break;
		case 'V':
			out += 5;
			break;
		case 'I':
			if (s[i + 1] == 'V')
			{
				out += 4;
				i++;
			}
			else if (s[i + 1] == 'X')
			{
				out += 9;
				i++;
			}
			else
				out += 1;
			break;
		case 'X':
			if (s[i + 1] == 'L')
			{
				out += 40;
				i++;
			}
			else if (s[i + 1] == 'C')
			{
				out += 90;
				i++;
			}
			else
				out += 10;
			break;
		case 'C':
			if (s[i + 1] == 'D')
			{
				out += 400;
				i++;
			}
			else if (s[i + 1] == 'M')
			{
				out += 900;
				i++;
			}
			else
				out += 100;
			break;
		default:
			return -1;
		}
		i++;
	}

	return out;
}

int main(int argc, char const *argv[])
{
	cout << "LeetCode 练习:" << romanToInt("VII") << endl;
	return 0;
}