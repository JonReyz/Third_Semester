#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]){
    int n;
    scanf("%d",&n);
    int *vec = (int *)malloc(n*sizeof(int));
    int i,j,t,counter;
    t = 0;
    for(i = 0; i < n; i++)
        vec[i] = 1;
    for(i = 0; i < n; i++){
        for(j = t;j <n; ){
            vec[j] = !vec[j];
            if(t == 0)
                j++;
            else if(t == 1)
                j = j+2;
            else
                j = j + t;
        }
        t++;
    }
    counter = 0;
    for(i =0 ; i < n; i++){
        if(vec[i] == 1)
            counter++;
    }
    printf("%d\n",counter);
    free(vec);
    return 0;
}