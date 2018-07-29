#define AS 26
struct trie {
    bool leaf;
    trie *node[AS];
    trie()    {
        leaf = false;
        for( int i = 0 ; i < AS ; i++ ) node[i] = NULL;
    }
};

struct data {
    int index, score;
    data(int a, int b)  {
        index = a;
        score = b;
    }
};

void insert(trie *root, string str) {
    trie *temp = root;
    for( int i = 0 ; i < str.size() ; i++ ) {
        int index = str[i] - 'a';
        if(temp->node[index] == NULL)
            temp->node[index] = new trie();
        temp = temp->node[index];
    }
    temp->leaf = true;
}

bool search(trie *root, string str) {
    trie *temp = root;
    for( int i = 0 ; i < str.size() ; i++ ) {
        int index = str[i] - 'a';
        if(temp->node[index] == NULL)
            return false;
        temp = temp->node[index];
    }
    return temp->leaf;
}

bool mysort(data *a, data *b) {
    if(a->score == b->score)    return a->index < b->index;
    return a->score > b->score;
}

vector<int> Solution::solve(string A, vector<string> &B) {
    trie *root = new trie();
    vector<int> res;
    string s = "";
    for( int i = 0 ; i < A.size() ; i++ )   {
        if(A[i] != '_')     s = s + A[i];
        else    {
            insert(root, s);
            s.clear();
        }
    }
    insert(root, s);
    data *form[B.size()];
    for( int i = 0 ; i < B.size() ; i++ )   {
        int score = 0;
        string s = "";
        for( int j = 0 ; j < B[i].size() ; j++ )    {
            if(B[i][j] != '_')      s += B[i][j];
            else    {
                if(search(root, s)) score++;
                s.clear();
            }
        }
        if(search(root, s)) score++;
        form[i] = new data(i, score);
    }
    sort(form, form + B.size(), mysort);
    for( int i = 0 ; i < B.size() ; i++ ) 
            res.push_back(form[i]->index);
    return res;
}
