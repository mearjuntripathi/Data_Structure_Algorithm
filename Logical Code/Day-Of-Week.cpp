/* A program to find day of a given date */
#include <bits/stdc++.h>
using namespace std;
 
int dayofweek(int d, int m, int y)
{
    static int t[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };
    y -= m < 3;
    return ( y + (y / 4) - (y / 100) + (y / 400) + t[m - 1] + d) % 7;
}
 
// Driver Code
int main()
{
    string days[7] = {
                        "Sunday", 
                        "Monday", 
                        "Tuesday", 
                        "Wednesday", 
                        "Thursday", 
                        "Friday", 
                        "Saturday"
                    };
    int day = dayofweek(01, 02, 1990);
    cout << days[day];
    return 0;
}