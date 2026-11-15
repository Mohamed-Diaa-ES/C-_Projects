#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> QuickSortFunction(vector<int> val)
{


    if (val.size() < 2)
        return val;
    int pivot = val[val.size() / 2];
    vector<int> LessArr;
    vector<int> GreaterArr;
    for (int i = 0; i < val.size(); i++)
    {
        if (val[i] < pivot)
        {
            LessArr.push_back(val[i]);
        }
        else if (val[i] > pivot)
        {

            GreaterArr.push_back(val[i]);
        }
    }

    vector<int>ResultToReturn ;
    
}
int TestQuickSort()
{

}

extern "C" void _start(void)
{
    TestQuickSort();

    // You MUST manually exit via a syscall, because returning from _start will segfault!
    ExitProcess(0);
}
