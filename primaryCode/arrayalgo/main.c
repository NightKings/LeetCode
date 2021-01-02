#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct hashTable {
    int key;
    UT_hash_handle hh;
};

int removeDuplicates(int* nums, int numsSize);
int maxProfit(int* prices, int pricesSize);
void rotate(int* nums, int numsSize, int k);

int main() {

    int* a;
    a = (int *)malloc(10*sizeof (int));
    
    if (a[4] == NULL)
        printf("%d",1);
}
//删除排序数组中重复项
int removeDuplicates(int* nums, int numsSize){
    int i = 0;
    for (int j = 0; j < numsSize; ++j) {
        if (nums[i]!=nums[j]){
            i++;
            nums[i]=nums[j];
        }
    }
    return i+1;

}
//买卖股票的最佳时机 II
int maxProfit(int* prices, int pricesSize){
    int sum = 0;
    for(int i = 0; i < pricesSize-1;i++){
        if(prices[i]<prices[i+1]){
            sum += prices[i+1] - prices[i];
        }
    }
    return sum;
}
//旋转数组
void reverse(int* nums, int start, int end){
    for(int i = 0; i < (end-start)/2;i++){
        int temp = nums[start + i];
        nums[start + i] = nums[end - i - 1];
        nums[end - i - 1] = temp;
    }
}
void rotate(int* nums, int numsSize, int k){
    if(k<1) return;
    if(numsSize<1) return;
    k %= numsSize;
    reverse(nums,0,numsSize);
    reverse(nums,0,k);
    reverse(nums,k,numsSize);
}
//存在重复元素
bool containsDuplicate(int* nums, int numsSize){
    int* a;
    a = (int *)malloc(numsSize*sizeof (int));
    for (int i = 0; i < numsSize; ++i) {
        if (a[nums[i]%numsSize] == NULL){
            a[nums[i]%numsSize] = nums[i];
        } else{
            return true;
        }
        return false;
    }
    return false;
}

