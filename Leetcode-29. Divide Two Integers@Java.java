class Solution {
    public int divide(int dividend, int divisor) {
        // Special Condition
        if(dividend == Integer.MIN_VALUE && divisor == 1) {
            return Integer.MIN_VALUE;
        }
        
        // Assign Temp Variables
        long a = dividend;
        long b = divisor;
        
        // Get Absolute
        a = Math.abs(a);
        b = Math.abs(b);

        // Pre-process 2's Power on Divisor
        /*
         @example 2^30*y, 2^29*y, 2^28*y, ..., 2^0*y
             e.g., For divisor=8, 2^2*8=32, 2^1*8=16, 2^0*8=8
        */
        long[] exp = new long[31];
        for(int i = 0; i < 31; i++) {
            exp[i] = (1 << i) * b;
        }
        
        // Subtract To Quotient
        long res = 0;
        for(int i = 30; i >= 0 && a > 0; i--) {
            if(a - exp[i] >= 0) {
                a -= exp[i];
                res += (long)1 << i;
            }
        }
        
        // Handle Symbol Issue
        if(dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0) {
            res = -res;
        }
        
        // Result Limits
        if(res > Integer.MAX_VALUE) {
            return Integer.MAX_VALUE;
        }
        else if(res < Integer.MIN_VALUE) {
            return Integer.MIN_VALUE;
        }
        
        // Return Result
        return (int)res;
    }
}