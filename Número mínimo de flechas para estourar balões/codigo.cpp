#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;

        // Ordenar primeiro os balões por tempo de término 
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        //Inicializa a contagem da primeira flecha na primeira posição
        int arrows = 1;
        long long arrow_pos = points[0][1]; 

        //Percorre o vetor recebido, sempre aumentando o número de flechas quando se torna necessário
        //Caso um balão comece e não intercale com o anterior. Ai aumenta a contagem de flechas e passa-se
        //para o próxima posição
        for (auto& balloon : points) {
            if (balloon[0] > arrow_pos) {
                arrows++;
                arrow_pos = balloon[1];
            }
        }

        return arrows;
    }
};
