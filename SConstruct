cflags = Split("-Wall -Wextra -pedantic -std=c99 -I include")

# cflags += Split("-g -O0")

env = Environment()
env.Append(CFLAGS=cflags)
env.Program("bin/example", "example.c")
