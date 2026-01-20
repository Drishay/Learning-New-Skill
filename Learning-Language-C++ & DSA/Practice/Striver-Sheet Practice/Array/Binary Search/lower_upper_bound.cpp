#include <bits/stdc++.h>
using namespace std;

int lower_bound(vector<int> &arr, int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n; // Default to n if x is greater than all elements

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
int upper_bound(vector<int> &arr, int n, int x)
{
    int left = 0, right = n - 1;
    int ans = n; // Default to n if x is greater than or equal to all elements

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] > x)
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
    vector<int> arr = {1, 2, 2, 2, 3, 4, 5};
    int n = arr.size();
    int x = 2;

    int lb = lower_bound(arr, n, x);
    int ub = upper_bound(arr, n, x);

    cout << "Lower Bound of " << x << " is at index: " << lb << endl;
    cout << "Upper Bound of " << x << " is at index: " << ub << endl;

    return 0;
}


/*
stl shortcut for lower_bound and upper_bound:
// int lb = lower_bound(arr.begin(), arr.end(), x) - arr.begin();
// int ub = upper_bound(arr.begin(), arr.end(), x) - arr.begin();
*/

