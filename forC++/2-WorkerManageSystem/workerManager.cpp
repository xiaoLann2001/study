#include "workerManager.h"

#include <cstdlib>
#include <termios.h>
#include <unistd.h>

#include <fstream>
#define FILENAME "EMPFile.txt"

/* 提示清屏 */
void wait()
{
    // Your program's logic here

    std::cout << "Press any key to continue..." << std::endl;

    // Set the terminal to raw mode to read a single character
    struct termios orig, raw;
    tcgetattr(STDIN_FILENO, &orig);
    raw = orig;
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);

    // Read a single character
    char input;
    read(STDIN_FILENO, &input, 1);

    // Restore the original terminal settings
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig);

    // Optionally, clear the terminal
    std::system("clear");

    return;
}

workerManager::workerManager()
{
    /* 文件不存在 */
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    if (!ifs.is_open())
    {
        /* 初始化属性 */
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    /* 文件存在且数据为空 */
    char ch;
    ifs >> ch;
    if (ifs.eof())
    {
        /* 文件为空 */
        /* 初始化属性 */
        this->m_EmpNum = 0;
        this->m_EmpArray = NULL;
        this->m_FileIsEmpty = true;
        ifs.close();
        return;
    }

    ifs.close();

    /* 文件存在并记录数据 */
    int num = this->get_EmpNum();
    cout << "职工人数为： " << num << endl;
    this->m_EmpNum = num;

    /* 开辟空间 */
    this->m_EmpArray = new Worker *[this->m_EmpNum];
    /* 将文件中的数据存到数组中 */
    this->Emp_Init();
}

void workerManager::Show_Menu()
{
    cout << "***************************" << endl;
    cout << "****** 职工管理系统 *******" << endl;
    cout << "***** 0、退出管理系统 *****" << endl;
    cout << "***** 1、添加职工信息 *****" << endl;
    cout << "***** 2、显示职工信息 *****" << endl;
    cout << "***** 3、删除职工信息 *****" << endl;
    cout << "***** 4、修改职工信息 *****" << endl;
    cout << "***** 5、查找职工信息 *****" << endl;
    cout << "***** 6、按照编号排序 *****" << endl;
    cout << "***** 7、清空所有文档 *****" << endl;
    cout << "***************************" << endl;
    cout << endl;
}

void workerManager::exit_System()
{
    cout << "欢迎下次使用!" << endl;
    wait();
    exit(0);
}

void workerManager::add_Emp()
{
    cout << "请输入要添加的职工数目: " << endl;

    int add_Num = 0;
    cin >> add_Num;

    if (add_Num <= 0)
    {
        cout << "输入有误" << endl;
    }
    else
    {
        /* 计算新空间大小 */
        int new_Num = this->m_EmpNum + add_Num;

        /* 开辟新空间 */
        Worker **newSpace = new Worker *[new_Num];

        /* 转移原来的数据 */
        if (this->m_EmpArray != NULL)
        {
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                newSpace[i] = this->m_EmpArray[i];
            }
        }

        /* 批量添加新数据 */
        for (int i = 0; i < add_Num; i++)
        {
            /* 职工数据 */
            int Id;      // 职工Id
            string Name; // 职工名称
            int DeptId;  // 职工部门

            cout << "请输入第" << i + 1 << "个职工的编号: " << endl;
            cin >> Id;
            if (this->IsExist(Id) != -1)
            {
                /* 跳过本次循环 */
                cout << "输入错误，请重新输入！" << endl;
                i--;
                continue;
            }

            cout << "请输入第" << i + 1 << "个职工的姓名: " << endl;
            cin >> Name;

            cout << "请输入第" << i + 1 << "个职工的部门编号: " << endl;
            cout << "1.普通职工" << endl
                 << "2.经理" << endl
                 << "3.老板" << endl;
            cin >> DeptId;

            Worker *worker = NULL;
            switch (DeptId)
            {
            case 1:
                worker = new Employee(Id, Name, DeptId);
                break;
            case 2:
                worker = new Manager(Id, Name, DeptId);
                break;
            case 3:
                worker = new Boss(Id, Name, DeptId);
                break;
            default:
                break;
            }

            /* 将职工指针放入数组 */
            newSpace[this->m_EmpNum + i] = worker;
        }

        /* 释放原有空间 */
        delete[] this->m_EmpArray;

        /* 更改新空间指向 */
        this->m_EmpArray = newSpace;

        /* 更改新的职工数 */
        this->m_EmpNum = new_Num;

        /* 将新的职工数据保存到文件中 */
        this->save();

        /* 提示文件不为空 */
        this->m_FileIsEmpty = false;

        /* 提示添加成功 */
        cout << "成功添加" << add_Num << "名新员工!" << endl;
    }

    /* 提示清屏 */
    wait();
}

void workerManager::save()
{
    ofstream ofs;
    ofs.open(FILENAME, ios::out); // 以写的方式打开文件

    /* 将每个职工的数据写入文件 */
    for (int i = 0; i < this->m_EmpNum; i++)
    {
        ofs << this->m_EmpArray[i]->m_Id << " "
            << this->m_EmpArray[i]->m_Name << " "
            << this->m_EmpArray[i]->m_DeptId << endl;
    }
    ofs.close();
}

/* 统计人数 */
int workerManager::get_EmpNum()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int Id;
    string Name;
    int DeptId;

    int num = 0;

    while (ifs >> Id && ifs >> Name && ifs >> DeptId)
    {
        /* 统计人数 */
        num++;
    }
    return num;
}

/* 初始化职工 */
void workerManager::Emp_Init()
{
    ifstream ifs;
    ifs.open(FILENAME, ios::in);

    int Id;
    string Name;
    int DeptId;

    int index = 0;
    while (ifs >> Id && ifs >> Name && ifs >> DeptId)
    {
        Worker *worker = NULL;

        if (DeptId == 1)
        {
            worker = new Employee(Id, Name, DeptId);
        }
        else if (DeptId == 2)
        {
            worker = new Manager(Id, Name, DeptId);
        }
        else
        {
            worker = new Boss(Id, Name, DeptId);
        }

        this->m_EmpArray[index] = worker;
        index++;
    }

    /* 关闭文件 */
    ifs.close();
}

/* 显示员工 */
void workerManager::Show_Emp()
{
    /* 判断文件是否为空 */
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或未添加职工！" << endl;
    }
    else
    {
        for (int i = 0; i < this->m_EmpNum; i++)
        {
            this->m_EmpArray[i]->Show_Info();
        }
    }
    wait();
}

/* 判断职工是否存在，如果存在返回其在数组中的位置，否则返回-1 */
int workerManager::IsExist(int id)
{
    int index = -1;

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (id == this->m_EmpArray[i]->m_Id)
        {
            index = i;
            break;
        }
    }
    return index;
}

/* 删除职工 */
void workerManager::Del_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或未添加职工！" << endl;
    }
    else
    {
        /* 按照职工编号删除职工 */
        cout << "请输入要删除的职工编号： " << endl;
        int id;
        cin >> id;

        int index = this->IsExist(id);
        if (index == -1)
        {
            cout << "删除失败，未找到职工！" << endl;
        }
        else
        {
            for (int i = index; i < this->m_EmpNum - 1; i++)
            {
                /* 数据前移 */
                this->m_EmpArray[i] = this->m_EmpArray[i + 1];
            }

            /* 更新职工数 */
            this->m_EmpNum--;

            /* 保存到文件 */
            this->save();

            cout << "删除成功！" << endl;
        }
    }
    wait();
}

/* 修改职工 */
void workerManager::Mod_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或未添加职工！" << endl;
    }
    else
    {
        /* 按照职工编号修改职工 */
        cout << "请输入要修改的职工编号： " << endl;
        int id;
        cin >> id;

        int index = this->IsExist(id);
        if (index == -1)
        {
            cout << "修改失败，未找到职工！" << endl;
        }
        else
        {
            cout << "查到第" << index << "个职工，请输入新的信息: " << endl;

            /* 职工数据 */
            int Id;      // 职工Id
            string Name; // 职工名称
            int DeptId;  // 职工部门

            cout << "请输入要修改的编号: " << endl;
            cin >> Id;

            /* 当存在重复编号且不是当前要修改的职工时 */
            if ((this->IsExist(Id) != -1) && (this->m_EmpArray[this->IsExist(Id)]->m_Id != Id))
            {
                cout << "输入错误！" << endl;
                wait();
                return;
            }

            cout << "请输入要修改的姓名: " << endl;
            cin >> Name;

            /* 注意！！！这里可能会使对象的类发生变化 */
            cout << "请输入要修改的职工的部门编号: " << endl;
            cout << "1.普通职工" << endl
                 << "2.经理" << endl
                 << "3.老板" << endl;
            cin >> DeptId;

            Worker *worker = NULL;
            switch (DeptId)
            {
            case 1:
                worker = new Employee(Id, Name, DeptId);
                break;
            case 2:
                worker = new Manager(Id, Name, DeptId);
                break;
            case 3:
                worker = new Boss(Id, Name, DeptId);
                break;
            default:
                cout << "输入错误！" << endl;
                break;
            }

            /* 删除原来的职工信息 */
            delete this->m_EmpArray[index];

            /* 更新数据到数组 */
            this->m_EmpArray[index] = worker;

            /* 保存到文件 */
            this->save();

            cout << "修改成功！" << endl;
        }
    }
    wait();
}

/* 判断职工姓名是否存在，如果存在返回1，否则返回0，
并将重名位置存入m_RenameArray，每次调用前数组元素赋值-1 */
int workerManager::IsRename(string name)
{
    /* flag用于判断是否存在重名，index是重名数组的索引 */
    int flag = 0;
    int index = 0;

    /* 初始化重名职工数组 */
    for (int i = 0; i < 5; i++)
    {
        this->m_RenameArray[i] = -1;
    }

    for (int i = 0; i < this->m_EmpNum; i++)
    {
        if (name == this->m_EmpArray[i]->m_Name)
        {
            flag = 1;
            if (index > 4)
            {
                cout << "还存在更多重名..." << endl;
                break;
            }
            this->m_RenameArray[index] = i;
            index++;
        }
    }
    return flag;
}

/* 查找职工 */
void workerManager::Find_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或未添加职工！" << endl;
    }
    else
    {
        cout << "请选择查找的方式：" << endl;
        cout << "1.按职工编号查找" << endl;
        cout << "2.按姓名查找" << endl;

        int select;
        cin >> select;
        if ((select != 1) && (select != 2))
        {
            cout << "输入错误！" << endl;
            wait();
            return;
        }

        if (select == 1)
        {
            cout << "请输入要查找的职工编号：" << endl;
            int Id;
            cin >> Id;

            if (this->IsExist(Id) == -1)
            {
                cout << "查无此人！" << endl;
            }
            else
            {
                cout << "以下职工符合要求：" << endl;
                this->m_EmpArray[this->IsExist(Id)]->Show_Info();
            }
        }
        else
        {
            cout << "请输入要查找的职工姓名：" << endl;
            string Name;
            cin >> Name;

            if (this->IsRename(Name))
            {
                /* 显示重名职工信息 */
                cout << "共有以下职工为此名：" << endl;
                for (int i = 0; i < 5; i++)
                {
                    if (this->m_RenameArray[i] == -1)
                    {
                        /* 跳过空的重名数组元素 */
                        continue;
                    }
                    this->m_EmpArray[this->m_RenameArray[i]]->Show_Info();
                }
            }
            else
            {
                cout << "查无此人！" << endl;
            }
        }
    }
    wait();
}

/* 排序职工 */
void workerManager::Sort_Emp()
{
    if (this->m_FileIsEmpty)
    {
        cout << "文件不存在或未添加职工！" << endl;
    }
    else
    {
        /* 选择排序 */
        cout << "请选择排序方式：" << endl;
        cout << "1.按职工编号升序排列" << endl;
        cout << "2.按职工编号降序排列" << endl;

        int select;
        cin >> select;
        if((select != 1) && (select != 2))
        {
            cout << "输入错误！" << endl;
            wait();
            return;
        }

        for (int i = 0; i < this->m_EmpNum; i++)
        {
            /* 最小值或最大值下标 */
            int MinOrMax = i;
            for (int j = i + 1; j < this->m_EmpNum; j++)
            {
                /* 升序 */
                if (select == 1)
                {
                    if(this->m_EmpArray[MinOrMax]->m_Id > this->m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
                /* 降序 */
                else
                {
                    if(this->m_EmpArray[MinOrMax]->m_Id < this->m_EmpArray[j]->m_Id)
                    {
                        MinOrMax = j;
                    }
                }
            }
            /* 判断一开始认定的最小值或最大值是不是计算的最小值或最大值，如果不是，交换数据 */
            if(i != MinOrMax)
            {
                Worker* temp = this->m_EmpArray[i];
                this->m_EmpArray[i] = this->m_EmpArray[MinOrMax];
                this->m_EmpArray[MinOrMax] = temp;
            }         
        }
        cout << "排序成功！" << endl;
        this->save();
        this->Show_Emp();
    }
}

/* 清空文件 */
void workerManager::Clean_File()
{
    cout << "确定清空？" << endl;
    cout << "1.确定" << endl;
    cout << "2.取消" << endl;

    int select;
    cin >> select;

    if(select == 1)
    {
        /* 清空文件 */
        ofstream ofs(FILENAME, ios::trunc); //删除文件后重新创建
        ofs.close();

        if(this->m_EmpArray != NULL)
        {
            /* 删除堆区每个职工对象 */
            for (int i = 0; i < this->m_EmpNum; i++)
            {
                delete this->m_EmpArray[i];
                this->m_EmpArray[i] = NULL;
            }

            /* 删除堆区指针数组 */
            delete[] this->m_EmpArray;
            this->m_EmpNum = 0;
            this->m_FileIsEmpty = true;
            cout << "清空成功！" << endl;
        }
        wait();
    }
    else if(select == 2)
    {
        cout << "取消删除" << endl;
        wait();
        return;
    }
    else
    {
        cout << "输入错误！" << endl;
        wait();
        return;
    }
    
}

workerManager::~workerManager()
{
}
