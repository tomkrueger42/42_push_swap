ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
ARG="5 4 3 2 1"

./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
