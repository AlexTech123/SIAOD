int linearSearch(Table& table, string article) {

    movementsAmount++;
    comparisonsAmount++;

    for (int i = 0; i < table.goods.size(); i++) {
        comparisonsAmount++;
        comparisonsAmount++;
        if (table.goods[i].article == article) {
            return i;
        }
    }
    return -1;
}

int linearSearchWithBarrier(Table& table, string article) {
    movementsAmount++;
    table.goods.push_back({"", article, 0, "", 0});
    movementsAmount++;
    int i = 0;
    comparisonsAmount++;
    while (table.goods[i].article != article) {
        comparisonsAmount++;
        i++;
    }
    return i < table.goods.size() - 1 ? i : -1;
}
