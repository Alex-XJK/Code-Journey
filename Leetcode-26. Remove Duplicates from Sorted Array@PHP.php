class Solution {

/**
 * @param Integer[] $nums
 * @return Integer
 */
function removeDuplicates(&$nums) {
    $previous = null;
    foreach ($nums as $index => $value) {
        if ($value === $previous) {
            unset($nums[$index]);
        }
        else {
            $previous = $value;
        }
    }

    return count($nums);
}
}