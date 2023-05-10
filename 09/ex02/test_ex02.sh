#!bin/bash
make re;

GREEN='\033[0;32m'
YELLOW='\033[1;33m'
RED='\033[0;31m'
NC='\033[0m'

echo -e "${YELLOW}Running PmergeMe with arguments 'a b c'${NC}"
./PmergeMe "a" "b" c

echo -e "${YELLOW}Running PmergeMe with arguments '3 -2 1'${NC}"
./PmergeMe 3 -2 1

echo -e "${YELLOW}Running PmergeMe with arguments '5 4 3 3 2 1'${NC}"
./PmergeMe 5 4 3 3 2 1

echo -e "${YELLOW}Running PmergeMe with arguments '1 2 3'${NC}"
./PmergeMe 1 2 3

echo -e "${YELLOW}Running PmergeMe with arguments '3 2 1'${NC}"
./PmergeMe 3 2 1

echo -e "${YELLOW}Running PmergeMe with 30 random numbers between 2 and 1000${NC}"
./PmergeMe $(jot -r 30 2 1000 | tr '\n' ' ')

echo -e "${YELLOW}Running PmergeMe with 50 random numbers between 2 and 1000${NC}"
./PmergeMe $(jot -r 50 2 1000 | tr '\n' ' ')

echo -e "${YELLOW}Running PmergeMe with 80 random numbers between 2 and 5000${NC}"
./PmergeMe $(jot -r 80 2 5000 | tr '\n' ' ')

echo -e "${YELLOW}Running PmergeMe with 100 random numbers between 2 and 5000${NC}"
./PmergeMe $(jot -r 100 2 5000 | tr '\n' ' ')

echo -e "${GREEN}All PmergeMe executions completed.${NC}\n"
echo -e "Running make fclean: "

make fclean;
