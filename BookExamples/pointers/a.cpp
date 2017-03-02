#include<iostream>
using namespace std;

int main() {
    int numbers[] = {1,2, 3, 4, 5};
    int len = 5;
 //   const int* num = numbers;
    for (int i = 0; i < len ; i++ )
    cout << "{" << numbers[i] << "}" ;
    return 0;
    
}

