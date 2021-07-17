//表达式： 由项与运算符组成
//项：          因子与运算符组成(项的运算符只有加减)
//因子：      表达式与运算符组成（因子的运算符只有乘除）


#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
int factor_value();//读入一个因子并且返回其值
int term_value();//读入一项并且返回它的值
int expression_value();//读入一个表达式，并算出该表达式的值
int main() {


	cout << expression_value() << endl;
	return 0;
}


int expression_value() {//求一个表达式的值
	int result = term_value();//读入一个项，并算出项的值
	bool more = true;
	while (more)
	{
		char op = cin.peek();//看一个字符，不取走
		if (op == '+' || op == '-') {
			cin.get();//从输入中取走一个字符
			int value = term_value();
			if (op == '+')result += value;
			else { result -= value; }
		}
		else { more = false; }
		return result;
	}
	
}

int term_value() {//求一个项的值
	int result = factor_value();//求第一的因子的值
	while (true) {
		char op = cin.peek();
		if (op == '*' || op == '/') {
			cin.get();
			int value = factor_value();
			if (op == '*')result *= value;
			else result /= value;
		}
		else break;
	}
	return result;
}

int factor_value() {//求一个因子的值
	int result = 0;
		char c = cin.peek();
		if (c == '(') {
			cin.get();//读取左括号，并扔掉
			result = expression_value();
			cin.get();//读取有括号。并扔掉
		}
		else
		{
			while (isdigit(c))//用来检测一个字符是否为十进制
			{
				result = 10 * result + c - '0';
				cin.get();
				c = cin.peek();
			}
		}
		return result;
}