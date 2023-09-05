# Day : 2

![Day 2](../images/day2.png)

## [Question 1](#question-1-remove-duplicates-from-sorted-array): [Remove Duplicates from Sorted Array](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

Given an integer array `nums` sorted in `non-decreasing order`, remove the duplicates [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) such that each unique element appears only once. The relative order of the elements should be kept the same. Then return the number of unique elements in `nums`.

Consider the number of unique elements of `nums` to be `k`, to get accepted, you need to do the following things:

* Change the array `nums` such that the first `k` elements of `nums` contain the unique elements in the order they were present in `nums` initially. The remaining elements of `nums` are not important as well as the size of `nums`.
* Return k.

**Custom Judge:**
 
    The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }

If all assertions pass, then your solution will be accepted.

 

**Example 1:**

&nbsp; **Input:** nums = [1,1,2]

&nbsp; **Output:** 2, nums = [1,2,_]

&nbsp; **Explanation:** Your function should return k = 2, with the first two elements of nums being 1 and 2 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

**Example 2:**

&nbsp; **Input:** nums = [0,0,1,1,1,2,2,3,3,4]

&nbsp; **Output:** 5, nums = [0,1,2,3,4,_,_,_,_,_]

&nbsp; **Explanation:** Your function should return k = 5, with the first five elements of nums being 0, 1, 2, 3, and 4 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

**Constraints:**

* `1 <= nums.length <= 3 * 104`
* `-100 <= nums[i] <= 100`
* `nums` is sorted in non-decreasing order.

## Solution

**Approach:**

The approach is to scan the input array `nums` from left to right. At each iteration, we compare the current element `nums[i]` with the next element `nums[i + 1]`. If they are not equal, we copy `nums[i + 1]` to the next available position in the output array, and increment the counter `res`.

Once we have scanned the entire input array, we use the `erase()` method to remove all elements from the output array after position `res`. This ensures that the output array only contains the unique elements from the input array.

**Algorithm:**

    int removeDuplicates(vector<int>& nums) {
    // Initialize the result array and the counter.
    int res = 1;

    // Iterate over the input array.
    for (int i = 0; i < nums.size() - 1; i++) {
        // If the current element is not equal to the next element, copy the next element to the result array.
        if (nums[i] != nums[i + 1]) {
            nums[res++] = nums[i + 1];
        }
    }

    // Remove all elements from the result array after position `res`.
    nums.erase(nums.begin() + res, nums.end());

    // Return the number of unique elements in the input array.
    return res;
    }

1. Initialize a variable `res` to `1`. This will be the index of the next available element in the new array.
2. Iterate through the array, starting from index `0`.
    * If the current element is not equal to the next element, then copy the current element to the new array at index `res`.
    * Increment `res` by `1`.
3. Erase the elements from the original array after index `res`.
4. Return `res`.


## [Question 2](#question-2): [Remove Duplicates from Sorted Array II](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

Given an integer array `nums` sorted in non-decreasing order, remove some duplicates [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) such that each unique element appears at most twice. The relative order of the elements should be kept the same.

Since it is impossible to change the length of the array in some languages, you must instead have the result be placed in the first part of the array `nums`. More formally, if there are k elements after removing the duplicates, then the first `k` elements of `nums` should hold the final result. It does not matter what you leave beyond the first `k` elements.

Return `k` after placing the final result in the first `k` slots of `nums`.

Do not allocate extra space for another array. You must do this by modifying the input array [in-place](https://en.wikipedia.org/wiki/In-place_algorithm) with `O(1)` extra memory.

**Custom Judge:**

The judge will test your solution with the following code:

    int[] nums = [...]; // Input array
    int[] expectedNums = [...]; // The expected answer with correct length

    int k = removeDuplicates(nums); // Calls your implementation

    assert k == expectedNums.length;
    for (int i = 0; i < k; i++) {
        assert nums[i] == expectedNums[i];
    }
If all assertions pass, then your solution will be accepted.


**Example 1:**


&nbsp; **Input:** nums = [1,1,1,2,2,3]

&nbsp; **Output:** 5, nums = [1,1,2,2,3,_]

&nbsp; **Explanation:**Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).

**Example 2:**


&nbsp; **Input:** nums = [0,0,1,1,1,1,2,3,3]

&nbsp; **Output:** 7, nums = [0,0,1,1,2,3,3,_,_]

&nbsp; **Explanation:**Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 

**Constraints:**

* `1 <= nums.length <= 3 * 104`
* `-104 <= nums[i] <= 104`
* `nums` is sorted in non-decreasing order.

## Solution

**Approach:**

The approach is to maintain two counters, `n` and `times`. `n` keeps track of the number of unique elements in the array, and `times` keeps track of the number of consecutive duplicate elements.

The algorithm works as follows:

1. Initialize `n` to `1` and times to `0`.
2. Iterate over the array from index `1` to `nums.size() - 1`.
3. If the current element is equal to the previous element, increment `times`.
    * If `times` is less than 2, then add the current element to the unique array.
    * Otherwise, do nothing.
4. If the current element is not equal to the previous element, then set `times` to 0.
    * Add the current element to the unique array.
5. After the loop, erase the duplicate elements from the original array.

**Algorithm:**

**C++**

    int removeDuplicates(vector<int>& nums) {
    // 1. Initialize `n` and `times`.
    int n = 1;
    int times = 0;

    // 2. Iterate over the array from index 1 to `nums.size() - 1`.
    for (int i = 1; i < nums.size(); i++) {

        // 3. If the current element is equal to the previous element, increment `times`.
        if (nums[i] == nums[i - 1]) {
        times++;

        // 3.1 If `times` is less than 2, then add the current element to the unique array.
        if (times < 2) {
            nums[n++] = nums[i];
        }
        }

        // 4. If the current element is not equal to the previous element, then set `times` to 0.
        else {
        times = 0;

        // 4.1 Add the current element to the unique array.
        nums[n++] = nums[i];
        }
    }

    // 5. After the loop, erase the duplicate elements from the original array.
    nums.erase(nums.begin() + n, nums.end());

    return n;
    }

## [Question 3](#question-3): [Find All Numbers Disappeared in an Array](https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array/)
Given an array `nums` of n integers where `nums[i]` is in the range `[1, n]`, return an array of all the integers in the range `[1, n]` that do not appear in `nums`.

 

**Example 1:**

&nbsp; **Input:** nums = [4,3,2,7,8,2,3,1]
&nbsp;  **Output:** [5,6]

**Example 2:**

&nbsp; **Input:** nums = [1,1]
&nbsp; **Output:** [2]

**Constraints:**

* n == nums.length
* 1 <= n <= 105
* 1 <= nums[i] <= n

## Solution
**Approach:**

The approach of the code is to mark all the numbers that are present in the list as negative. The missing numbers will be the ones that are still positive.

**Algorithm:**

1. Initialize a vector `res` to store the missing numbers.
2. Iterate over the list `nums`.
    * For each number `num`:
    * If `nums[abs(num) - 1] < 0`: continue.
    * Otherwise: nums[abs(num) - 1] *= -1.
3. Iterate over the list nums again.
    * For each number num:
        * If `num > 0`: push `num + 1` to the vector `res`.
4. Return the vector `res`.

**CODE CPP**

    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0 ; i < n ; i++){
            if(nums[abs(nums[i])-1] < 0)
                continue;
            nums[abs(nums[i])-1] *= -1;
        }
        
        vector<int> res;

        for(int i=0;i<n;i++)
            if(nums[i]>0)
                res.push_back(i+1);
        
        return res;
    }

**Here is a more detailed explanation of the code:**

1. The first step is to initialize a vector `res` to store the missing numbers. This vector will be empty at the beginning.
2. The next step is to iterate over the list `nums`. For each number `num` in the list, we do the following:
    * If the number `nums[abs(num) - 1]` is already negative, then that means the number num has already been marked as missing. So, we just continue to the next number.
    * Otherwise, we mark the number `num` as missing by multiplying it by -1.
    3. After we have iterated over the entire list `nums`, we iterate over it again. This time, we only add the numbers that are still positive to the vector `res`. These are the missing numbers.
    4. Finally, we return the vector `res`.

This algorithm works because it ensures that each number in the list is marked as either present or missing. The missing numbers are the ones that are still positive after we have iterated over the list twice.

## [Question 4](#question-4): [Intersection of Two Arrays](https://leetcode.com/problems/intersection-of-two-arrays/description/)
Given two integer arrays `nums1` and `nums2`, return an array of their intersection. Each element in the result must be unique and you may return the result in **any order**.

**Example 1:**

&nbsp; **Input:** nums1 = [1,2,2,1], nums2 = [2,2]

&nbsp; **Output:** [2]

**Example 2:**

&nbsp; **Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]

&nbsp; **Output:** [9,4]

&nbsp;  **Explanation:** [4,9] is also accepted.
 

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

## Solution

**Approach:**

The approach is to first sort the two arrays, nums1 and nums2. This is done so that we can easily compare elements from the two arrays and find the intersections.

Once the arrays are sorted, we can start traversing them simultaneously. We keep track of two pointers, l1 and l2, which point to the current elements in nums1 and nums2, respectively.

We compare the elements pointed to by l1 and l2. If the elements are equal, then we add the element to a new array, which will store the intersection of the two arrays. We also increment both l1 and l2.

If the elements are not equal, then we simply increment the pointer that points to the smaller element.

We continue this process until we reach the end of one of the arrays.

Finally, we return the new array that stores the intersection of the two arrays.

**Algorithm:**
The algorithm can be broken down into the following steps:

1. Sort the `nums1` and `nums2` arrays.
2. Initialize two pointers `l1` and `l2` to the beginning of the `nums1` and nums2 arrays, respectively.
3. Initialize a counter `pos` to `0`.
4. Iterate while `l1` is less than the length of `nums1` and `l2` is less than the length of `nums2`:
    * If `nums1[l1] < nums2[l2]`, then increment `l1`.
    * If `nums1[l1] > nums2[l2]`, then increment `l2`.
    * If `nums1[l1] == nums2[l2]`, then do the following:
        * If `pos > 0 `and `nums1[pos - 1]` != nums1[l1], then add `nums1[l1]` to the result vector at index pos.
        * Increment `pos`.
        * Increment `l1` and `l2`.
5. Remove all elements from the result vector after index `pos`.
6. Return the result vector.


C++

    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Sort the two arrays.
    sort(nums1.begin(), nums1.end());
    sort(nums2.begin(), nums2.end());

    // Create a new array to store the intersection of the two arrays.
    vector<int> intersection;

    // Declare two pointers to keep track of the current elements in the two arrays.
    int l1 = 0;
    int l2 = 0;

    // Iterate over the two arrays.
    while (l1 < nums1.size() && l2 < nums2.size()) {
            if(nums1[l1] < nums2[l2])
                l1++;
            else if(nums1[l1]>nums2[l2])
                l2++;
            else{ 
                if(nums1[l1] == nums2[l2]){
                    if((pos > 0 && nums1[pos-1] != nums1[l1]) || pos == 0)
                        nums1[pos++] = nums1[l1];
                }
                l1++;
                l2++;
            }
        }
        nums1.erase(nums1.begin()+pos,nums1.end());
        return nums1;
    }

This algorithm works because it guarantees that the first `pos` elements in the result vector will be the elements that are present in both `nums1` and `nums2`. This is because at each step, the algorithm only adds an element to the result vector if it is also present in the other array.

The time complexity of this algorithm is `O(N log N)`, where `N` is the length of the longer array. This is because the sorting step takes `O(N log N)` time, and the rest of the steps take `O(N)` time. The space complexity of this algorithm is `O(N)`, because the result vector can hold up to `N` elements.

## [Question 5](#question-5): [Intersection of Two Arrays II](https://leetcode.com/problems/intersection-of-two-arrays-ii/)
Given two integer arrays `nums1` and `nums2`, return *an array of their intersection*. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.

 

**Example 1:**


&nbsp; **Input:** nums1 = [1,2,2,1], nums2 = [2,2]

&nbsp; **Output:** [2,2]

**Example 2:**


&nbsp; **Input:** nums1 = [4,9,5], nums2 = [9,4,9,8,4]

&nbsp; **Output:** [4,9]

&nbsp; **Explanation:** [9,4] is also accepted.
 

**Constraints:**

* `1 <= nums1.length, nums2.length <= 1000`
* `0 <= nums1[i], nums2[i] <= 1000`

## Solution
**Approach:**

The approach is to first sort the two given arrays, nums1 and nums2. This is done so that we can find the intersection of the two arrays more efficiently. Once the arrays are sorted, we can use a simple two pointer algorithm to find the intersection.

    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

        int l1 = 0;
        int l2 = 0;
        int pos = 0;
        while(l1 < nums1.size() && l2 < nums2.size()){
            if(nums1[l1] < nums2[l2])
                l1++;
            else if(nums1[l1]>nums2[l2])
                l2++;
            else{ 
                if(nums1[l1] == nums2[l2]){
                    // if((pos > 0 && nums1[pos-1] != nums1[l1]) || pos == 0)
                    nums1[pos++] = nums1[l1];
                }
                l1++;
                l2++;
            }
        }
        nums1.erase(nums1.begin()+pos,nums1.end());
        return nums1;
    }

**Algorithm:**

1. Initialize two pointers l1 and l2 to point to the beginning of the two arrays, respectively.
2. Iterate while l1 is less than the length of nums1 and l2 is less than the length of nums2.
    * If `nums1[l1] < nums2[l2]`, then increment `l1`.
    * If `nums1[l1] > nums2[l2]`, then increment `l2`.
    * If `nums1[l1] == nums2[l2]`, then do the following:
        * If `pos` is greater than `0` and `nums1[pos - 1] != nums1[l1]` (this means that the current element is not a duplicate), then add `nums1[l1]` to `nums1` at index `pos`.
        * Increment `pos`.
        * Increment `l1` and `l2`.
3. After the loop, erase the elements in `nums1` from index `pos` onwards. This is because these elements are not part of the intersection.

**Complexity:**

The time complexity of this algorithm is `O(m + n)`, where m is the length of `nums1` and `n` is the length of `nums2`. This is because the sorting step takes `O(m log m)` time and the two pointer loop takes `O(m + n)` time.

The space complexity of this algorithm is `O(1)`, since we are only using two pointers.

## [Question 6](#question-6): [Maximum Population Year](https://leetcode.com/problems/maximum-population-year/)
You are given a 2D integer array logs where each l`ogs[i] = [birthi, deathi]` indicates the birth and death years of the i<sup>th</sup> person.

The population of some year `x` is the number of people alive during that year. The ith person is counted in year x's population if `x` is in the inclusive range `[birthi, deathi - 1]`. Note that the person is not counted in the year that they die.

*Return the **earliest** year with the **maximum population.***
 

**Example 1:**


&nbsp; **Input:** logs = [[1993,1999],[2000,2010]]

&nbsp; **Output:** 1993

&nbsp; **Explanation:**The maximum population is 1, and 1993 is the earliest year with this population.

Example 2:


&nbsp; **Input:** logs = [[1950,1961],[1960,1971],[1970,1981]]

&nbsp; **Output:** 1960

&nbsp; **Explanation:**
The maximum population is 2, and it had happened in years 1960 and 1970.
The earlier year between them is 1960.
 

**Constraints:**

* `1 <= logs.length <= 100`
* `1950 <= birthi < deathi <= 2050`
## Solution
**Approach:**

The approach of the code is to use a cumulative sum array to track the population of each year. The cumulative sum array is initialized to all zeros. Then, for each log, the corresponding year is incremented in the cumulative sum array. Finally, the maximum population is found by iterating over the cumulative sum array and finding the index with the maximum value.

**Algorithm:**

The algorithm of the code can be broken down into the following steps:

1. Initialize a cumulative sum array of size 101 (assuming the years are from 1950 to 2050).
2. For each log:
    * Increment the cumulative sum array at the index of the start year.
    * Decrement the cumulative sum array at the index of the end year.
3. Find the maximum value in the cumulative sum array.
4. Return the year corresponding to the maximum value.

**Here is a more detailed explanation of each step:**

1. The cumulative sum array is initialized to all zeros. This means that initially, the population of all years is assumed to be 0.
2. For each log, the corresponding year is incremented in the cumulative sum array. This means that the population of the year is increased by 1.
3. The maximum population is found by iterating over the cumulative sum array and finding the index with the maximum value. This means that the year with the maximum population is found.
4. The year corresponding to the maximum value is returned.

**code**    

    int maximumPopulation(vector<vector<int>>& logs) {
        int year[101] = {0};

        for(int i=0;i<logs.size();i++){
            year[logs[i][0]-1950]++;
            year[logs[i][1]-1950]--;
        }

        for(int i = 1 ; i < 101 ; i++){
            year[i] += year[i-1];
        }

        int max = 0;
        int maxYear = 1950;

        for(int i = 0 ; i < 101 ; i++){
            if(max < year[i]){
                max = year[i];
                maxYear = 1950 + i;
            }
        }
        return maxYear;
    }

## [Question 7](#question-7): [Find Pivot Index](https://leetcode.com/problems/find-pivot-index/description/)
Given an array of integers `nums`, calculate the pivot index of this array.

The **pivot index** is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to the index's right.

If the index is on the left edge of the array, then the left sum is `0` because there are no elements to the left. This also applies to the right edge of the array.

Return the **leftmost pivot index**. If no such index exists, return `-1`.


**Example 1:**

&nbsp; **Input:** nums = [1,7,3,6,5,6]

&nbsp; **Output:** 3

&nbsp; **Explanation:**
The pivot index is 3.<br>
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11<br>
Right sum = nums[4] + nums[5] = 5 + 6 = 11

**Example 2:**

&nbsp; **Input:** nums = [1,2,3]

&nbsp; **Output:** -1

&nbsp; **Explanation:**
There is no index that satisfies the conditions in the problem statement.

**Example 3:**

&nbsp; **Input:** nums = [2,1,-1]

&nbsp; **Output:** 0

&nbsp; **Explanation:**
The pivot index is 0.<br>
Left sum = 0 (no elements to the left of index 0)<br>
Right sum = nums[1] + nums[2] = 1 + -1 = 0
 

**Constraints:**
* `1 <= nums.length <= 104`
* `-1000 <= nums[i] <= 1000`