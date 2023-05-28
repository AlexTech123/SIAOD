#include <iostream>
#include <vector>
#include <string>
#include <random>

using namespace std;

mt19937 rnd(time(0));

vector<string> isbns;
vector<string> names;

void genIsbns(int size) {
    isbns.resize(size);

    for (int i = 0; i < size; i++) {
        isbns[i] = char(rnd() % 10 + '0');
        isbns[i] += '-';
        for (int j = 0; j < 4; j++) {
            isbns[i] += char(rnd() % 10 + '0');
        }
        isbns[i] += '-';
        for (int j = 0; j < 4; j++) {
            isbns[i] += char(rnd() % 10 + '0');
        }
        isbns[i] += '-';
        isbns[i] += char(rnd() % 10 + '0');
    }
}

void genNames(int size) {
    names.resize(size);
    for (int i = 0; i < size; i++) {
        int lenName = rnd() % 5 + 5;
        for (int j = 0; j < lenName; j++) {
            names[i] += char(97 + rnd() % 26);
        }
    }
}

void createData(string& data, int n) {
    genIsbns(10);
    genNames(100);
    for (int i = 0; i < n; i++) {
        data += isbns[rnd() % 10];
        data += ' ';
        data += names[rnd() % 100];
        data += ' ';
    }
}

int prefix_function(string s, string t) {
    s = t + '#' + s;

    int n = s.size();
    vector<int> pi(n);

    int cnt = 0;

    for (int i = 1; i < n; ++i) {

        int j = pi[i - 1];

        while (j > 0 && s[i] != s[j]) {
            j = pi[j - 1];
        }
            
        if (s[i] == s[j]) {
            j++;
        }

        pi[i] = j;

        if (pi[i] == t.size()) {
            cnt++;
        }
    }
    return cnt;
}

int main()
{
    int n = 100000;
    string data;
    createData(data, n);
    
    string toFind = isbns[rnd() % 10];
    cout << toFind << "\n-------------------------------------------\n";
    //cout << data << '\n';
    cout << prefix_function(data, toFind);
}
