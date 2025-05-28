# Philosophers 🍽️

[![42 School](https://img.shields.io/badge/42-School-blue)](https://42firenze.it/)
[![GitHub license](https://img.shields.io/github/license/Nazar963/42_philosopher)](https://github.com/Nazar963/42_philosopher/blob/main/LICENSE)
[![Build Status](https://img.shields.io/github/actions/workflow/status/Nazar963/42_philosopher/.github/workflows/build.yml?branch=main)](https://github.com/Nazar963/42_philosopher/actions)

A solution to the classic Dining Philosophers Problem, implementing concurrency control with threads/mutexes (mandatory) to prevent deadlocks and data races.

![Philosophers Visualization](https://raw.githubusercontent.com/Nazar963/42_philosopher/main/images/demo.gif)

## Table of Contents 📖
- [Problem Description](#problem-description)
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [Algorithm](#algorithm)
- [Testing](#testing)
- [Resources](#resources)
- [Acknowledgments](#acknowledgments)
- [License](#license)

## Problem Description
The Dining Philosophers Problem is a classic synchronization challenge in computer science where multiple philosophers (threads/processes) share limited resources (forks). Each philosopher alternates between eating, sleeping, and thinking. To eat, a philosopher must acquire two adjacent forks without deadlocks or starvation .

**Project Requirements**:
- Prevent philosopher starvation
- Avoid data races and deadlocks
- Handle variable number of philosophers
- Monitor philosopher states to prevent death by starvation
- Support optional meal count termination

## Features

### Mandatory (Threads/Mutexes) 🔧
| Feature | Implementation |
|---------|----------------|
| Philosopher Threads | Each philosopher as separate thread |
| Fork Management | Mutex-protected fork array |
| Death Monitoring | Dedicated monitor thread |
| State Logging | Timestamped protected output |
| Meal Counting | Optional termination condition |


## Installation

### Requirements
- GCC (GNU Compiler Collection)
- GNU Make
- POSIX-compliant system

### Compilation
```bash
# Clone repository
git clone https://github.com/Nazar963/42_philosopher.git
cd 42_philosopher

# Compile mandatory part
make
```

## Usage

### Mandatory Syntax
```bash
./philo <number_of_philos> <time_to_die> <time_to_eat> <time_to_sleep> \
[number_of_meals]
```

### Examples
```bash
# 4 philosophers, die after 310ms without eating, 
# take 200ms to eat, 200ms to sleep, no meal limit
./philo 4 310 200 200

# 5 philosophers with 7 meal limit
./philo_bonus 5 800 200 200 7
```

### Output Format
```
[timestamp] [philo_id] [action]
```
Actions: `has taken a fork`, `is eating`, `is sleeping`, `is thinking`, `died`

## Algorithm

### Mandatory Solution
![Philosophers Example](https://raw.githubusercontent.com/Nazar963/42_Philosopher/main/images/graph.png)

### Key Techniques
1. **Deadlock Prevention**:  
   - Resource hierarchy (odd/even philosopher differentiation)
   - Timed lock acquisition attempts

2. **Starvation Avoidance**:  
   - Fair scheduling through turn-based eating
   - Priority inheritance for mutexes

3. **Data Race Prevention**:  
   - Mutex-protected shared memory access
   - Atomic operations for state changes 

## Testing

### Standard Tests
```bash
# Normal execution (should not die)
./philo 4 410 200 200

# Death simulation
./philo 4 310 200 200

# Meal termination
./philo 5 800 200 200 7
```

### Advanced Testing

1. **Memory Leak Check**:  
   ```bash
   valgrind --leak-check=full ./philo 4 410 200 200
   ```

2. **Performance Stress Test**:  
   ```bash
   ./philo 200 800 200 200
   ```

### Recommended Testers
- [MichelleJiam/LazyPhilosophersTester](https://github.com/MichelleJiam/LazyPhilosophersTester)
- [newlinuxbot/Philosphers-42Project-Tester](https://github.com/newlinuxbot/Philosphers-42Project-Tester)

## Resources
1. [The Dining Philosophers Problem Explained](https://medium.com/@ruinadd/philosophers-42-guide-the-dining-philosophers-problem-893a24bc0fe2) 
2. [42 Philosophers Gitbook](https://42-cursus.gitbook.io/guide) 
3. [POSIX Threads Programming Guide](https://hpc-tutorials.llnl.gov/posix/)

## Acknowledgments
- **42 School** for the project concept and guidelines
- **Edsger Dijkstra** for originally formulating the problem
- Peer reviewers at **42 Network** for rigorous testing
- Open-source community for testers and debugging tools

## 🤝 Contributing
Feel free to submit issues or pull requests if you have suggestions for improving the test suite or adding more test cases.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## 📧 Contact
For questions or feedback, please open an issue in the repository.

## ⭐ Star this repository if you found it helpful!
[![GitHub stars](https://img.shields.io/github/stars/Nazar963/42_philosopher?style=social)](https://github.com/Nazar963/42_philosopher/stargazers)

---

🪶 *"Concurrency requires wisdom, not just code."*  
[![42 School](https://img.shields.io/badge/42-profile-blue)](https://profile-v3.intra.42.fr/users/naal-jen)
[![GitHub Profile](https://img.shields.io/badge/GitHub-Nazar963-lightgrey)](https://github.com/Nazar963)
[![GitHub Follow](https://img.shields.io/github/followers/Nazar963?style=social)](https://github.com/Nazar963)

---

Good luck with your Philosophers project at 42! 🚀