void subsetsWithDup(int index, const vector<int> &S, vector<int> &path, vector<vector<int> > &paths) {
    if(index == S.size())
        return;
    for(int i = index; i < S.size(); i++) {
        if( i != index && S[i] == S[i-1]) 
            continue;
        path.push_back(S[i]);
        paths.push_back(path);
        subsetsWithDup(i+1, S, path, paths);
        path.pop_back();
    }
}

vector<vector<int> > subsetsWithDup(vector<int> &S) {
    vector<vector<int>> paths;
    vector<int> path;
    paths.push_back(path);
    sort(S.begin(), S.end());
    subsetsWithDup( 0, S, path, paths );
    return paths;
}
