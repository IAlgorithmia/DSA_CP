echo "enter three numbers : "
read num1
read num2
read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then 
    echo "$num1 is the largest"
elif [ $num2 -gt $num3 -a $num2 -gt $num1 ]
then 
    echo "$num2 is the largest"
else
    echo "$num3 is the largest"
fi 
