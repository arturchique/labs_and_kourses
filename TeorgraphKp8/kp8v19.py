# библиотеки для ввода данных пользователем
from tkinter import *
from tkinter import messagebox
from tkinter import ttk

# библиотеки для работы с графом и его визуализации
import networkx as nx
from networkx.algorithms.approximation.independent_set import maximum_independent_set
import matplotlib.pyplot as plt

root = Tk()
root.title('Нахождение ядра неориентированного графа')
nodes_count = 0
matrix = list()
matrix_entry = list()


def confirm_count():
    global nodes_count
    global matrix_entry
    nodes_count = int(matrix_size_entry.get())
    matrix_size_entry.delete(0, END)
    label.config(text=f"Количество вершин -- {nodes_count}")
    matrix_size_entry.grid_remove()
    first_page_btn.grid_remove()
    matrix_entry = [0] * nodes_count ** 2
    for i in range(nodes_count ** 2):
        matrix_entry[i] = Entry(root, width=7)
        matrix_entry[i].grid(row=i // nodes_count + 1, column=i % nodes_count)
    second_page_btn.grid(columnspan=12)
    print(matrix_entry)


def confirm_matrix():
    global nodes_count
    global matrix_entry
    global matrix
    matrix = [0] * nodes_count ** 2
    for i in range(len(matrix_entry)):
        matrix[i] = int(matrix_entry[i].get())
        matrix_entry[i].grid_remove()
    print(matrix)
    render_graph()


def render_graph():
    global nodes_count
    global matrix
    i = 0
    g = nx.Graph()
    p = nx.Graph()
    colors = ["#00ffff", "#000000", "#0000ff", "#ff00ff", "#00ff00", "#800000", "#ff0000", "#ffff00"]
    for node in range(nodes_count):
        g.add_node(node)
        p.add_node(node)
    for element in matrix:
        if element == 1 and i // nodes_count != i % nodes_count:
            g.add_edge(i // nodes_count, i % nodes_count)
            p.add_edge(i // nodes_count, i % nodes_count)
        i += 1
    one_color = []
    node_color = ["b" for i in range(len(g.nodes))]
    j = 0
    while j <= len(g.nodes):
        one_color = list(maximum_independent_set(p))
        p.remove_nodes_from(one_color)
        # print(one_color)
        # print(p.nodes)
        for i in range(len(node_color)):
            if i in one_color:
                node_color[i] = colors[j]
        j += 1
        # print(node_color)
    nx.draw_planar(g, with_labels=True, node_color=node_color, alpha=0.8)
    plt.show()


label = Label(root, text="Введите количество вершин графа", width=40)
matrix_size_entry = Entry(root, width=80)
first_page_btn = Button(root, text="Ввести", command=confirm_count, width=80)
second_page_btn = Button(root, text="Раскрасить планарный граф", command=confirm_matrix, width=80)


label.grid(row=0, columnspan=10)
matrix_size_entry.grid()
first_page_btn.grid()

root.mainloop()