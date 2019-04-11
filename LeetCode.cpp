#include <iostream>

using namespace std;


/*
	1.两数之和
	给定一个整数数组 nums 和一个目标值 target，请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
	你可以假设每种输入只会对应一个答案。但是，你不能重复利用这个数组中同样的元素。
*/
int sumOfNums(int nums[],int target) {

	for (int i = 0; i < 6; ++i)
	{
		int a = nums[i];
		int b = target - a; //判断b的值在不在给的数组中（不包括自己）

		for (int j = 0; j < 6; ++j)
		{
			if (j == i) { break; }
			if (nums[j] == b) {
				cout << "输出结果:" << nums[i] << "+" << nums[j]  << "=" << target << endl;
			}
		}
	}
	return 0;
}

/*
	2.两数相加
	给出两个 非空 的链表用来表示两个非负的整数。其中，它们各自的位数是按照 逆序 的方式存储的，并且它们的每个节点只能存储 一位 数字。

如果，我们将这两个数相加起来，则会返回一个新的链表来表示它们的和。

您可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/


int main(int argc, char const *argv[])
{
	cout << "---------- LeetCode算法刷题练习 ----------" << endl;
	int numbers[6] = {2,3,4,5,6,7};
	cout << "第一题:" << sumOfNums(numbers,7) << endl;;
	
	return 0;
}