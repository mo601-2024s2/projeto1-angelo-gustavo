#!/bin/bash
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 000.main.c -o 000.main.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 011.const.c -o 011.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 012.const.c -o 012.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 013.const.c -o 013.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 014.const.c -o 014.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 015.const.c -o 015.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 016.const.c -o 016.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 017.const.c -o 017.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 018.const.c -o 018.const.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 021.cast.c -o 021.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 022.cast.c -o 022.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 023.cast.c -o 023.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 024.cast.c -o 024.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 025.cast.c -o 025.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 026.cast.c -o 026.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 027.cast.c -o 027.cast.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 031.add.c -o 031.add.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 032.add.c -o 032.add.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 033.add.c -o 033.add.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 034.add.c -o 034.add.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 041.sub.c -o 041.sub.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 042.sub.c -o 042.sub.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 043.sub.c -o 043.sub.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 044.sub.c -o 044.sub.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 051.mul.c -o 051.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 052.mul.c -o 052.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 053.mul.c -o 053.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 054.mul.c -o 054.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 055.mul.c -o 055.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 056.mul.c -o 056.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 057.mul.c -o 057.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 058.mul.c -o 058.mul.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 061.div.c -o 061.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 062.div.c -o 062.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 063.div.c -o 063.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 064.div.c -o 064.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 065.div.c -o 065.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 066.div.c -o 066.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
# riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 067.div.c -o 067.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
# riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 068.div.c -o 068.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
# riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 069.div.c -o 069.div.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 071.bool.c -o 071.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 072.bool.c -o 072.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 073.bool.c -o 073.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 074.bool.c -o 074.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 075.bool.c -o 075.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 076.bool.c -o 076.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 077.bool.c -o 077.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 078.bool.c -o 078.bool.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 081.shift.c -o 081.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 082.shift.c -o 082.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 083.shift.c -o 083.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 084.shift.c -o 084.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 085.shift.c -o 085.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 086.shift.c -o 086.shift.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 111.if.c -o 111.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 112.if.c -o 112.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 113.if.c -o 113.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 114.if.c -o 114.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 115.if.c -o 115.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 116.if.c -o 116.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 117.if.c -o 117.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 118.if.c -o 118.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 119.if.c -o 119.if.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 121.loop.c -o 121.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 122.loop.c -o 122.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 123.loop.c -o 123.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 124.loop.c -o 124.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 125.loop.c -o 125.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 126.loop.c -o 126.loop.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 131.call.c -o 131.call.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 132.call.c -o 132.call.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 133.call.c -o 133.call.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 134.call.c -o 134.call.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 141.array.c -o 141.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 142.array.c -o 142.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 143.array.c -o 143.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 144.array.c -o 144.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 145.array.c -o 145.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
riscv64-linux-gnu-gcc -g -march=rv32im -std=gnu99 -mabi=ilp32 crt.S 146.array.c -o 146.array.riscv -g -march=rv32im -std=gnu99 -mabi=ilp32 -nostartfiles -nostdinc -nostdlib 
 
