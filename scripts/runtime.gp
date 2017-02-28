reset
set ylabel 'time(sec)'
set style fill solid
set title 'perfomance comparison'
set term png enhanced font 'Verdana,10'
set output 'runtime.png'

plot [:][:0.150]'output.txt' using 2:xtic(1) with histogram title 'original', \
'' using ($0):(0.085):2 with labels title ' ' textcolor lt 1, \
'' using 3:xtic(1) with histogram title 'optimized'  , \
'' using ($0):(0.08):3 with labels title ' ' textcolor lt 2, \
'' using 4:xtic(1) with histogram title 'binarysearchtree'  , \
'' using ($0):(0.075):4 with labels title ' ' textcolor lt 3, \
'' using 5:xtic(1) with histogram title 'combine'  , \
'' using ($0):(0.07):5 with labels title ' ' textcolor lt 4, \
