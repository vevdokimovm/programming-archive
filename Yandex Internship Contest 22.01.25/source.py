# Task B.

N, B = [int(x) for x in input().split()]

A = [int(x) for x in input().split()]

# В общем и целом фиксируем число в A, равное B и делаем его пивотом

# Проверим, что такое число вообще есть
index_B = -1
for i in range(N):
    if A[i] == B:
        index_B = i
        break

ans = 0

# Переберем в наглую все дельта влево и вправо просто чтобы
# выполнялись два условия на медиана и нечетность отрезка
for deltaLeft in range(0, index_B + 1):
    for deltaRight in range(0, N - index_B + 1):
        start = index_B - deltaLeft
        end = index_B + deltaRight

        if (end - start + 1) % 2 == 0:
            continue

        # Проверяем на выход за границы
        if start < 0:
            continue
        if end >= N:
            continue

        sub_seq = []
        for i in range(start, end + 1):
            sub_seq.append(A[i])

        sub_seq = sorted(sub_seq)
        index_mediana = len(sub_seq) // 2
        if sub_seq[index_mediana] == B:
            ans += 1
                
print(ans)
        