echo "Enter a number:"
read p
m=1
echo "Pattern with $p rows: "
while [ $m -le $p ]
do
	a=$m
	while [ $a -le $p ]
	do
		printf " "
		a=$(($a+1))
	done

	n=1
	while [ $n -le $m ]
	do
		printf "*"
		n=$(($n+1))
	done

	i=1
	while [ $i -lt $m ]
	do
		printf "*"
		i=$(($i+1))
	done
	echo
	m=$(($i+1))
done
