// 977. Squares of a Sorted Array
// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.
// Example 1:

// Input: nums = [-4,-1,0,3,10]
// Output: [0,1,9,16,100]
// Explanation: After squaring, the array becomes [16,1,0,9,100].
// After sorting, it becomes [0,1,9,16,100].
// Example 2:

// Input: nums = [-7,-3,2,3,11]
// Output: [4,9,9,49,121]
 
// Constraints:

// 1 <= nums.length <= 104
// -104 <= nums[i] <= 104
// nums is sorted in non-decreasing order.


solution

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        int k = n - 1;

        while (l <= r) {
            int leftSq = nums[l] * nums[l];
            int rightSq = nums[r] * nums[r];

            if (leftSq > rightSq) {
                ans[k] = leftSq;
                l++;
            } else {
                ans[k] = rightSq;
                r--;
            }
            k--;
        }

        return ans;
    }
};


// 20. Valid Parentheses
// Solved
// Easy
// Topics
// premium lock icon
// Companies
// Hint
// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.


solution:-

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (char c : s) {
            if (c == '(' || c == '{' || c == '[') {
                st.push(c);
            } else {
                if (st.empty()) return false;
                char top = st.top();
                st.pop();
                if (c == ')' && top != '(') return false;
                if (c == '}' && top != '{') return false;
                if (c == ']' && top != '[') return false;
            }
        }
        return st.empty();
    }
};

21. Merge Two Sorted Lists
Solved
Easy
Topics
premium lock icon
Companies
You are given the heads of two sorted linked lists list1 and list2.

Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

Return the head of the merged linked list.

solution:-

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        if (!list1) return list2;
        if (!list2) return list1;
        if (list1->val <= list2->val) {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        } else {
            list2->next = mergeTwoLists(list1, list2->next);
            return list2;
        }
    }
};

22. Generate Parentheses
Medium
Topics
premium lock icon
Companies
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

 

Example 1:

Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]
Example 2:

Input: n = 1
Output: ["()"]

solution:-
class Solution {
public:
    void backtrack(int n, int open, int close, string &curr, vector<string> &res) {
        // If the current string has length 2*n, it's a complete combination
        if ((int)curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        // Try to add '(' if we still can
        if (open < n) {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, res);
            curr.pop_back(); // backtrack
        }

        // Try to add ')' if it won't make it invalid (close < open)
        if (close < open) {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, res);
            curr.pop_back(); // backtrack
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(n, 0, 0, curr, res);
        return res;
    }
};


26. Remove Duplicates from Sorted Array
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums sorted in non-decreasing order, remove the duplicates in-place such that each unique element appears only once. The relative order of the elements should be kept the same.

Consider the number of unique elements in nums to be k​​​​​​​​​​​​​​. After removing duplicates, return the number of unique elements k.

The first k elements of nums should contain the unique numbers in sorted order. The remaining elements beyond index k - 1 can be ignored.

Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int[] expectedNums = [...]; // The expected answer with correct length

int k = removeDuplicates(nums); // Calls your implementation

assert k == expectedNums.length;
for (int i = 0; i < k; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

solution

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int k = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

27. Remove Element
Easy
Topics
premium lock icon
Companies
Hint
Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
Return k.
Custom Judge:

The judge will test your solution with the following code:

int[] nums = [...]; // Input array
int val = ...; // Value to remove
int[] expectedNums = [...]; // The expected answer with correct length.
                            // It is sorted with no values equaling val.

int k = removeElement(nums, val); // Calls your implementation

assert k == expectedNums.length;
sort(nums, 0, k); // Sort the first k elements of nums
for (int i = 0; i < actualLength; i++) {
    assert nums[i] == expectedNums[i];
}
If all assertions pass, then your solution will be accepted.

 solution:

 class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};

75. Sort Colors
Medium
Topics
premium lock icon
Companies
Hint
Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.

We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.

You must solve this problem without using the library's sort function.

 

Example 1:

Input: nums = [2,0,2,1,1,0]
Output: [0,0,1,1,2,2]
Example 2:

Input: nums = [2,0,1]
Output: [0,1,2]

solution

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++; mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

 55.Given an array arr[] of distinct integers of size n and a value sum, the task is to find the count of triplets (i, j, k), having (i<j<k) with the sum of (arr[i] + arr[j] + arr[k]) smaller than the given value sum.

Examples :

Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with sum less than 2 (-2, 0, 1) and (-2, 0, 3). 
Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
Output: 4
Explanation: Below are triplets with sum less than 12 (1, 3, 4), (5, 1, 3), (1, 3, 7) and (5, 1, 4).

solution:-

class Solution {
  public:
    long long countTriplets(int n, long long sum, long long arr[]) {
        sort(arr, arr + n);
        long long count = 0;
        for (int i = 0; i < n - 2; i++) {
            int left = i + 1, right = n - 1;
            while (left < right) {
                if (arr[i] + arr[left] + arr[right] < sum) {
                    count += (right - left);
                    left++;
                } else {
                    right--;
                }
            }
        }
        return count;
    }
};