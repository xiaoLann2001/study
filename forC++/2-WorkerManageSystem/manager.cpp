#include "manager.h"

/* 构造函数 */
Manager::Manager(int Id, string Name, int DeptId)
{
    this->m_Id = Id;
    this->m_Name = Name;
    this->m_DeptId = DeptId;
}

/* 显示个人信息 */
void Manager::Show_Info()
{
    cout << "职工编号: " << this->m_Id
         << "\t职工姓名: " << this->m_Name
         << "\t岗位: " << this->m_DeptId
         << "\t岗位职责: 完成老板交给的任务,并下发任务给员工" << endl;
}

/* 获取岗位名称 */
string Manager::getDeptName()
{
    return string("经理");
}