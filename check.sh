ARG="5 4 3 2 1"
ARG="`ruby -e "puts (0..9).to_a.shuffle.join(' ')"`"

./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
