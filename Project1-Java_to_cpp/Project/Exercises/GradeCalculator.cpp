#include <iostream>
using namespace std;

int main() {
    /* User requested input */
    int student;
    cout << "Enter the number of students: ";
    cin >> student;

    /* Find best score */
    int bestScore;
    int i, score[student];
    cout << "Enter " << student <<" scores: ";
    for (int k = 0; k < student; k++) {
        cin >> score[k];
    }

    for (int i = 0; i < student; i++) {
        if (score[i] > score[i - 1])
            bestScore = score[i];
    }

    /* Initial nested statement disabled to match the provided Java code */
    /* for(i = 0; i < student; i++) {
        if (score[i] >= bestScore - 10) {
            cout << "Student " << i << " - Score: " << score[i] << ", Letter: A" << endl;
        }
        else if (score[i] >= bestScore - 20) {
            cout << "Student " << i << " - Score: " << score[i] << ", Letter: B" << endl;
        }
        else if(score[i] >= bestScore - 30) {
            cout << "Student " << i << " - Score: " << score[i] << ", Letter: C" << endl;
        }
        else if(score[i] >= bestScore - 40) {
            cout << "Student " << i << " - Score: " << score[i] << ", Letter: D" << endl;
        }
        else cout << "F" << endl;
    } */
    /* Display results based on bestScore*/
    for (i = 0; i < student; i++) {
        cout << "Student " << i << " - Score: " << score[i] << ", Letter: ";
        if (score[i] >= bestScore - 10) cout << "A" << endl;
        else if (score[i] >= bestScore - 20) cout << "B" << endl;
        else if (score[i] >= bestScore - 30) cout << "C" << endl;
        else if (score[i] >= bestScore - 40) cout << "D" << endl;
        else cout << "F" << endl;
    }
    return 0;
}


