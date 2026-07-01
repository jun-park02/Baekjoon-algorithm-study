/**
 * 문제 : 프로그래머스
 * 링크: https://school.programmers.co.kr/learn/courses/30/lessons/388351
 * 난이도: level 1
 * 알고리즘: 구현
 *
 * 풀이 아이디어:
 * - N<=1000 이기 때문에 그냥 for문으로 순회하면서 카운팅을 하면 될 것 같다고 생각했음.
 * - schedules와 timelogs를 순회하면서 카운팅.
 * - 토요일과 일요일은 미리 0으로 처리.
 * 
 * 메모:
 * - 세부 구현에서 뭔가 더 좋게 바꿀 수 있을거같은데
 *
 * 시간 복잡도: 7 * n -> O(N)
 * 공간 복잡도: O(N). 함수가 호출될 때 두 벡터가 복사되므로
 */

#include <string>
#include <vector>

using namespace std;

int solution(vector<int> schedules, vector<vector<int>> timelogs, int startday) {
    int answer = 0;
    int saturday = 6 - startday;
    int sunday = saturday + 1;

    if (startday == 7) {
        saturday = 6;
        sunday = 0;   
    }

    for (int i = 0; i < schedules.size(); i++) {
        int schedule_hour = schedules[i] / 100;
        int schedule_minutes = (schedules[i] % 100) + 10;

        if (schedule_minutes >= 60) {
            schedule_hour++;
            schedule_minutes %= 60;
        }

        int deadline = schedule_hour * 100 + schedule_minutes;

        timelogs[i][saturday] = 0;
        timelogs[i][sunday] = 0;

        for (int j = 0; j < 7; j++) {    
            int current_timelog = timelogs[i][j];

            if (current_timelog > deadline) break;

            if (j == 6) answer++;
        }
    }

    return answer;
}