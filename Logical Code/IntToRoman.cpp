#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	string intToRoman(int num) {
        string roman = "";
        while(num){
            if(num >= 1000){
                roman += 'M';
                num -= 1000;
            }
            if(num >= 900 && num < 1000){
                roman += 'C';
                roman += 'M';
                num -= 900;
            }
            if(num >= 500 && num < 900){
                roman += 'D';
                num -= 500;
            }
            if(num >= 400 && num < 500){
                roman += 'C';
                roman += 'D';
                num -= 400;
            }
            if(num >= 100 && num < 400){
                roman += 'C';
                num -= 100;
            }
            if(num >= 90 && num < 100){
                roman += 'X';
                roman += 'C';
                num -= 90;
            }
            if(num >= 50 && num < 90){
                roman += 'L';
                num -= 50;
            }
            if(num >= 40 && num < 50){
                roman += 'X';
                roman += 'L';
                num -= 40;
            }
            if(num >= 10 && num < 40){
                roman += 'X';
                num -= 10;
            }
            if(num >= 9 && num < 10){
                roman += 'I';
                roman += 'X';
                num -= 9;
            }
            if(num >= 5 && num < 9){
                roman += 'V';
                num -= 5;
            }
            if(num >= 4 && num < 5){
                roman += 'I';
                roman += 'V';
                num -= 4;
            }
            if(num >= 1 && num < 4){
                roman += 'I';
                num -= 1;
            }
        }
        return roman;
	}
};

//{ Driver Code Starts.
int main() {
    Solution s;
    int n;
    cin >> n;
    cout<<s.intToRoman(n)<<endl;
    return 0;
}
// } Driver Code Ends