#include<iostream>
#include<vector>
using namespace std;

int maxArea(vector<int>& height) {
    int m_area = -1, area;
    for(int i = 0 ; i < height.size(); i++){
        for(int j = 0; j < i ; j++){
            if(height[j] >= height[i]){
                area = height[i] * abs(i-j);
                break;
            }
            else if(j == -1) area = height[i] * abs(i-j);
            else area = min(height[i], height[j]) * abs(i-j);
        }
        m_area = max(m_area,area);
    }
    return m_area;
}

int main(){
    vector<int> height;
    int arr[] = {1,8,6,2,5,4,8,3,7};
    height.assign(arr, arr+sizeof(arr) / sizeof(arr[0]));
    maxArea(height);
    return 0;
}