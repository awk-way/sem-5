while true
do
    echo "1. Area and Circumference of Circle"
    echo "2. Area of Rectangle"
    echo "3. Area of Triangle"
    printf "4. Exit\n"
    printf "Enter your choice: "
    read choice

    case $choice in
        1)
            echo "Enter the radius of Circle: "
            read rad
            ac=$(echo "scale=2; 3.14 * $rad * $rad" | bc)  
            circum=$(echo "scale=2; 2 * 3.14 * $rad" | bc)
            echo "Circumference of Circle = $circum"
            echo "Area of Circle = $ac"
            ;;
        2)
            echo "Enter the length of Rectangle:"
            read l
            echo "Enter the breadth of Rectangle:"
            read b
            ar=$(($l*$b))
            echo "Area of Rectangle = $ar"
            ;;
        3)
            echo "Enter the base of Triangle:"
            read base
            echo "Enter the height of Triangle:"
            read h
            at=$((($base*$h)/2))
            echo "Area of Triangle = $at"
            ;;
        4)
            echo "Exiting program..."
            break
            ;;
        *)
            echo "Invalid choice! Please try again."
            ;;
    esac
    echo 
done