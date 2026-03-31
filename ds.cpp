// Question 1: 977. Squares of a Sorted Array
// Given an integer array nums sorted in non-decreasing order, return an array
// of the squares of each number sorted in non-decreasing order.
//
// Example 1:
// Input: nums = [-4, -1, 0, 3, 10]
// Output: [0, 1, 9, 16, 100]
//
// Example 2:
// Input: nums = [-7, -3, 2, 3, 11]
// Output: [4, 9, 9, 49, 121]
//
// Solution:
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

// Question 2: 20. Valid Parentheses
// Given a string s containing just the characters '(', ')', '{', '}', '['
// and ']', determine if the input string is valid.
//
// An input string is valid if:
// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
//
// Solution:
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

// Question 3: 21. Merge Two Sorted Lists
// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by
// splicing together the nodes of the first two lists.
// Return the head of the merged linked list.
//
// Solution:
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

// Question 4: 22. Generate Parentheses
// Given n pairs of parentheses, write a function to generate all combinations
// of well-formed parentheses.
//
// Example 1:
// Input: n = 3
// Output: ["((()))","(()())","(())()","()(())","()()()"]
//
// Example 2:
// Input: n = 1
// Output: ["()"]
//
// Solution:
class Solution {
public:
    void backtrack(int n, int open, int close, string& curr, vector<string>& res) {
        if ((int)curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, res);
            curr.pop_back();
        }

        if (close < open) {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string curr;
        backtrack(n, 0, 0, curr, res);
        return res;
    }
};

// Question 5: 26. Remove Duplicates from Sorted Array
// Given an integer array nums sorted in non-decreasing order, remove the
// duplicates in-place such that each unique element appears only once.
// The relative order of the elements should be kept the same.
//
// Return the number of unique elements in nums.
//
// Solution:
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

// Question 6: 27. Remove Element
// Given an integer array nums and an integer val, remove all occurrences of val
// in nums in-place. The order of the elements may be changed.
// Return the number of elements in nums which are not equal to val.
//
// Solution:
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

// Question 7: 75. Sort Colors
// Given an array nums with n objects colored red, white, or blue, sort them
// in-place so that objects of the same color are adjacent in the order
// red, white, and blue.
//
// Solution:
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) {
                mid++;
            } else {
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

// Question 8: Count Triplets With Sum Smaller Than Target
// Given an array arr[] of distinct integers of size n and a value sum,
// find the count of triplets (i, j, k), where i < j < k and
// arr[i] + arr[j] + arr[k] is smaller than the given value sum.
//
// Example 1:
// Input: n = 4, sum = 2, arr[] = {-2, 0, 1, 3}
// Output: 2
//
// Example 2:
// Input: n = 5, sum = 12, arr[] = {5, 1, 3, 4, 7}
// Output: 4
//
// Solution:
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


// 143. Reorder List
// Medium
// Topics
// premium lock icon
// Companies
// You are given the head of a singly linked-list. The list can be represented as:

// L0 → L1 → … → Ln - 1 → Ln
// Reorder the list to be on the following form:

// L0 → Ln → L1 → Ln - 1 → L2 → Ln - 2 → …
// You may not modify the values in the list's nodes. Only nodes themselves may be changed.

// solution

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;

        // Step 1: Find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode* second = slow->next;
        slow->next = nullptr;
        ListNode* prev = nullptr;
        ListNode* curr = second;
        while (curr) {
            ListNode* nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        second = prev;

        // Step 3: Merge two halves
        ListNode* first = head;
        while (second) {
            ListNode* tmp1 = first->next;
            ListNode* tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};