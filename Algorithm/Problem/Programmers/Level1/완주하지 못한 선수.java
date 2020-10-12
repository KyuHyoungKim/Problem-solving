import java.util.Arrays;
class Solution {
    public String solution(String[] participant, String[] completion) {
        String answer = "";
        int N = participant.length;
        int M = completion.length;
        Arrays.sort(participant);
        Arrays.sort(completion);
        
        for(int i = 1 ; i < M; i++)
            if(!participant[i].equals(completion[i])){
                answer = participant[i];
                break;
            }
        
        if(answer.length() == 0)
            answer = participant[N-1];
        return answer;
    }
}
