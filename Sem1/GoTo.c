#include <stdio.h>
int main(int argc, char const *argv[])
{
    // printf("Sometext inbetween the goto statements\n");
    // Welcome:
    //     printf("How are you?\n");
    //     goto end;
    // goto Welcome;
    // end:
    //     printf("We are at the end\n");
    // return 0;
    int index,a,b,c=1;
    for (a=0, index=0;a<8;a++, index++){
        printf("The value of index is %d\n", index);
        for (b=0;b<8;b++){
            printf("Enter any value. Enter 0 to exit\n");
            scanf("%d",&c);
            printf("The value entered by you is %d\n", c);
            if (c==0){
                goto end;
            }
        }
    }
    end:
    return 0;
}
