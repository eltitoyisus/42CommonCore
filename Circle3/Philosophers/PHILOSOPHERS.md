# Philosophers

## Description

Philosophers is a classic synchronization problem that teaches you the fundamentals of threading and process synchronization. Based on Dijkstra's dining philosophers problem, you must prevent deadlocks and race conditions while managing shared resources.

## Project Overview

The problem: Several philosophers sit at a round table with a bowl of spaghetti. They alternate between eating, thinking, and sleeping. To eat, a philosopher needs two forks (one on their left, one on their right). The challenge is to write a program that prevents philosophers from starving while avoiding deadlocks.

This project teaches you:
- Multi-threading concepts
- Mutex usage and synchronization
- Race condition prevention
- Deadlock avoidance
- Thread-safe programming
- Resource sharing problems

## The Rules

1. **Philosophers' actions**:
   - **Eating**: Requires two forks, can't be interrupted
   - **Thinking**: After eating
   - **Sleeping**: After eating (before thinking)

2. **Constraints**:
   - Philosophers don't communicate
   - They don't know if another philosopher is about to die
   - Avoid philosopher deaths!

3. **Simulation ends when**:
   - A philosopher dies from starvation
   - All philosophers have eaten at least `number_of_times_each_philosopher_must_eat` (optional)

## Usage

```bash
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

**Arguments**:
- `number_of_philosophers` - Number of philosophers (and forks)
- `time_to_die` - Time (ms) before a philosopher dies from starvation
- `time_to_eat` - Time (ms) a philosopher takes to eat
- `time_to_sleep` - Time (ms) a philosopher spends sleeping
- `number_of_times_each_philosopher_must_eat` - (Optional) Simulation stops when all philosophers eat this many times

**Examples**:
```bash
./philo 5 800 200 200          # 5 philosophers, dies at 800ms, eats for 200ms, sleeps for 200ms
./philo 5 800 200 200 7        # Same but stops after each philosopher eats 7 times
./philo 4 410 200 200          # 4 philosophers with tight timing
./philo 1 800 200 200          # Edge case: 1 philosopher (should die)
```

## Output Format

```
[timestamp_in_ms] [philosopher_id] [action]
```

**Actions**:
- `has taken a fork`
- `is eating`
- `is sleeping`
- `is thinking`
- `died`

**Example**:
```
0 1 has taken a fork
0 1 has taken a fork
0 1 is eating
200 1 is sleeping
200 3 has taken a fork
200 3 has taken a fork
200 3 is eating
```

## Implementation Structure

```
philo/
├── Makefile
├── philo.h           # Header file
├── main.c            # Main and initialization
├── init.c            # Setup philosophers and mutexes
├── routine.c         # Philosopher routine
├── actions.c         # Eating, sleeping, thinking
├── monitor.c         # Death checking
├── utils.c           # Time and utility functions
└── cleanup.c         # Free resources
```

## Key Concepts

### Mutexes
- Protect shared resources (forks)
- Prevent race conditions
- Lock before accessing shared data
- Always unlock after use

### Deadlock Prevention
Common strategies:
1. **Resource ordering** - Always pick up lower-numbered fork first
2. **Even/odd approach** - Even philosophers pick left first, odd pick right first
3. **Waiter solution** - Limit simultaneous eaters

### Data Race Prevention
- Protect all shared variables with mutexes
- Use separate mutex for print statements
- Protect philosopher state checks

### Timing
- Use `gettimeofday()` for timestamps
- Implement precise `usleep()` wrapper
- Check death condition regularly

## Thread Functions Allowed

```c
pthread_create()     // Create a thread
pthread_join()       // Wait for thread to terminate
pthread_detach()     // Detach a thread
pthread_mutex_init()    // Initialize mutex
pthread_mutex_destroy() // Destroy mutex
pthread_mutex_lock()    // Lock mutex
pthread_mutex_unlock()  // Unlock mutex
```

## Common Pitfalls

### Data Races
- Unprotected access to shared variables
- Multiple threads modifying same data
- Reading while another thread writes

### Deadlocks
- Circular wait condition
- All philosophers grab left fork simultaneously
- Need proper fork acquisition order

### Starvation
- Some philosophers never get to eat
- Unfair resource distribution
- Poor scheduling

### Memory Leaks
- Not joining/detaching threads
- Not destroying mutexes
- Forgetting to free allocated memory

## Testing Scenarios

### No Deaths Should Occur
```bash
./philo 5 800 200 200    # Should run indefinitely
./philo 4 410 200 200    # Tight timing but shouldn't die
./philo 2 800 200 200    # Two philosophers
```

### Death Should Occur
```bash
./philo 1 800 200 200    # Only one fork available, must die
./philo 4 310 200 100    # Impossible timing
```

### Optional Argument
```bash
./philo 5 800 200 200 7  # Should stop after all eat 7 times
./philo 4 410 200 200 10 # Each must eat 10 times
```

## Debugging Tips

1. **Use Thread Sanitizer**:
   ```bash
   gcc -fsanitize=thread -g
   ```

2. **Add Debug Prints** (remove for submission):
   ```c
   printf("[DEBUG] Philosopher %d acquired fork %d\n", id, fork_id);
   ```

3. **Test with Valgrind** (for memory leaks):
   ```bash
   valgrind --leak-check=full ./philo 5 800 200 200
   ```

4. **Helgrind** (thread debugging):
   ```bash
   valgrind --tool=helgrind ./philo 5 800 200 200
   ```

## Skills Acquired

- Multi-threading and parallelism
- Mutex synchronization
- Deadlock prevention strategies
- Race condition handling
- Thread-safe programming
- Resource management
- Concurrent algorithm design
- Understanding of dining philosophers problem
- Performance optimization in concurrent systems

## Circle

**Circle 3** - Threading and synchronization project at 42 School
