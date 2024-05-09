def josephus(N):
    # 초기 제자들의 리스트 생성
    students = list(range(1, N+1))
    current_index = 0  # 현재 시작 위치
    t = 1  # 단계

    while len(students) > 1:
        # t^3 계산
        step = t**3
        # 탈락할 제자의 인덱스 계산. (현재 인덱스 + step - 1) % 남은 제자 수
        current_index = (current_index + step - 1) % len(students)
        # 탈락할 제자 제거
        students.pop(current_index)
        # 다음 단계로
        t += 1

    return students[0]

# 입력 받기
N = int(input())
# 결과 출력
print(josephus(N))