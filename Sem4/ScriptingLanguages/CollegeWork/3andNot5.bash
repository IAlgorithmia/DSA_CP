start=50
while [ $start -lt 101 ]
do 
    if [ $((start%3)) -eq 0 -a $((start%5)) -ne 0 ]
    then 
        echo $start
    fi 
    start=$((start+1))
done 