
isExist = False
min_ = 1100000
ans = "-1"

def find_higher_in_permutations(it, num, s):

    global min_, ans, isExist

    check = int(s)

    if (len(s) == it + 1):
        length = len(str(check))

        if (length != len(s)):
            return

        if (check > num and check < min_):
            ans = str(check)
            min_ = check
            isExist = True
            return
        

    for j in range(it, len(s)):
        caretaker = s

        old = "$"

        if (j > it and caretaker[it] == caretaker[j]):
            continue

        if (old == s[j]):
            continue

        old = s[j]

        toSwap = list(caretaker)
        
        toSwap[it], toSwap[j] = toSwap[j], toSwap[it]

        caretaker = ""
        for i in toSwap:
            caretaker += i

        find_higher_in_permutations(it + 1, num, caretaker)
    

num = int(input())

s = sorted(str(num))

ss = ""
for i in s:
    ss += i

min_ = 1100000

find_higher_in_permutations(0, num, ss)

if (not isExist):
    ans = "-1"

print(ans)

isExist = False