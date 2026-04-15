class Solution {
    bool solve(string& s, int start, int end, int count) {
        if(start >= end) return true;
        if(s[start] != s[end]){
            if(count >= 1) return false;
            bool first = solve(s, start+1, end, count+1);
            bool second = solve(s, start, end-1, count+1);
            return first || second;
        }
        return solve(s, start+1, end-1, count);
    }
public:
    bool validPalindrome(string s) {
        return solve(s, 0, s.size()-1, 0);
    }
};