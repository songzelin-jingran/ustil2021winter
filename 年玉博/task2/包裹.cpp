#include<iostream>
#include<string>
#include<conio.h>
#include<cstdlib>
using namespace std;
//假设首重费为5，过2kg超重,每超重1kg加5
//加急起价费为10
class package
{
public:
	virtual double calculateCost() = 0;
	double weight, km;
	string name1, name2, address1, address2;
};
class ptpackage:public package
{
public:
	virtual double calculateCost()
	{
		if (weight <= 2&&weight>0)
		{
			return 5;
		}
		else
		{
			return (5 + (weight - 2) * 5);
		}
	}

};
class jjpackage :public package
{
public:
	virtual double calculateCost()
	{
		return (10 + weight * 10 + km * 0.02);
	}

};
void pp()
{
	package *t = new ptpackage;
	cout << "请输入寄件人姓名：" << endl;
	cin >> t->name1;
	cout << "请输入收件人姓名：" << endl;
	cin >> t->name2;
	cout << "请输入寄件人地址：" << endl;
	cin >> t->address1;
	cout << "请输入收件人地址：" << endl;
	cin >> t->address2;
	cout << "请输入快递重量：" << endl;
	cin >> t->weight;
	cout << "所需金额为" << t->calculateCost() << "元" << endl;
	free(t);
}
void jp()
{
	package *t = new jjpackage;
	cout << "请输入寄件人姓名：" << endl;
	cin >> t->name1;
	cout << "请输入收件人姓名：" << endl;
	cin >> t->name2;
	cout << "请输入寄件人地址：" << endl;
	cin >> t->address1;
	cout << "请输入收件人地址：" << endl;
	cin >> t->address2;
	cout << "请输入快递重量：" << endl;
	cin >> t->weight;
	cout << "请输入加急公里数" << endl;
	cin >> t->km;
	cout << "所需金额为" << t->calculateCost() << "元" << endl;
	free(t);
	
}

void List()
{
	cout<< "选择包裹类型：1.普通包裹\t2.加急包裹" << endl;
	cout << "     请输入要选择的包裹类型" << endl;
}
void main()
{
	while (1)
	{
		List();
		int t;
		cin >> t;
		switch (t)
		{
		case 1:
			pp();
			break;
		case 2:
			jp();
			break;
		default:
			cout << "输入有误，请重新输入！"<<endl;
			break;
		}
		system("pause");
		system("cls");
	}
}
