import pyttsx3
import PyPDF2
import keyboard
from tkinter.filedialog import *

book = askopenfilename()
pdfread = PyPDF2.PdfReader(book)
pages = len(pdfread.pages)

player = pyttsx3.init()
voices = player.getProperty('voices')
player.setProperty('voice', voices[1].id)

for num in range(0, pages):
    page = pdfread.pages[num]
    text = page.extract_text()
    player.save_to_file(text, 'test.mp3')
    player.runAndWait()
