#ifndef STUDY_FILE_H
#define STUDY_FILE_H

#include <iostream>
#include <fstream>
#include "worker.h"

using namespace std;

class File {

public:
//    File();
//    ~File();
    Worker ** Read(string filename);
    void Save();

    int CountLines(string filename);
};


#endif //STUDY_FILE_H
