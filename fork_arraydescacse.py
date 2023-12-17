from multiprocessing import Process, Manager, current_process

def sort_descending(arr):
    arr.sort(reverse=True)
    print(f"Parent Process ({current_process().pid}) - Sorted Descending: {arr}")

def sort_ascending(arr):
    arr.sort()
    print(f"Child Process ({current_process().pid}) - Sorted Ascending: {arr}")

def main():
    with Manager() as manager:

        shared_arr = manager.list([7, 2, 5, 1, 8, 6])

        parent_process = Process(target=sort_descending, args=(shared_arr,))
        child_process = Process(target=sort_ascending, args=(shared_arr,))


        parent_process.start()
        child_process.start()

    
        parent_process.join()
        child_process.join()

if __name__ == "__main__":
    main()
