#include <stdio.h>
int printstr(char str[]){
    int i = 0;
    while (str[i] != '\0'){
        printf("%c", str[i]);
        i++;
    }
    printf("\n");
    return 0;
}
int main(){
    // char str[] = {'v', 'a','i', 'b', 'h', 'a', 'v', '\0'};
    // char str[8] = "vaibhav";
    char str[55];
    gets(str); //this is preferred more over scanf for strings because we cant take white 
               //spaces using scanf !!!!
    printf("Using custom built function : \n");
    printstr(str);
    printf("Using printf : \n%s \n", str);
    printf("Using puts : \n");
    puts(str);
    return 0;
}