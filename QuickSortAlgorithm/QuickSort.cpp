#include <windows.h>
#include <iostream>
#include <vector>

using namespace std;
void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}
// using the Vecotrs
vector<int> QuickSortFunction_Vectors(vector<int> val)
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
    LessArr = QuickSortFunction_Vectors(LessArr);
    GreaterArr = QuickSortFunction_Vectors(GreaterArr);

    LessArr.insert(LessArr.end(), EqualArr.begin(), EqualArr.end());
    LessArr.insert(LessArr.end(), GreaterArr.begin(), GreaterArr.end());

    return LessArr;
}

int Partition(vector<int> &val, int low, int high)
{
    int mid = low + (high - low) / 2;

    swap(val[mid], val[high]);
    int pivot = val[high];
    int CuurentSmallerNumber = low - 1;

    for (int j = low; j < high; j++)
    {
        if (val[j] <= pivot)
        {
            CuurentSmallerNumber++;
            swap(val[CuurentSmallerNumber], val[j]);
        }
    }
    swap(val[CuurentSmallerNumber + 1], val[high]);
    return CuurentSmallerNumber + 1;
}
void QuickSortFunction_InplacePointers(vector<int> &val, int low, int high)
{
    if (low < high)
    {

        int PivotIndex = Partition(val, low, high);
        QuickSortFunction_InplacePointers(val, low, PivotIndex - 1);
        QuickSortFunction_InplacePointers(val, PivotIndex + 1, high);
    }
}

int main()
{

    vector<int> val = {1, 2, 35, 689, 86, 56, 56, 256, 53, 2, 35, 6, 53, 2, 32, 36, 56, 546, 2, 32, 3, 26, 5, 32, 32, 3};
    val = QuickSortFunction_Vectors(val);
    cout << endl
         << endl;
    for (int x : val)
        cout << x << " ";
    vector<int> val2 = {1, 2, 35, 689, 86, 56, 56, 256, 53, 2, 35, 6, 53, 2, 32, 36, 56, 546, 2, 32, 3, 26, 5, 32, 32, 3};
    QuickSortFunction_InplacePointers(val2, 0, val2.size() - 1);
    cout << endl
         << endl;
    for (int x : val2)
        cout << x << " ";
}