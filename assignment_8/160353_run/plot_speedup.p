#set terminal postscript eps enhanced color size 3.9,2.9
set term postscript eps enhanced monochrome 20 dashed dashlength 1 lw 1.5
set output "speedup.eps"
set logscale y
set key font ",22"
set xtics font ",22"
set ytics font ",22"
set ylabel font ",25"
set xlabel font ",25"
set xlabel "Number of Elements"
set ylabel "Average Speedup"
set yrange[0.5:]
set ytic auto
set boxwidth 1 relative
set style data histograms
set style histogram cluster
set style fill pattern border
plot 'partC' u 2:xticlabels(1) title "Thread 1",\
'' u 4 title "Thread 2" fillstyle pattern 7,\
'' u 6 title "Thread 4" fillstyle pattern 12,\
'' u 8 title "Thread 8" fillstyle pattern 12,\
'' u 10 title "Thread 16" fillstyle pattern 14
