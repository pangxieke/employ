#ifndef STUDY_WORKMANAGER_H
#define STUDY_WORKMANAGER_H

#include <iostream>
#include <fstream>
#include "worker.h"

#define FILENAME "data.txt"

//使用标准的命名空间
using namespace std;

class WorkManager {

public:
    //构造函数
    WorkManager();
    //析构函数
    ~WorkManager();

    //退出系统
    void exitSystem();
    //菜单
    void showMenu();
    //添加职工
    void addEmp();
    //显示职工信息
    void showEmp();
    //删除职工信息
    void delEmp();
    //修改职工
    void updateEmp();

private:
    //职工人数
    int num;
    //职工数组的指针
    Worker ** empArray;

    //用于判断职工是否存在，如果存在则返回职工所在数组中的位置，不存在返回-1
    int isExist(int id);

    //存储数据
    void save();
};


#endif //STUDY_WORKMANAGER_H
