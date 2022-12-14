#include<iostream>
using namespace std;
int main()
{
    static int arr[] = {1,3,5};
    cout<<arr[-1]<<arr[5];
    return 0;
}