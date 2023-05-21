#!/bin/bash

PTHS=$(grep -e "SRC_PTH.*=" -e "INC_PTH.*=" Makefile | awk '{ print $NF }')
PTHS+=" "
PTHS+=$(find $(grep -e "LIB_PTH.*=" Makefile | awk '{print $NF}') -mindepth 1 -maxdepth 1 | sed "/mlx/d")

HERE=$(pwd)

for pths in $PTHS; do
	echo PATH = [${pths}]
	cd ${HERE}/${pths}
	norminette -R CheckForbiddenSourceHeader
done
