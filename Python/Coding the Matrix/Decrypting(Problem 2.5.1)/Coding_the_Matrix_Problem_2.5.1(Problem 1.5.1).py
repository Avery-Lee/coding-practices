'''
Problem 1.5.1: An 11-symbol message has been encrypted as follows. Each symbol is represented
by a number between 0 and 26 (A → 0,B → 1, . . . ,Z → 25, space → 26). Each number
is represented by a five-bit binary sequence (0 → 00000, 1 → 00001, ..., 26 → 11010). Finally,
the resulting sequence of 55 bits is encrypted using a flawed version of the one-time pad: the
key is not 55 random bits but 11 copies of the same sequence of 5 random bits. The cyphertext
is

10101 00100 10101 01011 11001 00011 01011 10101 00100 11001 11010

Try to find the plaintext.
'''

'''
Problem 2.5.1: 11-심볼 메시지를 다음과 같이 암호화하였다고 생각하자. 각 심볼은 0과 26
사이의 숫자에 의해 표현된다(A -> 0, B -> 1, ..., Z -> 25, space -> 26). 각 숫자는 5-비트 이진
시퀀스 (0 -> 00000, 1 -> 00001, ..., 26 -> 11010)에 의해 표현된다. 마지막으로, 55비트의 결과
시퀀스는 결함이 있는 일회성 패드를 사용하여 암호화된다. 키는 55개의 랜덤 비트가 아니라 5
개 랜덤 비트로 구성된 동일한 시퀀스를 11번 복사한 것이다. 암호문은 다음과 같다.

10101 00100 10101 01011 11001 00011 01011 10101 00100 11001 11010

평문을 찾아보자.
'''


keys = [i for i in range(32)]
cryptogram = [0b10101, 0b00100, 0b10101, 0b01011, 0b11001, 0b00011, 0b01011, 0b10101, 0b00100, 0b11001, 0b11010]
plaintext = []

def Decrypt(value):
    ASCII = 65                                    # ∵ASCII code 'A' is 65.
    ALPHABET = 26 - 1                             # ∵Alphabet has 26 characters. & Index number starts 0.
    value += ASCII                                  
    if value > ALPHABET + ASCII:                             
        if value == ALPHABET + 1 + ASCII:
            value = ' '
            return value
        else:
            value -= ALPHABET + 1
    return chr(value)


for key in keys:
    temp_decrypt = []
    for crypt in cryptogram:
        value = crypt ^ key
        temp_decrypt.append(Decrypt(value))
    plaintext.append(''.join(temp_decrypt))
    temp_dec = []

print(plaintext)
