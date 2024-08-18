#include <stdio.h>

int main(int argc, char const *argv[])
{
    // KM to miles, Inches to foot, cms to inches, Pound to kgs, Inches to meters
    int dec = 1, ch = 0;
    float val = 0, ans = 0;
    while (dec == 1){
        printf("Welcome to the conversion factory\nThe choices are :\n");
        printf("1. KM to Miles\n2. Inches to feet\n3. CM to inches\n4. Pound to Kg\n5. Inches to meters\n");
        printf("Enter your choice as per item number\n");
        scanf("%d", &ch);
        if (ch == 1)
        {
            printf("Enter the value\n");
            scanf("%f", &val);
            ans = val/1.6;
            printf("The answer is %.2f\n", ans);
        }
        else if (ch == 2)
        {
            printf("Enter the value\n");
            scanf("%f", &val);
            ans = val/6;
            printf("The answer is %.2f\n", ans);
        }
        else if (ch == 3)
        {
            printf("Enter the value\n");
            scanf("%f", &val);
            ans = val/2.54;
            printf("The answer is %.2f\n", ans);
        }
        else if (ch == 4)
        {
            printf("Enter the value\n");
            scanf("%f", &val);
            ans = val/2.205;
            printf("The answer is %.2f\n", ans);
        }
        else if (ch == 5)
        {
            printf("Enter the value\n");
            scanf("%f", &val);
            ans = val/39.37;
            printf("The answer is %.2f\n", ans);
        }
        else {
            printf("WTF Bro enter a valid input\n");
        }      
        printf("Do you want to perform conversion again? (Enter 1 for Yes and 0 for No)\n");
        scanf("%d", &dec);
        if (dec==0){
            printf("Quitting the program. See you soon!\n");
        }
    } return 0;
    }
        // ALTERNATIVE SOLUTION :
        
int main()
{
    char input;
   float kmsToMiles = 0.621371;
   float inchesToFoot = 0.0833333;
   float cmsToInches = 0.393701;
   float poundToKgs = 0.453592;
   float inchesToMeters = 0.0254;
   float first, second;
   while (1)
   {
       printf("Enter the input character. q to quit\n       1. kms to miles\n       2. inches to foot\n       3. cms to inches\n       4. pound to kgs\n       5. inches to meters\n");

       scanf(" %c", &input);
       printf("The character is '%c'", input);
       switch (input)
       {
       case 'q':
        printf("Quitting the program...");
        goto end;
        break;

        case '1':
        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);
        second = first * kmsToMiles;
        printf("%.2f Kms is equal to %.2f Miles\n\n\n", first, second);
        break;

        case '2':
        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);
        second = first * inchesToFoot;
        printf("%f Inches is equal to %f Foot\n", first, second);
        break;

        case '3':
        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);
        second = first * cmsToInches;
        printf("%f Cms is equal to %f Inches\n", first, second);
        break;

        case '4':
        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);
        second = first * poundToKgs;
        printf("%f Pounds is equal to Kgs %f \n", first, second);
        break;

        case '5':
        printf("Enter quantity in terms of first unit\n");
        scanf("%f", &first);
        second = first * inchesToMeters;
        printf("%f inches is equal to %f meters \n", first, second);
        break;

       default:
       printf("In default now");
           break;
       }
   }
   end:
    return 0;
}