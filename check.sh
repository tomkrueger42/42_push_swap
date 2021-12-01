ARG="30 60 100 20 80 50 90 -10 40 10"
ARG="`ruby -e "puts (0..500).to_a.shuffle.join(' ')"`"

#./push_swap $ARG
./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
