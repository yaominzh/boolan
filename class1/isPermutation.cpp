bool isPermutation(string stringA, string stringB) {
    if (stringA.length() != stringB.length()) {
        return false;
    }

    unordered_map<char, int> hashMapA;
    unordered_map<char, int> hashMapB;
    for (int i = 0; i < stringA.length(); i++) {
        hashMapA[stringA[i]]++;
        hashMapB[stringB[i]]++;
    }

    if (hashMapA.size() != hashMapB.size()) {
        return false;
    }

    unordered_map<char, int>::iterator it;
    for (it = hashMapA.begin(); it != hashMapA.end(); it++) {
        if (it->second != hashMapB[it->first]) {
            return false;
        }
    }
    return true;
}
