# модули для работы с символьными вычислениями
from __future__ import division
from sympy import *
from sympy.combinatorics.free_groups import free_group, vfree_group, xfree_group
from sympy.combinatorics.fp_groups import FpGroup
from sympy import div, ZZ, QQ

# библиотека интерфейса
from tkinter import *
from tkinter import messagebox
from tkinter import ttk

# глобальные переменные
label3, label4 = 0, 0
generators_count, exp_count = 0, 0
generators = []
exp_list = []
generators_entry = []
exp_list_entry = []
root = Tk()
root.title("Отрисовка таблицы Кэли группы, заданной образующими и соотношениями")
n = 0


def in_exp_list(a):
    for element in exp_list:
        if divided(a, element):
            return True
    return False


def in_exp_list_which_works_just_with_hell_render(a):
    global n
    for element in exp_list:
        if divided(a, element):
            n = exp_list.index(element)
            return True
    return False


def power_mod(a, b):
    a = f"{a}"[3:]
    b = f"{b}"[3:]
    return S(int(a) % int(b))


def correct_mod(a, b):
    while div(a, b)[0] != 0:
        a = div(a, b)[0]
    return a


def more_than_one(a):
    a = f"{a}"
    if a[1] != "/":
        return True
    return False


def divided(a, b):
    if div(a, b)[0] == 0:
        return False
    return True


def scan_elements_count():
    global generators_count, exp_count
    global generators, exp_list
    global generators_entry, exp_list_entry
    global label3, label4
    generators_count = int(generators_count_entry.get())
    exp_count = int(exp_count_entry.get())
    label1.grid_remove()
    label2.grid_remove()
    exp_count_entry.grid_remove()
    generators_count_entry.grid_remove()
    button.grid_remove()
    print(generators_count)
    generators_entry = [j for j in range(generators_count)]
    generators = [j for j in range(generators_count)]
    exp_list_entry = [j for j in range(exp_count)]
    exp_list = [j for j in range(exp_count)]
    label3 = Label(root, text="Введите образующие")
    label3.grid()
    print(generators_entry)
    for j in range(generators_count):
        generators_entry[j] = Entry(root, width=20)
        generators_entry[j].grid()
        print(generators_entry)
    label4 = Label(root, text="Введите соотношения")
    label4.grid()
    for j in range(exp_count):
        exp_list_entry[j] = Entry(root, width=20)
        exp_list_entry[j].grid()
    button1.grid()


def scan_generators_and_exps():
    global generators, exp_list
    global generators_count, exp_count_entry
    global generators_entry, exp_list_entry
    global label3, label4
    label4.grid_remove()
    label3.grid_remove()
    button1.grid_remove()

    for j in range(len(generators_entry)):
        generators[j] = var(generators_entry[j].get())
        generators_entry[j].grid_remove()
        # print(generators[j])
        # print(type(generators[j]))
    for j in range(len(exp_list_entry)):
        exp_list[j] = eval(exp_list_entry[j].get())
        exp_list_entry[j].grid_remove()
        # print(exp_list[j])
        # print(type(exp_list[j]))
    create_group()
    render_cayley_table()
    print(generators)


def create_group():
    global generators, generators_count
    global exp_list, exp_count
    appended = True
    while appended:
        appended = False
        for i in range(len(generators)):
            for j in range(len(generators)):
                try:
                    if in_exp_list(generators[i] * generators[j]):
                        new_element = correct_mod(generators[i] * generators[j], exp_list[k])
                        # print(new_element)
                    else:
                        new_element = generators[i] * generators[j]
                except:
                    break
                if new_element not in generators:
                    generators.append(new_element)
                    appended = True
    return generators


def render_cayley_table():
    global generators, generators_count
    global exp_list, exp_count
    global n
    changed = True
    for i in range(len(generators)):
        ttk.Label(root, text=f"{generators[i]}", width=10, background="green").grid(column=i+1, row=0)
        ttk.Label(root, text=f"{generators[i]}", width=10, background="green").grid(column=0, row=i+1)
    for i in range(len(generators)):
        for j in range(len(generators)):
            while changed:
                changed = False
                if in_exp_list_which_works_just_with_hell_render(generators[i] * generators[j]):
                    new_element = correct_mod(generators[i] * generators[j], exp_list[n])
                    print(n)
            else:
                new_element = generators[i] * generators[j]
            ttk.Label(root, text=f"{new_element}", width=10).grid(column=j+1, row=i+1)


label1 = Label(root, text="Введите количество образующих", width=40)
generators_count_entry = Entry(root, width=40)
label2 = Label(root, text="Введите количество соотношений", width=40)
exp_count_entry = Entry(root, width=40)
button = Button(root, text="Ввод", command=scan_elements_count)
button1 = Button(root, text="Ввод", command=scan_generators_and_exps)

label1.grid()
generators_count_entry.grid()
label2.grid()
exp_count_entry.grid()
button.grid()

print(generators)

root.mainloop()