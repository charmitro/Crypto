def encrypt(string, key):
    text = string
    text = [ord(c) for c in text]
    result = []
    for i in range(len(text)):
        text[i] = text[i] + int(key)

    for i in range(len(text)):
        result.insert(i, chr(text[i]))
    result = "".join(str(i) for i in result)

    return result

def decrypt(string, key):
    text = string
    text = [ord(c) for c in text]
    result = []

    for i in range(len(text)):
        text[i] = text[i] - int(key)

    for i in range(len(text)):
        result.insert(i, chr(text[i]))

    result = "".join(str(i) for i in result)
    return result
