#taken from https://gist.github.com/aasmpro/7703a5055c1dae72fe02157f9c06b3c3

def main():
    processes = int(input("number of processes : "))
    resources = int(input("number of resources : "))
    max_resources = [int(i) for i in input("maximum resources : ").split()]

    print("\n-- allocated resources for each process --")
    currently_allocated = [[int(i) for i in input(f"process {j + 1} : ").split()] for j in range(processes)]

    print("\n-- maximum resources for each process --")
    max_need = [[int(i) for i in input(f"process {j + 1} : ").split()] for j in range(processes)]

    allocated = [0] * resources
    for i in range(processes):
        for j in range(resources):
            allocated[j] += currently_allocated[i][j]
    print(f"\ntotal allocated resources : {allocated}")

    available = [max_resources[i] - allocated[i] for i in range(resources)]
    print(f"total available resources : {available}\n")

    running = [True] * processes
    count = processes
    while count != 0:
        safe = False
        for i in range(processes):
            if running[i]:
                executing = True
                for j in range(resources):
                    if max_need[i][j] - currently_allocated[i][j] > available[j]:
                        executing = False
                        break
                if executing:
                    print(f"process {i + 1} is executing")
                    running[i] = False
                    count -= 1
                    safe = True
                    for j in range(resources):
                        available[j] += currently_allocated[i][j]
                    break
        if not safe:
            print("the processes are in an unsafe state.")
            break

        print(f"the process is in a safe state.\navailable resources : {available}\n")


if __name__ == '__main__':
    main()

'''
Sample Output

number of processes : 5
number of resources : 4
maximum resources : 8 5 9 7

-- allocated resources for each process --
process 1 : 2 0 1 1
process 2 : 0 1 2 1
process 3 : 4 0 0 3
process 4 : 0 2 1 0
process 5 : 1 0 3 0

-- maximum resources for each process --
process 1 : 3 2 1 4
process 2 : 0 2 5 2
process 3 : 5 1 0 5
process 4 : 1 5 3 0
process 5 : 3 0 3 3

total allocated resources : [7, 3, 7, 5]
total available resources : [1, 2, 2, 2]

process 3 is executing
the process is in a safe state.
available resources : [5, 2, 2, 5]

process 1 is executing
the process is in a safe state.
available resources : [7, 2, 3, 6]

process 2 is executing
the process is in a safe state.
available resources : [7, 3, 5, 7]

process 4 is executing
the process is in a safe state.
available resources : [7, 5, 6, 7]

process 5 is executing
the process is in a safe state.
available resources : [8, 5, 9, 7]
'''