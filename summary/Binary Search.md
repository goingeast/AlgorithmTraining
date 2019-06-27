# Binary Search
## Introduction
In this video, we gonna discuss binary search (BS) as below. 
- Typical use case of BS. 
- Key points of BS code
- How to solve problems using BS
- Examples
- Template code

## Typical use case of binary search?
Here is a quote from wikipedia:
 
> In computer science, binary search, also known as half-interval search, logarithmic search, or binary chop, is a search algorithm that finds the position of a target value within a sorted array. Binary search compares the target value to the middle element of the array. If they are not equal, the half in which the target cannot lie is eliminated and the search continues on the remaining half, again taking the middle element to compare to the target value, and repeating this until the target value is found. If the search ends with the remaining half being empty, the target is not in the array.
``
From the describtion above, we have to get three keys:
1. Data is **sorted**.
2. **Half of data is eliminated** due to missing some condition.
3. **Repeat** the process until **target is found** or **meet end condition**.

## Key points of BS code
With the three key points in mind, let see how our code implements these.

``` cplusplus
int binarySearch(vector<int>& sortedData, int target) {
    int left = 0;
    int right = sortedData.size() - 1;

    while(left <= right) {
        int mid = left + (right - left) / 2;
        if(sortedData[mid] == target) {
            return mid;
        } else if(sortedData[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // target is not found
}
```