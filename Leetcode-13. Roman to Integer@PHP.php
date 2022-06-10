class Solution {
    private static $dict = array(
        'I' => 1,       'V' => 5,
        'X' => 10,      'L' => 50,
        'C' => 100,     'D' => 500,
        'M' => 1000
    );

    /**
     * @param String $s
     * @return Integer
     */
    function romanToInt($s) {
        $result = 0;
        
        $prev = self::$dict[$s[0]];
        $curr = 0;
        
        $chars = str_split($s);
        foreach ($chars as $c) {
            $curr = self::$dict[$c];
            
            if ($curr <= $prev) {
                $result += $curr;
            }
            else {
                $result = $result - $prev + ($curr - $prev);
            }
            
            $prev = $curr;
        }
        
        return $result;
    }
}