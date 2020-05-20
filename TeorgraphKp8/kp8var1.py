# библиотеки для ввода данных пользователем
from tkinter import *
from tkinter import messagebox
from tkinter import ttk

# библиотеки для работы с графом и его визуализации
import networkx as nx
from networkx.algorithms.shortest_paths.generic import shortest_path


root = Tk()
root.title('Enter matrix size')
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
    render_graph()


def render_graph():
    global nodes_count
    global matrix
    i = 0
    g = nx.Graph()
    for node in range(nodes_count):
        g.add_node(node)
    for element in matrix:
        if element != 0 and i // nodes_count != i % nodes_count:
            g.add_edge(i // nodes_count, i % nodes_count, weight=element)
        i += 1
    for node1 in g.nodes:
        for node2 in g.nodes:
            ttk.Label(root, text=shortest_path(g, node1, node2)).grid()


label = Label(root, text="Введите одну цифру -- количество вершин графа", width=40)
matrix_size_entry = Entry(root, width=40)
first_page_btn = Button(root, text="Ввести", command=confirm_count)
second_page_btn = Button(root, text="Вывести все кратчайшие пути", command=confirm_matrix)


label.grid(row=0, columnspan=10)
matrix_size_entry.grid()
first_page_btn.grid()

root.mainloop()
