import pyautogui
import time
from PIL import Image
import pytesseract
# navigate to YouTube
pyautogui.press('win')
pyautogui.write('chrome')
time.sleep(2)
pyautogui.press('enter')
time.sleep(3)
pyautogui.write('https://www.youtube.com')
pyautogui.press('enter')
time.sleep(3)

# search for cat videos
pyautogui.write('cat videos')
pyautogui.press('enter')

# check that the search results contain cat videos
screenshot = pyautogui.screenshot()
assert 'cat videos' in pytesseract.image_to_string(screenshot).lower()

# select the first cat video in the search results
time.sleep(3)
pyautogui.moveTo(x=500, y=500)
pyautogui.click()
time.sleep(3)

# check that the video title contains "cat"
screenshot = pyautogui.screenshot()
assert 'cat' in pytesseract.image_to_string(screenshot).lower()

# close the browser window
pyautogui.hotkey('ctrl', 'w')
