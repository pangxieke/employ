#ifndef STUDY_WORKER_H
#define STUDY_WORKER_H

#include <iostream>

using namespace std;

class Worker
{
public:
    Worker(int id,string name,int dId);
    ~Worker();

    void showInfo() ;

    string getDeptName();

public:
    //职工编号
    int Id;
    //职工姓名
    string Name;
    //职工所在部门名称编号
    int DeptId;
};

#endif //STUDY_WORKER_H
