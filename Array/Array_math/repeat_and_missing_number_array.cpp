vector<int> Solution::repeatedNumber(const vector<int> &A) {
    long long int n = A.size(), sum = 0, suS = 0;
    for( int i : A )    {
        sum += (long long)i;
        suS += (long long)i*(long long)i;
    }
    long long int dif = n*(n+1)/2 - sum;
    long long int diS = n*(n+1)*(2*n+1)/6 - suS;
    long long int _sum = (diS/dif), a = (_sum - dif)/2;
    vector<int> res;
    res.push_back(a);
    res.push_back(_sum - a);
    return res;
}
