from c2pa import Reader
with open('face.png','rb') as f:
    r = Reader('image/png', f)
    print(r.json())
