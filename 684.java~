// We gonna apply the kruskal algorithm. 
class Solve{ 
	public static int[] parent;  

	public static void main(String args[]){
		int[][] edges = {{1,2},{1,3},{2,3}};  
		int[] res = solve(edges);  
		for (int i: res) System.out.print(i + " "); 
	} 

	public static int[] solve(int[][] edges){ 
		parent = new int[edges.length +1];     
		boolean value;  
		for (int i = 0 ; i < edges.length; i++)
			parent[i] = -1;  

		for (int i = 0 ; i < edges.length; i++){
			value = union(edges[i][0], edges[i][1]);  
			if (!value){
				int[] response = {edges[i][0], edges[i][1]}; 
				return response;  
			}

		}   
		int[] r = {0,0}; 
		return  r;
	}   

	public static int find(int n1){
		if (parent[n1] > 0) return find(parent[n1]);  
		return n1; 
	} 

	public static boolean union(int n1, int n2){   
		int par1 = find(n1); 
		int par2 = find(n2);   
		if (par1 > par2) {
			parent[par2] += parent[par1]; 
			parent[par1] = par2;  
			return true; 
		}
		else if (par2 > par1){
			parent[par1] += parent[par2]; 
			parent[par2] = par1;  
			return true; 
		}   
		return false; 	
 		
	} 
} 
