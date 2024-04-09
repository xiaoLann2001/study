#include <iostream>
using namespace std;

#include "workerManager.h"
#include <cstdlib>

#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

int main()
{
    workerManager wm;

    int choice;

    while (1)
    {
        wm.Show_Menu();
        cout << "请输入您的选择: " << endl;
        cin >> choice;

        switch (choice)
        {
        case 0:
            wm.exit_System();
            break;
        case 1:
            cout << "添加职工信息" << endl;
            wm.add_Emp();
            break;
        case 2:
            cout << "显示职工信息" << endl;
            wm.Show_Emp();
            break;
        case 3:
            cout << "删除职工信息" << endl;
            wm.Del_Emp();
            break;
        case 4:
            cout << "修改职工信息" << endl;
            wm.Mod_Emp();
            break;
        case 5:
            cout << "查找职工信息" << endl;
            wm.Find_Emp();
            break;
        case 6:
            cout << "按照编号排序" << endl;
            wm.Sort_Emp();
            break;
        case 7:
            cout << "清空所有文档" << endl;
            wm.Clean_File();
            break;
        default:
            cout << "输入错误,请重新输入!" << endl;
            system("clear");
            break;
        }
    }
}