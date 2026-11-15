#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;

vector<int> QuickSortFunction(vector<int> val, unsigned int vl)
{

    if (val.size() < 2)
        return val;
    int pivot = val[val.size() / 2];
    vector<int> LessArr;
    vector<int> GreaterArr;
    vector<int> EqualArr;
for (int i = 0; i < val.size(); i++)
    {
        if (val[i] < pivot)
            LessArr.push_back(val[i]);
        else if (val[i] > pivot)
            GreaterArr.push_back(val[i]);
        else
            EqualArr.push_back(val[i]); // Keeps all duplicates without recursing on them
    }
    LessArr = QuickSortFunction(LessArr, vl + 1);
    GreaterArr = QuickSortFunction(GreaterArr, vl + 1);

    LessArr.insert(LessArr.end(), EqualArr.begin(), EqualArr.end());
    LessArr.insert(LessArr.end(), GreaterArr.begin(), GreaterArr.end());

    return LessArr;
}
int main()
{
    cout<<"HELLLOOO"<<endl;
    vector<int> val = {1, 2, 35, 689, 86, 56, 56,256,53,2,35,6,53,2,32,36,56,546,2,32,3,26,5,32,32,3};
    val = QuickSortFunction(val, 0);
    cout<<endl<<endl;
    for (int i = 0; i < val.size(); i++)
    {

        cout<< val[i]<<"  "; 
    }
}