
current=2024
count=1
while [ $count -lt 21 ]
do 
    if [ $((current%4)) -eq 0 -a $((current%100)) -ne 0 -o $((current%400)) -eq 0 ]
    then 
        echo $current
        current=$((current+4))
        count=$((count+1))
    else
        current=$((current+4))
    fi 

done