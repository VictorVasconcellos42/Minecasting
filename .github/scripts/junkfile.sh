#!/bin/bash

FILES='
*.d
*.o
*.ko
*.obj
*.elf
*.ilk
*.map
*.exp
*.gch
.*.swp
*.pch
*.lib
*.a
*.la
*.lo
*.dll
*.so
*.so.*
*.dylib
*.exe
*.out
*.app
*.i*86
*.x86_64
*.hex
*.dSYM/
*.su
*.idb
*.pdb
*.mod*
*.cmd
.tmp_versions/
modules.order
Module.symvers
Mkfile.old
dkms.conf
'

let RET=0

for file in $FILES; do
	if [ "$(find . -name "${file}")" ]; then
		echo "$(find . -name "${file}")"
		RET=1;
	fi
done

exit $RET