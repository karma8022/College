def rotateNibble(text):
    """

    :param text: list of 0s and 1s
    :return: string
    """
    return text[4:] + text[:4]


def subNibble(order, text):
    """

    :param order: matrix
    :param text: list of 0s and 1s
    :return: int
    """
    subText = ""
    for i in range(int(len(text) / 4)):
        row = int(str(text[4 * i]) + str(text[4 * i + 1]), 2)
        col = int(str(text[4 * i + 2]) + str(text[4 * i + 3]), 2)
        subText += order[row][col]
    return int("0x" + subText, 16)


def shrow(text):
    return text[:4] + text[12:] + text[8:12] + text[4:8]


def multmixCol(text, mixCol):

    """

    :param text:
    :param mixCol:
    :return:
    """
    # converting text to int array
    mixColRef = {2: ["2", "4", "6", "8", "a", "c", "e", "3", "1", "7", "5", "b", "9", "f", "d"],
                 4: ["4", "8", "c", "3", "7", "b", "f", "6", "2", "e", "a", "5", "1", "d", "9"],
                 9: ["9", "1", "8", "2", "b", "3", "a", "4", "d", "5", "c", "6", "f", "7", "e"]}

    intTextCol = [[], []]
    for i in range(4):
        nibble = str(text[4 * i]) + str(text[4 * i + 1]) \
                 + str(text[4 * i + 2]) + str(text[4 * i + 3])
        intTextCol[i % 2].append(nibble)

    resultText = [[0, 0], [0, 0]]
    for i in range(2):
        for j in range(2):
            for k in range(2):

                row = mixCol[i][k]
                col = int(intTextCol[k][j], 2)

                if row == 1:
                    term = col
                    resultText[i][j] ^= term
                else:
                    term = mixColRef[row][col - 1]
                    resultText[i][j] ^= int(term, 16)

    resultBin1 = format(resultText[0][0], "b").zfill(4)
    resultBin2 = format(resultText[1][0], "b").zfill(4)
    resultBin3 = format(resultText[0][1], "b").zfill(4)
    resultBin4 = format(resultText[1][1], "b").zfill(4)

    return int(resultBin1 + resultBin2 + resultBin3 + resultBin4, 2)


class Key:

    def __init__(self):

        self.subkey2Hex = None
        self.subkey3Hex = None
        self.subkey1Hex = None
        self.subkey3 = None
        self.subkey2 = None
        self.subkey1 = None
        self.keyBinary = None
        self.key = None
        self.sub = [["9", "4", "a", "b"],
                    ["d", "1", "8", "5"],
                    ["6", "2", "0", "3"],
                    ["c", "e", "f", "7"]]

    def accept(self, k):

        self.key = k
        self.keyBinary = [int(i) for i in format(int(self.key, 16), "b").zfill(16)]

        if len(self.keyBinary) == 16:
            self.generateKey()
            return True
        else:
            return False

    def generateKey(self):

        # subkey1
        self.subkey1 = self.keyBinary.copy()
        self.subkey1Hex = hex(int("".join([str(i) for i in self.subkey1]), 2))[2:]

        # converting list to int
        w0 = int("".join([str(i) for i in self.subkey1[:8]]), 2)
        w1 = int("".join([str(i) for i in self.subkey1[8:]]), 2)

        # generating w2
        w1Bin = self.subkey1[8:]

        w2 = w0 ^ int("10000000", 2) ^ subNibble(self.sub, rotateNibble(w1Bin))

        # generating w3
        w3 = w2 ^ w1

        # subkey2

        self.subkey2 = [int(i) for i in format(int(hex(w2)[2:] + hex(w3)[2:], 16), "b")]
        self.subkey2Hex = hex(w2)[2:] + hex(w3)[2:]
        # generating w4
        w3Bin = [int(i) for i in format(w3, "b").zfill(8)]
        w4 = w2 ^ int("00110000", 2) ^ subNibble(self.sub, rotateNibble(w3Bin))

        # generating w5

        w5 = w4 ^ w3

        # subkey 3
        self.subkey3 = [int(i) for i in format(int(hex(w4)[2:] + hex(w5)[2:], 16), "b")]
        self.subkey3Hex = hex(w4)[2:] + hex(w5)[2:]


class simpleAes:

    def __init__(self, k):

        self.decText = None
        self.encText = None
        self.plainText = None
        self.ciphText = None
        self.keyGen = Key()
        self.isGen = self.keyGen.accept(k)
        self.sub = [["9", "4", "a", "b"],
                    ["d", "1", "8", "5"],
                    ["6", "2", "0", "3"],
                    ["c", "e", "f", "7"]]
        self.mixCol = [[1, 4],
                       [4, 1]]

        self.invsub = [["a", "5", "9", "b"],
                       ["1", "7", "8", "f"],
                       ["6", "0", "2", "3"],
                       ["c", "4", "d", "e"]]

        self.invmixCol = [[9, 2],
                          [2, 9]]

        if self.isGen:
            print("Key Entered:- ", k)
            print("Sub-keys Generated:- ")
            self.hexSubkey1 = self.keyGen.subkey1Hex
            self.hexSubkey2 = self.keyGen.subkey2Hex
            self.hexSubkey3 = self.keyGen.subkey3Hex
            print(f"\t1: {self.hexSubkey1}")
            print(f"\t2: {self.hexSubkey2}")
            print(f"\t3: {self.hexSubkey3}")
        else:
            print("Keys not generated")

    def plainToCiph(self, text):

        self.plainText = text
        # round 0
        round0res = int(self.plainText, 16) ^ int(self.hexSubkey1, 16)
        round0resBin = [int(i) for i in format(round0res, "b").zfill(16)]

        # round 1

        round1res = int(self.hexSubkey2, 16) ^ multmixCol(
            shrow(format(subNibble(self.sub, round0resBin), "b").zfill(16)), self.mixCol)
        round1resBin = [int(i) for i in format(round1res, "b").zfill(16)]

        # round 2
        tempRound2 = shrow(format(subNibble(self.sub, round1resBin), "b").zfill(16))
        round2res = int(self.hexSubkey3, 16) ^ int("".join([str(i) for i in tempRound2]), 2)
        self.encText = hex(round2res)[2:].zfill(4)

    def CiphToPlain(self, text):

        self.ciphText = text
        # round 0
        round0res = int(self.ciphText, 16) ^ int(self.hexSubkey3, 16)

        # round 1
        shiftRow = [int(i) for i in shrow(format(round0res, "b").zfill(16))]
        subst = subNibble(self.invsub, shiftRow)
        addRound1 = int(self.hexSubkey2, 16) ^ subst
        round1res = multmixCol(format(addRound1, "b").zfill(16), self.invmixCol)

        # round 2
        shiftRow = [int(i) for i in shrow(format(round1res, "b").zfill(16))]
        subst = subNibble(self.invsub, shiftRow)
        addRound2 = int(self.hexSubkey1, 16) ^ subst
        self.decText = hex(addRound2)[2:].zfill(4)


# main code

# plain text = D728, 6f6b ciph24ec
# key = 4af5, a73b ciph0738

key = input("Enter 16 bit key in hex code (0 to ffff): ")
ciph = simpleAes(key)
print("1.Encryption")
print("2.Decryption")
choice = input(":-")

if choice == "1":

    plaintext = input("Enter 16 bit plaintext to encrypt:- ")

    plainList = [int(i) for i in format(int(plaintext, 16), "b").zfill(16)]

    if len(plainList) == 16:
        ciph.plainToCiph(plaintext)
        print("Encrypted Text:- ", ciph.encText)

    else:
        print("Error occurred")

elif choice == "2":
    ciphText = input("Enter 16 bit cipher text to decrypt:- ")

    ciphList = [int(i) for i in format(int(ciphText, 16), "b").zfill(16)]

    if len(ciphList) == 16:
        ciph.CiphToPlain(ciphText)
        print("Decrypted Text:- ", ciph.decText)
        
       
#Input-Output       
#Enter 16 bit key in hex code (0 to ffff): 4AF5
#Key Entered:-  4AF5
#Sub-keys Generated:- 
#	1: 4af5
#	2: dd28
#	3: 87af
#1.Encryption
#2.Decryption
#:-1
#Enter 16 bit plaintext to encrypt:- D728
#Encrypted Text:-  24ec

        

    else:
        print("Error occurred")