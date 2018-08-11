#!/bin/shell
RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[32m'
YELL='\033[33m'
echo "\n\n\n"




function test(){

    args
        : string PLAYER
        : int TEST
        : string MAP

    echo "${YELL}==============================${PLAYER}========${MAP}===========================${NC}"
    echo "\n\n"
    echo "${GREEN}My    ===> O"
    echo "${RED}Enemy ===> X${NC}"

    c=1
    while [ $c -le 5 ]
    do
        ./resources/filler_vm -f resources/maps/map0${MAP} -p1 ./obaranni.filler -p2 ./resources/players/${PLAYER} > tests/log/${TEST}
        echo "\nTest ${TEST}"
        ME=$(cat tests/log/${TEST} | grep "== O")
        EN=$(cat tests/log/${TEST} | grep "== X")
        echo "     ${GREEN}${ME}\n     ${RED}${EN}${NC}"
        ((TEST++))
        ((c++))
    done

    echo "\n\n${YELL}          ==========REVERS==========${NC}"

    echo "${GREEN}My    ===> X"
    echo "${RED}Enemy ===> O${NC}"

    c=5
    while [ $c -le 9 ]
    do
        ./resources/filler_vm -f resources/maps/map0${MAP} -p2 ./obaranni.filler -p1 ./resources/players/${PLAYER} > tests/log/${TEST}
        echo "\nTest ${TEST}"
        EN=$(cat tests/log/${TEST} | grep "== O")
        ME=$(cat tests/log/${TEST} | grep "== X")
        echo "     ${GREEN}${ME}\n     ${RED}${EN}${NC}"
        ((TEST++))
        ((c++))
    done
   }


PLAYER='abanlin.filler'
TEST='1'
MAP='0'
test


PLAYER='carli.filler'
TEST='10'
MAP='0'
test

PLAYER='carli.filler'
TEST='10'
MAP='2'
test
