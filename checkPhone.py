from numpy import number
import phonenumbers
from phonenumbers import carrier, country_code_for_region

with open("phoneNum.txt") as f:
    lines = f.read()
    first = lines.split('\n',1)[0]

# print(first)

number = phonenumbers.parse(first)
operator = carrier.name_for_number(number,'en')

# print(operator)

f = open("phoneNum.txt", "w")
f.write(operator)
f.close()
