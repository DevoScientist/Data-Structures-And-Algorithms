class Solution {
public:
    int numSquares(int n) {
       
        int root = sqrt(n);
        if(root*root == n)
            return 1;
        
        while(!(n%4))  //n == (4^k)*(8m + 7);
        {
            n /= 4;
        }
        if(n%8 == 7)
            return 4;
        
        for(int i = 1; i*i < n ; i++)
        {
            root = sqrt(n - i*i);
            if(root*root == (n - i*i))
                return 2;
        }
        return 3;
    }
};
