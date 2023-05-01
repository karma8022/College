from tkinter import *
import sqlite3
import os
conn=sqlite3.connect("people.db")
cursor=conn.cursor()

cursor.execute("CREATE TABLE IF NOT EXISTS names(first_name text)")

def insert():
    name=e.get()
    cursor.execute("INSERT INTO names VALUES (?)",(name,))
    conn.commit()
    e.delete(0,END)
    
root=Tk()
root.geometry("500x300")
root.title("ADD YOUR NAME TO THE DATABASE:")

lbl_main=Label(root,text="Database Entry")
lbl_main.place(x=180,y=50)

e_label1=Label(root,text="First Name : ")
e_label1.place(x=50,y=100)

e=Entry(root, borderwidth=5, width=50)
e.place(x=120,y=100)

button_insert=Button(root,text="INSERT",command=insert)
button_insert.place(x=200,y=200)
root.mainloop()

cursor.execute("SELECT * FROM names")
table=cursor.fetchall()

list_names=[]

for row in table:
    list_names.append(row[0])
print(list_names)

conn.close()

for i in list_names:
    conn=sqlite3.connect(os.path.join('Project\databases',f"{i}.db"))
    cursor=conn.cursor()
    cursor.execute("CREATE TABLE IF NOT EXISTS equipment_issued(equipment_name)")
    conn.close()

dir_path = r"Project\databases"
res = []
flag = 0

for path in os.listdir(dir_path):
    if os.path.isfile(os.path.join(dir_path, path)):
        res.append(path)

print(res)

name_input = input("Enter your name:")
name_input = name_input + ".db"
file = "Project/databases/" + name_input 

for files in res:
    if files == name_input:
        flag = 1
        break

if flag == 1:
    print("Continue on GUI...")

    def add_db():
        equipment = clicked.get()
        label.config(text=equipment)
        conn = sqlite3.connect(file)
        cursor = conn.cursor()
        cursor.execute("INSERT INTO equipment_issued VALUES (?)", (equipment,))
        conn.commit()
        conn.close()

    root = Tk()

    root.geometry("450x450")
    root.title("SELECT THE ITEMS THAT YOU ARE ISSUING:")
    # Dropdown menu options
    options = [
        "Camera: ZWO 1600 MM pro monochrom ",
        "SOLARIX Solar filter (Explore Scientific -USA) - For RC 10",
        "ASI462MC(Color)",
        "Eyepieces: 40 mm",
        "Eyepieces: 25 mm",
        "Eyepieces: 15 mm",
        "Eyepieces: 9 mm",
        "Eyepieces: 4 mm",
        "GSO SuperView 20mm 1.15 Wide Angle Eyepiece",
        "GSO 2 inch 99% Quartz Dielectric mirror Diagonal CNC",
        "GSO 2x ED-Barlow-Lens (Multicoated)",
        "T-RING Canon M42",
        'T Adapter 1.25" ',
        "Eyepiece Projection Camera Adapter",
        "Mobile Cell Phone Adapter",
        "GSO 1.25",
        "32mm Camera Projection Lens (CPL) eyepiece",
        "COMA Corrector 2 inch",
        'GSO 0.5X Focal Reducer 1.25" with 25mm extension tube',
        "GSO ND Filter 25% GSO ND Filter 50%",
        "60mm GUIDE SCOPE",
        "Green Laser Pointer with rechargeable battery",
        'NexGen 2" Laser Collimator for Telescopes',
        "Astro R-Lite Red Flashlight for Astronomy",
        "Eyepiece and Accessory Soft Case",
        "Dessicant Cap 1.25 inch",
        "ZWO NB7nmD31",
        "ZWO EFW 8*1.25”",
        "ZWO LRGBI.25NEW",
        "ZWO EAF-with HC",
        "ZWO ASI AIR PLUS",
        "ZWO 12V 5A AC to DC Adapter for cooled cam & AIRPro",
        "ZWO UV IR Cut filter-1.25”",
    ]

    clicked = StringVar()
    clicked.set("Camera: ZWO 1600 MM pro monochrom")

    drop = OptionMenu(root, clicked, *options)
    drop.pack()

    # Create button, it will change label text
    button = Button(root, text="Add to Cart", command=add_db).pack()

    label = Label(root, text=" ")
    label.pack()

    root.mainloop()
else:
    print("Add your name to the database to continue...")
