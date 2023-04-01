
// } Driver Code Ends//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
    int binary_Search(int arr[], int start, int n, int x)
    {
        if (n >= start) {
            int mid = start + (n - start) / 2;
            if (arr[mid] == x)
                return mid;
           
            if (arr[mid] > x)
                return binary_Search(arr, start, mid - 1, x);
           
            return binary_Search(arr, mid + 1, n, x);
        }
 
      
        return -1;
    }
	// Converts arr[0..n-1] to reduced form.
	void convert(int arr[], int n) {
	    int temp[n];
        for(int i=0; i< n;i++)
            temp[i] = arr[i];
        sort(temp,temp+n);
        for(int i=0;i<n;i++)
            arr[i] = binary_Search(temp,0,n-1,arr[i]);
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        ob.convert(arr, n);
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends