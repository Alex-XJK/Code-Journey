/**
 * Definition for a binary tree node.
 * class TreeNode {
 *     public $val = null;
 *     public $left = null;
 *     public $right = null;
 *     function __construct($val = 0, $left = null, $right = null) {
 *         $this->val = $val;
 *         $this->left = $left;
 *         $this->right = $right;
 *     }
 * }
 */
class Solution {

    /**
     * @param TreeNode $root
     * @param Integer $val
     * @return TreeNode
     */
    function searchBST($root, $val) {
        if(is_null($root)){
            return NULL;
        }
        $rootValue = $root->val;
        if($rootValue == $val){
            return $root;
        }
        else if($rootValue < $val){
            return $this->searchBST($root->right, $val);
        }
        else if($rootValue > $val){
            return $this->searchBST($root->left, $val);
        }
        else {
            return NULL;            
        }
    }
}