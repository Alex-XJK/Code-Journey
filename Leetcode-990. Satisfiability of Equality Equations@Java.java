/**
* Implements "weighted quick union find" in Alg4.
*/
class WeightedQuickUnionUF {
    private int[] parent;
    private int[] size;
    private int count;

    public WeightedQuickUnionUF(int n) {
        count = n;
        parent = new int[n];
        size = new int[n];
        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    /**
     * Returns the number of sets.
     *
     * @return the number of sets (between {@code 1} and {@code n})
     */
    public int count() {
        return count;
    }

    /**
     * Returns the canonical element of the set containing element {@code p}.
     *
     * @param  p an element
     * @return the canonical element of the set containing {@code p}
     */
    public int find(int p) {
        while (p != parent[p]){
            p = parent[p];
        }
        return p;
    }

    /**
     * Returns true if the two elements are in the same set.
     *
     * @param  p one element
     * @param  q the other element
     * @return {@code true} if {@code p} and {@code q} are in the same set;
     *         {@code false} otherwise
     */
    public boolean isConnected(int p, int q) {
        return find(p) == find(q);
    }


    /**
     * Merges the set containing element {@code p} with the
     * the set containing element {@code q}.
     *
     * @param  p one element
     * @param  q the other element
     */
    public void union(int p, int q) {
        int rootP = find(p);
        int rootQ = find(q);
        if (rootP == rootQ) {
            return;
        }

        if (size[rootP] < size[rootQ]) {
            parent[rootP] = rootQ;
            size[rootQ] += size[rootP];
        }
        else {
            parent[rootQ] = rootP;
            size[rootP] += size[rootQ];
        }
        count--;
    }
}

class Solution {
    public boolean equationsPossible(String[] equations) {
        WeightedQuickUnionUF wquf = new WeightedQuickUnionUF(26);
        for (String str: equations) {
            if (str.charAt(1) == '=') {
                wquf.union((str.charAt(0) - 'a'), (str.charAt(3) - 'a'));
            }
        }
        for (String s: equations) {
            if (s.charAt(1) == '!') {
                if(wquf.isConnected(
                    (s.charAt(0) - 'a'), 
                    (s.charAt(3) - 'a')
                )) {
                    return false;
                }
            }
        }
        return true;
    }
}