echo "Numbers between 50-100 that are divisible by 3 & not by 5"
i=50
while [ $i -lt 100 ]
do
	di=$(($i%3))
	if [ $di -eq 0 ]
	then
		dj=$(($i%5))
		if [ $dj -ne 0 ]
		then
			printf "$i, "
		fi
	fi
	i=$(($i+1))
done
echo
