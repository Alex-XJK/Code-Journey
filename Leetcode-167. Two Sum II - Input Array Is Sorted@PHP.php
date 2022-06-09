class Solution {

    /**
     * @param Integer[] $numbers
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($numbers, $target) {
        $left = 0;
        $right = count($numbers) - 1;
        $isFind = false;
        
        while ($left < $right && !$isFind) {
            $sum = $numbers[$left] + $numbers[$right];
            if ($sum == $target) {
                $isFind = true;
            }
            elseif ($sum > $target) {
                $right -= 1;
            }
            else {
                $left += 1;
            }
        }
        
        return [$left + 1, $right + 1]; 
    }
}