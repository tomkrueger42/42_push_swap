ARG="`ruby -e "puts (0..10).to_a.shuffle.join(' ')"`"
ARG="l 2 1 -2 0 15 8 4 6 3 7 -1 12 35 21 42 10 11 9"

./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
