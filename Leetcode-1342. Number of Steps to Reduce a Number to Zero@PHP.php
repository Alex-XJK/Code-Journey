class Solution {

    /**
     * @param Integer $num
     * @return Integer
     */
    function numberOfSteps($num) {
        if ($num == 0) {
            return 0;
        }
        else {
            if ($num % 2 == 0) {
                return 1 + $this->numberOfSteps($num / 2);
            }
            else {
                return 1 + $this->numberOfSteps($num - 1);
            }
        }
    }
}