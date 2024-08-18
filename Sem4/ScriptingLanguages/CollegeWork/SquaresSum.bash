
echo "sum of squares -->bash script"
echo -n "enter the number : "
read num
sq=0
while [ $num -gt 0 ]
do 
    rem=$((num%10))
    sq=$((sq+rem**2))
    num=$((num / 10))
done
echo -n "sum of square is : "
echo $sq