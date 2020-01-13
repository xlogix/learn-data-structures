def get_fib(position):
    if position == 0:
        return 0
    if position == 1 or position == 2:
        return 1
    else:
        return get_fib(position-1) + get_fib(position-2)

# Test cases
print(get_fib(9))
print(get_fib(11))
print(get_fib(0))