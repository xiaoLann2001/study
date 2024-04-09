#include <iostream>
using namespace std;

#include <cstdlib>
#include <string>

#define MAX 1000	//最大人数

//联系人结构体
struct Person
{
	string m_Name;	//姓名
	int m_Sex;		//性别
	int m_Age;		//年龄
	string m_Phone;	//电话
	string m_Addr;	//住址
};

//通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];	//通讯录联系人数组
	int m_size;	//当前通讯录人员个数
};

//显示菜单
void showMenu()
{
	cout << "*************************" << endl;
	cout << "***** 1、添加联系人 *****" << endl;
	cout << "***** 2、显示联系人 *****" << endl;
	cout << "***** 3、删除联系人 *****" << endl;
	cout << "***** 4、查找联系人 *****" << endl;    
	cout << "***** 5、修改联系人 *****" << endl;
	cout << "***** 6、清空联系人 *****" << endl;
	cout << "***** 0、退出通讯录 *****" << endl;
	cout << "*************************" << endl;
}

//添加联系人函数
void addPerson(Addressbooks * abs)
{
	//判断通讯录是否已满
	if (abs->m_size >= MAX)
	{
		cout << "通讯录已满!" << endl;
		return;
	}
	else
	{
		//添加联系人

		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[abs->m_size].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别: " << endl;
		cout << "1:男" << endl;
		cout << "2:女" << endl;
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_size].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入." << endl;
		}

		//年龄
		int age;
		cout << "请输入年龄: " << endl;
		while(true)
		{
			cin >> age;
			if(age >= 0 && age <=120)
			{
				abs->personArray[abs->m_size].m_Age = age;
				break;
			}
			cout << "输入有误,请重新输入." << endl;
		}

		//电话
		string phone;
		cout << "请输入联系电话: " << endl;
		cin >> phone;
		abs->personArray[abs->m_size].m_Phone = phone;
		
		//住址
		string addess;
		cout << "请输入家庭住址: " << endl;
		cin >> addess;
		abs->personArray[abs->m_size].m_Addr = addess;

		//更新通讯录人数
		abs->m_size++;

		cout << "添加成功!" << endl;
	}
}

//显示所有联系人函数
void showPerson(Addressbooks * abs)
{
	//判断联系人是否为空
	if (abs->m_size == 0)
	{
		cout << "未添加联系人!" << endl;
		return;
	}
	else
	{
		//显示通讯录所有联系人
		cout << "通讯录:" << endl;
		for (int i = 0; i < abs->m_size; i++)
		{
			cout	<< "姓名: "	<< abs->personArray[i].m_Name	<< "\t"
					<< "性别: "	<< ( abs->personArray[i].m_Sex ==1 ?"男":"女" )<< "\t"
					<< "年龄: "	<< abs->personArray[i].m_Age	<< "\t"
					<< "电话: "	<< abs->personArray[i].m_Phone	<< "\t"
					<< "住址: "	<< abs->personArray[i].m_Addr	<< endl;
		}
	}
	
}

//检测联系人是否存在,如果存在返回位置,不存在返回-1
int isExist(Addressbooks * abs, string name)
{
	//遍历通讯录
	for (int i = 0; i < abs->m_size; i++)
	{
		if (abs->personArray[i].m_Name == name)
		{
			return i;
		}
		
	}
	//遍历结束都没找到
	return -1;
}

// cout << "请输入要删除联系人的姓名:" << endl;
// string name;
// cin >> name;

// if (isExist(abs, name) == -1)
// {
// 	cout << "查无此人" << endl;
// }
// else
// {
// 	cout << "找到此人" << endl;
// }

//删除联系人函数
void deletePerson(Addressbooks * abs)
{
	cout << "请输入要删除联系人的姓名:" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//删除的逻辑是从要删除的联系人开始,把后一个联系人覆盖到前一个,以此循环
		for (int i = result; i < abs->m_size; i++)
		{
			abs->personArray[i] = abs->personArray[i+1];
		}
		cout << "删除成功!" << endl;
		//更新联系人个数
		abs->m_size--;
	}
}

//查找联系人函数
void findPerson(Addressbooks * abs)
{
	cout << "请输入要查找联系人的姓名:" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		cout	<< "姓名: "	<< abs->personArray[result].m_Name	<< "\t"
				<< "性别: "	<< ( abs->personArray[result].m_Sex ==1 ?"男":"女" )<< "\t"
				<< "年龄: "	<< abs->personArray[result].m_Age	<< "\t"
				<< "电话: "	<< abs->personArray[result].m_Phone	<< "\t"
				<< "住址: "	<< abs->personArray[result].m_Addr	<< endl;
	}
}

//修改联系人函数
void modifyPerson(Addressbooks * abs)
{
	cout << "请输入要修改联系人的姓名:" << endl;
	string name;
	cin >> name;

	int result = isExist(abs, name);
	if (result == -1)
	{
		cout << "查无此人" << endl;
	}
	else
	{
		//修改联系人

		//姓名
		string name;
		cout << "请输入姓名: " << endl;
		cin >> name;
		abs->personArray[result].m_Name = name;

		//性别
		int sex = 0;
		cout << "请输入性别: " << endl;
		cout << "1:男" << endl;
		cout << "2:女" << endl;
		while(true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[result].m_Sex = sex;
				break;
			}
			cout << "输入有误,请重新输入." << endl;
		}

		//年龄
		int age;
		cout << "请输入年龄: " << endl;
		while(true)
		{
			cin >> age;
			if(age >= 0 && age <=120)
			{
				abs->personArray[result].m_Age = age;
				break;
			}
			cout << "输入有误,请重新输入." << endl;
		}

		//电话
		string phone;
		cout << "请输入联系电话: " << endl;
		cin >> phone;
		abs->personArray[result].m_Phone = phone;
		
		//住址
		string addess;
		cout << "请输入家庭住址: " << endl;
		cin >> addess;
		abs->personArray[result].m_Addr = addess;

		cout << "修改成功!" << endl;
	}
}

//清空联系人函数
void cleanPerson(Addressbooks * abs)
{
	cout << "您确定要删除所有联系人吗[y/n]?" << endl;
	char ack;
	cin >> ack;

	if(ack == 'n' || ack == 'N')
	{
		return;
	}
	else if(ack == 'y' || ack == 'Y')
	{
		abs->m_size = 0;
		cout << "删除成功!" << endl;
	}
}

int main()
{
	Addressbooks abs;
	abs.m_size = 0;
	
	int select = 0;

	while(1)
	{
		showMenu();

		cin >> select;
		switch (select)
		{
		case 1:     //1、添加联系人 
			addPerson(&abs);
			break;
		case 2:     //2、显示联系人
			showPerson(&abs);
			break;
		case 3:     //3、删除联系人
			deletePerson(&abs);
			break;
		case 4:     //4、查找联系人
			findPerson(&abs);
			break;
		case 5:     //5、修改联系人
			modifyPerson(&abs);
			break;
		case 6:     //6、清空联系人
			cleanPerson(&abs);
			break;
		case 0:     //0、退出通讯录
			cout << "欢迎下次使用!" <<endl;
			return 0;
			break;
		default:
			break;
		}
	} 
}