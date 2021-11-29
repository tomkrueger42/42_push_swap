ARG="4 67 100000 3 87 23 1000 -10000 10 2"
#ARG="`ruby -e "puts (1..10).to_a.shuffle.join(' ')"`"

./push_swap $ARG
#./push_swap $ARG | wc -l
#./push_swap $ARG | ./checker $ARG
