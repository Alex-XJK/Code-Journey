class Solution {
    public boolean checkRecord(String s) {
        int cA = 0;
        int cL = 0;
        for (int i = 0; i < s.length(); i++) {
            switch (s.charAt(i)) {
                case 'A':
                    cA += 1;
                    cL = 0;
                    if (cA > 1) {
                        return false;
                    }
                    break;
                case 'L':
                    cL += 1;
                    if (cL > 2) {
                        return false;
                    }
                    break;
                case 'P':
                    cL = 0;
                    break;
            }
        }
        return true;
    }
}