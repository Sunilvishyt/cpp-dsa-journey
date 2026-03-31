
//solution using for loop
#include <iostream>
using namespace std;

int fib(int num){
    if (num == 1) return 0;
    if (num == 2) return 1;
    
    int f = 0;
    int s = 1;
    int ans;
    
    for (int i = 0; i < num -2; i++){
        ans = f + s;
        f = s;
        s = ans;
    }
    return ans;
}

//solution using recursion
int fibrec(int num){
    if (num <= 1) return 0;
    if (num == 2) return 1;
    
    return fibrec(num-1) + fibrec(num-2);
}


int main()
{
    cout << "Using loop : "
    cout << fib(9);
    
    cout << endl;
    
    cout << "Using recursion : "
    cout << fibrec(9);
    return 0;
}
