#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <math.h>

int removeDuplicates(int* nums, int numsSize);
int maxProfit(int* prices, int pricesSize);
void rotate(int* nums, int numsSize, int k);
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize);
int* plusOne(int* digits, int digitsSize, int* returnSize);
void moveZeroes(int* nums, int numsSize);


int main() {
    int nums1[]={9,0,7,6,5,0,0,2,1,0};
    int nums2[]={9,9};

    moveZeroes(nums1,10);
    for (int i = 0; i < 10; ++i) {
        printf("%d",nums1[i]);
    }
}
//删除排序数组中重复项
/**
 * 该题使用快慢指针法，慢指针指示的值与快指针指示的值相比较，不同时则在慢指针的下一个进行替换。
 * **/
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
/**
 * 每次都是低卖高卖
 * **/
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
/**
 * 方法一 暴力循环k次，每次移动一个单位
 * 方法二 使用额外数组
 * 方法三 循环替换，直接将数字放到最终位置 需要额外的temp空间来记录最终位置上的值
 * 方法四 使用观察到旋转就是将数组进行三次翻转 使用reverse就可以翻转数组
 * **/
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
/**
 * 该题有两种解法
 * 一种是排序后重复元素必然相邻
 * 一种是使用哈希表，表中同种元素只能有一个 set HashSet
 * **/
int cmp(const void* _a, const void* _b) {
    int *a = (int*)_a, *b = (int*)_b;
    return *a == *b ? 0 : *a > *b ? 1 : -1;
}

bool containsDuplicate(int* nums, int numsSize){
    if (numsSize<2){
        return false;
    }
    qsort(nums,numsSize, sizeof(int),cmp);
    for (int i = 0; i < numsSize-1; ++i) {
        if (nums[i]==nums[i+1]){
            return true;
        }
    }
    return false;
}
//只出现一次的数字
/**
 * 该题可以使用哈希表和xor运算来进行
 * **/
int singleNumber(int* nums, int numsSize){
    for (int i = 1; i < numsSize; ++i) {
        nums[0] ^= nums[i];
    }
    return nums[0];
}

//两个数组的交集 II
/**
 *重复的元素时，首先想到哈希表
 * 两数组比较时，先排序后使用快慢指针
 * **/
int min(int a ,int b){
    if (a > b) return b;
    return a;
}

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize){
    qsort(nums1,nums1Size,sizeof(int),cmp);
    qsort(nums2,nums2Size, sizeof(int),cmp);
    *returnSize = 0;
    int* returnArray = (int*) malloc(sizeof(int)*min(nums1Size,nums2Size));
    int up=0,down=0;
    while (up < nums1Size && down < nums2Size){
        if (nums1[up] > nums2[down]) {
            down++;
        }else if (nums1[up] == nums2[down]) {
            returnArray[(*returnSize)++] = nums1[up];
            up++;
            down++;
        } else up++;
    }
    return returnArray;
}

//加一
/**
 * 大的数不能直接定义出来
 * **/
int* plusOne(int* digits, int digitsSize, int* returnSize){
    int carry = 1;
    *returnSize = 0;
    int* plusArray = (int*) malloc(sizeof(int)*(digitsSize+1));
    for (int i = digitsSize - 1; i >= 0; --i) {
        if (carry == 1){
            if (digits[i] + 1 == 10){
                carry = 1;
            } else{
                carry =0;
            }
            plusArray[(*returnSize)++] = (digits[i] + 1) % 10;
        } else{
            plusArray[(*returnSize)++] = digits[i];
        }

        if (i==0 & carry == 1){
            plusArray[(*returnSize)++] = 1;
        }
    }
    if ((*returnSize) == digitsSize){
        reverse(plusArray,0,digitsSize);
    } else{
        reverse(plusArray,0,digitsSize+1);
    }
    return plusArray;
}
//移动零
void moveZeroes(int* nums, int numsSize){
    int j=0;
    for (int i = 0; i <numsSize; ++i) {
        if (nums[i]!=0){
           nums[j] = nums[i];
           j++;
        }
    }
    for (int k = j; k < numsSize; ++k) {
        nums[j] = 0;
    }
}