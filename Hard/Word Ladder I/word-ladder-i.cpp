//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
    int wordLadderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> map;
        queue<pair<string,int>> q;
        
        for(int i=0;i<wordList.size();i++){
            map[wordList[i]]++;
        }
        
        q.push({beginWord,1});
        int len = 0;
        while(!q.empty() || map.size()==0){
            string word = q.front().first;
            int l = q.front().second;
            q.pop();
            if(word == endWord){
                len = l;
                break;
            }
            for(int i=0;i<wordList[0].length();i++){
                for(int j=0;j<26;j++){
                    string temp = word;
                    temp[i] = j+'a';
                    if(map[temp]){
                        q.push({temp,l+1});
                        map.erase(temp);
                    }
                }
            }
        }
        return len;
    }
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<string>wordList(n);
		for(int i = 0; i < n; i++)cin >> wordList[i];
		string startWord, targetWord;
		cin >> startWord >> targetWord;
		Solution obj;
		int ans = obj.wordLadderLength(startWord, targetWord, wordList);
		cout << ans << "\n";
	}
	return 0;
}
// } Driver Code Ends