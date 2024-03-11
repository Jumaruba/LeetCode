public class Solution {
    public string CustomSortString(string order, string s) {
        Dictionary<char, int> DictOrder = new Dictionary<char, int>(); 
        PopulateDictOrder(ref order, ref DictOrder);
        return BubbleSort(ref DictOrder, ref s);
    }

    // xalalala
    public string BubbleSort(ref Dictionary<char, int> DictOrder, ref string s) {
        var sortedPos = s.Length; 
        var currPos = 0; 
        var arrS = s.ToCharArray();
        while(sortedPos > currPos) {
            for (var i = 1 ; i < sortedPos; i++) {
                if (!IsLessThan(ref DictOrder, arrS[i-1], arrS[i])){
                    Console.WriteLine($"{arrS[i-1]} {arrS[i]} {arrS}");
                    var temp = arrS[i];
                    arrS[i] = arrS[i-1];
                    arrS[i-1] = temp; 
                }
            }
            sortedPos--; 
        }
        return new String(arrS);
    }

    public bool IsLessThan(ref Dictionary<char, int> DictOrder, char c1, char c2){
        int pos1, pos2; 
        Console.WriteLine($"{c1} {c2}");
        if (!DictOrder.TryGetValue(c1, out pos1)) 
            return false;
        if (!DictOrder.TryGetValue(c2, out pos2))
            return true; 

        if (pos1 < pos2) return true; 
        return false; 
    }

    public void PopulateDictOrder(ref string order, ref Dictionary<char, int> DictOrder){
        for (var i = 0 ; i < order.Length; i++){
            DictOrder.Add(order[i], i);
        }
    }


}
