/*

4 4 6
4 3 5
3 3 4
3 2 3
2 2 2
1 1 2
1 0 1
0 0 0

1 8 8
0 7 8


*/

class Solution {
public:
    int maximumScore(int a, int b, int c) {
        priority_queue<int, vector<int>>pq;

        pq.push(a);
        pq.push(b);
        pq.push(c);

        int steps=0;
        while(pq.size() > 1){
            int top1 = pq.top();
            pq.pop();
            int top2= pq.top();
            pq.pop();
            steps++;
            if(top1 - 1 > 0)
                pq.push(top1 - 1);
            if(top2 - 1 > 0)
                pq.push(top2 - 1);
        }

        return steps;
    }
};