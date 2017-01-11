// 一个合法的身份证号码由17位地区、日期编号和顺序编号加1位校验码组成。校验码的计算规则如下：
//
// 首先对前17位数字加权求和，权重分配为：{7，9，10，5，8，4，2，1，6，3，7，9，10，5，8，4，2}；然后将计算的和对11取模得到值Z；最后按照以下关系对应Z值与校验码M的值：
//
// Z：0 1 2 3 4 5 6 7 8 9 10
// M：1 0 X 9 8 7 6 5 4 3 2
//
// 现在给定一些身份证号码，请你验证校验码的有效性，并输出有问题的号码。
//
// 输入格式：
//
// 输入第一行给出正整数N（<= 100）是输入的身份证号码的个数。随后N行，每行给出1个18位身份证号码。
//
// 输出格式：
//
// 按照输入的顺序每行输出1个有问题的身份证号码。这里并不检验前17位是否合理，只检查前17位是否全为数字且最后1位校验码计算准确。如果所有号码都正常，则输出“All passed”。

#include <iostream>
using namespace std;

#define MAXSIZE 100
typedef char ID[19];

int Weight[] = { 7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2 };
char Verification[] = { '1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2' };

bool IfPassed(char Id[]) {
	int Sum = 0;
	for (int i = 0; i < 17; i++) {
		if (Id[i] > '9' || Id[i] < '0')  return false;
		Sum += (Id[i] - 48) * Weight[i];
	}
	if (Verification[Sum % 11] == Id[17])
		return true;
	return false;
}

int main() {
	ID Id[MAXSIZE];
	int N, Flag = 0, Tag = 0;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> Id[i];
	}
	for (int i = 0; i < N; i++) {
		if (!IfPassed(Id[i])) {
			if (Flag)
				cout << '\n';
			cout << Id[i];
			Flag = 1;
			Tag = 1;
		}
	}
	if (!Tag)
		cout << "All passed";
	return 0;
}
