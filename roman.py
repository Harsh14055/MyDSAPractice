sym = ['I','V','X','L','C','D','M']
value = [1,5,10,50,100,500,1000]
num = int(input("Enter a number : "))
if num in value:
    print(sym[value.index(num)])

i = 0 
n = num
while(n>0):
    i = i + 1
    n = n//10
s = str(num)
if len(s)<4:
    s = "0"*(4-len(s)) + s
l =[]
ans = ""

for i in s:
    l.append(int(i))
k = len(l)    
# 1234

for i in range(k):
    t = l[i]
    if i==0:
        ans = ans + t*'M'
    if i==1:
        if t==4 or t==9:
            if t == 4:
                ans = ans + 'CD'
            if t == 9:
                ans = ans + 'CM'
        elif t<4:
            ans = ans + 'C'*t
        elif t>=5:
            ans = ans + 'D' + 'C'*(t-5)
    if i==2:
        if t==4 or t==9:
            if t == 4:
                ans = ans + 'XL'
            if t == 9:
                ans = ans + 'XC'
        elif t<4:
            ans = ans + 'X'*t
        elif t>=5:
            ans = ans + 'L' + 'X'*(t-5)
    if i==3:
        if t==4 or t==9:
            if t == 4:
                ans = ans + 'IV'
            if t == 9:
                ans = ans + 'IX'
        elif t<4:
            ans = ans + 'I'*t
        elif t>=5:
            ans = ans + 'V' + 'I'*(t-5) 
                
    
print(ans)
''''


'''