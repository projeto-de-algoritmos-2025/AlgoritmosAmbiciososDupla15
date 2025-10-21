#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        int n = startTime.size();

        // Cria um vetor de "jobs" 
        vector<array<int, 3>> jobs(n);
        for (int i = 0; i < n; ++i) {
            jobs[i] = {endTime[i], startTime[i], profit[i]};
        }

        // Ordena os trabalhos pelo tempo de término 
        sort(jobs.begin(), jobs.end());
        
        // dp[i] guardará o lucro máximo possível considerando trabalhos até o índice i
        vector<int> dp(n);
        dp[0] = jobs[0][2]; 
        
        // Processa todos os trabalhos do segundo em diante
        for (int i = 1; i < n; ++i) {
            // Lucro atual se escolhermos o trabalho i
            int currProfit = jobs[i][2];
            
            // Busca binária para encontrar o último trabalho que NÃO sobrepõe o atual
            int l = 0, r = i - 1, lastNonOverlap = -1;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (jobs[mid][0] <= jobs[i][1]) {
                    lastNonOverlap = mid;
                    l = mid + 1;  
                } else {
                    r = mid - 1;  
                }
            }
            
            // Se encontrou um trabalho compatível, soma o lucro máximo até ele
            if (lastNonOverlap != -1)
                currProfit += dp[lastNonOverlap];
            
            dp[i] = max(dp[i - 1], currProfit);
        }
        
        return dp[n - 1];
    }
};
