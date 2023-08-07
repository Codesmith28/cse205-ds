#include <bits/stdc++.h>
using namespace std;

vector<int> findAns(vector<vector<int>> arr, int target)
{
    int row = 0;
    int col = arr[row].size() - 1;
    while (row < arr.size() && col >= 0)
    {
        if (arr[row][col] == target)
        {
            return {row, col};
        }

        // Target lies in further row
        if (arr[row][col] < target)
        {
            row++;
        }
        // Target lies in previous column
        else
        {
            col--;
        }
    }
    return {-1, -1};
}

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    // binary search in 2d matrix
    vector<int> ans = findAns(matrix, target);
    bool flag = false;

    // cout << "Element found at index: [";
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     if (i == ans.size() - 1)
    //         cout << ans[i];
    //     else
    //         cout << ans[i] << ", ";
    // }
    // cout << "]";

    if (ans[0] == -1 && ans[1] == -1)
        flag = false;
    else
        flag = true;

    return flag;
}

int main()
{
    vector<vector<int>> arr = {{1, 4, 7, 11, 15},
                               {2, 5, 8, 12, 19},
                               {3, 6, 9, 16, 22},
                               {10, 13, 14, 17, 24},
                               {18, 21, 23, 26, 30}};

    int target = 69;

    // check if both the elements are not -1 at the same time:

    cout << searchMatrix(arr, target) << endl;

    return 0;
}