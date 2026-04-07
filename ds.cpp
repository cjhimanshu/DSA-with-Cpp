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
class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> ans(n);
        int l = 0, r = n - 1;
        int k = n - 1;

        while (l <= r)
        {
            int leftSq = nums[l] * nums[l];
            int rightSq = nums[r] * nums[r];

            if (leftSq > rightSq)
            {
                ans[k] = leftSq;
                l++;
            }
            else
            {
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
class Solution
{
public:
    bool isValid(string s)
    {
        stack<char> st;
        for (char c : s)
        {
            if (c == '(' || c == '{' || c == '[')
            {
                st.push(c);
            }
            else
            {
                if (st.empty())
                    return false;
                char top = st.top();
                st.pop();
                if (c == ')' && top != '(')
                    return false;
                if (c == '}' && top != '{')
                    return false;
                if (c == ']' && top != '[')
                    return false;
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
class Solution
{
public:
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (!list1)
            return list2;
        if (!list2)
            return list1;
        if (list1->val <= list2->val)
        {
            list1->next = mergeTwoLists(list1->next, list2);
            return list1;
        }
        else
        {
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
class Solution
{
public:
    void backtrack(int n, int open, int close, string &curr, vector<string> &res)
    {
        if ((int)curr.size() == 2 * n)
        {
            res.push_back(curr);
            return;
        }

        if (open < n)
        {
            curr.push_back('(');
            backtrack(n, open + 1, close, curr, res);
            curr.pop_back();
        }

        if (close < open)
        {
            curr.push_back(')');
            backtrack(n, open, close + 1, curr, res);
            curr.pop_back();
        }
    }

    vector<string> generateParenthesis(int n)
    {
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
class Solution
{
public:
    int removeDuplicates(vector<int> &nums)
    {
        int k = 1;
        for (int i = 1; i < nums.size(); i++)
        {
            if (nums[i] != nums[i - 1])
            {
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
class Solution
{
public:
    int removeElement(vector<int> &nums, int val)
    {
        int k = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != val)
            {
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
class Solution
{
public:
    void sortColors(vector<int> &nums)
    {
        int low = 0, mid = 0, high = nums.size() - 1;
        while (mid <= high)
        {
            if (nums[mid] == 0)
            {
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            }
            else if (nums[mid] == 1)
            {
                mid++;
            }
            else
            {
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
class Solution
{
public:
    long long countTriplets(int n, long long sum, long long arr[])
    {
        sort(arr, arr + n);
        long long count = 0;
        for (int i = 0; i < n - 2; i++)
        {
            int left = i + 1, right = n - 1;
            while (left < right)
            {
                if (arr[i] + arr[left] + arr[right] < sum)
                {
                    count += (right - left);
                    left++;
                }
                else
                {
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

class Solution
{
public:
    void reorderList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
            return;

        // Step 1: Find middle
        ListNode *slow = head;
        ListNode *fast = head;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: Reverse second half
        ListNode *second = slow->next;
        slow->next = nullptr;
        ListNode *prev = nullptr;
        ListNode *curr = second;
        while (curr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }
        second = prev;

        // Step 3: Merge two halves
        ListNode *first = head;
        while (second)
        {
            ListNode *tmp1 = first->next;
            ListNode *tmp2 = second->next;
            first->next = second;
            second->next = tmp1;
            first = tmp1;
            second = tmp2;
        }
    }
};

202. Happy Number
Easy
Topics
premium lock icon
Companies
Write an algorithm to determine if a number n is happy.

A happy number is a number defined by the following process:

Starting with any positive integer, replace the number by the sum of the squares of its digits.
Repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1.
Those numbers for which this process ends in 1 are happy.
Return true if n is a happy number, and false if not.

solution:

class Solution
{
public:
    int sumOfSquares(int n)
    {
        int sum = 0;
        while (n > 0)
        {
            int d = n % 10;
            sum += d * d;
            n /= 10;
        }
        return sum;
    }

    bool isHappy(int n)
    {
        int slow = n;
        int fast = sumOfSquares(n);
        while (fast != 1 && slow != fast)
        {
            slow = sumOfSquares(slow);
            fast = sumOfSquares(sumOfSquares(fast));
        }
        return fast == 1;
    }
};

// 141. Linked List Cycle
// Easy
// Topics
// Companies
// Given head, the head of a linked list, determine if the linked list has a cycle in it.
// There is a cycle in a linked list if there is some node in the list that can be reached
// again by continuously following the next pointer.
// Return true if there is a cycle in the linked list. Otherwise, return false.
//
// Example 1:
// Input: head = [3, 2, 0, -4], pos = 1
// Output: true
// Explanation: There is a cycle in the linked list, where tail connects to the 1st node.
//
// Example 2:
// Input: head = [1, 2], pos = 0
// Output: true
// Explanation: There is a cycle in the linked list, where tail connects to the 0th node.
//
// Example 3:
// Input: head = [1], pos = -1
// Output: false
// Explanation: There is no cycle in the linked list.
//
// Solution:
class Solution
{
public:
    bool hasCycle(ListNode *head)
    {
        if (!head || !head->next)
            return false;

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (slow != fast)
        {
            if (!fast || !fast->next)
                return false;
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

// Question 10: 876. Middle of the Linked List
// Given the head of a singly linked list, return the middle node of the linked list.
// If there are two middle nodes, return the second middle node.
//
// Example 1:
// Input: head = [1, 2, 3, 4, 5]
// Output: [3, 4, 5]
//
// Example 2:
// Input: head = [1, 2, 3, 4, 5, 6]
// Output: [4, 5, 6]
//
// Solution:
class Solution
{
public:
    ListNode *middleNode(ListNode *head)
    {
        ListNode *slow = head;
        ListNode *fast = head;

        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow;
    }
};

// Question 11: 160. Intersection of Two Linked Lists
// Given the heads of two singly linked-lists headA and headB, return the node at
// which the two lists intersect. If the two linked lists have no intersection,
// return nullptr.
//
// Solution:
class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
            return nullptr;

        ListNode *a = headA;
        ListNode *b = headB;

        while (a != b)
        {
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        return a;
    }
};

// Question 12: 19. Remove Nth Node From End of List
// Given the head of a linked list, remove the nth node from the end of the list
// and return its head.
//
// Example 1:
// Input: head = [1, 2, 3, 4, 5], n = 2
// Output: [1, 2, 3, 5]
//
// Solution:
class Solution
{
public:
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        ListNode dummy(0);
        dummy.next = head;

        ListNode *fast = &dummy;
        ListNode *slow = &dummy;

        for (int i = 0; i <= n; i++)
        {
            fast = fast->next;
        }

        while (fast)
        {
            fast = fast->next;
            slow = slow->next;
        }

        ListNode *toDelete = slow->next;
        slow->next = slow->next->next;
        delete toDelete;

        return dummy.next;
    }
};

// Question 13: 234. Palindrome Linked List
// Given the head of a singly linked list, return true if it is a palindrome
// or false otherwise.
//
// Solution:
class Solution
{
public:
    bool isPalindrome(ListNode *head)
    {
        if (!head || !head->next)
            return true;

        ListNode *slow = head;
        ListNode *fast = head;
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode *prev = nullptr;
        ListNode *curr = slow->next;
        while (curr)
        {
            ListNode *nxt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nxt;
        }

        ListNode *p1 = head;
        ListNode *p2 = prev;
        while (p2)
        {
            if (p1->val != p2->val)
                return false;
            p1 = p1->next;
            p2 = p2->next;
        }

        return true;
    }
};

// Question 14: 283. Move Zeroes
// Given an integer array nums, move all 0's to the end of it while maintaining
// the relative order of the non-zero elements.
//
// Example:
// Input: nums = [0, 1, 0, 3, 12]
// Output: [1, 3, 12, 0, 0]
//
// Solution:
class Solution
{
public:
    void moveZeroes(vector<int> &nums)
    {
        int insertPos = 0;

        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] != 0)
            {
                nums[insertPos++] = nums[i];
            }
        }

        while (insertPos < nums.size())
        {
            nums[insertPos++] = 0;
        }
    }
};

// Question 15: 125. Valid Palindrome
// Given a string s, determine if it is a palindrome, considering only
// alphanumeric characters and ignoring cases.
//
// Example 1:
// Input: s = "A man, a plan, a canal: Panama"
// Output: true
//
// Example 2:
// Input: s = "race a car"
// Output: false
//
// Solution:
class Solution
{
public:
    bool isPalindrome(string s)
    {
        int left = 0;
        int right = s.size() - 1;

        while (left < right)
        {
            while (left < right && !isalnum(s[left]))
                left++;
            while (left < right && !isalnum(s[right]))
                right--;

            if (tolower(s[left]) != tolower(s[right]))
                return false;

            left++;
            right--;
        }

        return true;
    }
};

// Question 16: 167. Two Sum II - Input Array Is Sorted
// Given a 1-indexed array of integers numbers that is already sorted in
// non-decreasing order, find two numbers such that they add up to target.
// Return the indices of the two numbers as an integer array [index1, index2]
// of length 2.
//
// Solution:
class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;

        while (left < right)
        {
            int sum = numbers[left] + numbers[right];
            if (sum == target)
                return {left + 1, right + 1};

            if (sum < target)
                left++;
            else
                right--;
        }

        return {};
    }
};