#include <bits/stdc++.h>
using namespace std;
#define int long long

void insertionSort(vector<int> v) {
    int n = v.size();

    // insertion sort
    // start from first index and look the correct place for it
    // by using while loop which can end when we are at the leftmost
    // point or we have already found the location

    for (int i = 1; i < n; i++)
    {
        int key = v[i];
        int j = i - 1;
        while (j >= 0 and v[j] > key)
        {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = key;
    }

    // for (auto val : v)
    // {
    //     cout << val << " ";
    // }
    cout << endl;
}

int32_t main()
{
    cout << "Menu "  << endl;

    cout << "1. Enter 1 for best case. " << endl;
    cout << "2. Enter 2 for average case. " << endl;
    cout << "3. Enter 3 for worst case. " << endl;
    cout << "4. Enter -1 to exit. " << endl;

    int t; 
    while(cin >> t) {
        if(t == -1) break;
        int n = 15000;
        vector<int> v(n);
        if(t ==  1) {
            for(int i = 0; i < n; i++) {
                v[i] = i;
                // cout << v[i] << " ";
            }
        }
        else if(t == 2) {
            for (int i = 0; i < n; i++)
            {
                v[i] = rand() % 100000;
                // cout << v[i] << " ";
            }
        }
        else {
            for (int i = 0; i < n; i++)
            {
                v[i] = n - i;
                // cout << v[i] << " ";
            }
        }
        clock_t start = clock();
        insertionSort(v);
        // cout << "pop";
        clock_t end = clock();
        cout << double(end - start) << "ms" << endl;
    }

  

    return 0;
}
// 1 1 1 best case
// 670 680 689 average case
// 1372 1379 1388 worst case
