/* 
https://www.hackerrank.com/challenges/arrays-introduction/problem
*/
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main()
{
  int n;
  int arr[1000] = {0};
  cin >> n;

  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];    
  }

  for (int i = n-1; i >= 0; i--)
  {
    cout << arr[i] << " ";
  }  
 
return 0;

}
