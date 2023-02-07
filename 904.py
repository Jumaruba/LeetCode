class Solution:
    def totalFruit(self, fruits: List[int]) -> int:
        m = {}
        fsize = len(fruits)
        s = 0 
        mmax = 0 
        if fsize <= 2: 
            return fsize
        # Adding things to our map 
        while len(m) < 2 and s < fsize: 
            if fruits[s] in m.keys(): 
                m[fruits[s]] += 1
                mmax += 1
            else: 
                m[fruits[s]] = 1
                mmax += 1
            s += 1

        e = s
        s = 0
        while e < fsize: 
            f = fruits[e]
            if f not in m.keys():
                m[f] = 1 # len(m) = 3 
                while len(m) != 2: 
                    m[fruits[s]] -= 1
                    if m[fruits[s]] == 0:
                        del m[fruits[s]]
                    s += 1
            else: 
                m[f] += 1 

            e += 1

            mmax = max(mmax, m[list(m.keys())[0]] + m[list(m.keys())[1]]) 

        return mmax

        
    

            
