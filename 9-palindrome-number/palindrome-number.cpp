class Solution {
public:
    bool isPalindrome(int x) {
        long rev=0,pal=x;
        while(x>0)
        {
            int l=x%10;
            x=x/10;
            rev=(rev*10)+l;

        }
        if(rev==pal)
        {
            return true;
        }
            
        return false;
        
    }
    
};