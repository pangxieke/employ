#include "workManager.h"
#include "file.h"

WorkManager::WorkManager() {
    cout << "workManager start" << endl;

    //init data form file or db
    Worker ** empArray;
    File f;
    empArray = f.Read(FILENAME);
    this->empArray = empArray;

    num = f.CountLines(FILENAME);
    this->num = f.CountLines(FILENAME);
}

WorkManager::~WorkManager() {
    cout << "workManager stop" << endl;
}

void WorkManager::showMenu()
{
    cout << "**************************" << endl;
    cout << "**欢迎使用员工管理系统！**" << endl;
    cout << "******0.退出管理系统******" << endl;
    cout << "******1.增加员工信息******" << endl;
    cout << "******2.显示员工信息******" << endl;
    cout << "******3.删除离职员工******" << endl;
    cout << "******4.修改员工信息******" << endl;
    cout << "**************************" << endl;
    cout << endl;
}

void WorkManager::exitSystem()
{
    cout << "workManager exit!" << endl;
    //调用系统命令
    system("pause");
    exit(0);
}

void WorkManager::addEmp()
{
    int addNum = 0;
    cout << "请输入添加职工数量：" << endl;
    cin >> addNum;

    if (addNum <= 0)
    {
        cout << "输入有误" << endl;
        return;
    }
    //新空间大小 = 原来人数 + 新增人数
    int size = this->num + addNum;
    //开辟新空间
    Worker ** newSpace = new Worker*[size];

    //将原来的空间下数据，拷贝到新空间下
    if (this->num > 0){
        for(int i = 0; i < this->num; i++)
        {
            newSpace[i] = this->empArray[i];
        }
        delete [] this->empArray;
    }

    //疲劳添加新的数据
    for (int i = 0; i < addNum; i++) {
        int id;//职工编号
        string name;//职工姓名
        int dSelect;//部门编号选择
        cout << "请输入第 " << i + 1 << "个新职工的编号：" << endl;
        cin >> id;
        cout << "请输入第 " << i + 1 << "个新职工的姓名：" << endl;
        cin >> name;
        cout << "请选择该职工的一个岗位：" << endl;
        cout << "1.普通员工" << endl;
        cout << "2.经理" << endl;
        cout << "3.老板" << endl;
        cin >> dSelect;
        Worker *worker = NULL;
        worker = new Worker(id, name, dSelect);

        newSpace[this->num] = worker;
        this->num += 1;
    }
    this->empArray = newSpace;

    cout << "成功添加" <<addNum<<"名新职工！"<< endl;//提示添加成功
    this->save();
}

void WorkManager::showEmp()
{
    if(this->num > 0)
    {
        for(int i = 0; i < this->num; i++)
        {
            this->empArray[i]->showInfo();
        }
    }
}

void WorkManager::updateEmp()
{
    if(this->num <= 0){
        cout << "记录为空" << endl;
        return;
    }
    cout << "请输入修改职工的编号：" << endl;
    int id;
    cin >> id;

    //判断是否存在
    int index = this->isExist(id);
    if(index == -1){
        cout << "记录不存在" << endl;
        return;
    }

    int newId = 0;
    string newName = "";
    int dSelect = 0;

    cout << "查到" << id << "号职工，请输入新职工号：" << endl;
    cin >> newId;

    cout << "请输入新姓名：" << endl;
    cin >> newName;

    cout << "请输入岗位：" << endl;
    cout << "1.普通员工" << endl;
    cout << "2.经理" << endl;
    cout << "3.老板" << endl;
    cin >> dSelect;

//    delete this->empArray[id];
    Worker * worker = new Worker(newId, newName, dSelect);
    this->empArray[index] = worker;

    this->save();
}

void WorkManager::delEmp()
{
    cout << "请输入想要删除的员工编号:" << endl;
    int id;
    cin >> id;

    //判断是否存在
    int index = this->isExist(id);
    if(index == -1){
        cout << "记录不存在" << endl;
        return;
    }
    this->empArray[index] = NULL;
    this->num --;
    this->save();
}


int WorkManager::isExist(int id) {
    int index = -1;
    for(int i = 0; i < this->num; i++)
    {
        if(this->empArray[i]->Id == id)
        {
            index = i;
            break;
        }
    }
    return index;
}

void WorkManager::save()
{
    if(this->num <= 0)
    {
        return;
    }
    ofstream outfile;
    //用输出的方式来打开文件 -- 写文件
    outfile.open(FILENAME, ios::out);

    for(int i = 0; i < this->num; i++)
    {
        outfile << this->empArray[i]->Id << " "
                << this->empArray[i]->Name << " "
                << this->empArray[i]->DeptId << endl;
    }
    outfile.close();
}