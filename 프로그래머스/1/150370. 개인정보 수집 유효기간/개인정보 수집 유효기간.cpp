#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <sstream>

using namespace std;

int calculateTotalDays(int year, int month, int day) {
    return year * 12 * 28 + (month - 1) * 28 + day;
}

vector<int> solution(string today, vector<string> terms, vector<string> privacies) {
    vector<int> answer;
    
    // 오늘 날짜 계산해서 총 날짜로 바꾸기
    int year = stoi(today.substr(0, 4));
    int month = stoi(today.substr(5, 2));
    int day = stoi(today.substr(8, 2));
    int total = calculateTotalDays(year, month, day);
    
    // 약관 잘라서 map으로 저장
    map<char, int> termDurations;
    for (const string& term : terms) {
        stringstream ss(term);
        char name;
        int duration;
        ss >> name >> duration;
        termDurations[name] = duration;
    }
    
    // 프라이버시 날짜 계산
    for (int i = 0; i < privacies.size(); i++) {
        int y = stoi(privacies[i].substr(0, 4)); 
        int m = stoi(privacies[i].substr(5, 2)); 
        int d = stoi(privacies[i].substr(8, 2));
        char termName = privacies[i].back(); // privacies 벡터의 각 값에 가장 마지막 위치의 값 반환, 즉 여기서는 약관 반환
        int expiryDate = calculateTotalDays(y, m, d) + (termDurations[termName] * 28 - 1);
        
        // 비교
        if (expiryDate < total) {
            answer.push_back(i + 1);
        }
    }
    
    return answer;
}
