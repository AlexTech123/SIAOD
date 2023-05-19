#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <ctime>
#include <set>
#include <ctime>
using namespace std;

mt19937 rnd(time(0));
set<int> articles;

struct Record {
    string name;
    string article; // key
    int amount;
    string unit;
    int price;
};

struct Table {
    vector<Record> goods;
};

struct Node {
    Node() {
        for (int i = 0; i < 10; i++) {
            next[i] = nullptr;
        }
    }

    Node* next[10];
    int ind = -1;
};

void addToBor(string s, Node* root, int ind) {
    Node* cur = root;

    for (int i = 0; i < s.size(); i++) {
        char c = s[i];

        if (cur->next[c - '0'] == nullptr) {
            cur->next[c - '0'] = new Node();
        }

        cur = cur->next[c - '0'];
    }

    cur->ind = ind;
}

void createBor(Table& table, Node* root) {
    for (int i = 0; i < table.goods.size(); i++) {
        addToBor(table.goods[i].article, root, i);
    }
}

string genArticle() {
    int x = rnd() % 900000 + 100000;
    while (articles.find(x) != articles.end()) {
        x = rnd() % 900000 + 100000;
    }
    articles.insert(x);
    return to_string(x);
}

void createTable(Table& table, int n) {
    while (n--) {
        Record rcd;

        int lenName = rnd() % 5 + 5;
        for (int i = 0; i < lenName; i++) {
            rcd.name += char(97 + rnd() % 26);
        }

        rcd.article = genArticle();
        rcd.amount = rnd() % 100 + 1;
        rcd.unit += (char(97 + rnd() % 26));
        rcd.unit += (char(97 + rnd() % 26));
        rcd.price = rnd() % 1000 + 1;

        table.goods.push_back(rcd);
    }
}

void printTable(Table& table) {
    for (int i = 0; i < table.goods.size(); i++) {
        cout << "Name: " << table.goods[i].name << '\n';
        cout << "Article: " << table.goods[i].article << '\n';
        cout << "Amount: " << table.goods[i].amount << '\n';
        cout << "Unit: " << table.goods[i].unit << '\n';
        cout << "Price: " << table.goods[i].price << '\n';
        cout << "---------------------------------------\n";
    }
}

string toFind(Table& table) {
    return table.goods[rnd() % table.goods.size()].article;
}

int linearSearch(Table& table, string article) {
    for (int i = 0; i < table.goods.size(); i++) {
        if (table.goods[i].article == article) {
            return i;
        }
    }
    return -1;
}

int linearSearchWithBarrier(Table& table, string article) {
    table.goods.push_back({"", article, 0, "", 0});
    int i = 0;
    while (table.goods[i].article != article) {
        i++;
    }
    return i < table.goods.size() - 1 ? i : -1;
}

int BorSearch(Node* root, string article) {
    Node* cur = root;

    for (int i = 0; i < article.size(); i++) {
        cur = cur->next[article[i] - '0'];

        if (cur == nullptr) {
            return -1;
        }
    }

    return cur->ind;
}

int main()
{
    Table tbl;
    createTable(tbl, 10);
    printTable(tbl);
    string article = toFind(tbl);

    Node* root = new Node();
    createBor(tbl, root);

    clock_t start = clock();
    //cout << article << " " << linearSearch(tbl, article);
    //cout << article << " " << BorSearch(root, article);
    //cout << article << " " << linearSearchWithBarrier(tbl, article);
    clock_t end = clock();

    double duration = (double)(end - start) / CLOCKS_PER_SEC * 1000;
    cout << "\nTime taken: " << duration << " milliseconds" << endl << endl;
}
