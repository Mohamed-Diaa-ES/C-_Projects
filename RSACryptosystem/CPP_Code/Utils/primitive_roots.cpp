#include <iostream>

#include <vector>
#include <numeric>

using namespace std;

int main()
{
    long long n = 37;
    cout << "Enter a prime number: ";
    cin >> n;
    long long lastnumber = n - 1;

    vector<long long> primitiveRoots;

    for (long long a = 2; a < n; ++a)
    {
        long long current_power = 1;
        long long order = 0;

        for (long long m = 1; m <= lastnumber; ++m)
        {
            current_power = (current_power * a) % n;

            if (current_power == 1)
            {
                order = m;
                break;
            }
        }

        if (order == lastnumber)
        {
            primitiveRoots.push_back(a);
        }
    }

    cout << "we found  " << primitiveRoots.size() << " primitive roots for " << n << ":" << endl;
    for (size_t i = 0; i < primitiveRoots.size(); ++i)
    {
        cout << primitiveRoots[i] << ", ";
    }
    cout << endl;

    return 0;
}
