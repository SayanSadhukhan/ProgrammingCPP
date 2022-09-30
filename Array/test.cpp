#include <iostream>
using namespace std;
int main()
{
    int *nums;
    nums = new int;
    int a;
    int i = 0;
    while (cin >> a)
    {
        nums[i++] = a;
    }
i = 0;
    // do your output
    for(i = 0; i < 5; i++) cout<<nums[i]<<" ";
    cout<<endl;
    return 0;
}