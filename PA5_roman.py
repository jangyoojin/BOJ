special = ['IV', 'IX', 'XL', 'XC']

roman = input()
i = 0
result = 0
while i != len(roman):
    if roman[i:i+2] in special:
        if roman[i:i+2] == 'IV': result += 4
        elif roman[i:i+2] == 'IX': result += 9
        elif roman[i:i+2] == 'XL': result += 40
        elif roman[i:i+2] == 'XC': result += 90
        i += 2
    else:
        if roman[i] == 'I': result += 1
        elif roman[i] == 'V': result += 5
        elif roman[i] == 'X': result += 10
        elif roman[i] == 'L': result += 50
        elif roman[i] == 'C': result += 100
        i += 1
print(result)
