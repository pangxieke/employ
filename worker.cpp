#include "worker.h"

Worker::Worker(int id, string name, int depId)
{
    this->Id = id;
    this->Name = name;
    this->DeptId = depId;
}

//显示个人信息，纯虚函数
void Worker::showInfo()
{
    cout << "职工编号：" << this->Id << endl;
    cout << "职工姓名：" << this->Name << endl;
    cout << "职工岗位：" << this->getDeptName() << endl;//调用函数要加括号
    cout << "岗位职责：完成任务" << endl;
}

//获取岗位名称，纯虚函数
string Worker::getDeptName()
{
    return string("worker");
}