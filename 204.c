int countPrimes(int n){
    if (n <= 2) return 0; 
    bool v[n]; 
    memset(v, 0, n); 
    int t = 0, s = 0, c = 0; 

    for (int i = 2 ; i < sqrt(n)+1 ; i++) {  
        if (v[i] == false) {
            t = i*i; 
            while (t < n){
                v[t] = true;         
                t += i; 
            }
        }
    } 

    for (int i = 2 ; i< n; i++){ 
        c += !v[i]; 
    } 

      return c; 
