#!/bin/bash

if [ -f "push_swap" ] && [ -f "checker" ]
then
	echo "files found"
else
	make
fi

echo "\n"
read -p "Please enter the number of elements : " size
read -p "Please enter the number of tests : " nb
echo "\n"

(( i = 0 ))

until [ $i -eq $nb ]
do
	./push_swap `ruby -e "puts (1..$size).to_a.shuffle.join(' ')"` | wc -l > var.txt
	read ret < var.txt
	(( i++ ))
	((average = $average + ret))
done

((average = $average / $i))

if [ $size -eq 100 ] && [ $average -gt 700 ]
then
	echo "\n\033[1mAverage moves on a list of size $size ($nb tests) :\033[0m \033[31m$average\033[0m."
elif [ $size -eq 500 ] && [ $average -gt 5500 ]
then
	echo "\n\033[1mAverage moves on a list of size $size ($nb tests) :\033[0m \033[31m$average\033[0m."
else
	echo "\n\033[1mAverage moves on a list of size $size ($nb tests) :\033[0m \033[32m$average\033[0m."
fi
