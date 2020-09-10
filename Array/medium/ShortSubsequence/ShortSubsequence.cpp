
class ShortSubsequence {
public:
    int findShortest(vector<int> A, int n) {
        // write code here
        vector<int> B(A);
        sort(B.begin(), B.end());
        int i(0), j(n-1);
        while(i < n && A[i] == B[i])
        {
            i++;
        }
        while(j > i && A[j] == B[j])
        {
            j--;
        }
        
        return j-i+1;
    }
};
