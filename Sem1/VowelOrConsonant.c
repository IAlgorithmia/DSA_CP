#include <stdio.h>
int main(){
    char c;
    printf("Enter the alphabet : \n");
    scanf("%c", &c);
    char arr[10] = {'A','E','I','O','U','a','e','i','o','u'};
    int i;
    int ans;
    for (i = 0; i<= 9; i++){
        if (arr[i] == c){
            ans = 1;
            break;
        }
        else if(arr[i] != c){
            ans = 0;    
        }
    }
    if (ans == 1){
        printf("%c is a vowel", c);
    }
    else if (ans == 0){
        printf("%c is a consonant", c);
    }
}
