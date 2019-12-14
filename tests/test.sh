rm -f get_next_line
rm -f test_output

gcc -Wall -Wextra -Werror -D BUFFER_SIZE=5 -I. ../get_next_line.c ../get_next_line_utils.c test.c -o get_next_line
./get_next_line < simple

rm -f get_next_line
