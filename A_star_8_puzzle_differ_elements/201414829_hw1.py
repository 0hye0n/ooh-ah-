import argparse as ap
import heapq
import copy
import timeit

start = timeit.default_timer()
d = {}
parent = {}

def init():
    parser = ap.ArgumentParser()

    parser.add_argument("--input", type=str, default=None, help="input file")

    args = parser.parse_args()

    file = open(args.input)
    input = file.read()

    list = input.split("\n")
    current = list[0].split(" ")
    answer = list[1].split(" ")
    current = [[current[0], current[1], current[2]], [current[3], current[4], current[5]],
               [current[6], current[7], current[8]]]
    answer = [[answer[0], answer[1], answer[2]], [answer[3], answer[4], answer[5]], [answer[6], answer[7], answer[8]]]

    return current, answer

def make_hash(current):
    ret = ""
    for i in range(3):
        for j in range(3):
            ret = ret + current[i][j]
    return ret

def cal_diff(current, answer):
    ret = 0
    for i in range(3):
        for j in range(3):
            if current[i][j] != answer[i][j]:
                ret = ret + 1
    return ret

def find_zero(current):
    for i in range(3):
        for j in range(3):
            if current[i][j] == '0':
                return i, j

def print_arr(current):
    for i in range(3):
        for j in range(3):
            print(current[i][j], end=' ')
    print()

dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

current, answer = init()

priority_queue = []

x, y = find_zero(current)

heapq.heappush(priority_queue, (cal_diff(current, answer), 0, current, x, y))
hash = make_hash(current)
d[hash] = True
parent[hash] = None


while True:
    cost, depth, cur, curx, cury = heapq.heappop(priority_queue)

    if cal_diff(cur, answer) == 0:
        res = []
        res.append(cur)
        it = copy.deepcopy(cur)
        while parent[make_hash(it)] != None:
            res.append(parent[make_hash(it)])
            it = parent[make_hash(it)]

        k = depth
        while k >= 0:
            arr = res[k]
            print_arr(arr)
            k = k - 1
        break

    for i in range(4):
        nx = curx + dx[i]
        ny = cury + dy[i]
        if nx < 0 or nx >= 3 or ny < 0 or ny >= 3:
            continue
        temp = copy.deepcopy(cur)

        temp[curx][cury], temp[nx][ny] = temp[nx][ny], temp[curx][cury]
        hash = make_hash(temp)

        if hash in d:
            continue

        d[hash] = True
        parent[hash] = cur
        heapq.heappush(priority_queue, (depth + 1 + cal_diff(temp, answer), depth + 1, temp, nx, ny))


stop = timeit.default_timer()
print(stop - start)