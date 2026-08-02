set terminal png
set output "runtime_plot.png"
set datafile separator ","
set xlabel "Dataset Size (n)"
set ylabel "Average Runtime (seconds)"
set title "Quickselect Average Runtime"
plot "runtimes.csv" using 1:2 with linespoints title "Quickselect"