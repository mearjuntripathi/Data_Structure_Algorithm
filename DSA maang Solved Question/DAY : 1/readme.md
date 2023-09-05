# Day : 1

![Day 1](../images/day1.png)

## [Question 1](#question-1): [Two sum](https://leetcode.com/problems/two-sum/)
Given an array of integers `nums` and an integer `target`, return indices of the two numbers such that they add up to `target`.

You may assume that each input would have *exactly one solution*, and you may not use the same element twice.

You can return the answer in any order.

**Example 1:**

&nbsp; **Input:** nums = [2,7,11,15], target = 9

&nbsp; **Output:** [0,1]

&nbsp; **Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1].

**Example 2:**
    
&nbsp; **Input:** nums = [3,2,4], target = 6

&nbsp; **Output:**  [1,2]

**Example 3:**

&nbsp; **Input:** nums = [3,3], target = 6

&nbsp; **Output:** 
    [0,1]
 

**Constraints:**

* 2 <= nums.length <= 104
* -109 <= nums[i] <= 109
* -109 <= target <= 109

## Solution :


**Algorithm:**
1. Create a hash map mp that maps each number in the array to its index.
2. Iterate over the array.
    * For each number, `nums[i]`:
        * Check if the hash map contains the complement of `nums[i]`, which is `target - nums[i]`.
            * If it does, return the indices of `nums[i]` and the complement as a two-element vector.
        * Otherwise, add `nums[i]` to the hash map.
3. If no two numbers in the array add up to target, return a two-element vector with the elements `-1` and `-1`.

**Approach:**
The key idea of this solution is to use a hash map to store the numbers in the array and their corresponding indices. This allows us to quickly check if the complement of a given number is present in the hash map.

The time complexity of this solution is O(n), where `n` is the length of the array. The space complexity is O(n), which is the space used by the hash map.

Here is an implementation of the solution in C++:

    vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp;
    for (int i = 0; i < nums.size(); i++) {
        if (mp.count(target - nums[i])) {
        return {mp[target - nums[i]], i};
        }
        mp[nums[i]] = i;
    }
    return {-1, -1};
    }


## [Question 2](#question-2): [Best Time to Buy and Sell Stock](https://leetcode.com/problems/best-time-to-buy-and-sell-stock/)
You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.

 

**Example 1:**

&nbsp; **Input:** prices = [7,1,5,3,6,4]

&nbsp; **Output:** 5

&nbsp; **Explanation:** Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

**Example 2:**

&nbsp; **Input:** prices = [7,6,4,3,1]

&nbsp; **Output:** 0

&nbsp; **Explanation:** In this case, no transactions are done and the max profit = 0.
 

**Constraints:**
* `1 <= prices.length <= 105`
* `0 <= prices[i] <= 104`

## Solution:

**Approach:**

The given code finds the maximum profit that can be made by buying and selling stocks at different times. The idea is to maintain the minimum price of the stock seen so far. At each step, we calculate the profit that can be made by buying the stock at the current price and selling it at the minimum price seen so far. The maximum profit is the maximum of all such profits.

**Algorithm:**
The algorithm can be implemented as follows:

1. Initialize the minimum price to the first price in the array.
2. For each price in the array:
    * Update the minimum price to the minimum of the current price and the minimum price seen so far.
    * Calculate the profit that can be made by buying the stock at the current price and selling it at the minimum price seen so far.
    * Keep track of the maximum profit.
3. Return the maximum profit.

**Implementation in C++:**

    int max (int n1,int n2){return n1>n2?n1:n2;}
    int min (int n1,int n2){return n1<n2?n1:n2;}
    int maxProfit(vector<int>&prices ){
        int ans = 0;
        int m = prices[0];
        for(int i=1;i<prices.size();i++){
            m = min(prices[i],m);
            ans = max(ans, (prices[i]-m));
        }
        return ans;
    }

***Here is an explanation of the code:***
* The function maxProfit() takes a vector of prices as input.
* The variable ans stores the maximum profit.
* The variable minPrice stores the minimum price seen so far.
* The for loop iterates over all the prices in the array.
    * In each iteration, we update the minPrice to the minimum of the current price and the minPrice seen so far.
    * We then calculate the profit that can be made by buying the stock at the current price and selling it at the minPrice.
    * We update the ans variable to the maximum of the ans and the profit calculated in the previous step.
* Finally, the function returns the ans variable.

## [Question 3](#question-3): [Majority Element](https://leetcode.com/problems/majority-element/)
Given an array nums of size n, return the majority element.

The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

**Example 1:**

&nbsp; **Input:** nums = [3,2,3]

&nbsp; **Output:** 3

**Example 2:**

&nbsp; **Input:** nums = [2,2,1,1,1,2,2]

&nbsp; **Output:** 2
 

**Constraints:**
* `n == nums.length`
* `1 <= n <= 5 * 104`
* `-109 <= nums[i] <= 109`
 

***Follow-up:** Could you solve the problem in linear time and in O(1) space*

## Solution
**Approach:** 

The code uses the Boyer-Moore majority vote algorithm to find the majority element in an array. The algorithm works by maintaining a candidate element and a count of the number of times that element has been seen. Initially, the candidate element is the first element in the array and the count is set to 1. Then, the algorithm iterates over the rest of the array. For each element, if the element is equal to the candidate element, then the count is incremented. Otherwise, the count is decremented. If the count ever reaches 0, then the candidate element is set to the current element and the count is set to 1.

**Algorithm:**

1. Initialize a candidate element to the first element in the array.
2. Initialize a count to 1.
3. Iterate over the rest of the array:
    * If the current element is equal to the candidate element, then increment the count.
    * Otherwise, decrement the count.
    * If the count reaches 0, then set the candidate element to the current element and set the count to 1.
4. Return the candidate element.

This algorithm works because, if there is a majority element in the array, then the algorithm will eventually set the candidate element to that element and the count will be greater than 0. Otherwise, the algorithm will never set the count to greater than 0, which means that there is no majority element in the array.

This algorithm has a time complexity of O(n) and a space complexity of O(1).


**Here is an explanation of the code you have provided:**

    int majorityElement(vector<int>& nums) {
        int majority = nums[0];
        int count = 0;
        for(int i = 0; i < nums.size() ; i++){
            if(count == 0){
                majority = nums[i];
                count = 1;
            }else{
                if(nums[i] == majority)
                    count ++;
                else count--;
            }
        }
        return majority;        
    }

* The first line declares the function `majorityElement`, which takes a vector of integers as input and returns the majority element in the vector.
* The second line declares the variables `majority` and `count`. The variable `majority` stores the candidate element and the variable `count` stores the number of times that element has been seen.
* The third line starts the loop that iterates over the vector of integers.
* The fourth line checks if the count is 0. If it is, then the algorithm sets the candidate element to the current element and sets the count to 1.
* The fifth line checks if the current element is equal to the candidate element. If it is, then the algorithm increments the count. Otherwise, the algorithm decrements the count.
* The sixth line goes back to the top of the loop.
* The seventh line returns the candidate element.

## [Question 4](#question-4): [Move Zeroes](https://leetcode.com/problems/move-zeroes/)
Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

***Note:** that you must do this in-place without making a copy of the array.*

 

**Example 1:**

&nbsp; **Input:** nums = [0,1,0,3,12]

&nbsp; **Output:** [1,3,12,0,0]

**Example 2:**

&nbsp; **Input:** nums = [0]

&nbsp; **Output:** [0]
 

**Constraints:**

* 1 <= nums.length <= 104
* -231 <= nums[i] <= 231 - 1
 

`Follow up: Could you minimize the total number of operations done?`

## Solution

**Approach:**

The approach is to maintain two pointers, `low` and `pos`. The `low` pointer points to the first non-zero element in the array. The `pos` pointer points to the current element in the array.

We iterate through the array, and if the current element is non-zero, we swap it with the element at the `low` pointer. We then increment both pointers.

If the current element is zero, we simply increment the `pos` pointer.

**Algorithm:**

    void moveZeroes(vector<int>& nums) {
      int low = 0;
      int pos = 0;
      int size = nums.size();

      while (low < size && pos < size) {
        if (nums[low] == 0 && nums[pos] == 0) {
          pos++;
        } else {
          if (nums[low] == 0 && nums[pos] != 0) {
            nums[low] = nums[pos];
            nums[pos] = 0;
          }
          low++;
          pos++;
        }
      }
    }
**Explanation:**

The first step is to initialize the `low` and `pos` pointers. The `low` pointer is initialized to 0, and the pos pointer is initialized to 0. The `size` variable stores the number of elements in the array.

## [Question 5](#question-5): [Squares of a Sorted Array](https://leetcode.com/problems/squares-of-a-sorted-array/)
Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 

**Example 1:**

&nbsp; **Input:** nums = [-4,-1,0,3,10]

&nbsp; **Output:** [0,1,9,16,100]

&nbsp; **Explanation:** After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

**Example 2:**

&nbsp; **Input:** nums = [-7,-3,2,3,11]

&nbsp; **Output:** [4,9,9,49,121]
 

**Constraints:**

* `1 <= nums.length <= 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in non-decreasing order.

***Follow up:** Squaring each element and sorting the new array is very trivial, could you find an O(n) solution using a different approach?
*

## Solution
**Approach:**  The approach is to use a greedy algorithm. The greedy algorithm works as follows:

1. Initialize two pointers, `left` and `right`, pointing to the beginning and end of the array, respectively.
2. Iterate through the array from the end, starting from index `size - 1`.
3. At each iteration, compare the absolute values of `nums[left]` and `nums[right]`.
    * If the absolute value of `nums[left]` is greater than the absolute value of `nums[right]`, then add the square of `nums[left]` to the result array.
    *  Otherwise, add the square of `nums[right]` to the result array.
    * Update the pointers accordingly.
4. Once the entire array has been traversed, return the result array.

**Algorithm:**

    vector<int> sortedSquares(vector<int>& nums) {
    // Initialize two pointers.
    int left = 0, right = nums.size() - 1;

    // Create a result array.
    vector<int> result(nums.size());

    // Iterate through the array from the end.
    for (int i = nums.size() - 1; i >= 0; i--) {
        // Compare the absolute values of the elements at the pointers.
        if (abs(nums[left]) > abs(nums[right])) {
        // Add the square of the element at the left pointer to the result array.
        result[i] = nums[left] * nums[left];
        // Move the left pointer one position to the right.
        left++;
        } else {
        // Add the square of the element at the right pointer to the result array.
        result[i] = nums[right] * nums[right];
        // Move the right pointer one position to the left.
        right--;
        }
    }

    // Return the result array.
    return result;
    }

## [Question 6](#question-6): [Merge Sorted Array](https://leetcode.com/problems/merge-sorted-array/)

You are given two integer arrays `nums1` and `nums2`, sorted in **non-decreasing order**, and two integers `m` and `n`, representing the number of elements in `nums1` and `nums2` respectively.

**Merge** `nums1` and `nums2` into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array `nums1`. To accommodate this, `nums1` has a length of `m + n`, where the first `m` elements denote the elements that should be merged, and the last `n` elements are set to `0` and should be ignored. `nums2` has a length of `n`.

 

**Example 1:**


&nbsp; **Input:** nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3

&nbsp; **Output:** [1,2,2,3,5,6]

&nbsp; **Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.

**Example 2:**


&nbsp;**Input:** nums1 = [1], m = 1, nums2 = [], n = 0

&nbsp;**Output:** [1]

&nbsp;**Explanation:** The arrays we are merging are [1] and [].
The result of the merge is [1].
Example 3:


&nbsp; **Input:** nums1 = [0], m = 0, nums2 = [1], n = 1

&nbsp; **Output:** [1]

&nbsp; **Explanation:** The arrays we are merging are [] and [1].
The result of the merge is [1].
Note that because m = 0, there are no elements in nums1. The 0 is only there to ensure the merge result can fit in nums1.
 

**Constraints:**

* `nums1.length == m + n`
* `nums2.length == n`
* `0 <= m, n <= 200`
* `1 <= m + n <= 200`
* `-109 <= nums1[i], nums2[j] <= 109`
 

***Follow up:** Can you come up with an algorithm that runs in `O(m + n)` time?*

## Solution

**Approach:**

`The merge()` function merges two sorted arrays, nums1 and nums2, into a single sorted array. The function works by first checking if either of the arrays is empty. If nums2 is empty, then the function simply returns. If nums1 is empty, then the function copies nums2 to nums1 and returns.

If neither of the arrays is empty, then the function initializes three pointers:

* `last_n1`: Points to the last element in nums1.
* `last_n2`: Points to the last element in nums2.
* `last_result`: Points to the last element in the merged array (which is initially equal to the last element in nums1 + the last element in nums2).

The function then iterates until `last_n2` is less than or equal to `0`. At each iteration, the function checks if the element pointed to by `last_n1` is less than or equal to the element pointed to by `last_n2`. If it is, then the function copies the element pointed to by `last_n2` to the element pointed to by `last_result` and decrements both `last_n2` and `last_result`. Otherwise, the function copies the element pointed to by last_n1 to the element pointed to by `last_result` and decrements last_n1.

Once the loop terminates, the function has merged the two sorted arrays into a single sorted array.

**Algorithm:** The algorithm of the merge() function can be summarized as follows:

1. Check if either of the arrays is empty.
2. If nums2 is empty, then return.
3. If nums1 is empty, then copy nums2 to nums1 and return.
4. Initialize last_n1 and last_n2 to point to the last elements of nums1 and nums2, respectively.
5. Initialize last_result to point to the last element of the merged array.
6. Enter a loop that iterates until last_n2 is less than or equal to 0.
7. In each iteration of the loop, check if the element at last_n1 is less than or equal to the element at last_n2.
8. If it is, then copy the element at last_n2 to the element at last_result and decrement both last_n2 and last_result.
9. Otherwise, copy the element at last_n1 to the element at last_result and decrement both last_n1 and last_result.
10. Return

        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // Check if either of the arrays is empty.
            if (n == 0) {
                return;
            }
            if (m == 0) {
                nums1 = nums2;
                return;
            }

            // Initialize pointers to the end of each array.
            int last_n1 = m - 1;
            int last_n2 = n - 1;
            int last_result = m + n - 1;

            // Iterate until last_n2 is less than or equal to 0.
            while (last_n2 >= 0) {
                // Check if the element pointed to by last_n1 is less than or equal to the element pointed to by last_n2.
                if (nums1[last_n1] <= nums2[last_n2]) {
                nums1[last_result] = nums2[last_n2];
                last_n2--;
                } else {
                nums1[last_result] = nums1[last_n1];
                last_n1--;
                }
                last_result--;
            }
        }