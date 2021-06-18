import java.util.ArrayList;

public class Prim {

	public void prim(int[][] G) {
		int[][] ans = new int[7][7];
		int[] flag = new int[G.length]; //点是否访问过
		for (int i = 0; i < G.length; i++) {
			flag[i] = 0;
		}
		
		ArrayList<Integer> list = new ArrayList<Integer>();
		list.add(0);
		flag[0] = 1;
		while (list.size() < G.length) {
			int mindistance = Integer.MAX_VALUE;
			int minj = -1;
			int mini = -1;
			for (int i = 0; i < list.size(); i++) {
				int ii = list.get(i);
				for (int j = 0; j < G.length; j++) {
					if (flag[j] != 1) {
						if (G[ii][j] != 0 && G[ii][j] < mindistance) {
							mindistance = G[ii][j];
							minj = j;
							mini = ii;
						}
					}
				}
			}
			flag[minj] = 1;
			list.add(minj);
			ans[mini][minj] = 1;
			ans[minj][mini] = 1;
		}
		System.out.println("Prim算法中，访问图的顺序为：");
		System.out.println(list);
		System.out.println("Prim算法中，构造的最小生成树为：");
		for (int i = 0; i < ans.length; i++) {
			for (int j = 0; j < ans[0].length; j++) {
				System.out.print(ans[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String[] args) {
		Prim prim = new Prim();
		int[][] graph = {{0,2,4,1,0,0,0},
			   			 {2,0,0,3,10,0,0},
			   			 {4,0,0,2,0,5,0},
			   			 {1,3,2,0,7,8,4},
			   			 {0,10,0,7,0,0,6},
			   			 {0,0,5,8,0,0,1},
			   			 {0,0,0,4,6,1,0}};
		prim.prim(graph);
	}
}
