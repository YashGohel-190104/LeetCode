/*
Given an integer n, find a sequence that satisfies all of the following:

The integer 1 occurs once in the sequence.
Each integer between 2 and n occurs twice in the sequence.
For every integer i between 2 and n, the distance between the two occurrences of i is exactly i.
The distance between two numbers on the sequence, a[i] and a[j], is the absolute difference of their indices, |j - i|.
Return the lexicographically largest sequence. It is guaranteed that under the given constraints, there is always a solution.
A sequence a is lexicographically larger than a sequence b (of the same length) if in the first position where a and b differ, sequence a has a number greater than the corresponding number in b. For example, [0,1,9,0] is lexicographically larger than [0,1,5,6] because the first position they differ is at the third number, and 9 is greater than 5.

Example 1:

Input: n = 3
Output: [3,1,2,3,2]
Explanation: [2,3,2,1,3] is also a valid sequence, but [3,1,2,3,2] is the lexicographically largest valid sequence.
Example 2:

Input: n = 5
Output: [5,3,1,4,3,5,2,4,2]
*/
class Solution {
public:

    int n, az;
    bitset<21> viz = 0;
    vector<int> ans;
    
    bool dfs(int pos) {
        if (pos==az) return viz.count()==n;  // Base case: all numbers used
        if (ans[pos]!= 0) return dfs(pos+1);  // Skip if already filled
        
        for (int j=n; j>= 1; j--) {  // larger first
            if (viz[j]) continue;  // If j is used, skip
            int next_pos=(j>1)?pos+j:pos;  // should put j
            
            if (next_pos>=az || ans[next_pos]!=0) continue;  // Ensure valid placement
            
            ans[pos]=ans[next_pos]= j;  // Place j
            viz[j]=1;
            
            if (dfs(pos+1)) return 1;  // Recurse
            
            // Backtrack
            ans[pos]=ans[next_pos]=viz[j]=0;
        }
        return 0;
    }

    vector<int> constructDistancedSequence(int n) {
         this->n=n;
        az=2*n-1;
        ans.assign(az, 0);
        dfs(0);
        return ans;
    }
};

