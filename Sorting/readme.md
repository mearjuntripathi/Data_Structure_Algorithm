# Sorting

The operation of sorting is the most common task performed by computers today. Sorting is used to arrange names and numbers in meaningful ways. 

## Types of sorting
Sorting can be performed in many ways. Over a time several methods (or algorithms) are being developed to sort data(s). 
<ul>
<li>Bubble sort</li>
<li>Selection sort</li>
<li>Quick sort</li>
<li>Merge sort</li>
<li>Heap sort</li>
<li>Binary sort</li>
<li>Shell sort</li>
<li>Radix sort</li>
</ul>

## Complexity of Sorting Algorithm
The complexity of sorting algorithm measures the running time of n items to be sorted. The operations in the sorting algorithm, where A1, A2 ..... An contains the items to be sorted and B is an auxiliary location, can be generalized as:
<pre>
<ol type='a'>
    <li>Comparisons- which tests whether Ai < Aj or test whether Ai < B </li>
    <li>Interchange- which switches the contents of Ai and Aj or of Ai and B</li>
    <li>Assignments- which set B = A and then set Aj = B or Aj = Ai</li>
</ol>
</pre>
Normally, the complexity functions measure only the number of comparisons, since the number of other operations is at most a constant factor of the number of comparisons.

<hr>

## Bubble Sort
In bubble sort, each element is compared with its adjacent element. If the first element is larger than the second one, then the positions of the elements are interchanged, otherwise it is not changed. Then next element is compared with its adjacent element and the same process is repeated for all the elements in the array until we get a sorted array.

<br>

![Bubble Sort](https://www.w3resource.com/w3r_images/bubble-short.png)
<pre>
<center> Algorithm </center> 

STEP 1: Start with the first element.

STEP 2: Compare the current element with the next element.

STEP 3: If the current element is greater than the next element, then swap both the elements. If not, move to the next element.

STEP 4: Repeat steps 1 – 3 until we get the sorted list.


Time Complexity  : O(n^2)
Space Complexity : O(1)

</pre>

## Insertion Sort
Insertion sort algorithm sorts a set of values by inserting values into an existing sorted file. Compare the second element with first, if the first element is greater than second, place it before the first one. Otherwise place is just after the first one. Compare the third value with second. If the third value is greater than the second value then place it just after the second. Otherwise place the second value to the third place. And compare third value with the first value. If the third value is greater than the first value place the third value to second place, otherwise place the first value to second place. And place the third value to first place and so on.

<br>

![Insertion sort](https://miro.medium.com/v2/resize:fit:765/0*1zi2XtjiLXa3LYZh.PNG)

<pre>
<center> Algorithm </center>

Step 1 − If the element is the first one, it is already sorted.

Step 2 – Move to next element

Step 3 − Compare the current element with all elements in the sorted array

Step 4 – If the element in the sorted array is smaller than the current element, iterate to the next element. Otherwise, shift all the greater element in the array by one position towards the right

Step 5 − Insert the value at the correct position

Step 6 − Repeat until the complete list is sorted


Time Complexity : O(n^2)
Space Complexity : O(1)
</pre>

## Selection Sort

The algorithm repeatedly selects the smallest (or largest) element from the unsorted portion of the list and swaps it with the first element of the unsorted portion.<br>
This process is repeated for the remaining unsorted portion  of the list until the entire list is sorted.

<br>

![Selection Sort](https://www.programiz.com/sites/tutorial2program/files/Selection-sort-0.png)

<pre>
<center>Algorithm</center>
    
STEP 1 − Set MIN to location 0

STEP 2 − Search the minimum element in the list

STEP 3 − Swap with value at location MIN

STEP 4 − Increment MIN to point to next element

STEP 5 − Repeat until list is sorted

Time Complexity : O(n^2)
Space Complexity : O(1)
</pre>

## Merge Sort
Merging is the process of combining two or more sorted array into a third sorted array. Divide the array into approximately n/2 sub-arrays of size two and set the element in each sub array. Merging each sub-array with the adjacent sub-array will get another sorted sub-array of size four. Repeat this process until there is only one array remaining of size n.

<br>

![merge sort](https://www.programiz.com/sites/tutorial2program/files/merge-sort-example_0.png)
<pre>
        <center>Algotithm</center> 
STEP 1 − if it is only one element in the list it is already sorted, return.

STEP 2 − divide the list recursively into two halves until it can no more be divided.

STEP 3 − merge the smaller lists into new list in sorted order.

Time Complexity : O(nlog(n))
Space Complexity : O(n)
</pre>

## Quick Sort
It is one of the widely used sorting techniques and it is also called the partition-exchange sort. 
Quick sort is an efficient algorithm and it passes a very good time complexity in average case.  
<br>

![quick sort](https://cdn-images-1.medium.com/max/1080/1*-Ew3z7-bu0gjNXKL6plLzA.jpeg)

<pre>
<center>Algorithm</center>

Step 1: First check low is less then high

Step 2: Then make a pivot to lower element

Step 3: divide a array in two part 

    Step a: left side has a lower element as pivot 

    Step b: right side has a greator element as pivot

Step 4: And repeat step 1-3 for two subarray 

    Step a: one for greator element as pivot 

    Step b: one for lower lower element as pivot

Time Complexity : [ wrost case O(n^2) || best case : O(n) || average case : O(n log n)  ]
Space Complexity : O(log n)
</pre>


## Counting Sort
Counting sort is a sorting technique based on keys between a specific range. It works by counting the number of objects having distinct key values (a kind of hashing). Then do some arithmetic operations to calculate the position of each object in the output sequence.

![counting sort](https://www.researchgate.net/publication/220686480/figure/fig4/AS:667707569614851@1536205298801/Example-of-counting-sort.png)

### <center>Algorithm</center>
    
    Step 1 − I get a max element in array.

    Step 2 – Create a new array of length max with element 0.

    Step 3 − Increase a new array element as frequency of element in array.

    Step 4 – After inserting we get a frequency of each element in array.

    Step 5 − Reinsert the value in old array as their frequency.

    Time Complexity: O(N + K) 
        
    Auxiliary Space: O(N + K)

        where, N is the number of elements in the input array and K is the range of input.