echo "Enter a number : "
read num
count=2
check=0
while [ $count -lt $num ]
do
remainder=`expr $num % $count`
count=$((count + 1))
if [ ${remainder} = 0 ]
then
check=1
break
fi
done
if [ $check = 0 ]
then
echo "The number is prime!"
else
echo "The number is not prime!"
fi
