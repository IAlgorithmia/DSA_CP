    #include <stdio.h>
    struct complex
    {
        int real;
        int imaginary;
    };
    struct complex multi(struct complex a, struct complex b)
    {
        struct complex ans;
        ans.real = a.real*b.real - a.imaginary*b.imaginary;
        ans.imaginary = a.real*b.imaginary + a.imaginary*b.real;
        return ans;
    }
    int main()
    {
        struct complex c1;
        struct complex c2;
        printf("Enter two complex numbers : (Form - Real_Part Imaginary_Part)\n");
        scanf("%d %d %d %d", &c1.real, &c1.imaginary, &c2.real, &c2.imaginary);
        printf("The complex numbers are %d + %di and %d + %di\n", c1.real, c1.imaginary, c2.real, c2.imaginary);
        printf("Their sum is %d + %di\n", (c1.real + c2.real), (c1.imaginary + c2.imaginary));
        printf("Their product is %d + %di", multi(c1, c2));
        return 0;
    }