#include <string>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    vector<int> answer;
    
    map <string, int> mem;

	for (int i = 0; i < name.size(); i++) {
		mem[name[i]] = yearning[i];
	}

	for (int i = 0; i < photo.size(); i++) {
		int cnt = 0;
		for (int j = 0; j < photo[i].size(); j++) {
			cnt += mem[photo[i][j]];
		}
		answer.push_back(cnt);
	}
    
    return answer;
}