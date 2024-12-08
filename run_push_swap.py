import random
import subprocess
import argparse

oparations = []

def run_push_swap(numbers_count):
	numbers = random.sample(range(-500, 500), numbers_count)

	numbers_str = " ".join(map(str, numbers))

	command_append = f"./push_swap {numbers_str}"
	command_count = f"./push_swap {numbers_str} | wc -l"

	# subprocess.run(command_append, shell=True)
	result = subprocess.run(command_count, shell=True, stdout=subprocess.PIPE, text=True)

	print(f"\n\n{command_append}")
	print(f"\033[92mOperations: {int(result.stdout.strip().split()[0])}\033[0m\n\n")

	oparations.append(int(result.stdout.strip().split()[0]))

if __name__ == "__main__":
	parser = argparse.ArgumentParser()
	parser.add_argument("numbers_count", type=int)

	args = parser.parse_args()

	for _ in range(10000):
		run_push_swap(args.numbers_count)

	print("\033[94mTest ran successfully 10000 times, with 100 random numbers in the range -500 to 500\033[0m")
	print(f"Average operations: {sum(oparations) / len(oparations)}")
	print(f"Max operations: {max(oparations)}")
	print(f"Min operations: {min(oparations)}")
	print(f"90% of data lay between: {sorted(oparations)[int(len(oparations) * 0.1)]} and {sorted(oparations)[int(len(oparations) * 0.9)]}")


# avg: 100 => 679.41
# avg: 500 => 6150.4

#after fix

# avg: 100 => 605.62 -11%
# avg: 500 => 5284.93 -15%
