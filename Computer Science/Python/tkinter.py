from tkinter import *

root = Tk()
root.title('Introduction to tkinter')
root.iconbitmap("Python_icon.ico")
root.geometry("500x500")

# Part 1
# hw = Label(root, text="Hello world!")
# hw.pack()

# Part 2
# topleft1 = Label(root, text="(0, 0)")
# topleft2 = Label(root, text="(0, 1)")
# bottomright1 = Label(root, text="(6, 6)")
# bottomright2 = Label(root, text="(6, 5)")
# middle = Label(root, text="(3, 3)")

# topleft1.grid(row=0, column=0)
# topleft2.grid(row=0, column=1)
# bottomright1.grid(row=6, column=6)
# bottomright2.grid(row=6, column=5)
# middle.grid(row=3, column=3)

# Part 3
# def display_label():
#     label = Label(root, text="You clicked the button")
#     label.pack()

# button = Button(root, text="Click", command=display_label, padx=30, pady=10, fg="#000", bg="#0f9")
# button.pack()

# Part 4
# entry = Entry(root, width=50)
# entry.insert(0, "Enter your name")
# entry.pack()

# def display_entry():
#     label_text = "Hello " + entry.get()
#     label = Label(root, text=label_text)
#     label.pack()
#     entry.delete(0, END)

# button = Button(root, text="Click", command=display_entry, padx=30, pady=10, fg="#000", bg="#0f9")
# button.pack()

# Part 5
# from PIL import ImageTk, Image

# img = ImageTk.PhotoImage(Image.open("Python_logo.png"))
# img_lbl = Label(image=img)
# img_lbl.pack()

# quit = Button(root, text="Quit", command=root.quit)
# quit.pack()

# Part 6
# frame1 = LabelFrame(root, padx=42, pady=42)
# frame2 = LabelFrame(root, padx=42, pady=42)

# frame1.pack(padx=5, pady=5)
# frame2.pack(padx=5, pady=5)

# button1 = Button(frame1, text="1")
# button2 = Button(frame1, text="2")
# button3 = Button(frame2, text="3")
# button4 = Button(frame2, text="4")

# button1.grid(row=0, column=0)
# button2.grid(row=1, column=1)
# button3.grid(row=0, column=1)
# button4.grid(row=1, column=0)

# Part 7
# pl_en = [("jeden", "one"), ("dwa", "two"), ("trzy", "three")]

# en_translation = StringVar()
# en_translation.set(pl_en[1][1])

# for (pl, en) in pl_en:
#     Radiobutton(root, text=pl, variable=en_translation, value=en).pack()

# Label(root, textvariable=en_translation).pack()

# es_integer = [("uno", 1), ("dos", 2), ("tres", 3)]

# integer_value = IntVar()
# integer_value.set(2)

# for (es, integer) in es_integer:
#     Radiobutton(root, text=es, variable=integer_value, value=integer).pack()

# Label(root, textvariable=integer_value).pack()

# Part 8
# from tkinter import messagebox
# # showinfo, showwarning, showerror, askquestion, askokcancel, askyesno

# def popup():
#     response = messagebox.askyesno("Some popup", "Do you like math?")
#     Label(root, text=response).pack()

# Button(root, text="Popup", command=popup).pack()

# Part 9
# from PIL import ImageTk, Image

# def open_new_window():
#     new_window = Toplevel()
#     new_window.title("New window")
    
#     # If you don't use global variable, your image won't appear
#     global img
#     img = ImageTk.PhotoImage(Image.open("Python_logo.png"))
#     Label(new_window, image=img).pack()

#     Button(new_window, text="Close", command=new_window.destroy).pack()

# Button(root, text="Open new window", command=open_new_window).pack()

# Part 10
# from tkinter import filedialog
# from PIL import ImageTk, Image

# def open_file():
#     location = filedialog.askopenfilename(initialdir="C:\\Users\\Kamil\\Downloads", title="Select file", filetypes=(("piendżi", "*.png"), ("dżejpidżi", "*.jpg"), ("nieważnejaki", "*.*")))
#     Label(root, text=location).pack()

#     global img
#     img = ImageTk.PhotoImage(Image.open(location))
#     Label(root, image=img).pack()

# Button(root, text="Open file", command=open_file).pack()

# Part 11
# tired = IntVar()
# Checkbutton(root, text="Are you tired?", variable=tired).pack()
# Label(root, textvariable=tired).pack()

# Part 12
# options = ["pl", "en", "es"]
# language = StringVar()
# language.set("es")
# OptionMenu(root, language, *options).pack()
# Label(root, textvariable=language).pack()

root.mainloop()
