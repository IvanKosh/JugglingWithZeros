/* 
 * File:   main.cpp
 * Author: bat
 *
 * Created on 20 Ноябрь 2015 г., 11:12
 */

#include <iostream>
#include <fstream>

using namespace std;

string toBoolSequence(string line) {
    string result = "";
    int l = line.length();
    if (line[1] == ' ') {
        for (int i = 0; i < l-2; i++) {
            result += '0';
        }

    }
    if (line[2] == ' ') {
        for (int i = 0; i < l-3; i++) {
            result += '1';
        }
    }
    return result;
}

long boolStrToInt(string str) {
    long result = 0;
    for (int i = 0; i < str.length(); i++) {
        if (str[i] == '1') {
            result = result |= 1;
            result = result << 1;
        }
        if (str[i] == '0') {
            result = result << 1;
        }
    }
    result = result >> 1;
    return result;
}

int main(int argc, char *argv[]) {
    ifstream stream(argv[1]);
    string line;
    while (getline(stream, line)) {
        string boolSequence = "";
        bool take = false;
        int j = 0;
        int i;
        for (i = 0; i < line.length(); i++) {
            if ((line[i] == ' ') && take) {
                boolSequence += toBoolSequence(line.substr(j, i-j));
                j = i+1;
                take = false;
            }
            else if ((line[i] == ' ') && !take) {
                take = true;
            }
        }
        boolSequence += toBoolSequence(line.substr(j, i-j));
        cout << boolStrToInt(boolSequence) << '\n';
    }
    return 0;
}