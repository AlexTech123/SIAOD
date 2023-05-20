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

int BorSearch(Node* root, string article) {
    movementsAmount++;
    Node* cur = root;

    movementsAmount++;
    comparisonsAmount++;
    for (int i = 0; i < article.size(); i++) {
        comparisonsAmount++;
        cur = cur->next[article[i] - '0'];
        movementsAmount++;
        comparisonsAmount++;
        if (cur == nullptr) {
            return -1;
        }
    }

    return cur->ind;
}
