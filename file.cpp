#include "file.h"

Worker ** File::Read(string filename) {
    //文件行数
    int line;
    line = this->CountLines(filename);
    Worker ** empArray = new Worker*[line];

    ifstream outfile;
    outfile.open(filename, ios::in);
    //文件不存在 || 文件为空
    if (!outfile.is_open() || outfile.eof())
    {
        //init
        outfile.close();
        return empArray;
    }

    int id;
    string name;
    int dId;
    int index = 0;
    while (outfile >> id && outfile >> name && outfile >> dId)
    {
        Worker * worker = NULL;
        worker = new Worker(id, name, dId);
        empArray[index] = worker;

        index++;
    }
    outfile.close();

    return empArray;
}

//统计行数
int File::CountLines(string filename) {
    ifstream ReadFile;
    int n = 0;
    string tmp;
    ReadFile.open(filename, ios::in);//ios::in 表示以只读的方式读取文件
    //文件打开成功
    if (ReadFile.fail())
    {
        n = 0;
    }else
    {
        while (getline(ReadFile, tmp, '\n')) {
            n++;
        }
    }
    ReadFile.close();
    return n;
}
