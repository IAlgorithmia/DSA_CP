function find_sum()
{
sum=`expr $1 + $2`
echo $sum
diff=`expr $1 - $2`
echo $diff
}
find_sum 20 30
res=`find_sum 50 80` #we don't get 130 twice because the output of the echo for this instance is stored in the res variable itself, without the res variable, print hoga, else res mein store ho jayega
#more than one echo ho rahe hue to saare res mein save ho jayenge
echo $res