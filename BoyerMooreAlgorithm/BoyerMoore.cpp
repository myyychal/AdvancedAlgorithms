#include <iostream>

using namespace std;

int* getLastArray(string pattern, int first, int last);
int* getBMNextArray(int piArray[], string pattern);
void toLower(string &a);
void printIntArray(int* array, int length);

int main() {

    int zp = ' ';
    int zk = '~';

    string text;
    string pattern;

    cout << "Give me a text: " << endl;
    getline(cin,text);
    cout << "Give me a pattern: " << endl;
    getline(cin,pattern);

    //toLower(pattern);
    //toLower(text);

    int patternLength = pattern.length();
    int textLength = text.length();

    int *BMNext;
    int *pi = new int[patternLength+1];
    int* lastArray;

    // BMNext and Last arrays
    BMNext = getBMNextArray(pi, pattern);
    lastArray = getLastArray(pattern, zp, zk);

    cout << "BMNext: " << endl;
    printIntArray(BMNext, patternLength+1);
    cout << "PI: " << endl;
    printIntArray(pi, patternLength+1);
    cout << "Last: " << endl;
    printIntArray(lastArray, zk - zp +1);

    int pp = -1;
    int i = 0;
    while (i <= textLength - patternLength){
        int j = patternLength-1;
        while (j > -1 && pattern[j] == text[i+j]){
            j--;
        }
        if (j != -1){
            i = i + max(BMNext[j+1], j-lastArray[text[i+j] - zp]);
        } else {
            pp = i;
            cout << pp << " ";
            i = i + BMNext[0];
        }
    }

    if (pp == -1){
        cout << "Pattern has not beed found." << endl;
    }

    return 0;

}

int* getLastArray(string pattern, int first, int last){
    int *lastArray = new int[last-first+1];
    for (int i=0; i< last - first + 1; i++){
        lastArray[i] = -1;
    }
    for (int i=0; i<pattern.length(); i++){
        lastArray[pattern[i] - first] = i;
    }
    return lastArray;
}

int* getBMNextArray(int piArray[], string pattern){
    // I stage
    int m = pattern.length();
    int *BMNext = new int[m+1];
    for (int j=0; j<m+1; j++){
        BMNext[j] = 0;
        piArray[j] = 0;
    }
    int i = m;
    int b = m+1;
    piArray[i] = b;
    while (i > 0){
        while (b <= m && pattern[i-1] != pattern[b-1]){
            if (BMNext[b] == 0){
                BMNext[b] = b - i;
            }
            b = piArray[b];
        }
        b = b-1;
        i = i-1;
        piArray[i] = b;
    }
    // II stage
    b = piArray[0];
    for (int j=0; j<m+1; j++){
        if (BMNext[j] == 0){
            BMNext[j] = b;
        }
        if (j == b){
            b = piArray[b];
        }
    }
    return BMNext;
}

void toLower(string &a){
    for(int i = 0; a[i]; i++){
        a[i] = tolower(a[i]);
    }
}

void printIntArray(int* array, int length){
    for (int i=0; i < length; i++){
        cout << array[i] << " ";
    }
    cout << endl;
}