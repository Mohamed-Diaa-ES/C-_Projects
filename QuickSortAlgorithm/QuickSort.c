#include <stdio.h>

void swap(int *p1, int *p2)
{
    int temp = *p1;
    *p1 = *p2;
    *p2 = temp;
}

int Partition(int *val, int low, int high)
{
    int mid = low + (high - low) / 2;

    swap(val+mid, val+high);
    int pivot = val[high];
    int CuurentSmallerNumber = low - 1;

    for (int j = low; j < high; j++)
    {
        if (val[j] <= pivot)
        {
            CuurentSmallerNumber++;
            swap(val + CuurentSmallerNumber, val + j);
        }
    }
    swap(val + CuurentSmallerNumber+1, val + high);
    return CuurentSmallerNumber + 1;
}
void QuickSortFunction_InplacePointers(int *val, int low, int high)
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

    int val[20] = {20, 19, 18, 17, 16, 15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    QuickSortFunction_InplacePointers(val, 0, 20);

    for(int i=0;i<20;i++)
    {
        printf("%d  ",val[i]);
    }
}