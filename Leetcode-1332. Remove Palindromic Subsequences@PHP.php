class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function removePalindromeSub($s) {
        $rev = strrev($s);
        if ($s == $rev) {
            return 1;
        }
        else {
            return 2;
        }
    }
}