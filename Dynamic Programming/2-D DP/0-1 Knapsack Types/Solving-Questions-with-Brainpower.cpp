/*
You are given a 0-indexed 2D integer array questions where questions[i] = [pointsi, brainpoweri].

The array describes the questions of an exam, where you have to process the questions in order (i.e., starting from question 0) and 
make a decision whether to solve or skip each question. 
Solving question i will earn you pointsi points but you will be unable to solve each of the next brainpoweri questions. 
If you skip question i, you get to make the decision on the next question.

For example, given questions = [[3, 2], [4, 3], [4, 4], [2, 5]]:
If question 0 is solved, you will earn 3 points but you will be unable to solve questions 1 and 2.
If instead, question 0 is skipped and question 1 is solved, you will earn 4 points but you will be unable to solve questions 2 and 3.
Return the maximum points you can earn for the exam.

Input: questions = [[3,2],[4,3],[4,4],[2,5]]
Output: 5
Explanation: The maximum points can be earned by solving questions 0 and 3.
- Solve question 0: Earn 3 points, will be unable to solve the next 2 questions
- Unable to solve questions 1 and 2
- Solve question 3: Earn 2 points
Total points earned: 3 + 2 = 5. There is no other way to earn 5 or more points.

Solution:                                                                                                                                                   */
    vector<long long>dp;
    long long knp(vector<vector<int>>& q,int n){
        if(n<0) return 0;
        if(dp[n]!=-1)  return dp[n];
        return dp[n]=max(q[n][0]+knp(q,n-q[n][1]-1), knp(q,n-1));  
    }
    
    long long mostPoints(vector<vector<int>>& q) {
        int n=q.size();
        reverse(q.begin(),q.end());
        for(int i=0;i<=n;i++) dp.push_back(-1);
        return knp(q,n-1);
    }
