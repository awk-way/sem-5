echo "Enter a number:"
read c
x=$c
sum=0

numdig=${#c}

while [ $x -gt 0 ]
do
    r=$(($x % 10))
    pow=$(echo "$r^$numdig" | bc)
    sum=$(echo "$sum + $pow" | bc)
    x=$(($x / 10))
done

if [ $sum -eq $c ]
then
    echo "It is an Armstrong number"
else
    echo "It is not an Armstrong number"
fi
