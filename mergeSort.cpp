#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr, int start, int end)
{
    // here we are first making a temp array(v)
    vector<int> v;
    v.reserve(end - start + 1);
    int mid = start + (end - start) / 2;
    int i = start;
    int j = mid + 1;
    // filling the temp array, by getting the smallest element available in both the arrays
    while (i <= mid and j <= end)
    {
        // eg  arr1 = 1 5 7 9 , i = 0
        //     arr2 = 3 4 8 9 , j = 0
        // take arr1[i] and then i++
        // I have done it in single line only 
        if (arr[i] <= arr[j])
        {
            v.push_back(arr[i++]);
        }
        else
        {
            v.push_back(arr[j++]);
        }
    }
    // now the above loop is over that means 
    // either i == mid or j == end
    // therefore we need to fill the remaining elements
    while (i <= mid)
    {
        v.push_back(arr[i++]);
    }
    while (j <= end)
    {
        v.push_back(arr[j++]);
    }
    // now copy back the elements of the temp array to the original array
    // NOTE: v is starting from 0, where as array arr is to be filled from start 
    // so we do [p-start] to do filling.
    for (int p = start; p <= end; p++)
    {
        arr[p] = v[p - start];
    }
    return;
}

void mergeSort(vector<int> &arr, int start, int end)
{
    // cout << start << " " << end << endl;
    if (start >= end) // single element encountered 
        return;
    int mid = start + (end - start) / 2;
    // first sort the 
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, start, end);
}

int main()
{

    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    cout << endl;
    mergeSort(v, 0, v.size() - 1);
    for (auto x : v)
        cout << x << " ";

    // cout << "Menu " << endl;

    // cout << "1. Enter 1 for best case. " << endl;
    // cout << "2. Enter 2 for average case. " << endl;
    // cout << "3. Enter 3 for worst case. " << endl;
    // cout << "4. Enter -1 to exit. " << endl;

    // int t;
    // while(cin >> t) {
    //     if(t == -1) break;
    //     int n = 20000;
    //     if(t == 1) {

    //     }
    //     else if(t == 2) {

    //     }
    //     else if(t == 3) {

    //     }

    // }

    return 0;
}
