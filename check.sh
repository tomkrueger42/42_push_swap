ARG="`ruby -e "puts (0..5).to_a.shuffle.join(' ')"`"
ARG="30 60 100 20 80 50 90 -10 40 10"

#./push_swap $ARG
#./push_swap $ARG | wc -l
./push_swap $ARG | ./checker $ARG
