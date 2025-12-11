#include <bits/stdc++.h>
using namespace std;

// Utility function to print a segment of the vector with optional indent
void printSegment(const vector<int>& nums, int left, int right, int indentLevel) {
    string indent(indentLevel * 2, ' ');
    cout << indent;
    for (int i = left; i <= right; i++) {
        cout << nums[i] << ' ';
    }
    cout << endl;
}

void merge(vector<int>& nums, int left, int right, int mid, int depth) {
    string indent(depth * 2, ' ');
    vector<int> temp(right - left + 1);
    int i = left;
    int j = mid + 1;
    int k = 0;

    cout << indent << "Splitting segments at depth " << depth << ":\n";
    cout << indent << "- Left half  [" << left << "..." << mid << "]: ";
    printSegment(nums, left, mid, depth);
    cout << indent << "- Right half [" << mid + 1 << "..." << right << "]: ";
    printSegment(nums, mid + 1, right, depth);

    while (i <= mid && j <= right) {
        if (nums[i] < nums[j])
            temp[k++] = nums[i++];
        else
            temp[k++] = nums[j++];
    }

    while (i <= mid) temp[k++] = nums[i++];
    while (j <= right) temp[k++] = nums[j++];

    // Copy back to original array
    for (int idx = left, t = 0; idx <= right; idx++, t++) {
        nums[idx] = temp[t];
    }

    cout << indent << "After merging segments [" << left << "..." << right << "] at depth " << depth << ": ";
    printSegment(nums, left, right, depth);
    cout << endl;
}

void mergesort(vector<int>& nums, int left, int right, int depth = 0) {
    if (left >= right) {
        string indent(depth * 2, ' ');
        cout << indent << "Base case reached at index " << left << ": " << nums[left] << endl << endl;
        return;
    }

    int mid = (left + right) / 2;

    string indent(depth * 2, ' ');
    cout << indent << "Recursively sorting left half [" << left << "..." << mid << "] at depth " << depth << endl;
    mergesort(nums, left, mid, depth + 1);

    cout << indent << "Recursively sorting right half [" << mid + 1 << "..." << right << "] at depth " << depth << endl;
    mergesort(nums, mid + 1, right, depth + 1);

    cout << indent << "Merging two halves [" << left << "..." << mid << "] and [" << mid + 1 << "..." << right << "] at depth " << depth << endl;
    merge(nums, left, right, mid, depth);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "Enter the number of elements: ";
    int n;
    cin >> n;

    vector<int> nums(n);
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    cout << "\nInitial array: ";
    for (const auto& num : nums) cout << num << ' ';
    cout << "\n\nStarting merge sort visualization...\n\n";

    mergesort(nums, 0, n - 1);

    cout << "Final sorted array: ";
    for (const auto& num : nums) cout << num << ' ';
    cout << endl;

    return 0;
}

