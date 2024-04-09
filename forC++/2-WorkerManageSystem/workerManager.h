#pragma once
#include <iostream>
using namespace std;
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

class workerManager
{
public:
    /* 构造函数 */
    workerManager();

    /* 显示菜单 */
    void Show_Menu();

    /* 退出系统 */
    void exit_System();

    /* 添加职工函数 */
    void add_Emp();

    /* 保存到文件 */
    void save();

    /* 统计人数 */
    int get_EmpNum();

    /* 初始化职工 */
    void Emp_Init();

    /* 显示职工 */
    void Show_Emp();

    /* 判断职工是否存在，如果存在返回其在数组中的位置，否则返回-1 */
    int IsExist(int id);

    /* 删除职工 */
    void Del_Emp();

    /* 修改职工 */
    void Mod_Emp();

    /* 判断职工姓名是否存在，如果存在返回1，否则返回0，
    并将重名位置存入m_RenameArray，每次调用前数组元素赋值-1 */
    int IsRename(string name);

    /* 查找职工 */
    void Find_Emp();

    /* 排序职工 */
    void Sort_Emp();

    /* 清空文件 */
    void Clean_File();

    /* 析构函数 */
    ~workerManager();

    /* 职工人数 */
    int m_EmpNum;

    /* 职工重名数组，最多支持5人，-1代表空位 */
    int m_RenameArray[5];

    /* 职工数组指针 */
    Worker **m_EmpArray;

    /* 标志文件是否为空 */
    bool m_FileIsEmpty;
};
