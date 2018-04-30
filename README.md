/*链接：
查找和排序
题目：输入任意（用户，成绩）序列，可以获得成绩从高到低或从低到高的排列,相同成绩
      都按先录入排列在前的规则处理。
   例示：
   jack      70
   peter     96
   Tom       70
   smith     67
   从高到低  成绩            
   peter     96    
   jack      70    
   Tom       70    
   smith     67    
   从低到高
   smith     67  
   Tom       70    
   jack      70    
   peter     96      
输入描述:
输入多行，先输入要排序的人的个数，然后输入排序方法0（降序）或者1（升序）再分别输入他们的名字和成绩，以一个空格隔开
输出描述:
按照指定方式输出名字和成绩，名字和成绩之间以一个空格隔开
*/
#include<iostream>
#include<string>
#include<vector>
#include<stdlib.h>
using namespace std;
struct stu{//定义结构体
	string name;
	int grade;
};
void sort(vector<stu>&, int);//???
int main()
{
	int num,way;
	while (cin >> num >> way)
	{
		vector<stu> v;//定义一个不定长数组
		for (auto i = 0; i < num; i++)//自动类型判断i
		{
			stu s;
			cin >> s.name >> s.grade;
			v.push_back(s);
		}
		sort(v, way);
	}
}
void sort(vector<stu>&v, int way)//排序函数
{
	if (v.empty() || (way != 0 && way != 1))
		return;
	int max = 0; int beg, end;
	for (auto p = v.begin(); p != v.end(); ++p)//vector<stu>::interaor p;
	{
		max = max < (*p).grade ? (*p).grade : max;//选择最大值
	}
	if (way == 0)//降序
	{
		for (int i = max; i >= 0; --i)
		{
			for (auto q = v.begin(); q != v.end(); ++q)
			{
				if ((*q).grade == i)
					cout << (*q).name << ' ' << (*q).grade << endl;
			}
		}
	}
	if(way==1)//升序
	{
		for (int i = 0; i <= max; i++)
		{
			for (auto p = v.begin(); p != v.end(); ++p)
			{
				if ((*p).grade == i)
					cout << (*p).name << ' ' << (*p).grade << endl;
			}
		}
	}
	system("pause");
}
