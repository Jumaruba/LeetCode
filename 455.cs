public class Solution {
    public int FindContentChildren(int[] children, int[] cookies) {
        cookies = cookies.OrderByDescending(c => c).ToArray(); 
        children = children.OrderByDescending(c => c).ToArray(); 
        var childPos = 0; 
        var cookiePos = 0; 
        var nSatisfied = 0;     // Number of satisfied children; 
        while (cookiePos < cookies.Length && childPos < children.Length){
            if (children[childPos] <= cookies[cookiePos]){
                nSatisfied += 1; 
                childPos += 1;
                cookiePos += 1; 
                continue; 
            }
            childPos += 1; 
        }

        return nSatisfied; 
    }
}
