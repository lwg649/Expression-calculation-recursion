//逆波兰表达式的定义
//:一个数是逆波兰表达式
//:“运算符  逆波兰表达式   逆波兰表达式 ”是逆波兰表达式
#include<iostream>
#include<cstdio>
using namespace std;
//读入一个逆波兰表达式，并计算它的值

double exp(){
	char s[20];
	cin >> s;
	switch (s[0]) {
	case'+': return exp() + exp();
	case'-':  return exp() + exp();
	case'*':  return exp() + exp();
	case'/':  return exp() + exp();
	default: return atof(s);//将字符串转换为一个双精度数
		break;
	}
}
int main() {
	printf("%lf", exp());
	return 0;
}