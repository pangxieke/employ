#include <iostream>
#include "workManager.h"

using namespace std;
int main()
{
    std::cout << "server start" << std::endl;
    WorkManager wm;
    wm.showMenu();
    int choice = 0;

    while (true)
    {
        cout << "Please select: " << endl;
        cin >> choice;
        switch (choice) {
            case 0:
                wm.exitSystem();
                break;
            case 1:
                wm.addEmp();
                break;
            case 2:
                wm.showEmp();
                break;
            case 3:
                wm.delEmp();
                break;
            case 4:
                wm.updateEmp();
                break;
            default:
                cout << "Not found, exit!" << endl;
                exit(0);
                break;
        }
    }
}