#include<iostream>
using namespace std;
int main() {
    while (true) {
        string runners;
        int teamScore['Z'+1] = {};
        int teamCount['Z'+1] = {};
        int numTeams = 0;
        int TeamSize = 0;
        cout << "Enter the race outcome: ";
        cin >> runners;
        if(runners=="done"){
            cout << "Thank you for running the race!";
            break;
        }
        for(int i = 0; i < runners.length(); ++i) {
            int index = runners[i] - 'A';
            teamScore[index]+=i+1;
            if(teamCount[index] == 0){
                ++numTeams;
            }
            ++teamCount[index];
            TeamSize = max(TeamSize, teamCount[index]);
        }
        if(TeamSize != runners.length()/numTeams){
            cout << "Teams don't have same amount of runners!" << endl;
            continue;
        }
        cout << endl;
        cout << "There are " << numTeams << " team(s)." << endl;
        cout << "Each team has " << TeamSize << " runner(s)." << endl;
        double topScore = runners.length() * 2;
        char winner;
        for(int i = 0; i < 26; i++) {
            if (teamScore[i] != 0){
                cout << (char)(65+i) << ": " << (double) teamScore[i]/TeamSize << endl;
                if (teamScore[i] < topScore) {
                    topScore = teamScore[i];
                    winner = (char)(65+i);
                }
            }
        }
        cout << "The winning team is " << winner << " with a score of: " << topScore/TeamSize << endl;
    }
    return 0;
}