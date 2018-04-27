set term postscript eps enhanced monochrome 20 dashed dashlength 1 lw 1.5
#set terminal postscript eps enhanced color
set logscale x
set key samplen 2 spacing 1 font ",22"

set xtics font ",22"
set ytics font ",22"
set ylabel font ",25"
set xlabel font ",25"

#set format y "10^{%L}"
set xlabel "Number of Element"
set ylabel "Execution Time"
set yrange[0:100000]
set xrange[1:1000000]
set ytic auto
set xtic auto


set output "partA_t5.eps"
plot 't5' using 1:2 notitle with points pt 1 ps 1.5

