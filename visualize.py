import subprocess
import matplotlib.pyplot as plt
from matplotlib.backends.backend_tkagg import FigureCanvasTkAgg
from matplotlib.figure import Figure
import tkinter as tk


def run_sort():
    # Execute the C program
    array_size = entry.get()
    result = subprocess.run(["./sort"], input=array_size, text=True, capture_output=True)

    # Parse the output
    lines = result.stdout.split("\n")
    labels = []
    times = []
    for line in lines:
        if line:
            parts = line.split(" - ")
            labels.append(parts[0])
            times.append(float(parts[1].split(": ")[1].split(" ")[0]))  # extract the time and convert it to float

    # Clear the old figure
    for widget in root.winfo_children():
        if type(widget).__name__ == 'Canvas':
            widget.destroy()

    # Create a new figure and add it to the canvas
    figure = Figure(figsize=(6, 5), dpi=100)
    ax = figure.add_subplot(111)
    bar_chart = FigureCanvasTkAgg(figure, root)
    bar_chart.get_tk_widget().pack()
    ax.barh(labels, times, color='blue')
    ax.set_xlabel('Time (milliseconds)')
    ax.set_title('Sorting Algorithm Performance')


root = tk.Tk()
root.title('Sorting Algorithm Performance')

label = tk.Label(root, text="Enter the size of the array: ")
label.pack()

entry = tk.Entry(root)
entry.pack()

button = tk.Button(root, text="Run", command=run_sort)
button.pack()

root.mainloop()
