//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
private:
    void solve(vector<vector<int>>& image, int sr, int sc, int newColor,int initialColor,
    int rl,int cl){

        image[sr][sc]=newColor;
        if(sr-1>=0 && image[sr-1][sc]==initialColor && image[sr-1][sc]!=newColor){
            solve(image,sr-1,sc,newColor,initialColor,rl,cl);
        }
        if(sr+1<rl && image[sr+1][sc]==initialColor && image[sr+1][sc]!=newColor ){
            solve(image,sr+1,sc,newColor,initialColor,rl,cl);
        }
        if(sc-1>=0 && image[sr][sc-1]==initialColor && image[sr][sc-1]!=newColor){
            solve(image,sr,sc-1,newColor,initialColor,rl,cl);
        }
        if(sc+1<cl && image[sr][sc+1]==initialColor && image[sr][sc+1]!=newColor ){
            solve(image,sr,sc+1,newColor,initialColor,rl,cl);
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int initialColor=image[sr][sc];
        int rl=image.size();
        int cl=image[0].size();
        // vector<vector<int>>visited(rl, vector<int>(cl, 0));https://media.geeksforgeeks.org/img-practice/prod/courses/1/Web/Content/3-90-fab-v3_1703855049.svg
        solve(image,sr,sc,newColor,initialColor,rl,cl);
        return image;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>image(n, vector<int>(m,0));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> image[i][j];
		}
		int sr, sc, newColor;
		cin >> sr >> sc >> newColor;
		Solution obj;
		vector<vector<int>> ans = obj.floodFill(image, sr, sc, newColor);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
	}
	return 0;
}
// } Driver Code Ends