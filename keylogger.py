import pynput
from pynput.keyboard import Key, Listener

def on_press(key):
    try:
        print(f"Pressed: {key.char}")
    except AttributeError:
        print(f"Special key pressed: {key}")


def on_release(key):
    if key == Key.esc:
        return False     

with Listener(on_press=on_press, on_release=on_release) as listener:
    listener.join()