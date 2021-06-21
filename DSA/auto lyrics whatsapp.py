import pyautogui
import time
from datetime import datetime


set_time = "00:36"
file_name = "/Users/shubhamahlawat/Course Work/C---Learning-Samples/DSA/lol.txt"


def do_it(file_name):
    # f = open(file_name, 'r')
    # time.sleep(4)
    for i in range(0,1000,1):
        if(i%2==0):
            pyautogui.typewrite("BEHENCHOD")
        else:
            pyautogui.typewrite("madarchod")
        pyautogui.press('enter')
        time.sleep(0.175)


while True:
    now = datetime.now()
    curr_time = now.strftime("%H:%M")
    if str(curr_time) == set_time:
        do_it(file_name)
        break
    else:
        continue
