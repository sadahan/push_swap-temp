#!/bin/bash

ret = 0
moyenne = 0
i = 0
ARG = `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`

until [ i -eq 100 ]
do
	ARG = `ruby -e "puts (1..500).to_a.shuffle.join(' ')"`
	ret = ./push_swap $ARG | wc -l
	let i = $i + 1
	moyenne = $moyenne + $ret
done
let moyenne = $moyenne / $i
echo "moyenne = $moyenne"