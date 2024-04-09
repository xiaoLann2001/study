#pragma once
#include <iostream>
using namespace std;
#include "worker.h"

/* 老板类 */
class Boss : public Worker
{
public:
    /* 显示个人信息 */
    virtual void Show_Info();

    /* 获取岗位名称 */
    virtual string getDeptName();

    /* 构造函数 */
    Boss(int Id, string Name, int DeptId);
    ~Boss();
};