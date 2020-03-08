import re

string = input()

flag = True

if len(string) < 7:
    flag = False

if len(re.findall(r"[!@#$%&*]", string)) < 2:
    flag = False

if len(re.findall(r"[1-9]", string)) < 2:
    flag = False

if flag:
    print('Strong')
else:
    print('Weak')
