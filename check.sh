ARG="`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`"
./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
