ARG="`ruby -e "puts (0..99).to_a.shuffle.join(' ')"`"
ARG="100 2000 1000 -2000 90 1500 8 4 6 3"

./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
