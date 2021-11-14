1817 · Divide Chocolate
Algorithms
Hard
Accepted Rate
40%

DescriptionSolutionNotesDiscussLeaderboard
Description
You have one chocolate bar that consists of some chunks. Each chunk has its own sweetness given by the array sweetness.

You're going to share this chocolate with K friends, so you need to cut K times to get K + 1 pieces, each of which is made up of a series of small pieces.

Being generous, you will eat the piece with the minimum total sweetness and give the other pieces to your friends.

Find the maximum total sweetness of the piece you can get by cutting the chocolate bar optimally.

0 <= K < sweetness.length <= 10^4
1 <= sweetness[i] <= 10^5
Example
Example 1:

Input: sweetness = [1,2,3,4,5,6,7,8,9], K = 5
Output: 6
Explanation: You can divide the chocolate to [1,2,3], [4,5], [6], [7], [8], [9]
Example 2:

Input: sweetness = [5,6,7,8,9,1,2,3,4], K = 8
Output: 1
Explanation: There is only one way to cut the bar into 9 pieces.
Example 3:

Input: sweetness = [1,2,2,1,2,2,1,2,2], K = 2
Output: 5
Explanation: You can divide the chocolate to [1,2,2], [1,2,2], [1,2,2]


Solution : 

class Solution {
public:
    /**
     * @param sweetness: an integer array
     * @param K: an integer
     * @return:  return the maximum total sweetness of the piece
     */ 
     bool ok(vector <int> v, int cuts, int maxVal){
      int counter = 0;
      int temp = 0;
      for (int i = 0; i <= v.size(); i++) {
         if (temp >= maxVal) {
            counter++;
            temp = 0;
         }
         if (i == v.size()) {
            break;
         }
         temp += v[i];
      }
      return counter >= cuts;
   }
   int maximizeSweetness(vector<int>& s, int k) {
      int maxa = -1;
      int n = s.size();
      int low = 0;
      int high = 0;
      for (int i = 0; i < n; i++) {
         low = min(low, s[i]);
         high += s[i];
      }
      high++;
      while (low < high) {
         int mid = low + (high - low + 1) / 2;
         if (ok(s, k + 1, mid))
            low = mid;
         else
            high = mid - 1;
      }
      return low;
   }

};
