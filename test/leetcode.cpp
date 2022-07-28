#include<iostream>
#include<vector>
#include<queue>
#include<stack>
#include<map>

using namespace std;

namespace lt315{
    vector<int> ans;

    void merge(vector<int>&nums,vector<int>&idx,int l ,int mid,int r){
        int l1=l,r1=mid,l2=mid+1,r2=r;
        vector<int> tmp;
        vector<int> index;
        while(l1<=mid&&l2<=r){
            if(nums[l1]>nums[l2]){
                ans[idx[l1]]+=r2-l2;
                tmp.push_back(nums[l1]);
                index.push_back(idx[l1]);
                l1++;
            }
            else{
                tmp.push_back(nums[l2]);
                index.push_back(idx[l2]);
                l2++;
            }
        }
        while(l1<=mid){
            ans[idx[l1]]+=r2-l2;
            tmp.push_back(nums[l1]);
            index.push_back(idx[l1]);
            l1++;
        }
        while(l2<=r){
            tmp.push_back(nums[l2]);
            index.push_back(idx[l2]);
            l2++;
        }
        for(int i=0;i<tmp.size();i++){
            nums[l+i]=tmp[i];
            idx[l+i]=index[i];
        }   
    }

    void qsort(vector<int>&nums,vector<int>&idx,int l,int r){
        if(l>=r){
            return;
        }
        int mid=(l+r)/2;
        qsort(nums,idx,l,mid);
        qsort(nums,idx,mid+1,r);
        merge(nums,idx,l,mid,r);
    }
    
    vector<int> countSmaller(vector<int>& nums) {

        int n=nums.size();
        ans.resize(n);
        
        vector<int> idx(n);       
        for(int i=0;i<n;i++){
             idx[i]=i;
        }
        qsort(nums,idx,0,n-1);
        return ans;
    }
    void test(){
        vector<int> nums={5,2,6,1};
        countSmaller(nums);
    }
}
int main(){
    return 0;
}