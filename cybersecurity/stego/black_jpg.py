from PIL import Image
NOME_FILE = "nuovo_file_valido.jpg"
immagine = Image.new("RGB", (640, 480), color=(0, 0, 0))
immagine.save(NOME_FILE, "JPEG")
print(f"File '{NOME_FILE}' generato con successo e con struttura valida!")
with open(NOME_FILE, "rb") as f:
    print(f"Primi 4 byte reali del file generato: {f.read(4).hex().upper()}")
