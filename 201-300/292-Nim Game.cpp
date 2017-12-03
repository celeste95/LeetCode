class Solution {
public:
    bool canWinNim(int n) {
        if(n%4) return true;
        else return false;
    }
	
	bool canWinNim(int n) {
    return n % 4 != 0 ;
}
};