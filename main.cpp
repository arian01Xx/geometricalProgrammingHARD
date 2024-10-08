#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n=points.size();
        if(n<=2) return n;

        int max_points=0;

        for(int i=0; i<n; i++){
            unordered_map<string,int> slope_count;
            int duplicate=1;
            int vertical=0;

            for(int j=i+1; j<n; j++){
                int dx=points[j][0]-points[i][0];
                int dy=points[j][1]-points[i][1];
                if(dx==0 && dy==0){
                    duplicate++;
                }else if(dx==0){
                    vertical++;
                }else{
                    int g= __gcd(dx,dy);
                    dx/=g;
                    dy/=g;
                    if(dx<0){
                        dx=-dx;
                        dy=-dy;
                    }
                    string slope=to_string(dx)+"/"+to_string(dy);
                    slope_count[slope]++;
                }
            }
            int current_max=vertical;
            for(auto& kv: slope_count){
                current_max=max(current_max, kv.second);
            }
            max_points=max(max_points, current_max+duplicate);
        }
        return max_points;
    }
};

int main(){
    return 0;
}