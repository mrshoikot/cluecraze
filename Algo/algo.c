#include <stdio.h>


int main(){

    int limit = 1000,show = 500,x,y,check,i,j,randIndex,t,k;
    int all[limit], tempLen, temp[show];


    // put 1 to limit in all array
    for(i=1;i<=limit;i++){
        all[i-1] = i;
    }

    while(nonZeroLen(all, limit) > 1){

        tempLen = 0;
        k=0;

        // Generate random show'th number
        while(tempLen < show){

            randIndex  = randomInt(0,limit/2-1);
            x = all[randIndex];
            y = randomInt(1,limit);

            // Check if x is present in temp
            if(isPresent(temp,x,tempLen) == 0){
                temp[k] = x;
                tempLen++;
                k++;
            }else if(isPresent(temp,y,tempLen) == 0){
                temp[k] = y;
                tempLen++;
                k++;
            }

        }

        // Sort Temp
        for(i=0; i<tempLen; i++)
        {
            for(j=i+1; j<tempLen; j++)
            {
                if(temp[i] > temp[j])
                {
                    t       = temp[i];
                    temp[i] = temp[j];
                    temp[j] = t;
                }
            }
        }

        printArr(temp, tempLen);

        scanf("%d", &check);

        if(check){
            for(i=0;i<limit;i++){
                if(isPresent(temp,all[i],tempLen)){
                    all[i] = all[i];
                }else{
                    all[i] = 0;
                }
            }
        }else{
            for(i=0;i<limit;i++){
                if(isPresent(temp,all[i],tempLen) == 0){
                    all[i] = all[i];
                }else{
                    all[i] = 0;
                }
            }
        }

        //printArr(all, limit);


    }

    for(i=0;i<limit;i++){
        if(all[i] != 0){
            printf("Your guessed number is :- %d\n", all[i]);
        }
    }

}


void printArr(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int nonZeroLen(int arr[], int n){
    int i,c=0;
    for(i=0;i<n;i++){
        if(arr[i] != 0){
            c++;
        }
    }
    return c;
}

int randomInt(int lower, int upper)
{

    return (rand() % (upper - lower + 1)) + lower;
}

int isPresent(int arr[],int n,int size){
    int i;
    for(i=0;i<size;i++){
        if(n==arr[i]){
            return 1;
        }
    }
    return 0;
}
