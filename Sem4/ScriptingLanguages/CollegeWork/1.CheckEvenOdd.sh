echo "Enter a number : "
read num
remainder=`expr $num % 2`
if [ $remainder = 0 ]
then
echo "Number is even"
else
echo "number is odd"
fi
