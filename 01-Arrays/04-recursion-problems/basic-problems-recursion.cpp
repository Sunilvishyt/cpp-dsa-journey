//////////////////////////printing array elements with recursion \\\\\\\\\\\\\\\\\\\\\\\\\\

#include <iostream>
using namespace std;

void printer(int arr[], int n){
    if (n == -1) return ;
    printer(arr, n-1);
    cout << arr[n] << " ";
    return ;
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    printer(arr, sizeof(arr) / sizeof(arr[0])-1);
    return 0;
}


/////////////////////////////sum of arrays with recursion\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int sum (int arr[], int n){
    if (n == -1) return 0;
    
    return arr[n] + sum(arr, n-1);
    
}

int main()
{
    int arr[] = {1,2,3,4,5,6};
    cout << sum(arr, sizeof(arr) / sizeof(arr[0])-1);
    return 0;
}


///////////////////////////minimum element in array with recursion\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int minelement(int arr[], int n, int index){
    if (index == n-1) 
        return arr[index];
        
    return min(arr[index], minelement(arr, n, index +1));
}

int main()
{
    int arr[] = {1,2,3,4,-4,6};
    cout << minelement(arr, sizeof(arr) / sizeof(arr[0])-1, 0);
    return 0;
}

////////////////////////////check palindrome with recursion\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

bool checkpal(const string &str, int start, int end){
    if (start >= end) 
        return true;
        
    if (str[start] != str[end]) 
        return false;
        
    return checkpal(str, start+1, end-1);
}

int main()
{    
    string str = "racecar";
    if (checkpal(str, 0, str.size()-1)) 
        cout << "given string is palindrome";
        
    else 
        cout << "not palindrome";
        
    return 0;
}

///////////////////////////////check vowel or not with recursion\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

int checkvow(const string &str, int end){
    if (end == -1) 
        return 0;
        
    if (str[end] == 'a' or str[end] == 'e' or str[end] == 'i' or str[end] == 'o' or str[end] == 'u')
        return 1 + checkvow(str , end -1);
        
    else return checkvow(str, end -1);
}

int main()
{    
    string str = "aeioudfdfgg";
    int ans = checkvow(str, str.size()-1);
    cout << ans ;
    return 0;
}


//////////////reverse string with recursion.\\\\\\\\\\\\\\\\\\\\\\
#include <iostream>
using namespace std;

void reversestr(string &str, int start, int end){
    if (start >= end) 
        return;
        
    swap(str[start], str[end]);
    reversestr(str, start + 1, end -1);
    return;
}

int main()
{    
    string str = "aaabbbb";
    reversestr(str, 0, str.size()-1);
    
    cout << str ;
    return 0;
}


/*
note - just solve one case in case of recursion and other cases will be automatically handle by itself.
*/
