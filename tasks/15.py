n = int(input())

arr = list(map(int, input().split()))

ans = 0
max_in_arr = arr[0]

for i in range(1, n):
    cur = arr[i]
    prev = arr[i-1]

    if cur > max_in_arr:
        ans += (cur - max_in_arr)
        max_in_arr = cur
    elif cur < prev:
        ans += (prev - cur)

print(ans)