vector<int> Solution::plusOne(vector<int> &A) {
    vector<int> res;
    int carry = 0, i = 0, sum;
    while( i < A.size() && !A[i] )
        i++;
    if( i == A.size())
        return res.push_back({1});
    for( int j = A.size-1 ; j >= i ; j++ )  {
        sum = A[j] + carry
    }
}
