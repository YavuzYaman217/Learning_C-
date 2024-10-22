#include <stdio.h>
#include <stdlib.h>



int *Arr(){
    int *nums;
    int *temp = (int*)malloc(2*sizeof(int));
    unsigned short target = 9;
    int numbers[] = {2,11,7,15};
    int numbers_S = sizeof(numbers)/sizeof(numbers[0]);
    nums = (int*)calloc(numbers_S,sizeof(int));
    for(int i = 0;i < numbers_S;i++){
        nums[i] = numbers[i];
    }

    for(int j = 0; j < numbers_S;j++){
        int remain = target - nums[j];
        for(int k = 0;k< numbers_S;k++){
            if(remain == nums[k]){
                temp[0] = j;
                temp[1] = k;
                free(nums);
                return temp;
            }
        }
    }
    free(nums);
    return NULL;
}



int main(){
    int *results = Arr();
    if(results != NULL){
        printf("Indices: %d, %d\n", results[0], results[1]);
        free(results);
    }
    else {
        printf("No valid pair found.\n");
    }

    return 0;
}

/*
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *temp = (int*)calloc(2,sizeof(int));
    for(int i = 0;i< numsSize;i++){
        for(int j = i+1;j<numsSize;j++){
            if(nums[i] + nums[j] == target){
                temp[0] = i;
                temp[1] = j;
                return temp;
            }
        }
    }
    return -1;
}
*/
