ARG="100 2 1 -2 0 15 8 4 6 3"
ARG="`ruby -e "puts (-4..5).to_a.shuffle.join(' ')"`"

./push_swap $ARG
./push_swap $ARG | wc -l
#./push_swap $ARG | ./checker $ARG
