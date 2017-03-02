#include <iostream>
using namespace std;

int main()
{
    int score[i];
    int student;
    cout << "Enter the number of students: ";
    cin >> student;
    cout << "Enter 4 scores: ";
    cin >> score[i];
        //    cin >> score[i];
    int best = score[0];
    for (int i = 1; i < student; i++) {
        if (score[i] > best )
            best = score[i];
    }
}

    if (score[i] >= best -10)
            cout << "A" << endl;
    if (score[i] >= best -20)
            cout << "B" << endl;
    else
            cout << "F" << endl;


/*
int main(){
    int num;
    cout << "Enter the number of students: ";
    cin >> num;
    int arr[num], i, best;
    cout << "Enter 4 scores: ";
    for(i = 0; i < num; i++){
        if(i == 0) best = arr[i];
        cin >> arr[i];
        if(arr[i] > best) best = arr[i];
    }
    for(i = 0; i < num; i++){
        cout << "Score of student " << i + 1 << " is " << arr[i] << " and grade is ";
        if(arr[i] >= best - 10) cout << "A";
        else if(arr[i] >= best - 20) cout << "B";
        else if(arr[i] >= best - 30) cout << "C";
        else if(arr[i] >= best - 40) cout << "D";
        else cout << "F";
        cout << endl;
    } */




