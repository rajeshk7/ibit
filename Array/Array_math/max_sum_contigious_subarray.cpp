int Solution::maxSubArray(const vector<int> &A) {
    int sum = 0, max_r = INT_MIN, maxi = INT_MIN;
    for( int i : A )    {
        sum += i;
        if(sum < 0)
            sum = 0;
        else
            max_r = max(sum, max_r);
        maxi = max(maxi, i);
    }
    return (max_r == INT_MIN) ? maxi : max_r ;
}
