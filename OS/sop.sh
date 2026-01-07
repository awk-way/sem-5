echo "Enter a number:"
read n
sum=0
i=2
primes=""

while [ $i -le $n ]
do
    ip=1
    j=2
    di=$(($i/2))
    while [ $j -le $di ]
    do
        dj=$(($i%$j))
        if [ $dj -eq 0 ]
        then
            ip=0
            break
        fi
        j=$(($j+1))
    done

    if [ $ip -eq 1 ]
    then
        sum=$(($sum+$i))

        if [ -z "$primes" ]
        then
            primes="$i"
        else
            primes="$primes + $i"
        fi
    fi
    i=$(($i+1))
done

echo "$primes = $sum"
