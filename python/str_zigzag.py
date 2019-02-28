def convert(s: str, numRows: int) -> str:
    if numRows == 1:
        return s

    lines = ['' for _ in range(numRows)]
    cur = 0
    down = True
    for char in s:
        lines[cur] += char
        cur += 1 if down else -1
        if cur == numRows - 1 or cur == 0:
            down = not down
    print(lines)
    return ''.join(lines)


if __name__ == '__main__':
    print(convert(s="PAYPALISHIRING", numRows=1))

