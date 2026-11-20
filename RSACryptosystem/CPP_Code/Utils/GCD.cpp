#include <iostream>

using namespace std;
int returnAbsValue(int val)
{
    return (val >= 0) ? val : -val;
}
void swap(int &v1, int &v2)
{
    int temp = v1;
    v1 = v2;
    v2 = temp;
}

void findGCD(int a, int b,int r)
{
    // setting them as absolute:
    a = returnAbsValue(a);
    b = returnAbsValue(b);

    if (b == a)
    {
        cout << "Two numbers are alike then the output is: " << a << endl;
       return ;
    }
    else if ((b % a) == 0 || (a % b) == 0)
    {
        cout << "Two numbers are mulitples of each other then the output is: " << (a < b ? a : b) << endl;
       return ;
    }

    if (a < b)
    {
        swap(a, b);
    }
    while (true)
    {

        r = a % b;
        if (r > 0)
        {
            a = b;
            b = r;
        }
        else
        {
            break;
        }
    }
    cout << "The result of GCD is: " << a << endl;
}
int main()
{
    int a, b, r;

    cout << "Enter Two Integers: (a,b) " << endl;
    cin >> a;
    cin >> b;

    findGCD(a,b,r);

   return 0;
}