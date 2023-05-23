#!/bin/bash

PTHS=$(grep -e "SRC_PTH.*=" -e "INC_PTH.*=" Makefile | awk '{ print $NF }')
PTHS+=" "
PTHS+=$(find $(grep -e "LIB_PTH.*=" Makefile | awk '{print $NF}') -mindepth 1 -maxdepth 1 | sed "/mlx/d")

HERE=$(pwd)

let RET=0

for pths in $PTHS; do
	cd ${HERE}/${pths};
	norminette -R CheckForbiddenSourceHeader;
	if [ $? != 0 ]; then
		RET=1;
	fi
done

exit $RET
