#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

class Score
{
public:

	void inputscore(int eng, int mat, int com)
	{
		this->english = eng;
		this->math = mat;
		this->computer = com;
	}
	int english;
	int math;
	int computer;
	float pjscore;
private:
	
};



class Student
{
public:
	friend class Score;
	//Student();
	//Student(float pjscore);               //构造函数

	~Student();              //析构函数
	//Student(const Student&stu);//拷贝构造函数
	Student Input();         //输入函数
	void show(Student stu[]);//显示函数
	void change(Student *stu);//改值
	int Search(Student stu[]);//查找
	void task5(Student stu[]);//选项五，计算不同科目平均值
	float pingjun(Student stu[],int score,int mode);
	static int number;
private:
	string id;
	string name;
	Score score;
	//float *ptr;
};
int Student::number = 0;

/*Student::Student()
{
	//ptr = new float;
}
Student::Student(const Student&stu)//拷贝构造函数
{

}
Student::Student(float pjscore) //构造函数
{
	this->score.pjscore = 0;//初始化
}
*/
Student::~Student()//析构函数 
{
	//cout << "信息处理完成" << endl;
	//delete ptr;//释放内存
}

float Student::pingjun(Student stu[],int score, int mode) //平均值
{
	//mode为选择模式 0.所有成绩 1.英语 2.数学 3.计算机
	float s=0;
	int i;
	switch (mode)
	{
	case 0:
		return (score / 3.0);
	case 1:
		for (i = 0; i < number; i++)
		{
			s = s + stu[i].score.english;
		}
		s = s / number;
		break;
	case 2:
		for (i = 0; i < number; i++)
		{
			s = s + stu[i].score.math ;
		}
		s = s / number;
		break;
	case 3:
		for (i = 0; i < number; i++)
		{
			s = s + stu[i].score.computer;
		}
		s = s / number;
		break;
	}
	return s;
}

//信息输入
Student Student::Input()
{
	int e, m, c;
	Student stu;
	cout << "学号：" << endl;
	cin >> stu.id;
	cout << "姓名：" << endl;
	cin >> stu.name;
	cout << "英语：" << endl;
	cin >> e;
	cout << "数学:" << endl;
	cin >> m;
	cout << "计算机：" << endl;
	cin >> c;
	stu.score.inputscore(e, m, c);
	number++;
	stu.score.pjscore = stu.pingjun(&stu,e + m + c,0);
	return stu;

}

int Student::Search(Student stu[])
{
	int n,i;
	string s;
	cout << "请输入查找方式" << endl;
	cout << "1.按学号 2.按姓名 " << endl;
	cin >> n;
	switch (n)
	{
	case 1:
		cout << "请输入要查找同学的学号：";
		cin >> s;
		for (i = 0; i < number; i++)
		{
			if (s == stu[i].id)
			{
				return i;
			}
		}
		cout << "未查到相关同学" << endl;
		
	case 2:
		cout << "请输入要查找同学的姓名：";
		cin >> s;
		for (i = 0; i < number; i++)
		{
			if (s == stu[i].name)
			{
				return i;
			}
		}
		cout << "未查到相关同学" << endl;
		
	}
	return -1;
}
void Student::show(Student stu[])
{
	for (int i = 0; i < number; i++)
	{
		cout << " 学号 " << stu[i].id;
		cout << " 姓名 " << stu[i].name;
		cout << " 英语成绩 " << stu[i].score.english;
		cout << " 数学成绩 " << stu[i].score.math;
		cout << " 计算机成绩 " << stu[i].score.computer;
		cout << " 平均成绩 " << stu[i].score.pjscore << endl;
	}
	
}
void Student::change(Student *stu)//修改数据
{
	cout << "按顺序输入数据，每输入完成后按回车" << endl;
	cout << "学号  姓名  英语成绩  数学成绩  计算机成绩" << endl;
	cin >> stu->id;
	cin >> stu->name;
	cin >> stu->score.english;
	cin >> stu->score.math;
	cin >> stu->score.computer;

}
void Student::task5(Student stu[])
{
	int n;
	float r;
	cout << "请选择要统计的科目" << endl;
	cout << "1.英语 2.数学 3.计算机" << endl;
	cin >> n;
	r=stu->pingjun(stu, 0, n);
	cout << "所选科目的平均成绩为：" << r << endl;
}

void List()
{
	cout << "1.添加学生信息" << endl;
	cout << "2.修改学生信息" << endl;
	cout << "3.显示数据" << endl;
	cout << "4.统计某一课程平均成绩" << endl;
	cout << "5.退出" << endl;
}

void main()
{
	Student stu, date[50];
	int s,r;
	while (1)
	{
		List();
		cin >> s;
		switch (s)
		{
		case 1:
			date[stu.number-1] = stu.Input();
			break;
		case 2:
			r = stu.Search(date);
			if (r == -1)break;
			stu.change(&date[r]);
			break;
		case 3:
			stu.show(date);
			break;
		case 4:
			stu.task5(date);
			break;
		case 5:
			return;
		}
		system("pause");
		system("cls");
	}
}
