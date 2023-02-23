#!/bin/bash
N3=3
N5=5
N100=100
N500=500

RED="\e[31m"
ENDCOLOR="\e[0m"

ARGS3=$(./number_generator/generate $N3)
ARGS5=$(./number_generator/generate $N5)
ARGS100=$(./number_generator/generate $N100)
ARGS500=$(./number_generator/generate $N500)

RES3=$(./push_swap $ARGS3 | wc -l)
RES5=$(./push_swap $ARGS5 | wc -l)
RES100=$(./push_swap $ARGS100 | wc -l)
RES500=$(./push_swap $ARGS500 | wc -l)

make re

echo \\n\\nTotal-------------\\n\\n
echo $RED'3--'$ENDCOLOR
echo Quantidade gerada: $N3\\nNúmero de movimentos: $RES3
echo $RED'5--'$ENDCOLOR
echo Quantidade gerada: $N5\\nNúmero de movimentos: $RES5
echo $RED'100--'$ENDCOLOR
echo Quantidade gerada: $N100\\nNúmero de movimentos: $RES100
echo $RED'500--'$ENDCOLOR
echo Quantidade gerada: $N500\\nNúmero de movimentos: $RES500