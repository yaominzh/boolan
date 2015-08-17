void permuteHelper(int index, vector<int> &num, vector<vector<int>> &paths ) {      
    if(index > num.size()) {
        return;
    }

    if(index == num.size()) {
        paths.push_back(num);
    }
              
    unordered_set<int> used;
    for(int i = index; i < num.size(); i++ ) {
       // handle duplicates        
        if(used.count(num[i]))
            continue;

        // make choice
        swap(num,index,i);
        permuteHelper(index+1,num,paths);

        // backtracking
        swap(num,index,i);        
        used.insert(num[i]);
    }    
}

vector<vector<int>> permuteUnique(vector<int> &num) {
    vector<vector<int>> paths;
    permuteHelper(0,num,paths);
    return paths;
}
