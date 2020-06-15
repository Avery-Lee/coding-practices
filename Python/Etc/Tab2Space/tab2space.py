import sys

try:
    src = sys.argv[1]
    dst = sys.argv[2]

    if len(sys.argv) == 4:
        if sys.argv.count("-r") == True and sys.argv[1] == "-r":
                src = sys.argv[2]
                dst = sys.argv[3]
                with open(src, 'r', encoding='utf-8') as f1:
                    with open(dst, 'w', encoding='utf-8') as f2:
                        space = f1.read()
                        f2.write(space.replace(" "*4, "\t"))
        else: 
            print("You must type '-r' at the first argument to activate the reverse function.")

    elif len(sys.argv) == 3:
        with open(src, 'r', encoding='utf-8') as f1:
            with open(dst, 'w', encoding='utf-8') as f2:
                tab = f1.read()
                f2.write(tab.replace("\t", " "*4))
    else:
        print("You can only type 2 or 3 arguments. \nTo activate the reverse function, you can type '-r' argument before [input]")
except:
    print("Please type with [input] [output]. The [input] file must exist. \nFor instance, \"python practice.py file1.txt file2.txt\" \nTo activate the reverse function, you can type '-r' argument before [input]")