#include <bits/stdc++.h>
using namespace std;

int floor(vector<int> &arr, int n, int x) //floor function finds the greatest element less than or equal to x.
{
    int left = 0, right = n - 1;
    int ans = -1; // Default to -1 if no floor exists

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] <= x)
        {
            ans = mid; // Potential answer found
            left = mid + 1; // Look for a larger index
        }
        else
        {
            right = mid - 1; // Move to the left half
        }
    }

    return ans;
}

int ceil(vector<int> &arr, int n, int x) //ceil function finds the smallest element greater than or equal to x.
{ //same like lower_bound function
    int left = 0, right = n - 1;
    int ans = n; // Default to n if no ceil exists

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] >= x)
        {
            ans = mid; // Potential answer found
            right = mid - 1; // Look for a smaller index
        }
        else
        {
            left = mid + 1; // Move to the right half
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1, 2, 4, 6, 8, 10};
    int n = arr.size();
    int x = 5;

    int flr = floor(arr, n, x);
    int cl = ceil(arr, n, x);

    if (flr != -1)
        cout << "Floor of " << x << " is at index: " << flr << " (Value: " << arr[flr] << ")" << endl;
    else
        cout << "No floor exists for " << x << endl;

    if (cl != n)
        cout << "Ceil of " << x << " is at index: " << cl << " (Value: " << arr[cl] << ")" << endl;
    else
        cout << "No ceil exists for " << x << endl;

    return 0;
}

