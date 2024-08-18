#include <stdio.h>
int main(){
    float a,b;
    printf("Enter number a\n");
    scanf("%f", &a);
    printf("Enter number b\n");
    scanf("%f", &b);
    printf("The sum is %.2f\n", a+b);
    printf("The division of 5 by 2 results in %.2f", 5/2);
    Division operator in C only returns integer
    const float c = 32;
    c = 34;
    printf("My \t backslash \\n Hey there \n");  
    printf("sound aaaja ree");
    int a,b,c;
    a=4<5;
    b=5>2;
    c=a && b;
    printf("%d", c);
    if (a && b){
        printf("Both statements are true");
    }
    int i;
    for (i=0; i<=5;i++){
        printf("%d\n", i);
    }
    char a = "Vaibhav";
    printf("The name is %c",a);
    printf("Enter the name ");
    scanf("%c", &a);
    printf("The name is : %s", a);
    int i=1;
    for (;i<=5;){
        printf("The value of i is %d\n", i);
        i++;
    }
    // TYPE-CASTING
    
    int a;
    a=54;
    printf("%f",(float)a);
    printf("%d", 2&3);
    return 0;
}